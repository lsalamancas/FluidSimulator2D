#ifndef RENDERER_H
#define RENDERER_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "ParticleSystem.h"

class Renderer {
public:
    Renderer(FluidSolver& solver, int width, int height);  
    ~Renderer();
    bool init(int width, int height);
    void render(ParticleSystem& particleSystem);    
    void cleanup();
    void setupProjection();
    static void mouseCallback(GLFWwindow* window, int button, int action, int mods);
    GLFWwindow* getWindow() { return window; }
private:
    GLFWwindow* window;
    static int screenWidth, screenHeight; // store window dimensions
    // Static pointer to FluidSolver
    static FluidSolver* fluidSolverPtr;

};

#endif