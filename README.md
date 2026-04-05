# ESP32 Web Server + Local Control UI

This project runs an ESP32 as a WiFi access point with a simple web server to toggle LEDs, and a local Node.js UI that proxies button clicks to the ESP32 endpoints.

## Local Setup (WiFi + Node)

### 1) Flash the ESP32 and start the AP

```bash
# From the project root
pio run -t upload
```

Optional: open the serial monitor to confirm the AP and IP.

```bash
pio device monitor
```

Now connect your computer/phone to the ESP32 access point:

- SSID: `ESP32_Server`
- Password: `12345678`

The ESP32 AP IP is `http://192.168.4.1` and exposes:

- `http://192.168.4.1/on`
- `http://192.168.4.1/off`

### 2) Run the local Node.js server

```bash
cd server
pnpm install
pnpm start
```

Open the UI at `http://localhost:3000` and use the buttons to toggle the LEDs.

### If it doesn’t work

Check these first:

- The ESP32 AP is visible and your device is connected to `ESP32_Server`.
- The ESP32 IP matches `http://192.168.4.1` (see serial output).
- Port `3000` isn’t already in use.
