#ifndef VECTOR3_H
#define VECTOR3_H

typedef struct {
    float x, y, z;
} Vector3;

Vector3 vec3_add(Vector3 a, Vector3 b);
Vector3 vec3_sub(Vector3 a, Vector3 b);
Vector3 vec3_scale(Vector3 v, float s);
float vec3_dot(Vector3 a, Vector3 b);
Vector3 vec3_cross(Vector3 a, Vector3 b);
float vec3_length(Vector3 v);
Vector3 vec3_normalize(Vector3 v);

#endif // VECTOR3_H
