#include <stdlib.h>
#include "settings.h"

typedef struct Settings{
    int volume;
    int brightness;
} Settings;

static Settings* instance = NULL;

Settings * create_settings(void){
    if (instance == NULL){
        instance = malloc(sizeof(Settings));
        instance->volume = 50;
        instance->brightness = 70;
    }
    return instance;
}

int settings_get_volume(const Settings *s){
    return s->volume;
}
int settings_get_brightness(const Settings *s){
    return s->brightness;
}
void settings_set_volume(Settings *s, int new_volume){
    s->volume = new_volume;
}
void settings_set_brightness(Settings *s, int new_brightness){
    s->brightness = new_brightness;
}