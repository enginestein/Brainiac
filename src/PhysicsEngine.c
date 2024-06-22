#include "PhysicsEngine.h"

void simulate(RigidBody bodies[], int bodyCount, float dt) {
    // Update all bodies
    for (int i = 0; i < bodyCount; ++i) {
        update_rigidbody(&bodies[i], dt);
    }

    // Check for collisions
    for (int i = 0; i < bodyCount; ++i) {
        for (int j = i + 1; j < bodyCount; ++j) {
            Collision collision;
            if (check_collision(&bodies[i], &bodies[j], &collision)) {
                // Handle collision response (simple elastic collision)
                Vector3 relativeVelocity = vec3_sub(bodies[i].velocity, bodies[j].velocity);
                float velocityAlongNormal = vec3_dot(relativeVelocity, collision.contactNormal);
                
                if (velocityAlongNormal > 0) {
                    continue;
                }
                
                float restitution = 1.0f; // Assume perfect elastic collision
                float impulseMagnitude = -(1 + restitution) * velocityAlongNormal;
                impulseMagnitude /= (1 / bodies[i].mass) + (1 / bodies[j].mass);
                
                Vector3 impulse = vec3_scale(collision.contactNormal, impulseMagnitude);
                
                bodies[i].velocity = vec3_add(bodies[i].velocity, vec3_scale(impulse, 1 / bodies[i].mass));
                bodies[j].velocity = vec3_sub(bodies[j].velocity, vec3_scale(impulse, 1 / bodies[j].mass));
            }
        }
    }
}
