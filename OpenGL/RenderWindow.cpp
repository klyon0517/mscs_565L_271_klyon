#include "RenderWindow.h"
#include <corecrt_math.h>

void renderWindow(
    GLFWwindow* window,
    Shader_s& ourShader,
    unsigned int& VAO)
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // 5. use our shader program when we want to render an object
    ourShader.use();
    glBindVertexArray(VAO);

    // render the triangle
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glfwSwapBuffers(window);
}