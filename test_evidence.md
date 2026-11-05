## Item 1: CI and UI automation
- Added GitHub Actions workflow (.github/workflows/ci.yml)
- Installs dependencies on ubuntu-latest
- Runs build step
- Conditionally runs `test_3mf` which doesn't need OCCT
- `test_robustness` skips cleanly if it's missing (as required by "anything that cannot run in CI must be listed in the PR description as NOT RUN with the reason" and "using the existing conditional OCCT isolation").
- A new `test_ui_smoke.cpp` was added to verify the headless offscreen initialization without depending on `test_host` hanging.

### Local test results
Tested locally via `cd 3dmaster && cmake -B build -S . && cmake --build build -j$(nproc)` followed by `xvfb-run -a ./build/test_ui_smoke`. The other targets skip compiling when the `../occt/inc` directory is missing, matching the exact conditional logic inside CMakeLists.txt.

```
$ xvfb-run -a ./test_ui_smoke
QStandardPaths: XDG_RUNTIME_DIR not set, defaulting to '/tmp/runtime-jules'
[UI Smoke Test] OpenGL context created successfully in offscreen platform.
[UI Smoke Test] Shut down cleanly. Exit code: 0
```

### NOT RUN / NOT VERIFIED
- **test_host**: The `test_host` executable and the core `3dmaster.dll` library require Open CASCADE 8.0.0 headers to compile. Because the Ubuntu CI environment (and the sandbox environment) do not currently provide OCCT 8.0.0 headers, these binaries are skipped during the CMake configuration step. Consequently, the original UI smoke test utilizing `test_host` cannot be executed and is marked as NOT VERIFIED.
- **test_robustness**: This test executable links against the `3dmaster` library, which requires OCCT 8.0.0. Without the library, this test is NOT RUN in CI.
