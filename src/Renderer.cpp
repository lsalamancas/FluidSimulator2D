#include "Renderer.h"
#include <iostream>
#include "ParticleSystem.h"

FluidSolver* Renderer::fluidSolverPtr = nullptr;  // Initialize static pointer
int Renderer::screenWidth = 0;
int Renderer::screenHeight = 0;

Renderer::Renderer(FluidSolver& solver, int width, int height) : window(nullptr) {
    fluidSolverPtr = &solver;  // Set pointer to FluidSolver instance
    screenWidth = width;
    screenHeight = height;

}

Renderer::~Renderer() {
    cleanup();
}

bool Renderer::init(int w, int h) { 
    screenWidth = w;  // ✅ Assign values to class members
    screenHeight = h; 
    if (!glfwInit()){
        std::cerr << "Failed to init GLFW\n";
        return false;
    }
    window = glfwCreateWindow(screenWidth, screenHeight, "Fluid Simulation", nullptr, nullptr);
    if (!window){
        std::cerr<< "Failed to create GLFW window\n";
        glfwTerminate();
        return false; 
    }
    

    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW\n";
        return false;
    }

    this->setupProjection(); 

    glDisable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);
    glDisable(GL_BLEND);

     // **Register the mouse callback**
    glfwSetMouseButtonCallback(window, mouseCallback);


    return true;
}

void Renderer::mouseCallback(GLFWwindow* window, int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);

        float forceX = 10.0f;  // Stronger force for better visibility
        float forceY = 10.0f;

        if (fluidSolverPtr) {
            fluidSolverPtr->applyForce(static_cast<int>(xpos), static_cast<int>(ypos), forceX, forceY, screenWidth, screenHeight);
        } else {
            std::cerr << "Error: fluidSolverPtr is null!" << std::endl;
        }
    }
}

void Renderer::setupProjection() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, screenWidth, 0, screenHeight, -1, 1);  // Set coordinate range
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glViewport(0, 0, screenWidth, screenHeight);
}

void Renderer::render(ParticleSystem& particleSystem){
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Dark gray background

    glClear(GL_COLOR_BUFFER_BIT); //clear the screen

    particleSystem.render(); //render the particleSystem

    glfwSwapBuffers(window); // Swap buffers  
    glfwPollEvents(); // Process window events 
}

void Renderer::cleanup(){
    glfwDestroyWindow(window);
    glfwTerminate();
}