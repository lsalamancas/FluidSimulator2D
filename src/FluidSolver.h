#ifndef FLUID_SOLVER_H
#define FLUID_SOLVER_H

#include <vector>

class FluidSolver {
public:
    FluidSolver(int gridSize, float viscosity, float dt);
    
    void updateFluid();      // Update fluid simulation each frame
    void applyForce(int mouseX, int mouseY, float fx, float fy, int screenWidth, int screenHeight);  // External force input
    void setBoundary();      //  Boundary handling for fluid edges
    void applyVorticityConfinement();

    //getters
    int getGridSize() const { return N;}
    const std::vector<std::vector<float>>& getU() const { return u;}
    const std::vector<std::vector<float>>& getV() const { return v;}


private:
    int N;  // Grid resolution
    float viscosity, dt;  // Fluid properties

    std::vector<std::vector<float>> u, v;  // Velocity field (u = X, v = Y)
    std::vector<std::vector<float>> p;     //  Pressure field

    void diffuseVelocity();  //  Viscosity effect
    void advectVelocity();   // Fluid transport
    void projectPressure();  //  Enforce incompressibility
};

#endif