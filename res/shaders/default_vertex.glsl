#version 400

layout(location=0) in vec4 in_Position;
layout(location=1) in vec4 in_Color;
out vec4 color;

void main() {
    gl_Position = in_Position;
    color = in_Color;
}
