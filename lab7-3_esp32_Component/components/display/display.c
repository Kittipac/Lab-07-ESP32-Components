#include <stdio.h>
#include <string.h>
#include "esp_log.h"
#include "display.h"

static const char *TAG = "DISPLAY";

void display_init(void)
{
    ESP_LOGI(TAG, "  Display Component initialized");
    ESP_LOGI(TAG, " File: %s, Line: %d", __FILE__, __LINE__);
    ESP_LOGI(TAG, " Virtual display ready for operation");
}

void display_show_sensor_data(float temperature, float humidity, float heat_index)
{
    ESP_LOGI(TAG, "┌─────────────────────────────────┐");
    ESP_LOGI(TAG, "│        SENSOR DATA DISPLAY      │");
    ESP_LOGI(TAG, "├─────────────────────────────────┤");
    ESP_LOGI(TAG, "│   Temperature: %6.2f°C      │", temperature);
    ESP_LOGI(TAG, "│  Humidity:    %6.2f%%       │", humidity);
    ESP_LOGI(TAG, "│  Heat Index:  %6.2f        │", heat_index);
    ESP_LOGI(TAG, "└─────────────────────────────────┘");
}

void display_show_status(const char* status)
{
    ESP_LOGI(TAG, "┌─────────────────────────────────┐");
    ESP_LOGI(TAG, "│         SYSTEM STATUS           │");
    ESP_LOGI(TAG, "├─────────────────────────────────┤");
    ESP_LOGI(TAG, "│ Status: %-23s │", status);
    ESP_LOGI(TAG, "└─────────────────────────────────┘");
}

void display_clear(void)
{
    ESP_LOGI(TAG, " Display cleared");
    ESP_LOGI(TAG, "");
}
