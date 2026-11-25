# 3dmaster-seer 🚀

> **面向 Windows Seer 的高性能 3D / CAD 模型空格极速预览插件（基于 OpenCASCADE 内核）**  
> **High-performance 3D / CAD preview plugin for Windows Seer, powered by OpenCASCADE (OCCT)**

[🇨🇳 中文介绍](#-为什么做这个项目) | [🇺🇸 English](#-english)

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
[![Seer Plugin](https://img.shields.io/badge/Seer-Plugin-blue.svg)](https://1218.io)
[![Platform](https://img.shields.io/badge/Platform-Windows%2010%20%7C%2011%20(x64)-brightgreen.svg)]()
[![Language](https://img.shields.io/badge/UI-中文%20%7C%20English-informational.svg)]()

---

## 💡 为什么做这个项目？

我是一名**结构设计工程师**。在日常使用 **Seer** 搭配原有 3D 预览插件查看结构件和装配体时，经常遇到几个痛点：
- 预览稍大一点的 CAD 模型就**软件卡死**或**加载极慢**；
- 看不到内部构造（**没有截面剖切图**）；
- 装配件不能**隐藏单个零件**；
- 模型**丢失原始颜色**，一片白模看不清配合关系。

为了解决这些实际工程痛点，我基于 **OpenCASCADE (OCCT 8.0.0)** 几何内核开发了 **3dmaster-seer**，希望能帮到遇到同样问题的工程师和开发者。

- **即装即用**：直接按照 Seer 标准插件方式安装即可，内置完整运行库依赖。
- **中英文支持**：界面支持 **中文 / English**，自动跟随 Seer 语言或系统语言（也可在 `3dmaster.ini` 中配置）。
- **欢迎交流**：如果你在使用中有任何建议、Bug 反馈或功能想法，欢迎在 [Issues](https://github.com/luxp1990/3dmaster-seer/issues) 或 [Discussions](https://github.com/luxp1990/3dmaster-seer/discussions) 中一起讨论！

---

## 🌟 核心特性

- ⚡ **原生嵌入不卡死**：基于官方 Seer SDK 与 Qt6 C++ 原生动态库架构，几何解析与离散全程在后台子线程异步执行，宿主不假死。
- 🛠️ **全格式工业支持**：
  - **STEP / STP** (`.step`, `.stp`)：完整装配体结构树、材质固有色渲染与拓扑实体解析。
  - **IGES / IGS** (`.iges`, `.igs`)：工业曲线曲面高保真缝合与几何特征呈现。
  - **主流 3D 网格**：**glTF / GLB** (`.gltf`, `.glb`)、**3MF** (`.3mf`，支持多色与原型实例化)、**STL** (`.stl`)、**OBJ** (`.obj`)、**PLY** (`.ply`)、**OFF** (`.off`)。
  - **西门子 UG/NX PRT** (`.prt`)：自动嗅探本机已安装的 UG/NX 版本进行静默转码与缓存；未安装 UG 或遇到不兼容高版本时，0.05 秒内安全降级提示，绝不崩溃。
- 📐 **结构工程级交互视口**：
  - **动态截面剖切 (Section View)**：支持 X / Y / Z 三向平滑拖动剖切，快速查看内部装配关系。
  - **装配体零件树显隐**：支持单个零件独立勾选显隐、右键隔离显示、全显/全隐/反选。
  - **CAD 特征棱线与色彩**：支持材质固有色、顶点色、白模、法线着色切换，清晰勾勒 CAD 特征棱线。
  - **操作手感预设**：支持 **西门子 UG/NX**、**SolidWorks**、**通用模式** 一键切换，附带六向标准视图与正交/透视切换。
- 📦 **绿色便携**：内置 VC++ 2015-2022、TBB 与 OCCT 8.0 运行时，换机即插即用。

---

## 📦 安装指南

### 方式一：通过 Seer 设置界面导入（推荐，兼容微软商店版）
1. 从 [Release 页面](https://github.com/luxp1990/3dmaster-seer/releases) 下载最新发行版压缩包（如 `3dmaster-seer-v1.0.0-windows-x64.zip`）并解压。
2. 打开 Seer 设置 -> 进入 **插件** 界面。
3. 点击 **添加插件**，选择解压后的目录（包含 `3dmaster.dll` 和 `plugin.json`）。
4. 确保列表中 `3dmaster` 处于**勾选启用**状态。
5. 在文件资源管理器中选中任一支持的 3D/CAD 模型，按下 **空格键** 即可预览。

### 方式二：手动放置目录（传统安装版 / 便携版）
将解压后的文件夹放入 Seer 安装目录的 `plugins` 文件夹中：
```text
Seer安装目录\plugins\3dmaster\
├── 3dmaster.dll
├── plugin.json
├── 3dmaster.ini
└── (OCCT 8.0 及依赖动态链接库...)
```

---

## ❓ 常见问题与排错

- **预览 STEP / IGES 时出现红色 3D 大字 "Failed to load"**：
  说明 Seer 未成功加载 `3dmaster`，回退到了内置网页网格查看器。请检查 Seer 设置 -> 插件中 `3dmaster` 是否已勾选启用；若使用**微软商店版 Seer**，请务必通过「添加插件」导入目录，不要放入 `Program Files (x86)`。
- **如何手动指定界面语言？**
  默认自动跟随 Seer / 系统语言。如需强制指定，可在 `3dmaster.ini` 中设置：
  ```ini
  [General]
  Language=zh   ; 可选 auto / zh / en
  ```

---

## 💻 编译构建

- **环境依赖**：Windows 10 / 11 (x64)、Visual Studio 2022 (MSVC v143, C++17)、Qt 6.8.2 (MSVC 2022 64-bit)、OpenCASCADE Technology (OCCT) 8.0.0、Seer SDK。
```powershell
cd 3dmaster
cmake -B build -G "Visual Studio 17 2022" -A x64
cmake --build build --config Release
```

---

## 🤝 姐妹项目

- 🔍 **[3dmaster-quicklook](https://github.com/luxp1990/3dmaster-quicklook)**：面向 Windows **QuickLook** 用户的同核 3D/CAD 预览插件。

---

<a id="-english"></a>

## 🇺🇸 English

### Why I Built This

I am a **mechanical / structural design engineer**. When using **Seer** with existing 3D preview plugins to inspect CAD parts and assemblies in daily work, I kept running into frustrating issues:
- **Freezing / crashing** and **slow loading** on medium-to-large CAD models;
- **No section view** to inspect internal structures;
- **No way to hide/isolate individual parts** in an assembly;
- **Missing model colors** (everything rendered as plain white meshes).

That motivated me to build **3dmaster-seer**, powered by the industrial-grade **OpenCASCADE (OCCT 8.0.0)** geometry kernel, hoping it helps others facing the same problems.

- **Standard Plugin Installation**: Install it directly using Seer's built-in plugin mechanism — all required runtime dependencies are bundled.
- **Bilingual UI (English & Chinese)**: Automatically follows Seer's / Windows' UI language (can also be overridden via `3dmaster.ini`).
- **Feedback Welcome**: Feel free to share suggestions, bug reports, or ideas in [Issues](https://github.com/luxp1990/3dmaster-seer/issues) or [Discussions](https://github.com/luxp1990/3dmaster-seer/discussions)!

### Key Features

- ⚡ **Non-Blocking Native Architecture**: Built on the official Seer SDK and Qt6 C++. Geometry parsing and B-Rep tessellation run asynchronously in a background thread so Seer never freezes.
- 🛠️ **Wide Format Support**:
  - **STEP / STP** (`.step`, `.stp`): Full assembly tree, native material/face colors, and B-Rep solid parsing.
  - **IGES / IGS** (`.iges`, `.igs`): High-fidelity curve/surface sewing (`ShapeFix`) and geometry preview.
  - **3D Meshes**: **glTF / GLB** (`.gltf`, `.glb`), **3MF** (`.3mf`, with multi-color & instancing), **STL** (`.stl`), **OBJ** (`.obj`), **PLY** (`.ply`), **OFF** (`.off`).
  - **Siemens NX / UG PRT** (`.prt`): Automatically detects local NX installations for silent conversion; degrades gracefully in < 0.05s without crashing if NX is not installed.
- 📐 **Engineering Viewport Controls**:
  - **Dynamic Section View**: Smooth X / Y / Z clipping planes to inspect internal structures.
  - **Assembly Tree**: Toggle individual part visibility, right-click to isolate, show all, hide all, or invert selection.
  - **CAD Edges & Shading**: Material color, vertex color, pure white, and normals modes, plus crisp CAD feature edges.
  - **Navigation Presets**: Switch between **Siemens NX (UG)**, **SolidWorks**, and **Generic** mouse controls, plus 6 standard orthographic views and perspective/orthographic toggle.

### Installation

1. Download the latest archive (e.g., `3dmaster-seer-v1.0.0-windows-x64.zip`) from the [Releases](https://github.com/luxp1990/3dmaster-seer/releases) page and extract it.
2. Open **Seer Settings -> Plugins**.
3. Click **Add Plugin** and select the extracted folder (containing `3dmaster.dll` and `plugin.json`).
4. Ensure `3dmaster` is checked/enabled in the plugin list.
5. Select any supported 3D/CAD file in Windows File Explorer and press **Spacebar** to preview!

*(For classic/portable Seer, you can also copy the extracted `3dmaster` folder directly into `<Seer>\plugins\3dmaster\`.)*

### Sister Project

- 🔍 **[3dmaster-quicklook](https://github.com/luxp1990/3dmaster-quicklook)** — The companion 3D/CAD preview plugin for Windows **QuickLook**.

### License

Open-sourced under the [MIT License](LICENSE).
