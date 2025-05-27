# Understanding `FluidSolver.cpp` and Its Relation to the Navier-Stokes Equations

## Overview
The `FluidSolver.cpp` file implements a simplified fluid simulation using velocity and pressure fields. It follows a numerical approach to solving the **Navier-Stokes equations**, which describe the motion of incompressible fluids. These equations govern how velocity, pressure, and external forces interact to produce realistic fluid movement.

## Navier-Stokes Equations Breakdown

### 1. **Momentum Conservation (Navier-Stokes equation)**

\[
\frac{\partial \mathbf{u}}{\partial t} + (\mathbf{u} \cdot \nabla) \mathbf{u} = -\frac{1}{\rho} \nabla p + \nu \nabla^2 \mathbf{u} + \mathbf{F}
\]

- Represents the change in velocity \( \mathbf{u} \) over time.
- The term \( (\mathbf{u} \cdot \nabla) \mathbf{u} \) accounts for fluid advection.
- The \( \nu \nabla^2 \mathbf{u} \) term models viscosity diffusion.
- The \( \frac{1}{\rho} \nabla p \) term ensures pressure conservation.
- External forces \( \mathbf{F} \) such as gravity or user interactions influence motion.

### 2. **Mass Conservation (Incompressibility Constraint)**

\[
\nabla \cdot \mathbf{u} = 0
\]

- Ensures that fluid density remains constant.

## Implementation in `FluidSolver.cpp`

### 1. **Diffusion of Velocity**
Function: `diffuseVelocity()`
- Implements **viscosity effects** by diffusing velocity across neighboring grid points.
- Corresponds to the term \( \nu \nabla^2 \mathbf{u} \) in Navier-Stokes.

### 2. **Advection of Velocity**
Function: `advectVelocity()`
- Moves fluid particles by approximating fluid transport using previous velocity values.
- Models the **non-linear convection** term \( (\mathbf{u} \cdot \nabla) \mathbf{u} \).

### 3. **Pressure Projection**
Function: `projectPressure()`
- Enforces the incompressibility constraint \( \nabla \cdot \mathbf{u} = 0 \).
- Adjusts the velocity field to remove divergence.

### 4. **External Forces**
Function: `applyForce(x, y, fx, fy)`
- Adds external influence to the velocity field (user interactions, gravity).
- Corresponds to the \( \mathbf{F} \) term in Navier-Stokes.

### 5. **Fluid Update Loop**
Function: `updateFluid()`
- Sequentially executes:
  1. **Diffuse Velocity** (viscosity effects)
  2. **Advect Velocity** (fluid transport)
  3. **Project Pressure** (divergence correction)

## Conclusion
The `FluidSolver.cpp` effectively implements a numerical approximation of the Navier-Stokes equations by discretizing and iterating over grid-based velocity and pressure values. While simplified, it captures key behaviors of real-world fluid dynamics, making it a great foundation for particle-based simulations.

---

### **Tips for Proper Equation Rendering**
If you're using a markdown viewer that doesn't support LaTeX, you may need to enable math rendering explicitly. If you're on GitHub, equations in markdown will not display, but using a platform like Jupyter Notebook or VS Code extensions with MathJax will allow proper rendering.

Let me know if you need adjustments or a different format!