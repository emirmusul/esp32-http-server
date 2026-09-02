#include "esp_log.h"
#include "esp_http_server.h"

#include "http_server.h"

static const char *TAG = "http_server";

static const char root_page[] =
    "<!DOCTYPE html>"
    "<html><head><meta charset=\"utf-8\"><title>ESP32</title></head>"
    "<body><h1>ESP32 HTTP server is alive</h1></body></html>";

/* Handler for GET / */
static esp_err_t root_get_handler(httpd_req_t *req)
{
    ESP_LOGI(TAG, "GET / from socket fd %d", httpd_req_to_sockfd(req));

    httpd_resp_set_type(req, "text/html");
    return httpd_resp_send(req, root_page, HTTPD_RESP_USE_STRLEN);
}

static const httpd_uri_t root_uri = {
    .uri      = "/",
    .method   = HTTP_GET,
    .handler  = root_get_handler,
    .user_ctx = NULL,
};

httpd_handle_t http_server_start(void)
{
    httpd_config_t config = HTTPD_DEFAULT_CONFIG();
    config.lru_purge_enable = true;

    httpd_handle_t server = NULL;

    ESP_LOGI(TAG, "Starting HTTP server on port %d", config.server_port);

    esp_err_t err = httpd_start(&server, &config);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "httpd_start failed: %s", esp_err_to_name(err));
        return NULL;
    }

    ESP_ERROR_CHECK(httpd_register_uri_handler(server, &root_uri));

    ESP_LOGI(TAG, "Server started, %d handler(s) registered", 1);
    return server;
}

void http_server_stop(httpd_handle_t server)
{
    if (server != NULL) {
        httpd_stop(server);
    }
}