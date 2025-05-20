#ifndef RENDERER_H
#define RENDERER_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Renderer {
public:
    Renderer();  
    ~Renderer();
    bool init(int width, int height);
    void render();
    void cleanup();
    GLFWwindow* getWindow() { return window; }
private:
    GLFWwindow* window;
};

#endif