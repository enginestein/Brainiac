#ifndef PHYSICSENGINE_H
#define PHYSICSENGINE_H

#include "RigidBody.h"
#include "Collision.h"

void simulate(RigidBody bodies[], int bodyCount, float dt);

#endif // PHYSICSENGINE_H
