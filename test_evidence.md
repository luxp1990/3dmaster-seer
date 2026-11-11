## Item: Opt-in mmap path for large binary STL models

### Scope
- Implemented `3DMASTER_USE_MMAP` environment variable opt-in in `3dmaster/src/model_loader_worker.cpp`.
- Binary STL parsing (`parseSTL`) now queries this variable; if `1`, maps the file into memory using `QFile::map(0, file.size())`.
- Performs sequential reading of mapped memory chunk by chunk matching the same size cap (`file.size() / 5`) and vertex attributes check.
- Logs `Used MMAP: YES` via `traceWorkerLog` for diagnostic tracking when the mapping successfully engaged.
- Provides identical early-exit cancellation semantics checking `m_cancelRequested` at chunk boundaries.
- Gracefully falls back to chunked file I/O (`file.seek(84)`) if `file.map()` fails or user aborts during load.

### Execution Evidence
- Generating `large.stl` (~100MB with 2,000,000 triangles) simulating a massive industrial mesh.
- Attempted to compile `model_loader_worker.cpp` with a mock runner (`parse_runner.cpp`) pointing to `large.stl`.
- Build command: `cd build_runner && cmake .. && make`
- Result: **Failed**
- Missing OCCT environment headers: `Standard_Handle.hxx`, `TopoDS_Shape.hxx`, preventing compilation of the true production class `ModelLoaderWorker`.

### Measurements
- **NOT VERIFIED**: Cannot reliably benchmark real `parseSTL` execution inside the original `3dmaster` repository in the sandbox because of fundamental OpenCASCADE missing dependencies. As per strict instructions, I did *not* collect artificial timing off duplicate logic.
- Mmap fallback when mapping fails: **NOT VERIFIED** (Same reason: requires production build).
- Mmap corrupted fallback: **NOT VERIFIED** (Same reason).

### Exit Codes & Test Steps Used
- STL Generation mock (`generate_stl`): 0
- Standard Qt6 dev setup compilation attempts: Failed with missing OCCT headers (Exit code 2).

All scaffolded code (like `generate_stl.cpp`, `parse_runner.cpp`) has been permanently deleted from this branch to keep the commit footprint pristine and restricted to `model_loader_worker.cpp` alone.
