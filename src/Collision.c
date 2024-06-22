#include "Collision.h"

int check_collision(RigidBody *a, RigidBody *b, Collision *collision) {
    // Simplified sphere-sphere collision detection
    Vector3 diff = vec3_sub(a->position, b->position);
    float dist = vec3_length(diff);
    float combinedRadius = 1.0f; // Assume both bodies are unit spheres for simplicity

    if (dist < combinedRadius) {
        collision->bodyA = a;
        collision->bodyB = b;
        collision->contactPoint = vec3_add(a->position, vec3_scale(diff, 0.5f));
        collision->contactNormal = vec3_normalize(diff);
        collision->penetrationDepth = combinedRadius - dist;
        return 1;
    }

    return 0;
}
