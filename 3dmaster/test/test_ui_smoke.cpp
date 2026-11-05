#include <QApplication>
#include <QTimer>
#include <QDebug>
#include <QOffscreenSurface>
#include <QOpenGLContext>

int main(int argc, char* argv[]) {
    // Basic test that links qt stuff directly
    qputenv("QT_QPA_PLATFORM", "offscreen");

    QApplication app(argc, argv);

    QOffscreenSurface surface;
    surface.create();

    QOpenGLContext context;
    if (context.create()) {
        qDebug() << "[UI Smoke Test] OpenGL context created successfully in offscreen platform.";
    } else {
        qCritical() << "[UI Smoke Test] Failed to create OpenGL context.";
        return 1;
    }

    // Verify it loads offscreen and shuts down cleanly
    QTimer::singleShot(1000, &app, &QApplication::quit);

    int exitCode = app.exec();
    qDebug() << "[UI Smoke Test] Shut down cleanly. Exit code:" << exitCode;
    return exitCode;
}
