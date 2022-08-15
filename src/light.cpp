#include <light/light.h>

#include <GLFW/glfw3.h>

namespace light {

void Init() {
  glfwInit();
}

void Shutdown() {
  glfwTerminate();
}

}  // namespace light
