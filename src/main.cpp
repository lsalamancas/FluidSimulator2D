#include <iostream>
#include "Renderer.h"
#include "ParticleSystem.h"
#include "FluidSolver.h"

int main() {
    int width = 800;
    int height = 600;
    FluidSolver fluidSolver(250, 0.001f, 0.016f);  // Create fluid solver
    Renderer renderer(fluidSolver, width, height);
    if (!renderer.init(800, 600)) {
        std::cerr << "Renderer initialization failed!" << std::endl;
        return -1;
    }
    
    int numberParticles = 2000;
    //Create a particlesystem
   
    ParticleSystem particleSystem(numberParticles, width, height, fluidSolver);  // Pass FluidSolver

    //add the particles 

    for (int i = 0; i < numberParticles; i++){
        particleSystem.addParticle(rand() % 800, rand() % 600, 1.0f, 1.0f, 8.0f);
    }
    
    // std::cout << "Particle count: " << particleSystem.particles.size() << std::endl;
    std::cout << "Particle count: " << particleSystem.getParticleCount() << std::endl;
    while (!glfwWindowShouldClose(renderer.getWindow())) {
        fluidSolver.updateFluid();
        particleSystem.update(0.016f); // update particles parameters (60 FPS)
        renderer.render(particleSystem); //render particles
    }

    return 0;
}

