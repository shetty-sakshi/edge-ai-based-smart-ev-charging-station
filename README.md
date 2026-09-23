# Edge AI-Based Smart EV Charging Station

An IoT and Edge AI-driven multi-bay electric vehicle (EV) charging station firmware developed for ESP32 microcontrollers. The system autonomously monitors power demands across three charging bays, optimizes electrical load distribution at the edge to prevent grid overloads, and streams real-time operational telemetry to ThingsBoard Cloud.

---

## ⚡ Key Features

- **3-Bay Concurrent Management**: Simulates three independent charging bays (`BAY1`, `BAY2`, `BAY3`) running simultaneous charging cycles.
- **Edge AI Load Balancing**: Evaluates charging demand and dynamically adjusts current allocation locally on each ESP32 without relying on constant cloud connectivity.
- **ThingsBoard Cloud Integration**: Real-time telemetry streaming (voltage, current, power, bay state) and bidirectional Remote Procedure Call (RPC) control.
- **Modular Firmware Design**: Clean separation of Edge AI heuristics, state machine logic, peripheral I/O, and networking layers.
- **Simulation-Ready**: Includes pre-configured Wokwi virtual hardware schematics for immediate execution and testing without physical hardware.

---

## 🔌 Charging Station Architecture

The infrastructure models three distinct charging bay profiles with dynamic power balancing and hardware-level protection:

| Bay Identifier | Target Vehicle Class | Power Rating | Sensors & Actuators |
| :--- | :--- | :--- | :--- |
| **BAY 1** | Standard EV (AC Fast) | Up to 7.4 kW | Current/voltage monitor, relay cut-off, status LEDs |
| **BAY 2** | Fleet / Commercial EV | Up to 11 kW | Current sensor, temperature monitor, safety interlock |
| **BAY 3** | Rapid Charge Priority | Up to 22 kW | Active load-balancing shunt, PWM controller, status indicator |

- **Adaptive Load Balancing**: When combined current draw threatens aggregate transformer limits, Edge AI throttles lower-priority bays dynamically.
- **Fault Protection & Safety**: Automatic relay isolation triggers immediately upon detecting over-current, voltage surges, or thermal limit exceedance.

---

## 📊 ThingsBoard Cloud Dashboards

The system interfaces with customized ThingsBoard dashboards to deliver operational observability and remote administration:

### 1. Master Station Overview Dashboard
- **Aggregate Power Consumption**: Live radial gauges displaying station-wide kW draw against capacity limits.
- **Bay Status Matrix**: Multi-state cards showing the operational state of each bay (`IDLE`, `CHARGING`, `COMPLETE`, `FAULT`).
- **Energy Metering**: Cumulative kilowatt-hours (kWh) delivered per charging session and historical energy trends.

### 2. Individual Bay Telemetry Dashboards (Bay 1 / Bay 2 / Bay 3)
- **Time-Series Charts**: High-frequency telemetry plots for voltage (V), charging current (A), and temperature (°C).
- **Battery State of Charge (SoC)**: Simulated battery charging curve tracking.
- **Edge AI Allocation Feed**: Live visualization of dynamic current ceilings enforced by the edge optimization engine.

### 3. Operator Remote Control (RPC) Panel
- **Remote Bay Control**: Bidirectional RPC switches for manual session start, pause, and emergency cutoff.
- **Dynamic Priority Override**: Assign rapid-charging priority to specific bays during peak hours.
- **Configurable Operational Attributes**: Tune maximum current ceilings and safety trip points directly from the cloud UI.

---

## 🛠️ Tech Stack

- **Microcontroller**: ESP32
- **Core Framework & Language**: C/C++, PlatformIO Core / VS Code
- **IoT & Telemetry**: ThingsBoard Cloud (MQTT / HTTP)
- **Virtual Simulation**: Wokwi Simulation Platform (`diagram.json`, `wokwi.toml`)

---

## 📁 Repository Structure

```text
├── BAY1/
│   └── esp32_blink/          # Bay 1 firmware, Edge AI model, and Wokwi circuit
├── BAY2/
│   └── esp32_blink/          # Bay 2 firmware, Edge AI model, and Wokwi circuit
├── BAY3/
│   └── esp32_blink/          # Bay 3 firmware, Edge AI model, and Wokwi circuit
└── .gitignore                # Excludes private network credentials & build artifacts
