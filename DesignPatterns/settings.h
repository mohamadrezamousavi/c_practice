#ifndef SETTINGS_H
#define SETTINGS_H

typedef struct Settings Settings;

Settings *create_settings(void);
int settings_get_volume(const Settings *s);
int settings_get_brightness(const Settings *s);
void settings_set_volume(Settings *s, int new_volume);
void settings_set_brightness(Settings *s, int new_brightness);

#endif