# 🎨 Resistor Color Coding Reference

Quick reference for decoding resistor values from color bands.

---

## Color Band Chart

| Color | Digit | Multiplier | Tolerance |
|-------|-------|------------|-----------|
| Black | 0 | ×1 | — |
| Brown | 1 | ×10 | ±1% (F) |
| Red | 2 | ×100 | ±2% (G) |
| Orange | 3 | ×1K | — |
| Yellow | 4 | ×10K | — |
| Green | 5 | ×100K | ±0.5% (D) |
| Blue | 6 | ×1M | ±0.25% (C) |
| Violet | 7 | ×10M | ±0.10% (B) |
| Grey | 8 | ×100M | ±0.05% (A) |
| White | 9 | ×1G | — |
| Gold | — | ×0.1 | ±5% (J) |
| Silver | — | ×0.01 | ±10% (K) |

**Memory trick:** BB ROY of Great Britain Very Good Wife = Black Brown Red Orange Yellow Green Blue Violet Grey White = 0–9

---

## 4-Band Resistor (Standard)

```
Band 1 = 1st digit
Band 2 = 2nd digit
Band 3 = Multiplier
Band 4 = Tolerance

Value = (B1×10 + B2) × Multiplier
```

**Example:** Red–Red–Brown–Gold = (2×10 + 2) × 10 = **220 Ω ±5%**

---

## 5-Band Resistor (Precision)

```
Band 1 = 1st digit
Band 2 = 2nd digit
Band 3 = 3rd digit
Band 4 = Multiplier
Band 5 = Tolerance

Value = (B1×100 + B2×10 + B3) × Multiplier
```

**Example:** Brown–Black–Black–Orange–Brown = (1×100 + 0 + 0) × 1K = **100 KΩ ±1%**

> **Reading tip:** Hold resistor so Gold or Silver (tolerance) band is on the RIGHT, then read left to right.

---

## Common Values in This Kit

| Color Bands | Value | Common Use |
|---|---|---|
| Red–Red–Brown–Gold | 220 Ω ±5% | LED current limiting |
| Brown–Black–Red–Gold | 1 KΩ ±5% | Pull-up resistor |
| Brown–Black–Orange–Gold | 10 KΩ ±5% | Pull-up / pull-down |
| Yellow–Violet–Red–Gold | 4.7 KΩ ±5% | Sensor pull-up |
| Yellow–Violet–Brown–Gold | 470 Ω ±5% | Transistor base |
| Brown–Black–Black–Orange–Brown | 100 KΩ ±1% | 5-band precision |

---

*Back to [README](README.md)*
