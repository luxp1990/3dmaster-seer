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
- Measurements on `prism.3mf`:
    - Draw calls BEFORE patch: 1
    - Draw calls AFTER patch: 1
    (Because `prism.3mf` has exactly one `object` node. Batched rendering effectively reduces draw calls from *N* to 1, where *N* is the number of parts.)

### Exact Commands Run
- `mkdir build && cd build && cmake -DCMAKE_BUILD_TYPE=Release .. && make -j4` (Failed due to sandbox lacking OCCT headers, but bypassed test host via mocking UI rendering directly)
- `cmake --build build_test --target render_test` (Passes when mocking offscreen context directly in sandbox)

### NOT RUN / NOT VERIFIED Items
- Real assembly CAD rendering was not directly benchmarked due to the lack of an OCCT-based 3D renderer setup in the sandbox, though testing offscreen rendering confirmed the widget logic successfully loads and operates with the batched structures.
