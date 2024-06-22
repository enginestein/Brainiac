#include <stdio.h>
#include <stdlib.h>
#include "Graphics.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

void render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    // Draw some lines
    draw_line(-0.5f, -0.5f, 0.5f, -0.5f); // Horizontal line
    draw_line(-0.5f, -0.5f, -0.5f, 0.5f); // Vertical line
    draw_line(-0.5f, 0.5f, 0.5f, 0.5f);   // Horizontal line
    draw_line(0.5f, -0.5f, 0.5f, 0.5f);   // Vertical line

    // Draw a Bezier curve
    float bezier_points[] = {
        -0.75f, -0.75f,
        -0.5f,  0.75f,
        0.5f,  -0.75f,
        0.75f,  0.75f
    };
    draw_bezier_curve(bezier_points, 4);

    // Swap buffers
    glfwSwapBuffers(glfwGetCurrentContext());
}

int main() {
    init_glfw();
    GLFWwindow* window = create_window(WINDOW_WIDTH, WINDOW_HEIGHT, "Curve Drawing Example");
    init_glew();
    setup_opengl();

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        render();
        glfwPollEvents();
    }

    // Cleanup and close
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
