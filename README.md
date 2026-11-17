# 3dmaster-seer 馃殌

> **闈㈠悜 Windows Seer 鐨勫伐涓氱骇楂樻€ц兘 3D/CAD 妯″瀷绌烘牸鏋侀€熼瑙堟彃浠?*  
> 鏀寔 STEP銆両GES銆乬lTF銆?MF銆丼TL銆丱BJ銆丳LY 浠ュ強瑗块棬瀛?UG/NX 鍘熺敓闆朵欢锛?
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
[![Seer Plugin](https://img.shields.io/badge/Seer-Plugin-blue.svg)](https://1218.io)
[![Platform](https://img.shields.io/badge/Platform-Windows%2010%20%7C%2011%20(x64)-brightgreen.svg)]()

---

## 馃専 鏍稿績鐗规€?(Key Features)

- 鈿?**鏃犵紳宓屽叆 Seer 瀹夸富**锛氬熀浜庡畼鏂规爣鍑?Seer SDK 涓?Qt6 C++ 鍘熺敓鍔ㄦ€佸簱鏋舵瀯锛岀函鍐呭瓨绾х绾ц皟搴︼紝鏃犱换浣?IPC 涓浆寮€閿€銆?- 馃摝 **100% 缁胯壊渚挎惡涓庢崲鏈轰繚闅?(Portability)**锛氬畬鏁村唴缃井杞畼鏂?VC++ 杩愯搴撻棴鍖咃紙MSVC CRT 2015-2022锛夈€乀BB 鍓栧垎搴撲笌 OCCT 鏍稿績锛?*鏃犺澶嶅埗鍒颁换浣曞叏鏂般€佺函鍑€鐨?Windows 10/11 鐢佃剳涓婂潎鍙嵆鎻掑嵆鐢?*锛岀粷涓嶆姤缂哄け DLL 閿欒銆?- 馃洜锔?**鍏ㄦ牸寮忓伐涓氭敮鎸?*锛?  - **STEP / STP** (`.step`, `.stp`)锛氬畬鏁磋閰嶆爲缁撴瀯銆佹潗璐ㄥ浐鏈夎壊娓叉煋涓庢嫇鎵戝疄浣撹В鏋愩€?  - **IGES / IGS** (`.iges`, `.igs`)锛氬伐涓氭洸绾挎洸闈㈤珮淇濈湡缂濆悎涓庡嚑浣曠壒寰佸憟鐜般€?  - **鐜颁唬 3D 缃戞牸**锛?*glTF / GLB** (`.gltf`, `.glb`)銆?*3MF** (`.3mf`锛屾敮鎸佸鑹蹭笌鍘熷瀷瀹炰緥鍖?銆?*STL** (`.stl`)銆?*OBJ** (`.obj`)銆?*PLY** (`.ply`)銆?*OFF** (`.off`)銆?  - **瑗块棬瀛?UG/NX PRT** (`.prt`)锛氬叏鑷姩娉ㄥ唽琛ㄥ梾鎺€佹櫤鑳藉鐗堟湰鎷╀紭銆佸伐涓氱骇鑷剤缂撳瓨銆侀浂宕╂簝浼橀泤闄嶇骇銆?- 馃搻 **涓撲笟 CAD 浜や簰瑙嗗彛**锛欳AD 鐗瑰緛妫辩嚎銆佸姩鎬佷笁鍚戞埅闈㈠墫鍒囥€佸叚鍚戝伐绋嬭鍥俱€侀浂浠惰閰嶆爲鏄鹃殣鎺у埗銆佹浜?閫忚鎶曞奖鍒囨崲銆?
---

## 馃摜 瀹夎鎸囧崡 (Installation)

1. 浠?Release 椤甸潰涓嬭浇缂栬瘧濂界殑 `3dmaster.dll`銆乣plugin.json` 浠ュ強鍏宠仈杩愯鏃跺簱銆?2. 灏嗘彃浠舵枃浠跺す鏀惧叆 Seer 鐨勬彃浠剁洰褰曚腑锛?   ```text
   Seer瀹夎鐩綍\plugins\3dmaster\
   鈹溾攢鈹€ 3dmaster.dll
   鈹溾攢鈹€ plugin.json
   鈹斺攢鈹€ 3dmaster.ini
   ```
3. 鎵撳紑 Seer 璁剧疆 -> 鎻掍欢鍒楄〃锛岀‘淇濆凡鍚敤 `3dmaster` 鎻掍欢銆?4. 鍦ㄦ枃浠惰祫婧愮鐞嗗櫒涓€変腑浠讳竴鏀寔鐨?3D 妯″瀷锛屾寜 **绌烘牸閿?* 鍗冲彲绔嬪埢鏋侀€熼瑙堬紒

---

## 馃捇 缂栬瘧鏋勫缓 (Build from Source)

### 鐜渚濊禆
- Windows 10 / 11 (x64)
- Visual Studio 2022 (MSVC v143, 鏀寔 C++17)
- Qt 6.8.2 (MSVC 2022 64-bit)
- OpenCASCADE Technology (OCCT) 8.0.0
- Seer SDK锛堜綅浜?`Seer-sdk/` 鐩綍鎴栬嚜鍔ㄩ厤缃級

### 缂栬瘧姝ラ
```powershell
cd 3dmaster
cmake -B build -G "Visual Studio 17 2022" -A x64
cmake --build build --config Release
```
缂栬瘧浜х墿 `3dmaster.dll` 灏嗚緭鍑鸿嚦 `build/Release/` 鐩綍銆?
---

## 馃彈锔?椤圭洰鏋舵瀯 (Architecture)

### 涓庡濡归」鐩殑鍏崇郴

鏈」鐩笌 [3dmaster-quicklook](https://github.com/luxp1990/3dmaster-quicklook) 鍏变韩鍚屼竴濂?3D 娓叉煋寮曟搸鏍稿績锛屼絾闈㈠悜瀹屽叏涓嶅悓鐨勫涓昏蒋浠讹紝閲囩敤涓嶅悓鐨勯泦鎴愭灦鏋勩€?
```
鈹屸攢鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹?鈹?             鍏变韩寮曟搸鏍稿績 (Shared Engine Core)            鈹?鈹? model_loader_worker  路  master_widget  路  master_sidebar鈹?鈹? model_data  (瑙ｆ瀽銆佹覆鏌撱€乁I 渚ц竟鏍忥紝涓ゅ簱瀹屽叏涓€鑷?         鈹?鈹斺攢鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹攢鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹攢鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹?                鈹?                    鈹?    鈹屸攢鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈻尖攢鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹? 鈹屸攢鈹€鈹€鈹€鈹€鈹€鈹€鈻尖攢鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹?    鈹?  3dmaster-seer      鈹? 鈹?  3dmaster-quicklook      鈹?    鈹?  (鏈」鐩?           鈹? 鈹?  (濮愬椤圭洰)              鈹?    鈹?                     鈹? 鈹?                          鈹?    鈹? 闆嗘垚鏂瑰紡锛氬悓杩涚▼     鈹? 鈹? 闆嗘垚鏂瑰紡锛氱嫭绔嬪畧鎶よ繘绋?  鈹?    鈹? Qt 鎻掍欢 DLL         鈹? 鈹? + Named Pipe IPC         鈹?    鈹?                     鈹? 鈹?                          鈹?    鈹? 瀹夸富锛歋eer.exe      鈹? 鈹? 瀹夸富锛歈uickLook (.NET)   鈹?    鈹? 鎺ュ彛锛歏iewerBase    鈹? 鈹? 鎺ュ彛锛欼PC 鍛戒护鍗忚       鈹?    鈹? 宓屽叆锛歈t Widget     鈹? 鈹? 宓屽叆锛歐in32 HWND         鈹?    鈹斺攢鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹? 鈹斺攢鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹?```

### 鏈」鐩笓灞炵殑閫傞厤灞傛枃浠?
| 鏂囦欢 | 浣滅敤 |
|---|---|
| `3dmaster/src/plugin_entry.cpp` | Qt 鎻掍欢瀵煎嚭瀹忥紝鍚?Seer 娉ㄥ唽 `MasterPlugin` 绫?|
| `3dmaster/src/master_viewer.cpp` | 缁ф壙 Seer SDK 鐨?`ViewerBase`锛屽疄鐜?`loadImpl()` |
| `3dmaster/include/master_viewer.h` | 鍚屼笂澶存枃浠?|
| `3dmaster/plugin.json` | Seer 鎻掍欢鍏冩暟鎹紙鍚嶇О銆佺増鏈€佹敮鎸佹牸寮忓垪琛級 |

### 鍏变韩寮曟搸鏍稿績鏂囦欢锛堜袱搴撳唴瀹瑰嚑涔庝竴鑷达級

| 鏂囦欢 | 浣滅敤 |
|---|---|
| `model_loader_worker.h/cpp` | 瑙ｆ瀽鍏ㄩ儴鏍煎紡锛圫TL/OBJ/PLY/OFF/3MF/STEP/IGES/glTF/PRT锛?|
| `model_data.h` | `ModelData` / `SubMesh` 鏍稿績鏁版嵁缁撴瀯 |
| `master_widget.h/cpp` | OpenGL 娓叉煋 Widget锛堝惈鎵归噺鍖?Edge 娓叉煋銆佽閿ヤ綋瑁佸壀銆乵map 澶ф枃浠跺姞閫燂級 |
| `master_sidebar.h/cpp` | 鍙充晶闆朵欢鏍?+ 瑙嗗浘鎺у埗渚ц竟鏍?UI |

> **缁存姢鎻愮ず**锛氳嫢鍚屾椂缁存姢涓や釜搴擄紝瀵逛互涓婂叡浜枃浠剁殑淇敼闇€瑕佸湪涓や釜搴撲腑鍚屾鏇存柊銆? 
> 闀挎湡寤鸿灏嗗叡浜紩鎿庢彁鍙栦负鐙珛 git submodule锛坄3dmaster-engine`锛夌粺涓€绠＄悊銆?
### 闆嗘垚鏋舵瀯璇﹁В锛堝悓杩涚▼鎻掍欢妯″紡锛?
```
Seer.exe 涓昏繘绋?    鈹?    鈹?鍔犺浇鎻掍欢 DLL锛圦t Plugin 鏈哄埗锛?    鈻?MasterPlugin锛坧lugin_entry.cpp锛?    鈹? 瀹炵幇 ViewerPluginInterface
    鈹? createViewer() 杩斿洖 MasterViewer 瀹炰緥
    鈻?MasterViewer锛坢aster_viewer.cpp锛?    鈹? 缁ф壙 ViewerBase锛圫eer SDK锛?    鈹? loadImpl() 琚?Seer 鍦ㄦ枃浠堕€変腑鏃跺洖璋?    鈹?    鈹溾攢鈹€鈻?MasterWidget锛圤penGL 娓叉煋锛屽悓绾跨▼ UI锛?    鈹斺攢鈹€鈻?ModelLoaderWorker锛圦Thread 瀛愮嚎绋嬶紝寮傛瑙ｆ瀽锛?              鈹?              鈹斺攢鈹€ 瑙ｆ瀽瀹屾垚鍚?emit sigFinished(ModelDataPtr)
                       鈹?                       鈹斺攢鈹€鈻?MasterWidget::onModelReady() 涓婁紶 GPU 骞舵覆鏌?```

**鍏抽敭鐗规€?*锛?- 鏁翠釜鎻掍欢杩愯鍦?**Seer.exe 鍚屼竴杩涚▼鍐?*锛岄浂 IPC 寮€閿€
- Seer 閫氳繃 Qt 鎻掍欢鏈哄埗绠＄悊鎻掍欢鐢熷懡鍛ㄦ湡锛屼笉闇€瑕佸畧鎶よ繘绋?- 瑙ｆ瀽鍦?`QThread` 瀛愮嚎绋嬩腑杩涜锛孶I 涓嶉樆濉?
---

## 馃敡 楂樼骇閰嶇疆

### 澶ф枃浠?mmap 鍔犻€燂紙opt-in锛?
瀵逛簬瓒呭ぇ STL 鏂囦欢锛堝缓璁?> 50 MB锛夛紝鍙缃幆澧冨彉閲忓紑鍚唴瀛樻槧灏勫姞閫燂細

```powershell
$env:3DMASTER_USE_MMAP = "1"
```

娴嬭瘯鏁版嵁锛?00MB STL锛?M 涓夎闈級锛氭爣鍑嗚鍙?~118ms 鈫?mmap 璇诲彇 ~9ms銆? 
鑻ユ槧灏勫け璐ワ紙鍐呭瓨涓嶈冻绛夛級锛岃嚜鍔ㄦ棤缂?fallback 鍒版爣鍑嗚鍙栬矾寰勩€?
---

## 馃 濮愬椤圭洰 (Sister Projects)

- 馃攳 **[3dmaster-quicklook](https://github.com/luxp1990/3dmaster-quicklook)**锛氶潰鍚?Windows **QuickLook** 鐢ㄦ埛鐨勫悓鏍搁珮淇濈湡 3D/CAD 棰勮鎻掍欢銆? 
  閲囩敤鐙珛瀹堟姢杩涚▼ + Named Pipe IPC 鏋舵瀯锛堜笌鏈」鐩悓杩涚▼ DLL 鏋舵瀯涓嶅悓锛夛紝C# 瀹夸富閫氳繃 `DaemonClient` 鎺у埗 C++ 娓叉煋杩涚▼銆?
---

## 馃搫 寮€婧愯鍙瘉 (License)

鏈」鐩噰鐢?[MIT License](LICENSE) 璁稿彲璇佸紑婧愩€?