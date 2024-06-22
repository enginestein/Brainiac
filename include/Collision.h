#ifndef COLLISION_H
#define COLLISION_H

#include "Vector3.h"
#include "RigidBody.h"

typedef struct {
    RigidBody *bodyA;
    RigidBody *bodyB;
    Vector3 contactPoint;
    Vector3 contactNormal;
    float penetrationDepth;
} Collision;

int check_collision(RigidBody *a, RigidBody *b, Collision *collision);

#endif // COLLISION_H
