#include "RigidBody.h"

void update_rigidbody(RigidBody *body, float dt) {
    // Update velocity based on acceleration
    body->velocity = vec3_add(body->velocity, vec3_scale(body->acceleration, dt));
    
    // Update position based on velocity
    body->position = vec3_add(body->position, vec3_scale(body->velocity, dt));
    
    // Clear acceleration for the next frame
    body->acceleration = (Vector3){0, 0, 0};
}
