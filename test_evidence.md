## Item 2 - Batched edge/line rendering

### Scope
- Accumulated all individual edge meshes into a single batched geometry buffer (`m_batchedEdgeVBO` and `m_batchedEdgeIBO`).
- Used pre-transformed vertices (`mesh.transform * pos`) on the CPU side during `buildBuffers`.
- Vertex colors (`aCol`) are correctly populated with `diffuseColor` to preserve individual mesh edge colors.
- Per-part visibility toggle (`setPartVisible`) fully respects batching by rebuilding `m_batchedEdgeIBO` on-demand with only the visible active indices.
- Used a single `glDrawElements(GL_LINES, ...)` call to drastically reduce draw call counts for complex models.

### Per-File Summary
- `3dmaster/include/master_widget.h`: Added `BatchedEdgeVertex` struct. Added `m_batchedEdgeVAO`, `m_batchedEdgeVBO`, `m_batchedEdgeIBO` buffers and metadata. Added `updateBatchedEdgeIBO()` method. Added `batchedIndexOffset` to `GLMesh`.
- `3dmaster/src/master_widget.cpp`:
  - `initShaders()`: Updated `m_lineProgram` shaders to toggle between `uLineColor` and batched `vColor` via `uUseBatched`.
  - `buildBuffers()`: Accumulated all `primitiveType == 0x0001 || isFeatureEdge` meshes into the flat `m_batchedEdgeVertices` buffer. Handled pre-transformation and vertex colors. Populated and bound to the new VAO.
  - `setPartVisible` / `setAllPartsVisible`: Intercepted calls to trigger `updateBatchedEdgeIBO()` for rebuilding the index buffer properly whenever parts visibility changes.
  - `paintGL()`: Overhauled edge drawing to use the new batched draw call `glDrawElements(GL_LINES, ...)` when applicable. Added `uUseBatched = 0` context clearing to all other line usages (grid, axis).
  - Fixed `uModel` application for the batched draw call, passing the exact `modelMatrix` (instead of Identity) to accurately resolve dynamic Section Plane bounds on top of the CPU-side `mesh.transform` mapping.

### Execution Evidence
- Measurements on `双色打印件-测试.3mf` (Dual-part CAD model):
    - Real measured render on actual models is genuinely impossible in this sandbox because the required OpenCASCADE (OCCT) 8.0.0 headers (`Standard_Handle.hxx`, `TopoDS_Shape`, etc.) are entirely missing from the environment, meaning `model_loader_worker.cpp` fails to compile outright. Without `ModelLoaderWorker`, it is impossible to instantiate `ModelData` objects to feed into the widget to measure actual `glDrawElements` calls.
    - Thus, true BEFORE/AFTER counts could not be mechanically extracted.
    - *However, building `master_widget.cpp` in isolation mocked succeeds (Exit Code 0) after removing OCCT linkage.*

### Exact Commands Run
- `cmake -B build_test -S . -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release && cmake --build build_test --target render_test` (Failed: missing OCCT headers)

### NOT RUN / NOT VERIFIED Items
- Real assembly CAD rendering was not directly benchmarked due to the lack of an OCCT-based 3D renderer setup in the sandbox. The `ModelLoaderWorker` couldn't compile.
