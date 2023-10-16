#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Shader_s.h"

void renderWindow(
    GLFWwindow*,
    Shader_s&,
    unsigned int&);
