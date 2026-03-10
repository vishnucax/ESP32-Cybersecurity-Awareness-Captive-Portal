# ESP32 Cybersecurity Awareness Captive Portal 🚀

A **cybersecurity awareness demo project** built using an **ESP32**.
This project creates a **fake Wi-Fi portal (captive portal)** that demonstrates how attackers could collect information on public Wi-Fi networks.

⚠️ **Purpose:** Educational demonstration for cybersecurity awareness.

DEMO VIEDO : https://youtube.com/shorts/MeoPR8zMElo?feature=share

When a user connects to the ESP32 Wi-Fi network:

1. A **hacker-style terminal screen** appears.
2. A **fake network security scan animation** runs.
3. A **login form (Name + Email)** appears.
4. The entered data is shown and logged in the **Serial Monitor**.
5. An awareness message explains the risk of fake Wi-Fi portals.

This project is great for **college presentations, IoT demos, and cybersecurity awareness workshops**.

---

# 📸 Demo Flow

### 1️⃣ Connect to Wi-Fi

```
SSID: LEAD_WiFi
Password: (None)
```

---

### 2️⃣ Hacker Terminal Animation

```
> Booting Network Gateway...
> Loading Security Modules...
> Scanning Connected Devices...
> Checking Firewall Integrity...
> Initializing Captive Portal...
```
![WhatsApp Image 2026-03-10 at 11 43 58 AM](https://github.com/user-attachments/assets/df057d18-f650-4f03-8a9f-9ab01ca6b943)


---

### 3️⃣ Login Portal Appears

```
Secure Network Access
User Name
User Email
Authorize Access
```

---

### 4️⃣ Awareness Screen

```
ACCESS LOGGED
User: Rahul
Email: rahul@gmail.com

Cybersecurity Awareness Demo
```

---

# 🧠 Project Concept

This project demonstrates how **fake public Wi-Fi login pages can collect user information**.

In real life, attackers sometimes create fake networks like:

```
Free_Public_WiFi
Airport_Free_WiFi
CoffeeShop_WiFi
```

Users connect and unknowingly enter personal details.

This demo helps explain **why you should never trust unknown public Wi-Fi portals**.

---

# ⚙️ Hardware Required

| Component               | Quantity |
| ----------------------- | -------- |
| ESP32 Development Board | 1        |
| Red LED                 | 1        |
| Blue LED                | 1        |
| 220Ω Resistor           | 2        |
| Breadboard              | 1        |
| Jumper Wires            | Few      |

---

# 🔌 Wiring Diagram

```
Red LED  → GPIO2 (D2) → 220Ω Resistor → GND
Blue LED → GPIO4 (D4) → 220Ω Resistor → GND
```

LED polarity:

```
ESP32 GPIO → Resistor → LED (+ long leg)
LED (- short leg) → GND
```

---

# 💡 LED Indicators

| LED         | Behavior      | Meaning             |
| ----------- | ------------- | ------------------- |
| 🔴 Red LED  | Slow blinking | System running      |
| 🔵 Blue LED | Fast blinking | User submitted form |

---

# 🧰 Software Requirements

Install:

* **Arduino IDE**
* **ESP32 Board Package**

Libraries used:

```
WiFi.h
WebServer.h
DNSServer.h
```

These are included with the ESP32 board package.

---

# 🛠️ Installation Steps

### 1️⃣ Install ESP32 Board

In Arduino IDE:

```
File → Preferences
```

Add this URL to **Additional Boards Manager URLs**:

```
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
```

Then install **ESP32** from **Boards Manager**.

---

### 2️⃣ Upload Code

1. Open the `.ino` file.
2. Select board:

```
ESP32 Dev Module
```

3. Select correct **COM Port**.
4. Click **Upload**.

---

### 3️⃣ Open Serial Monitor

Set baud rate:

```
115200
```

Example output:

```
Hotspot Started
192.168.4.1

-------- New User --------
Visitor #: 1
Name: Rahul
Email: rahul@gmail.com
--------------------------
```

---

# 🌐 How It Works

1️⃣ ESP32 creates a **Wi-Fi hotspot**

```
LEAD_WiFi
```

2️⃣ User connects to it.

3️⃣ DNS server redirects all requests to:

```
192.168.4.1
```

4️⃣ A **captive portal page** opens automatically.

5️⃣ User enters information.

6️⃣ ESP32 logs the data.

---

# 🎓 Educational Value

This project demonstrates:

* Captive portals
* Wi-Fi security risks
* Social engineering
* IoT networking
* ESP32 web servers

It is ideal for:

* **Cybersecurity awareness demos**
* **IoT projects**
* **College presentations**
* **Networking experiments**

---

# ⚠️ Disclaimer

This project is created **only for educational and awareness purposes**.

Do **NOT** use this system to collect real user information without permission.

Always follow ethical and legal guidelines when working with network security.

---

# 👨‍💻 Developer

**Vishnu K**

Portfolio:

```
https://vishnucax.github.io/future-predictor
```

---

# ⭐ If you like this project

Give it a ⭐ on GitHub and share it with others learning **ESP32 and cybersecurity**.
