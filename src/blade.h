//
// Created by brian on 1/8/17.
//

#ifndef BLADE_BLADE_H
#define BLADE_BLADE_H

#include <stdint.h>

#define BLADE_OK 0
#define BLADE_ERR_INIT_GLFW 1
#define BLADE_ERR_INIT_GLFW_WINDOW 2
#define BLADE_ERR_INIT_GLEW 3

int blade_init(const char *appName, int screenWidth, int screenHeight);
void blade_terminate();

void blade_update();
void blade_render();
void blade_pollEvents();
double blade_deltaTime();

int blade_window_shouldClose();
void blade_window_swapBuffers();

void blade_timer_start();
double blade_timer_stop();

#endif //BLADE_BLADE_H
