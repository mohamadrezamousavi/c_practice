#include <stdio.h>
#include "settings.h"

int main(){

    int new_volume, new_brightness;
    printf("Enter new volume: ");
    scanf("%d", &new_volume);
    printf("Enter new Brightness: ");
    scanf("%d", &new_brightness);
    Settings* instance1 = NULL;
    Settings* instance2 = NULL;

    instance1 = create_settings();
    settings_set_volume(instance1, new_volume);
    settings_set_brightness(instance1, new_brightness);
    instance2 = create_settings();
    printf("new Value: %d\n",settings_get_volume(instance2));
    printf("new Brightness: %d\n",settings_get_brightness(instance2));

}