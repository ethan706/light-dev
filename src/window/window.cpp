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

  for (auto i : layers_) {
    i->OnUpdate();
  }
}

void Window::AttachLayer(int index, Layer* layer) {
  if (index >= 0) {
    layers_.insert(layers_.begin() + index, layer);
  } else {
    layers_.insert(layers_.end() - index + 1, layer);
  }
  layer->OnAttach();
}

void Window::DetachLayer(int index) {
  if (index >= 0) {
    layers_[index]->OnDetach();
    layers_.erase(layers_.begin() + index);
  } else {
    layers_[layers_.size() - index + 1]->OnDetach();
    layers_.erase(layers_.end() - index + 1);
  }
}

int Window::GetLayerAmount() const {
  return layers_.size();
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
