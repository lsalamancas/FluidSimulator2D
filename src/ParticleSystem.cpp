#define _USE_MATH_DEFINES
#include <cmath>
#include "ParticleSystem.h"
#include <GL/gl.h>
#include <iostream>
#include "FluidSolver.h"
#include <algorithm>


ParticleSystem::ParticleSystem(int qtParticles, int simWidth, int simHeight, FluidSolver& solver)
    : width(simWidth), height(simHeight), fluidSolver(solver) {
    particles.reserve(qtParticles);
}

void ParticleSystem::addParticle(float x, float y, float vx, float vy, float radius) {
    particles.emplace_back(x, y, vx, vy, 0.0f, 1.0f, 0.0f, radius); // White particle
}

void ParticleSystem::update(float dt) {
    const float damping = 0.98f;
    const float maxVelocity = 50.0f;
    const float collisionRadius = 8.0f;  // Defines the collision detection range

    for (size_t i = 0; i < particles.size(); i++) {
        Particle& p1 = particles[i];

        int gridX = (p1.x * fluidSolver.getGridSize()) / width;
        int gridY = (p1.y * fluidSolver.getGridSize()) / height;

        gridX = std::clamp(gridX, 1, fluidSolver.getGridSize() - 2);
        gridY = std::clamp(gridY, 1, fluidSolver.getGridSize() - 2);

        p1.vx = fluidSolver.getU()[gridX][gridY];
        p1.vy = fluidSolver.getV()[gridX][gridY];

        p1.vx = std::clamp(p1.vx, -maxVelocity, maxVelocity);
        p1.vy = std::clamp(p1.vy, -maxVelocity, maxVelocity);

        // **Particle-to-particle collision check**
        for (size_t j = i + 1; j < particles.size(); j++) {
            Particle& p2 = particles[j];

            float dx = p2.x - p1.x;
            float dy = p2.y - p1.y;
            float distance = std::sqrt(dx * dx + dy * dy);

            if (distance < collisionRadius && distance > 0.0f) {
                // Simple elastic collision handling
                float overlap = (collisionRadius - distance) * 0.5f;
                p1.x -= overlap * (dx / distance);
                p1.y -= overlap * (dy / distance);
                p2.x += overlap * (dx / distance);
                p2.y += overlap * (dy / distance);

                // Swap velocities (elastic collision approximation)
                std::swap(p1.vx, p2.vx);
                std::swap(p1.vy, p2.vy);

                // Apply damping to slow down the collision response
                p1.vx *= 0.9f;
                p1.vy *= 0.9f;
                p2.vx *= 0.9f;
                p2.vy *= 0.9f;
            }
        }

        p1.vx *= damping;
        p1.vy *= damping;

        p1.x += p1.vx * dt;
        p1.y += p1.vy * dt;

        if (p1.x - p1.radius <= 0 || p1.x + p1.radius >= width) {
            p1.x = std::clamp(p1.x, p1.radius, width - p1.radius);
            p1.vx *= -0.5f;
        }

        if (p1.y - p1.radius <= 0 || p1.y + p1.radius >= height) {
            p1.y = std::clamp(p1.y, p1.radius, height - p1.radius);
            p1.vy *= -0.5f;
        }
    }
}

void ParticleSystem::render() {
    glEnable(GL_POINT_SMOOTH);
    // Adjust point size as needed
    glPointSize(particles[0].radius); 
    glBegin(GL_POINTS);
    for (const auto& p : particles) {
        
        glColor3f(p.r, p.g, p.b);  // Use particle color
        glVertex2f(p.x, p.y);  // Draw particles as points
    }
    glEnd();
}


