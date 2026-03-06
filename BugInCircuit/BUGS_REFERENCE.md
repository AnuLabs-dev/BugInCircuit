# 🐛 PCB Bug Reference — All 12 Bugs

Complete list of all intentional faults across the three relay circuit boards.

---

## 🔌 2-Channel Circuit — 2 Bugs

Each channel path: ESP32 SIG → Optocoupler (PH1U) → BC547 Transistor → Relay → Load

| Bug # | Title | Problem | Cause | Fix |
|-------|-------|---------|-------|-----|
| Bug 1 | Missing Supply to Optocoupler (U1H2, CH1) | PH1U4 pin 4 not receiving Vcc supply | PCB hole connection missing | Jumper between U1H2 bottom and top holes — 5V restored to PH1U4 pin 4 |
| Bug 2 | Flyback Diode Not Connected (Relay 2 — U5) | D2U5 not soldered across relay coil — no back-EMF protection | Diode omission during PCB assembly | Solder D2U5: cathode to Vcc side, anode to transistor collector |

**Correction process:** Visual inspection → Multimeter continuity test → Channel-wise ESP32 output activation → Verify LED + relay click per channel.

---

## ⚡ 4-Channel Circuit — 4 Bugs

| Bug # | Title | Problem | Cause | Fix |
|-------|-------|---------|-------|-----|
| Bug 1 | Missing Supply — Optocoupler CH1 | PH1U4 pin 4 no Vcc | PCB hole missing | Jumper U1H2 bottom → top |
| Bug 2 | Flyback Diode Missing (Relay 2 — U5) | D2U5 not across relay coil | Diode omission | Solder D2U5, correct polarity |
| Bug 3 | Signal Not Reaching LED (CH3 — D1U6) | D27 not connected to D1U6 anode — CH3 LED stays OFF | PCB trace missing/misrouted | Connect D27 to D1U6 anode — LED restored |
| Bug 4 | Flyback Diode Missing (Relay 4 — U7) | D2U7 not across relay 4 coil | Diode omission | Solder D2U7 — cathode to Vcc, anode to collector |

---

## 🔧 6-Channel Circuit — 6 Bugs

| Bug # | Title | Problem | Cause | Fix |
|-------|-------|---------|-------|-----|
| Bug 1 | Missing Supply — Optocoupler CH1 | PH1U4 pin 4 no Vcc | PCB hole missing | Jumper U1H2 bottom → top |
| Bug 2 | Flyback Diode Missing (Relay 2 — U5) | D2U5 not soldered | Diode omission | Solder D2U5, correct polarity |
| Bug 3 | Signal Not Reaching LED (CH3 — D1U6) | D27 not at D1U6 anode | Trace missing | Connect D27 to D1U6 anode |
| Bug 4 | Flyback Diode Missing (Relay 4 — U7) | D2U7 missing | Diode omission | Solder D2U7 |
| Bug 5 | Signal Not Reaching LED (CH5 — D1U8) | D25 not at D1U8 anode — Relay 5 LED stays OFF | Missing PCB trace | Connect D25 to D1U8 anode — Relay 5 LED restored |
| Bug 6 | Transistor Base Disconnected (CH6) | BC547 base for Relay 6 not connected to base resistor — transistor never biased, relay stays OFF | Missing trace between transistor base and resistor | Connect base to resistor — Relay 6 fully operational |

**Universal debug approach:**
1. Visual PCB inspection
2. Multimeter continuity on supply traces
3. Activate each ESP32 output independently
4. Verify LED + relay click per channel

---

*Back to [README](README.md)*
