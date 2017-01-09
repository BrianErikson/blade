//
// Created by brian on 1/8/17.
//

#include <stdio.h>
#include <stdlib.h>
#include "blade.h"
#include "GL/glew.h"
#include "GLFW/glfw3.h"

GLFWwindow *window;
double startTime, prevDeltaTime, deltaTime;


int blade_init(const char *appName, int screenWidth, int screenHeight) {
    if (!glfwInit()) {
        fprintf(stderr, "GLFW could not instantiate\n");
        return BLADE_ERR_INIT_GLFW;
    }

    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);

    window = glfwCreateWindow(screenWidth, screenHeight, appName, NULL, NULL);
    if (window == NULL) {
        fprintf(stderr, "Unable to create GLFW window\n");
        return BLADE_ERR_INIT_GLFW_WINDOW;
    }
    glfwMakeContextCurrent(window);
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    int glewRes;
    if ((glewRes = glewInit()) != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW with an error code of %d\n",
                glewRes);
        return BLADE_ERR_INIT_GLEW;
    }

    return BLADE_OK;
}

void blade_terminate() {
    if (window != NULL)
        glfwTerminate();
}

void blade_update() {

}

void blade_render() {
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void blade_pollEvents() {
    glfwPollEvents();
}

int blade_window_shouldClose() {
    int result = 0;
    if (window != NULL) {
        if (glfwWindowShouldClose(window)) {
            result = 1;
        }
    }

    return result;
}

void blade_window_swapBuffers() {
    glfwSwapBuffers(window);
}

void blade_timer_start() {
    startTime = glfwGetTime();
}

double blade_timer_stop() {
    deltaTime = glfwGetTime() - startTime;
    return deltaTime;
}

double blade_deltaTime() {
    return deltaTime;
}
