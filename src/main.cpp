#include <iostream>
#include "Renderer.h"

int main() {
    Renderer renderer;
    if (!renderer.init(800, 600)) return -1;

    while (!glfwWindowShouldClose(renderer.getWindow())) {
        renderer.render();
    }

    return 0;
}

