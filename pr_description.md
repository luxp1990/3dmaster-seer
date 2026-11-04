## Comprehensive Health Check and Fixes

### Findings (ordered by severity)

1. **Build and correctness (Severe):**
   - **Missing Dependencies**: The `CMakeLists.txt` was missing `Qt6::GuiPrivate` dependency for building `test_3mf`.
   - **Incorrect Header**: `test_3mf.cpp` included `<QtCore/private/qzipreader_p.h>` which doesn't exist; it should have been `<QtGui/private/qzipreader_p.h>`.
   - **Dangling Pointers / Double Free**: `MasterWidget::~MasterWidget` mistakenly called `.destroy()` on `QOpenGLVertexArrayObject` and `QOpenGLBuffer` smart pointers directly. Added explicit `.reset()` to prevent them from trying to auto-delete destroyed resources.

2. **Dependencies and configuration (High):**
   - **OCCT Dependency Isolation**: OCCT targets in `CMakeLists.txt` were required unconditionally, failing builds in CI environments lacking OCCT 8.0.0. I wrapped `3dmaster`, `test_occt_step`, `test_gltf`, and `test_host` behind an `if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/../occt/inc")` check to gracefully fall back in restricted environments.

3. **Security and resource safety (High):**
   - **Hardcoded File Paths**: Multiple files (`test_host.cpp`, `test_3mf.cpp`, `test_gltf.cpp`, `test_occt_step.cpp`) were hardcoded to use specific Windows-style paths (e.g., `D:/seer/3dmaster/3dmaster/test_models/box.glb` and `C:/Users/50350/Downloads/...`). These were updated to relative paths matching `../test_models/...`.
   - **Log File Locations**: Unsafe absolute logging paths (like `D:/seer/...` or `/tmp/...`) were rewritten to write directly to the working directory (`test_log.txt` and `3dmaster.log`) avoiding permission errors.
   - **Platform-Specific APIs**: The code correctly uses `#ifdef Q_OS_WIN` around `MoveFileExW` usage, keeping it safe for cross-platform fallback options.

4. **Tests (Medium):**
   - Cross-platform test paths and setups were fixed. We confirmed `test_3mf` correctly parses test models without breaking.

### Test Results
- Cleanly compiled `test_3mf` in a Linux environment after isolating missing OCCT components.
- Ran `./test_3mf ../../test_models/prism.3mf` successfully:
  `Parsed vertex count: 6, triangle count: 8`

### Deliberate Omissions
- Did not touch any CAD/3D parsing or file reading modules (outside simple path fixes in tests) to avoid conflicting with the robust 3D/CAD robustness reading task currently underway.
