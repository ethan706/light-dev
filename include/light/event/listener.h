#ifndef LIGHT_EVENT_LISTENER_H_
#define LIGHT_EVENT_LISTENER_H_

#include <functional>
#include <light/config.h>
#include <light/event/keyboard.h>
#include <light/event/mouse.h>
#include <light/event/window.h>

namespace light {

class LIGHT_API EventListener {
 public:
  std::function<void(KeyDownEvent&)> OnKeyDown;
  std::function<void(KeyUpEvent&)> OnKeyUp;
  std::function<void(KeyRepeatEvent&)> OnKeyRepeat;

  std::function<void(MouseMoveEvent&)> OnMouseMove;
  std::function<void(MouseDownEvent&)> OnMouseDown;
  std::function<void(MouseUpEvent&)> OnMouseUp;
  std::function<void(MouseScrollEvent&)> OnMouseScroll;
};

class LIGHT_API WindowEventListener {
 public:
  std::function<void(WindowCloseEvent&)> OnWindowClose;
  std::function<void(WindowResizeEvent&)> OnWindowResize;
};

}  // namespace light

#endif  // LIGHT_EVENT_LISTENER_H_
