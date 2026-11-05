#include <QCoreApplication>
#include <QTimer>
#include <QFile>
#include <QDir>
#include <iostream>
#include "../include/model_loader_worker.h"

void writeTestFile(const QString& path, const QByteArray& content) {
    QFile file(path);
    if (file.open(QIODevice::WriteOnly)) {
        file.write(content);
        file.close();
    }
}

class TestWorker : public QObject {
    Q_OBJECT
public:
    explicit TestWorker(const QStringList& files, QObject* parent = nullptr) : QObject(parent), testFiles(files), currentIndex(0) {}

public slots:
    void runNextTest() {
        if (currentIndex >= testFiles.size()) {
            std::cout << "All robustness tests completed successfully." << std::endl;
            QCoreApplication::quit();
            return;
        }

        QString currentFile = testFiles[currentIndex];
        std::cout << "Testing file: " << currentFile.toStdString() << std::endl;

        loader = new ModelLoaderWorker(currentFile, this);
        connect(loader, &ModelLoaderWorker::sigFinished, this, &TestWorker::onFinished);
        connect(loader, &ModelLoaderWorker::sigFailed, this, &TestWorker::onFailed);

        QTimer::singleShot(0, loader, &ModelLoaderWorker::startLoading);
    }

    void onFinished(ModelDataPtr model) {
        std::cout << "  -> Finished (Loaded " << (model ? model->meshes.size() : 0) << " meshes)" << std::endl;
        cleanupAndNext();
    }

    void onFailed(const QString& err) {
        std::cout << "  -> Failed cleanly: " << err.toStdString() << std::endl;
        cleanupAndNext();
    }

private:
    void cleanupAndNext() {
        if (loader) {
            loader->deleteLater();
            loader = nullptr;
        }
        currentIndex++;
        QTimer::singleShot(10, this, &TestWorker::runNextTest);
    }

    QStringList testFiles;
    int currentIndex;
    ModelLoaderWorker* loader = nullptr;
};

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    QString tempDir = QDir::tempPath() + "/3dmaster_robustness_tests";
    QDir().mkpath(tempDir);

    QStringList files;

    // 1. Truncated Binary STL
    QString file1 = tempDir + "/truncated.stl";
    QByteArray stl1(80, 0); // Header
    uint32_t tris = 10000;
    stl1.append(reinterpret_cast<const char*>(&tris), 4);
    stl1.append(QByteArray(100, 0)); // Only 2 triangles data instead of 10000
    writeTestFile(file1, stl1);
    files << file1;

    // 2. Malformed OBJ with out-of-bounds indices and NaN
    QString file2 = tempDir + "/malformed.obj";
    QByteArray obj2 = "v NaN 1.0 2.0\nv 1.0 2.0 3.0\nf 10/10/10 1/1/1 2/2/2\n";
    writeTestFile(file2, obj2);
    files << file2;

    // 3. PLY with invalid vertex count and malformed indices
    QString file3 = tempDir + "/malformed.ply";
    QByteArray ply3 = "ply\nformat ascii 1.0\nelement vertex 999999\nproperty float x\nproperty float y\nproperty float z\nelement face 1\nproperty list uchar int vertex_indices\nend_header\n0 0 0\n3 0 9999 1\n";
    writeTestFile(file3, ply3);
    files << file3;

    // 4. OFF with out-of-bounds face index
    QString file4 = tempDir + "/malformed.off";
    QByteArray off4 = "OFF\n3 1 0\n0 0 0\n1 0 0\n0 1 0\n3 0 1 5\n";
    writeTestFile(file4, off4);
    files << file4;

    TestWorker worker(files);
    QTimer::singleShot(0, &worker, &TestWorker::runNextTest);

    return app.exec();
}
#include "test_robustness.moc"
