#ifndef BLADE_IO_H
#define BLADE_IO_H

#define BLADE_ERR_IO_SHADER_VERT 4
#define BLADE_ERR_IO_SHADER_FRAG 5
#define BLADE_ERR_IO_SHADER_LINK 6

#include <GL/glew.h>

/**
 * Reads an entire File to string
 * @param path
 * @return a calloc'd string. Free when done.
 */
char *bld_io_fileToString(const char *path);

GLuint bld_io_compileShader(const char *vertPath, const char *fragPath,
                            char *errorCode);

#endif //BLADE_IO_H
