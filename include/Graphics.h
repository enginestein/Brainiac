#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

void init_glfw();
GLFWwindow* create_window(int width, int height, const char* title);
void init_glew();
void setup_opengl();
void draw_line(float x1, float y1, float x2, float y2);
void draw_bezier_curve(float* points, int num_points);

#endif // GRAPHICS_H
