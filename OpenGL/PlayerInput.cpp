#include "PlayerInput.h"

void playerInput(
    GLFWwindow* window) {
    
    glfwPollEvents();

    // Handle player quitting
    if (Keyboard::isKeyPressed(Keyboard::Escape)) {
        glfwSetWindowShouldClose(window, true);
    }

}