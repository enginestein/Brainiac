#include <stdio.h>
#include "PhysicsEngine.h"

int main() {
    // Create some rigid bodies
    RigidBody bodies[2];
    bodies[0] = (RigidBody){{0, 0, 0}, {1, 0, 0}, {0, 0, 0}, 1};
    bodies[1] = (RigidBody){{2, 0, 0}, {-1, 0, 0}, {0, 0, 0}, 1};

    float dt = 0.01f;
    for (int i = 0; i < 100; ++i) {
        simulate(bodies, 2, dt);
        printf("Body 0: (%f, %f, %f)\n", bodies[0].position.x, bodies[0].position.y, bodies[0].position.z);
        printf("Body 1: (%f, %f, %f)\n", bodies[1].position.x, bodies[1].position.y, bodies[1].position.z);
    }

    return 0;
}
