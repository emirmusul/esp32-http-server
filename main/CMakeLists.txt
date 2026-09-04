idf_component_register(SRCS "esp32-http-server.c"
                            "wifi_sta.c"
                            "http_server.c"
                            "sensor.c"
                            "dht.c"
                       INCLUDE_DIRS "."
                       REQUIRES nvs_flash
                                esp_wifi
                                esp_event
                                esp_netif
                                esp_http_server
                                esp_driver_gpio
                                esp_timer
                                json
                       EMBED_FILES "www/index.html"
                                   "www/style.css"
                                   "www/app.js")
