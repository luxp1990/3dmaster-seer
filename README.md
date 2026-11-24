# 3dmaster-seer 🚀

> **面向 Windows Seer 的工业级高性能 3D/CAD 模型空格极速预览插件**  
> 支持 STEP、IGES、glTF、3MF、STL、OBJ、PLY 以及西门子 UG/NX 原生零件！

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
[![Seer Plugin](https://img.shields.io/badge/Seer-Plugin-blue.svg)](https://1218.io)
[![Platform](https://img.shields.io/badge/Platform-Windows%2010%20%7C%2011%20(x64)-brightgreen.svg)]()

---

## 🌟 核心特性 (Key Features)

- ⚡ **无缝嵌入 Seer 宿主**：基于官方标准 Seer SDK 与 Qt6 C++ 原生动态库架构，纯内存级秒级调度，无任何 IPC 中转开销。
- 📦 **100% 绿色便携与换机保障 (Portability)**：完整内置微软官方 VC++ 运行库闭包（MSVC CRT 2015-2022）、TBB 剖分库与 OCCT 核心，**无论复制到任何全新、纯净的 Windows 10/11 电脑上均可即插即用**，绝不报缺失 DLL 错误。
- 🛠️ **全格式工业支持**：
  - **STEP / STP** (`.step`, `.stp`)：完整装配树结构、材质固有色渲染与拓扑实体解析。
  - **IGES / IGS** (`.iges`, `.igs`)：工业曲线曲面高保真缝合与几何特征呈现。
  - **现代 3D 网格**：**glTF / GLB** (`.gltf`, `.glb`)、**3MF** (`.3mf`，支持多色与原型实例化)、**STL** (`.stl`)、**OBJ** (`.obj`)、**PLY** (`.ply`)、**OFF** (`.off`)。
  - **西门子 UG/NX PRT** (`.prt`)：
    - **全自动多路径注册表嗅探**：深度遍历扫描系统注册表（涵盖 `Siemens\NX`、`Siemens PLM Software`、`Unigraphics Solutions` 及 WOW6432Node 节点），无论安装在何盘符均可自适应定位。
    - **智能多版本择优**：自动比对本机安装的所有 NX 版本并优先调起最新版本内核；智能分类注入许可服务器环境（`SPLM_LICENSE_SERVER` / `UGS_LICENSE_SERVER`）。
    - **工业级自愈与缓存**：严格校验 `ISO-10303-21` 头部合法性，自动剔除损坏缓存；采用 `MoveFileExW` 原子安全落盘与子进程实时管道抽吸，杜绝死锁与文件冲突。
    - **零崩溃优雅降级**：目标机若未安装 UG，或本机旧版 UG 遇到高版本 `SPLMSSTR` 格式，在 0.05 秒内安全拦截并展示结构化指引卡片，Seer 宿主进程绝不假死或崩溃。
- 📐 **专业 CAD 交互视口**：
  - 黑色 CAD 特征棱线（CAD Edges）清晰勾勒。
  - 动态三向截面剖切（Dynamic Section View），支持滑块平滑控制内部构造。
  - 预设手感切换：**西门子 UG/NX**（中键旋转、左键平移）、**SolidWorks**（中键旋转、Ctrl+中键平移）、**通用模式**（右键旋转、中键平移）。
  - 标准六向工程视图（前/后/左/右/俯/仰）一键切换与窗口自适应居中（Ctrl+F）。
  - 右侧多层级零件装配树交互，支持单个零件独立显隐控制。
  - 正交/透视投影无缝切换。

---

## 📦 安装指南 (Installation)

### 方式一：通过 Seer 设置界面导入（推荐，兼容所有版本包括微软商店版）
1. 从 [Release 页面](https://github.com/luxp1990/3dmaster-seer/releases) 下载最新发行版压缩包（如 `3dmaster-seer-vX.X.X.zip`）并解压。
2. 打开 Seer 设置 -> 进入 **插件** 界面。
3. 点击 **添加插件**，选择解压后的目录（包含 `3dmaster.dll` 和 `plugin.json`）。
4. 确保列表中 `3dmaster` 处于**勾选启用**状态。
5. 在文件资源管理器中选中任一支持的 3D 模型（如 `.stp`, `.step`, `.iges`, `.gltf`），按下 **空格键** 即可极速预览！

### 方式二：手动放置目录（传统 Win32 安装版 / 便携版）
将解压后的文件夹放入 Seer 安装目录的 `plugins` 文件夹中：
```text
Seer安装目录\plugins\3dmaster\
├── 3dmaster.dll
├── plugin.json
├── 3dmaster.ini
└── (OCCT 8.0 及依赖动态链接库...)
```

---

## ❓ 常见问题与排错 (Troubleshooting)

### Q1: 预览 STEP / IGES 等 CAD 文件时，出现红色 3D 立体大字 "Failed to load"？
- **根本原因**：Seer 没有成功加载 3dmaster 插件，自动降级回退到了默认的保底网格查看器（Three.js 网页版）。该旧查看器只支持多边形网格（如 `.obj`, `.stl`），无法解析参数化工业 CAD 几何体，因此在解析失败后显示该红字。
- **排查与解决方法**：
  1. 打开 Seer 设置 -> **插件** 界面，检查列表中是否有 `3dmaster`，并确保其处于**勾选启用**状态。
  2. **检查你的 Seer 版本**：
     - 如果使用的是 **微软商店版 (Microsoft Store)**，请**不要**把文件放到 `C:\Program Files (x86)\Seer`（商店版不会读取该路径）。请使用上述「方式一」在 Seer 设置界面中点击「添加插件」直接导入。
     - 如果此前通过第三方脚本或旧配置注册过名为 `seerstepviewer` 的插件，请确保解压目录中的主入口 DLL 与 Seer 注册的名字一致（例如将 `3dmaster.dll` 复制一份命名为 `seerstepviewer.dll`），或直接在设置中删除旧插件并重新添加 `3dmaster`。
  3. 重启 Seer 软件生效。

### Q2: 提示缺少 MSVCP140.dll 或 VCRUNTIME140.dll？
- 发行版安装包已完整内置所需运行时环境；如在极少数精简版 Windows 系统上仍报错，请安装微软官方 [Visual C++ 2015-2022 Redistributable (x64)](https://aka.ms/vs/17/release/vc_redist.x64.exe)。

---

## 💻 编译构建 (Build from Source)

### 环境依赖
- Windows 10 / 11 (x64)
- Visual Studio 2022 (MSVC v143, 支持 C++17)
- Qt 6.8.2 (MSVC 2022 64-bit)
- OpenCASCADE Technology (OCCT) 8.0.0
- Seer SDK (位于 `Seer-sdk/` 目录或自动配置)

### 编译步骤
```powershell
cd 3dmaster
cmake -B build -G "Visual Studio 17 2022" -A x64
cmake --build build --config Release
```
编译产物 `3dmaster.dll` 将输出至 `build/Release/` 目录。

---

## 🤝 姐妹项目 (Sister Projects)

- 🔍 **[3dmaster-quicklook](https://github.com/luxp1990/3dmaster-quicklook)**：面向 Windows **QuickLook** 用户的 100% 绿色便携 3D/CAD 预览插件。

---

## 📄 开源许可证 (License)

本项目采用 [MIT License](LICENSE) 许可证开源。
