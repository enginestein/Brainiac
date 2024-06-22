#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/glu.h>  // Add this for gluPerspective on Windows
#include "PhysicsEngine.h"

gcc -o physics_engine Simulation.c Vector3.c RigidBody.c Collision.c PhysicsEngine.c -lGL -lGLU -lglfw -lGLEW -lm
./physics_engine


#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

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
    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)WINDOW_WIDTH / (double)WINDOW_HEIGHT, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void draw_rigidbody(RigidBody* body) {
    glPushMatrix();
    glTranslatef(body->position.x, body->position.y, body->position.z);
    glutWireSphere(1.0, 16, 16);  // Assume unit sphere for simplicity
    glPopMatrix();
}

void render(RigidBody bodies[], int bodyCount) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    for (int i = 0; i < bodyCount; ++i) {
        draw_rigidbody(&bodies[i]);
    }

    glfwSwapBuffers(glfwGetCurrentContext());
}

int main() {
    init_glfw();
    GLFWwindow* window = create_window(WINDOW_WIDTH, WINDOW_HEIGHT, "3D Physics Engine");
    init_glew();
    setup_opengl();

    // Create some rigid bodies
    RigidBody bodies[2];
    bodies[0] = (RigidBody){{0, 0, 0}, {1, 0, 0}, {0, 0, 0}, 1};
    bodies[1] = (RigidBody){{2, 0, 0}, {-1, 0, 0}, {0, 0, 0}, 1};

    float dt = 0.01f;
    while (!glfwWindowShouldClose(window)) {
        simulate(bodies, 2, dt);
        render(bodies, 2);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
