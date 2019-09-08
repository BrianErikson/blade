//
// Created by brian on 1/8/17.
//

#include <stdio.h>
#include <stdlib.h>
#include "bld.h"
#include "GL/glew.h"
#include "GLFW/glfw3.h"

GLFWwindow *window;
GLuint shaderProgram;
double startTime, prevDeltaTime, deltaTime;

char bld_init(const char *appName, int screenWidth, int screenHeight)
{
    if (!glfwInit()) {
        fprintf(stderr, "GLFW could not instantiate\n");
        return BLADE_ERR_INIT_GLFW;
    }

    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    window = glfwCreateWindow(screenWidth, screenHeight, appName, NULL, NULL);
    if (window == NULL) {
        fprintf(stderr, "Unable to create GLFW window\n");
        return BLADE_ERR_INIT_GLFW_WINDOW;
    }
    glfwMakeContextCurrent(window);
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    glfwSwapInterval(1); // vsync -- waits for 1 monitor refresh before swapping

    int glewRes;
    if ((glewRes = glewInit()) != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW with an error code of %d\n",
                glewRes);
        bld_terminate();
        return BLADE_ERR_INIT_GLEW;
    }

    char result;
    shaderProgram = bld_io_compileShader(
        "../res/shaders/default_vertex.glsl",
        "../res/shaders/default_fragment.glsl",
        &result
    );

    if (result != 0) {
        fprintf(stderr, "Error compiling shaders. Error code %d\n", result);
        bld_terminate();
        return result;
    }

    return BLADE_OK;
}

void bld_terminate()
{
    if (window != NULL)
        glfwTerminate();
}

void bld_update()
{

}

void bld_render()
{
    glUseProgram(shaderProgram);
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void bld_pollEvents()
{
    glfwPollEvents();
}

int bld_window_shouldClose()
{
    int result = 0;
    if (window != NULL) {
        if (glfwWindowShouldClose(window)) {
            result = 1;
        }
    }

    return result;
}

void bld_window_swapBuffers()
{
    glfwSwapBuffers(window);
}

void bld_timer_start()
{
    startTime = glfwGetTime();
}

double bld_timer_stop()
{
    deltaTime = glfwGetTime() - startTime;
    return deltaTime;
}

double bld_deltaTime()
{
    return deltaTime;
}
