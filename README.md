# Evangelion Unit-02 Helmet – NeoPixel Eye Controller

This Arduino sketch drives the **LED eye system for a custom Evangelion Unit‑02 cosplay helmet**. It controls **two NeoPixel LED rings/strips (left and right eyes)** and uses a **single hidden push button** to cycle through multiple animation modes suitable for in‑helmet operation.

Designed specifically for an **Eva‑02 aesthetic**: aggressive color, clean motion, and simple controls that work reliably while worn.

---

## ✨ Features

* Purpose-built for an **Evangelion Unit‑02 helmet**
* Dual NeoPixel outputs for **left and right eyes**
* One-button **mode cycling** (easy to access inside helmet)
* Non-blocking animations using `millis()` (no freezing or lag)
* Safe default brightness for wearable use

---

## 🔧 Helmet Hardware Setup

* Microcontroller compatible with Arduino (ESP8266 / ESP32 / Arduino Nano, etc.)
* **2× NeoPixel LED rings or strips** (16 LEDs each)
* **Momentary push button** (mounted inside helmet)
* Internal pull-up resistor used (no external resistor required)
* External 5V power supply or battery pack (recommended)

This setup is intended to be mounted **inside the helmet shell**, with LED rings aligned behind translucent eye lenses.

---

## 🧩 Pin Configuration

| Function       | Pin    |
| -------------- | ------ |
| Left Eye LEDs  | GPIO 4 |
| Right Eye LEDs | GPIO 5 |
| Mode Button    | GPIO 0 |

🔘 **Button wiring:**

* Connect the button between **GPIO 0 and GND**
* Uses `INPUT_PULLUP`, ideal for simple, reliable helmet wiring

---

## 📦 Library Requirements

Install the following library via the Arduino Library Manager:

```
Adafruit NeoPixel
```

---

## 🎮 Eye Animation Modes

Press the button to cycle through **three Eva‑02 themed modes**:

### Mode 0 — Static Green (Standby)

* Both eyes glow solid green
* Works well as a neutral or powered-on state

### Mode 1 — Rainbow Cycle (Activation / Show Mode)

* Smooth animated rainbow across both eyes
* HSV color space with gamma correction
* Ideal for conventions or display mode

### Mode 2 — Cross‑Eyes Pattern (Combat / Alert)

* Moving segmented green pattern
* Creates a mechanical, animated eye effect
* Designed to look aggressive and alive through lenses

---

## 🧠 How the System Works

* `handleButton()` debounces and detects presses while worn
* `mode` variable selects the current eye animation
* All animations are **non-blocking**, ensuring instant mode switching
* Brightness is limited to reduce heat and eye strain

---

## ⚙️ Adjustable Parameters

```cpp
#define NUM_LEDS_L 16
#define NUM_LEDS_R 16
Lefteyes.setBrightness(50);
Righteyes.setBrightness(50);
```

* Increase brightness cautiously — wearable NeoPixels can get hot
* LED count must match the physical eye rings

---

## 🔋 Power & Safety Notes (Wearable)

* ⚠️ **Do NOT power NeoPixels directly from the MCU 5V pin**
* Use a dedicated 5V supply or battery pack
* Ensure **common ground** between LEDs and controller
* Keep wiring secure to avoid shorts inside the helmet

---

## 📝 License

Released under the **MIT License** — free to modify for personal or commercial cosplay projects.


