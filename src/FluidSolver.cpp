#include "FluidSolver.h"
#include <cmath>
#include <iostream>
#include <algorithm>

FluidSolver::FluidSolver(int gridSize, float viscosity, float dt)
    : N(gridSize), viscosity(viscosity), dt(dt),
      u(gridSize, std::vector<float>(gridSize, 0)), 
      v(gridSize, std::vector<float>(gridSize, 0)),
      p(gridSize, std::vector<float>(gridSize, 0)) {}

// **Step 1: Apply Diffusion (Viscosity)**
void FluidSolver::diffuseVelocity() {
    float diffusionRate = viscosity * dt;
    for (int i = 1; i < N - 1; i++) {
        for (int j = 1; j < N - 1; j++) {
            u[i][j] += diffusionRate * (u[i - 1][j] + u[i + 1][j] + u[i][j - 1] + u[i][j + 1] - 4 * u[i][j]);
            v[i][j] += diffusionRate * (v[i - 1][j] + v[i + 1][j] + v[i][j - 1] + v[i][j + 1] - 4 * v[i][j]);
        }
    }
}

// **Step 2: Improved Advection (Fluid Transport)**
void FluidSolver::advectVelocity() {
    for (int i = 1; i < N - 1; i++) {
        for (int j = 1; j < N - 1; j++) {
            float prevX = i - u[i][j] * dt;
            float prevY = j - v[i][j] * dt;

            int x0 = std::clamp(static_cast<int>(prevX), 1, N - 2);
            int y0 = std::clamp(static_cast<int>(prevY), 1, N - 2);

            // Blend old and new velocity values
            u[i][j] = 0.75f * u[i][j] + 0.25f * (u[x0][y0] + u[x0 + 1][y0]) * 0.5f;
            v[i][j] = 0.75f * v[i][j] + 0.25f * (v[x0][y0] + v[x0][y0 + 1]) * 0.5f;
        }
    }
}

// **Step 3: Vorticity Confinement (Preserve Swirls)**
void FluidSolver::applyVorticityConfinement() {
    std::vector<std::vector<float>> curl(N, std::vector<float>(N, 0));

    // Compute curl (fluid rotation)
    for (int i = 1; i < N - 1; i++) {
        for (int j = 1; j < N - 1; j++) {
            curl[i][j] = (v[i + 1][j] - v[i - 1][j]) - (u[i][j + 1] - u[i][j - 1]);
        }
    }

    // Apply vorticity force
    const float vorticityStrength = 5.0f;
    for (int i = 1; i < N - 1; i++) {
        for (int j = 1; j < N - 1; j++) {
            float forceX = vorticityStrength * (curl[i][j] - curl[i - 1][j]);
            float forceY = vorticityStrength * (curl[i][j] - curl[i][j - 1]);

            u[i][j] += forceX * dt;
            v[i][j] += forceY * dt;
        }
    }
}

// **Step 4: Enforce Incompressibility (Pressure Projection)**
void FluidSolver::projectPressure() {
    const float pressureDamping = 0.8f;

    for (int i = 1; i < N - 1; i++) {
        for (int j = 1; j < N - 1; j++) {
            float divergence = (u[i + 1][j] - u[i - 1][j] + v[i][j + 1] - v[i][j - 1]) / 2.0f;
            p[i][j] -= divergence * pressureDamping;
            u[i][j] -= p[i][j] / 2.0f;
            v[i][j] -= p[i][j] / 2.0f;
        }
    }
}

// **Step 5: Handle External Forces (Mouse Interaction)**
void FluidSolver::applyForce(int x, int y, float fx, float fy, int screenWidth, int screenHeight) {
    int gridX = (x * N) / screenWidth;
    int gridY = (y * N) / screenHeight;

    gridX = std::clamp(gridX, 1, N - 2);
    gridY = std::clamp(gridY, 1, N - 2);

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int nx = gridX + i;
            int ny = gridY + j;

            if (nx > 0 && nx < N - 1 && ny > 0 && ny < N - 1) {
                u[nx][ny] += fx / 5.0f;
                v[nx][ny] += fy / 5.0f;
            }
        }
    }
}

// **Step 6: Update Fluid State**
void FluidSolver::updateFluid() {
    diffuseVelocity();
    advectVelocity();
    applyVorticityConfinement(); // Preserve swirling motions
    projectPressure();

    // Apply damping to prevent velocity buildup
    const float fluidDamping = 0.95f;
    for (int i = 1; i < N - 1; i++) {
        for (int j = 1; j < N - 1; j++) {
            u[i][j] *= fluidDamping;
            v[i][j] *= fluidDamping;
        }
    }
}