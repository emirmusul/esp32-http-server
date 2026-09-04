# esp32-http-server

An ESP32 HTTP server built with ESP-IDF v6.0. The device connects to a WiFi
network in station mode and serves a web dashboard whose HTML, CSS and
JavaScript are embedded directly into the firmware image, so the assets are
served straight from flash without consuming any RAM.

## Current status

- WiFi station mode with automatic reconnection
- HTTP server on port 80 with a wildcard URI handler
- Static assets (HTML, CSS, JS) embedded via CMake `EMBED_FILES`

## Next steps

- A `/api/sensor` endpoint backed by a DHT22 sensor
- Live dashboard updates from the browser
- mDNS so the board can be reached at `esp32.local`

## Build

    idf.py set-target esp32
    idf.py menuconfig      # set WiFi SSID and password
    idf.py build
    idf.py -p <PORT> flash monitor
