idf_component_register(SRCS "esp32-http-server.c"
                            "wifi_sta.c"
                            "http_server.c"
                       INCLUDE_DIRS "."
                       REQUIRES nvs_flash
                                esp_wifi
                                esp_event
                                esp_netif
                                esp_http_server
                       EMBED_FILES "www/index.html"
                                   "www/style.css"
                                   "www/app.js")