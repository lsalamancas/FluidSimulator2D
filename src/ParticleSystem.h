#ifndef PARTICLE_SYSTEM_H
#define PARTICLE_SYSTEM_H

#include <vector>
#include "FluidSolver.h"

struct Particle{
    float x, y;     //position
    float vx, vy;   //velocity
    float r, g, b;  //color
    float radius;     //radius of the particle
    
    Particle(float px, float py, float velX, float velY, float red, float green, float blue, float rad) 
    : x(px), y(py), vx(velX), vy(velY), r(red), g(green), b(blue), radius(rad) {}
};

class ParticleSystem {
    public: 
        ParticleSystem(int qtParticles, int width, int height, FluidSolver& fluidSolver);
        void update(float dt); 
        void render();
        void addParticle(float x, float y, float vx, float vy, float radius);
        int getParticleCount() const { return particles.size(); }
    private: 
        std::vector<Particle> particles; 
        int width, height;     // for boundary collision
        FluidSolver& fluidSolver;
};

#endif