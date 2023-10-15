#include "RenderWindow.h"
#include <corecrt_math.h>

void renderWindow(
    GLFWwindow* window,
    unsigned int& shaderProgram,
    unsigned int& shaderProgram2,
    unsigned int& VAO) {

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // 5. use our shader program when we want to render an object
    glUseProgram(shaderProgram);

    // update the uniform color
    float timeValue = glfwGetTime();
    float greenValue = sin(timeValue) / 2.0f + 0.5f;
    int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
    glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);

    // render the triangle
    glBindVertexArray(VAO);
    // glDrawArrays(GL_TRIANGLES, 0, 3);
    // glBindVertexArray(VAO[1]);
    // glDrawArrays(GL_TRIANGLES, 0, 3);
    // glDrawArrays(GL_TRIANGLES, 0, 6);
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);

    glUseProgram(shaderProgram2);
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)(3 * sizeof(VAO)));
    
    glfwSwapBuffers(window);

}