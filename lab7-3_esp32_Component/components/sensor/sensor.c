#include <stdio.h>
#include <stdlib.h>
#include "esp_system.h"
#include "esp_random.h"
#include "esp_log.h"
#include "driver/gpio.h"
#include "sensor.h"

static const char *TAG = "ENHANCED_SENSOR";

void sensor_init(void)
{
    ESP_LOGI(TAG, " Enhanced Sensor Component initialized");
    ESP_LOGI(TAG, " File: %s, Line: %d", __FILE__, __LINE__);
    
    // กำหนด GPIO สำหรับ LED indicator
    gpio_config_t io_conf = {
        .pin_bit_mask = (1ULL << GPIO_NUM_2),
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = 0,
        .pull_down_en = 0,
        .intr_type = GPIO_INTR_DISABLE,
    };
    gpio_config(&io_conf);
    
    ESP_LOGI(TAG, " GPIO LED configured on pin 2");
}

float sensor_read_temperature(void)
{
    float temperature = 20.0 + (float)(esp_random() % 200) / 10.0f;
    ESP_LOGI(TAG, "  Temperature: %.2f°C", temperature);
    return temperature;
}

float sensor_read_humidity(void)
{
    float humidity = 40.0 + (float)(esp_random() % 400) / 10.0f;
    ESP_LOGI(TAG, " Humidity: %.2f%%", humidity);
    return humidity;
}

void sensor_read_all_data(void)
{
    ESP_LOGI(TAG, " Reading all sensor data...");
    
    // เปิด LED เมื่ออ่านข้อมูล
    gpio_set_level(GPIO_NUM_2, 1);
    
    float temp = sensor_read_temperature();
    float hum = sensor_read_humidity();
    
    // คำนวณ Heat Index
    float heat_index = temp + 0.5 * hum;
    ESP_LOGI(TAG, " Heat Index: %.2f", heat_index);
    
    // แสดงสถานะตามค่า Heat Index
    if (heat_index < 80) {
        ESP_LOGI(TAG, " Comfortable conditions");
    } else if (heat_index < 90) {
        ESP_LOGI(TAG, "  Caution: Possible fatigue");
    } else {
        ESP_LOGI(TAG, " Warning: High heat stress");
    }
    
    // ปิด LED หลังอ่านข้อมูลเสร็จ
    gpio_set_level(GPIO_NUM_2, 0);
}
