#include "Buffer.h"

// Callback for resizing the window
void framebuffer_size_callback(
    GLFWwindow* window,
    int& width,
    int& height) {

    glViewport(0, 0, width, height);

}