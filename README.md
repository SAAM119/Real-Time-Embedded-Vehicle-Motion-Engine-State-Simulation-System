 # Real-Time Embedded Vehicle Motion & Engine-State Control System

## 📌 Overview
This project implements a **Vehicle Control Unit (VCU) prototype** using an **ESP32** and **L298N motor driver**, designed to model **real vehicle control behavior** rather than simple motor actuation.

The system follows **ECU-style embedded architecture**, incorporating **engine-state management, motion control logic, speed profiling, braking behavior, and deterministic control rules**.  
It is intended as a **foundation-layer automotive ECU project**, aligned with **vehicle control & dynamics**, and structured for future **AI-assisted behavior modeling** and **ADAS integration**.

---

## 🎯 Objectives
- Design a **state-based vehicle control system**
- Implement **engine-driven control logic**
- Model **realistic vehicle motion behavior**
- Apply **embedded system architecture principles**
- Build a scalable base for **AI & ADAS extensions**

---

## ⚙️ System Features

### 🚗 Engine & Vehicle State Management
- Engine ON/OFF state machine  
- Engine-dependent vehicle operation  
- Dashboard-style engine status indication (LED)  
- State-driven control enforcement  

### 🧭 Vehicle Motion Control
- Forward & reverse motion  
- Left/right turning logic  
- Braking system  
- Emergency stop logic  
- Full stop control  
- Directional stability handling  

### ⚡ Speed & Dynamics Control
- PWM-based speed control  
- Dead-zone compensation  
- Smooth acceleration profiles  
- Controlled deceleration  
- Stable motion logic  
- Motor enable/disable separation  

---

## 🧠 Embedded System Architecture

### Control Model
- Engine-state driven logic  
- Motion-state dependent control  
- Speed-layer abstraction  
- Enable-layer management  
- Separation of **control logic** and **actuation**  
- Deterministic command execution  

### Concepts Implemented
- PWM-based actuation  
- Direction logic separation  
- Finite State Machine (FSM) design  
- Control-rule enforcement  
- Hardware–software co-design  
- Real-time embedded system thinking  
- System-level debugging  
- Vehicle behavior modeling  

---

## 🔧 Hardware Stack
- **ESP32** – Vehicle Control ECU core  
- **L298N Motor Driver** – Actuation interface  
- **DC Motors + Wheels** – Vehicle motion system  
- **Battery Power System** – Drive power  
- **LED Indicators** – Dashboard prototype indicator  
- Supporting electronics – resistors, wiring, breadboard  

---

## 💻 Software Stack
- **Language:** Embedded C++ (Arduino framework, structured & modular)  
- **Architecture:** Layered ECU-style design  
- **Control Method:** State-based logic with deterministic execution  
---

## 🎮 Control Interface
Command-driven control via serial interface:

| Command | Action |
|------|------|
| 1 | Engine ON |
| 2 | Forward |
| 3 | Brake |
| 4 | Engine OFF |
| 5 | Turn Left |
| 6 | Turn Right |

---

## 📷 Demo
Photos and videos of the working hardware prototype are included to demonstrate:
- Real-time motion control  
- Engine-state behavior  
- Speed and braking response  
- Hardware–software integration  

---

## 🛣️ Roadmap (Planned Extensions)
- RTOS-based task scheduling  
- CAN communication layer  
- Encoder-based feedback control  
- AI-assisted driving behavior modeling  
- ADAS-aware integration (lane / obstacle awareness)  
- Fault handling & degradation modes  

---

- ECU-style architecture  
- Vehicle control & dynamics logic  
- Embedded system discipline  
- Real-time deterministic behavior  
- Automotive-oriented system thinking  

Built as a **foundation system** for advanced automotive ECU, AI-assisted driving, and ADAS-focused development.

---

## 👤 Author
**Aman Vishwash**  
Electronics & Communication Engineering  
Automotive ECU | Vehicle Control | Embedded Systems
