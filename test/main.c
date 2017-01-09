//
// Created by brian on 1/8/17.
//

#include "../src/blade.h"

int main(int argc, char** argv) {
    unsigned int ct, lt, dt; // time
    double dts; // delta-time in seconds

    int result;
    if ((result = blade_init("BladeTest", 1920, 1080)) != BLADE_OK) {
        return result;
    }

    do {
        blade_timer_start();
        blade_update();
        blade_render();
        blade_window_swapBuffers();
        blade_pollEvents();
        blade_timer_stop();
    } while (!blade_window_shouldClose());

    blade_terminate();

    return 0;
}