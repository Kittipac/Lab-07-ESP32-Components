#include <stdio.h>
#include "esp_log.h"
#include "display.h"

static const char *TAG = "DISPLAY";

void display_init(void)
{
    ESP_LOGI(TAG, "  Display initialized from file: %s, line: %d", __FILE__, __LINE__);
    ESP_LOGI(TAG, " Display module ready");
}

void display_show_message(const char* message)
{
    ESP_LOGI(TAG, " Displaying from file: %s, line: %d", __FILE__, __LINE__);
    ESP_LOGI(TAG, " Message: %s", message);
}

void display_show_data(float value1, float value2)
{
    ESP_LOGI(TAG, " Data display from file: %s, line: %d", __FILE__, __LINE__);
    ESP_LOGI(TAG, " Value 1: %.2f", value1);
    ESP_LOGI(TAG, " Value 2: %.2f", value2);
}

void display_clear_screen(void)
{
    ESP_LOGI(TAG, " Screen cleared from file: %s, line: %d", __FILE__, __LINE__);
    ESP_LOGI(TAG, " Display ready for new content");
}
