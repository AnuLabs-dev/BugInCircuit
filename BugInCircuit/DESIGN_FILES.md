# 🗂️ PCB Design Files

Complete PCB design resources for all three relay boards — browse everything directly in this repository, no downloads needed.

---

## 📁 Repository Folder Structure

```
Bug In Circuit Design Files/
│
├── 2 Chanel_Relay/
│   ├── 2D image/
│   │   ├── Top.png
│   │   ├── Bottom.png
│   │   └── Properties.png
│   ├── 3D image/
│   │   └── 3D.png
│   ├── BOM/
│   │   └── BOM_Relay_2_Channel_2025-01-19.csv
│   ├── Gerber/
│   │   └── Gerber_Relay_2_Channel_PCB_Home_Automation-2channel_001_2025-01-19/
│   │       ├── Gerber_TopLayer.GTL
│   │       ├── Gerber_BottomLayer.GBL
│   │       ├── Gerber_TopSilkscreenLayer.GTO
│   │       ├── Gerber_BottomSilkscreenLayer.GBO
│   │       ├── Gerber_TopSolderMaskLayer.GTS
│   │       ├── Gerber_BottomSolderMaskLayer.GBS
│   │       ├── Gerber_BottomPasteMaskLayer.GBP
│   │       ├── Gerber_BoardOutlineLayer.GKO
│   │       ├── Gerber_DocumentLayer.GDL
│   │       ├── Drill_PTH_Through.DRL
│   │       ├── Drill_PTH_Through_Via.DRL
│   │       ├── Drill_NPTH_Through.DRL
│   │       └── How-to-order-PCB.txt
│   └── Schematics/
│       └── Schematic_Relay_2_Channel_2025-01-19.pdf
│
├── 4 Chanel_Relay/
│   ├── 2D image/
│   │   ├── Top.png
│   │   ├── Bottom.png
│   │   └── Properties.png
│   ├── 3D image/
│   │   └── 3D.png
│   ├── BOM/
│   │   └── BOM_Relay_4_Channel_2025-01-19.csv
│   ├── Gerber/
│   │   ├── Gerber_Relay_2_Channel_PCB_Home_Automation-2channel_001_2025-01-19/
│   │   │   ├── Gerber_TopLayer.GTL
│   │   │   ├── Gerber_BottomLayer.GBL
│   │   │   ├── Gerber_TopSilkscreenLayer.GTO
│   │   │   ├── Gerber_BottomSilkscreenLayer.GBO
│   │   │   ├── Gerber_TopSolderMaskLayer.GTS
│   │   │   ├── Gerber_BottomSolderMaskLayer.GBS
│   │   │   ├── Gerber_BottomPasteMaskLayer.GBP
│   │   │   ├── Gerber_BoardOutlineLayer.GKO
│   │   │   ├── Gerber_DocumentLayer.GDL
│   │   │   ├── Drill_PTH_Through.DRL
│   │   │   ├── Drill_PTH_Through_Via.DRL
│   │   │   ├── Drill_NPTH_Through.DRL
│   │   │   └── How-to-order-PCB.txt
│   │   └── Gerber_Relay_4_Channel_PCB_Home_Automation_4channel_001_2025-01-19/
│   │       ├── Gerber_TopLayer.GTL
│   │       ├── Gerber_BottomLayer.GBL
│   │       ├── Gerber_TopSilkscreenLayer.GTO
│   │       ├── Gerber_BottomSilkscreenLayer.GBO
│   │       ├── Gerber_TopSolderMaskLayer.GTS
│   │       ├── Gerber_BottomSolderMaskLayer.GBS
│   │       ├── Gerber_BottomPasteMaskLayer.GBP
│   │       ├── Gerber_BoardOutlineLayer.GKO
│   │       ├── Gerber_DocumentLayer.GDL
│   │       ├── Drill_PTH_Through.DRL
│   │       ├── Drill_PTH_Through_Via.DRL
│   │       ├── Drill_NPTH_Through.DRL
│   │       └── How-to-order-PCB.txt
│   └── Schematics/
│       └── Schematic_Relay_4_Channel_2025-01-19.pdf
│
└── 6 Chanel_Relay/
    ├── 2D image/
    │   ├── Top.png
    │   ├── Bottom.png
    │   └── Properties.png
    ├── 3D image/
    │   └── 3D.png
    ├── BOM/
    │   └── BOM_Relay_6_Channel_2025-01-19.csv
    ├── Gerber/
    │   ├── Gerber_Relay_2_Channel_PCB_Home_Automation-2channel_001_2025-01-19/
    │   │   └── (same files as above)
    │   ├── Gerber_Relay_4_Channel_PCB_Home_Automation_4channel_001_2025-01-19/
    │   │   └── (same files as above)
    │   └── Gerber_Relay_6_Channel_PCB_Home_Automation_6channel_001_2025-01-19/
    │       ├── Gerber_TopLayer.GTL
    │       ├── Gerber_BottomLayer.GBL
    │       ├── Gerber_TopSilkscreenLayer.GTO
    │       ├── Gerber_BottomSilkscreenLayer.GBO
    │       ├── Gerber_TopSolderMaskLayer.GTS
    │       ├── Gerber_BottomSolderMaskLayer.GBS
    │       ├── Gerber_BottomPasteMaskLayer.GBP
    │       ├── Gerber_BoardOutlineLayer.GKO
    │       ├── Gerber_DocumentLayer.GDL
    │       ├── Drill_PTH_Through.DRL
    │       ├── Drill_PTH_Through_Via.DRL
    │       ├── Drill_NPTH_Through.DRL
    │       └── How-to-order-PCB.txt
    └── Schematics/
        └── Schematic_Relay_6_Channel_2025-01-19.pdf
```

---

## 📄 File Types Explained

| Extension | Layer / Type | Description |
|-----------|-------------|-------------|
| `.GTL` | Top Copper Layer | Top side copper traces |
| `.GBL` | Bottom Copper Layer | Bottom side copper traces |
| `.GTO` | Top Silkscreen | Component labels and markings (top) |
| `.GBO` | Bottom Silkscreen | Component labels and markings (bottom) |
| `.GTS` | Top Solder Mask | Solder mask openings (top) |
| `.GBS` | Bottom Solder Mask | Solder mask openings (bottom) |
| `.GBP` | Bottom Paste Mask | Solder paste stencil (bottom) |
| `.GKO` | Board Outline | PCB edge/boundary shape |
| `.GDL` | Document Layer | Notes and fabrication markings |
| `.DRL` | Drill File | Hole positions and sizes |
| `.pdf` | Schematic | Full circuit schematic — open in any PDF viewer |
| `.csv` | BOM | Bill of Materials — component list with values |
| `.png` | 2D / 3D Image | Visual reference of the board |

---

## 🏭 How to Order PCBs Using Gerber Files

The Gerber files are fully extracted — no zips to open. To order PCBs:

1. Clone or download this repository
2. Open the `Gerber/` subfolder for your board, e.g.:
   `Bug In Circuit Design Files/2 Chanel_Relay/Gerber/Gerber_Relay_2_Channel_.../`
3. Select **all files** inside that subfolder and compress them into a new `.zip`
4. Upload the zip to any PCB manufacturer:
   - [JLCPCB](https://jlcpcb.com) — fast and affordable
   - [PCBWay](https://pcbway.com)
   - [OSHPark](https://oshpark.com)
5. Use standard **2-layer board** settings
6. Refer to `How-to-order-PCB.txt` inside the Gerber folder for additional notes

---

## 🔍 How to View Schematics

Click the `.pdf` file from the `Schematics/` folder on GitHub — it renders directly in the browser. You can also download it and open in any PDF viewer.

Cross-reference with [BUGS_REFERENCE.md](BUGS_REFERENCE.md) to trace each intentional bug back to its location on the schematic.

---

## 📊 How to Read the BOM

Click any `.csv` file in a `BOM/` folder on GitHub — it renders as a table automatically. Or download and open in Excel / Google Sheets. The BOM lists every component with its designator, value, footprint, and quantity.

---

*Back to [README](README.md)*
