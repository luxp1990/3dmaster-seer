cd 3dmaster
git checkout -b temp_fix
git add CMakeLists.txt test/test_robustness.cpp
git commit -m "Fix CMakeLists.txt and test_robustness to compile without OCCT

Do not link model_loader_worker.cpp into test_robustness when OCCT is missing,
instead provide a dummy ModelLoaderWorker implementation in test_robustness.cpp
when DISABLE_OCCT_FOR_TESTING is defined, which avoids compiling any OCCT code."

git checkout item-1-ci-13871792053728383575
git cherry-pick temp_fix
