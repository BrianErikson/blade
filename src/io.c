//
// Created by brian on 12/21/16.
//

#include "io.h"
#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>

char *blade_io_fileToString(const char *path) {
    FILE *file;

    file = fopen(path, "rb");

    // Determine file size
    fseek(file, 0, SEEK_END);
    long size = ftell(file) + 1; // +1 for \0
    fseek(file, 0, SEEK_SET);

    size_t num;
    char *buf = calloc((size_t) size, sizeof(char));
    fread(buf, 1, (size_t) size, file);
    buf[size - 1] = '\0';

    fclose(file);
    return buf;
}

GLuint compileShader(const char *fs, GLenum shaderType, char *error) {
    GLuint shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, &fs, NULL);
    glCompileShader(shader);

    GLint status;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    if (status == GL_FALSE) {
        GLint infoLogLength;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength);
        GLchar strInfoLog[1 + infoLogLength];
        glGetShaderInfoLog(shader, infoLogLength, NULL, strInfoLog);
        fprintf(stderr, "Compile failure in shader:\n %s\n", strInfoLog);
        switch (shaderType) {
            case GL_VERTEX_SHADER:
                *error = BLADE_ERR_IO_SHADER_VERT;
                break;
            case GL_FRAGMENT_SHADER:
                *error = BLADE_ERR_IO_SHADER_FRAG;
                break;
            default:
                break;
        }
        glDeleteShader(shader);
        return 0;
    }

    return shader;
}

GLuint compileShaderProgram(GLuint vert, GLuint frag, char *error) {
    GLuint program;
    program = glCreateProgram();
    glAttachShader(program, vert);
    glAttachShader(program, frag);

    glLinkProgram(program);

    GLint status;
    glGetProgramiv(program, GL_COMPILE_STATUS, &status);
    if (status == GL_FALSE) {
        GLint infoLogLength;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &infoLogLength);
        GLchar strInfoLog[1 + infoLogLength];
        glGetProgramInfoLog(program, infoLogLength, NULL, strInfoLog);
        fprintf(stderr, "Linker failure in shader program:\n %s\n", strInfoLog);
        *error = BLADE_ERR_IO_SHADER_LINK;
    }

    glDetachShader(program, vert);
    glDetachShader(program, frag);
    glDeleteShader(vert);
    glDeleteShader(frag);
    return program;
}

GLuint blade_io_compileShader(const char *vertPath, const char *fragPath,
                              char *errorCode) {
    char *vs, *fs;
    GLuint program, vert, frag;

    *errorCode = 0;
    vs = blade_io_fileToString(vertPath);
    fs = blade_io_fileToString(fragPath);

    vert = compileShader(vs, GL_VERTEX_SHADER, errorCode);
    if (*errorCode > 0) {
        *errorCode = BLADE_ERR_IO_SHADER_VERT;
        free(vs);
        free(fs);
        return 0;
    }
    frag = compileShader(fs, GL_FRAGMENT_SHADER, errorCode);
    if (*errorCode > 0) {
        *errorCode = BLADE_ERR_IO_SHADER_FRAG;
        free(vs);
        free(fs);
        return 0;
    }

    program = compileShaderProgram(vert, frag, errorCode);
    if (*errorCode > 0) {
        *errorCode = BLADE_ERR_IO_SHADER_LINK;
        glDeleteProgram(program);
    }

    free(vs);
    free(fs);
    return program;
}