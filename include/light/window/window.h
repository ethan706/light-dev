#ifndef LIGHT_WINDOW_WINDOW_H_
#define LIGHT_WINDOW_WINDOW_H_

#include <array>
#include <string>
#include <vector>
#include <light/config.h>
#include <light/event/listener.h>
#include <light/window/layer.h>

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

  void AttachLayer(int index, Layer* layer);
  void DetachLayer(int index);
  int GetLayerAmount() const;

  WindowEventListener listener;

  // read only
  const unsigned int &width;
  const unsigned int &height;
  const std::string &title;

 private:
  void Init();

  void* window_;
  std::vector<Layer*> layers_;

  unsigned int width_;
  unsigned int height_;
  std::string title_;
};

}  // namespace light

#endif  // LIGHT_WINDOW_WINDOW_H_
