#include <stdio.h>
#include <stdlib.h>
#include "esp_system.h"
#include "esp_random.h"
#include "esp_log.h"
#include "sensor.h"

static const char *TAG = "SENSOR";

void sensor_init(void)
{
    ESP_LOGI(TAG, " Sensor initialized from file: %s, line: %d", __FILE__, __LINE__);
    ESP_LOGI(TAG, " Sensor module ready for operation");
}

void sensor_read_data(void)
{
    ESP_LOGI(TAG, " Reading sensor data from file: %s, line: %d", __FILE__, __LINE__);
    
    // จำลองการอ่านข้อมูลจาก sensor
    float temperature = 25.5 + (float)(esp_random() % 100) / 10.0f;
    float humidity = 60.0 + (float)(esp_random() % 400) / 10.0f;
    
    ESP_LOGI(TAG, "  Temperature: %.1f°C", temperature);
    ESP_LOGI(TAG, " Humidity: %.1f%%", humidity);
}

void sensor_check_status(void)
{
    ESP_LOGI(TAG, " Sensor status check from file: %s, line: %d", __FILE__, __LINE__);
    ESP_LOGI(TAG, " All sensors operating normally");
}
