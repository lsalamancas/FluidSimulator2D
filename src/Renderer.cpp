#include "Renderer.h"
#include <iostream>

Renderer::Renderer() : window(nullptr){}

Renderer::~Renderer() {
    cleanup();
}

bool Renderer::init(int width, int height){
    if (!glfwInit()){
        std::cerr << "Failed to init GLFW\n";
        return false;
    }
    window = glfwCreateWindow(width, height, "Fluid Simulation", nullptr, nullptr);
    if (!window){
        std::cerr<< "Failed to create GLFW window\n";
        glfwTerminate();
        return false; 
    }

    glfwMakeContextCurrent(window);
    glewInit();
    return true;
}

void Renderer::render(){
    glClear(GL_COLOR_BUFFER_BIT); //clear the screen

    // TODO: add fluid visualization rendering logic here

    glfwSwapBuffers(window); // Swap buffers  
    glfwPollEvents(); // Process window events 
}

void Renderer::cleanup(){
    glfwDestroyWindow(window);
    glfwTerminate();
}