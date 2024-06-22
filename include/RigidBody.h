#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "Vector3.h"

typedef struct {
    Vector3 position;
    Vector3 velocity;
    Vector3 acceleration;
    float mass;
} RigidBody;

void update_rigidbody(RigidBody *body, float dt);

#endif // RIGIDBODY_H
