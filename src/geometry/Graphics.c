#include "Graphics.h"

void init_glfw() {
    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        exit(EXIT_FAILURE);
    }
}

GLFWwindow* create_window(int width, int height, const char* title) {
    GLFWwindow* window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!window) {
        glfwTerminate();
        fprintf(stderr, "Failed to create GLFW window\n");
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    return window;
}

void init_glew() {
    GLenum err = glewInit();
    if (err != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW: %s\n", glewGetErrorString(err));
        exit(EXIT_FAILURE);
    }
}

void setup_opengl() {
    glEnable(GL_DEPTH_TEST);
    glViewport(0, 0, 800, 600);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)800 / (double)600, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void draw_line(float x1, float y1, float x2, float y2) {
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

void draw_bezier_curve(float* points, int num_points) {
    glBegin(GL_LINE_STRIP);
    for (float t = 0; t <= 1.0; t += 0.01) {
        float x = 0, y = 0;
        for (int i = 0; i < num_points; ++i) {
            float bin_coeff = binomial_coefficient(num_points - 1, i);
            float pow_t = pow(t, i);
            float pow_one_minus_t = pow(1 - t, num_points - 1 - i);
            x += bin_coeff * pow_t * pow_one_minus_t * points[2 * i];
            y += bin_coeff * pow_t * pow_one_minus_t * points[2 * i + 1];
        }
        glVertex2f(x, y);
    }
    glEnd();
}

float binomial_coefficient(int n, int k) {
    float res = 1;
    if (k > n - k) k = n - k;
    for (int i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}
