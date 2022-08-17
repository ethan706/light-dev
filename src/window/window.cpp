#include <light/window/window.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <light/event/keyboard.h>

namespace light {

Window::Window(std::array<unsigned int, 2> size)
    : width(width_), height(height_), title(title_),
      width_(size[0]), height_(size[1]) {
  Init();
}

Window::Window(std::array<unsigned int, 2> size, std::string title)
    : width(width_), height(height_), title(title_),
      width_(size[0]), height_(size[1]), title_(title) {
  Init();
}

Window::~Window() {
  Destroy();
}

void Window::Destroy() {
  glfwDestroyWindow(static_cast<GLFWwindow*>(window_));
}

void Window::SetSize(std::array<unsigned int, 2> size) {
  glfwSetWindowSize(static_cast<GLFWwindow*>(window_), size[0], size[1]);
  width_ = size[0];
  height_ = size[1];
}

void Window::SetTitle(std::string title) {
  glfwSetWindowTitle(static_cast<GLFWwindow*>(window_), title.c_str());
  title_ = title;
}

void Window::Update() {
  glfwPollEvents();
  glfwSwapBuffers(static_cast<GLFWwindow*>(window_));
}

void Window::Init() {
  window_ = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

  glfwMakeContextCurrent(static_cast<GLFWwindow*>(window_));
  gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

  // GLFW callbacks
  glfwSetWindowUserPointer(static_cast<GLFWwindow*>(window_), this);

  glfwSetWindowCloseCallback(static_cast<GLFWwindow*>(window_),
      [](GLFWwindow* window) {
    Window* window_ = static_cast<Window*>(glfwGetWindowUserPointer(window));

    WindowCloseEvent event;
    window_->listener.OnWindowClose(event);
  });

  glfwSetWindowSizeCallback(static_cast<GLFWwindow*>(window_),
      [](GLFWwindow* window, int width, int height) {
    Window* window_ = static_cast<Window*>(glfwGetWindowUserPointer(window));

    WindowResizeEvent event({width, height});
    window_->listener.OnWindowResize(event);
  });
}

}  // namespace light
