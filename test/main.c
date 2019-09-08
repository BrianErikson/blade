//
// Created by brian on 1/8/17.
//

#include <stdio.h>
#include "../src/blade.h"

int main(int argc, char** argv) {
    unsigned int ct, lt, dt; // time
    double dts; // delta-time in seconds

    char result;
    if ((result = bld_init("BladeTest", 1920, 1080)) != BLADE_OK) {
        return result;
    }

    do {
        bld_timer_start();
        bld_update();
        bld_render();
        bld_window_swapBuffers();
        bld_pollEvents();
        bld_timer_stop();
    } while (!bld_window_shouldClose());

    bld_terminate();

    return 0;
}