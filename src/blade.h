#ifndef BLADE_BLADE_H
#define BLADE_BLADE_H

#include <stdint.h>
#include "io.h"

#define BLADE_OK 0
#define BLADE_ERR_INIT_GLFW 1
#define BLADE_ERR_INIT_GLFW_WINDOW 2
#define BLADE_ERR_INIT_GLEW 3

char bld_init(const char *appName, int screenWidth, int screenHeight);
void bld_terminate();

void bld_update();
void bld_render();
void bld_pollEvents();
double bld_deltaTime();

int bld_window_shouldClose();
void bld_window_swapBuffers();

void bld_timer_start();
double bld_timer_stop();

#endif //BLADE_BLADE_H
