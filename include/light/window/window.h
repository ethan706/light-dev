#ifndef LIGHT_WINDOW_WINDOW_H_
#define LIGHT_WINDOW_WINDOW_H_

#include <array>
#include <string>
#include <light/config.h>
#include <light/event/listener.h>

namespace light {

class LIGHT_API Window {
 public:
  Window(std::array<unsigned int, 2> size);
  Window(std::array<unsigned int, 2> size, std::string title);
  ~Window();

  void Destroy();

  void SetSize(std::array<unsigned int, 2> size);
  void SetTitle(std::string title);

  void Update();

  WindowEventListener listener;

  // read only
  const unsigned int &width;
  const unsigned int &height;
  const std::string &title;

 private:
  void Init();

  void* window_;

  unsigned int width_;
  unsigned int height_;
  std::string title_;
};

}  // namespace light

#endif  // LIGHT_WINDOW_WINDOW_H_
