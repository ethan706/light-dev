#include <light/event/mouse.h>

namespace light {

MouseEvent::MouseEvent(std::array<double, 2> pos)
    : pos(pos) {}

MouseMoveEvent::MouseMoveEvent(std::array<double, 2> pos)
    : MouseEvent(pos) {}

EventType MouseMoveEvent::GetType() const {
  return EventType::MouseMove;
}

MouseDownEvent::MouseDownEvent(std::array<double, 2> pos,
                               MouseButton button, Mod mod)
    : MouseEvent(pos), button(button), mod(mod) {}

EventType MouseDownEvent::GetType() const {
  return EventType::MouseDown;
}

MouseUpEvent::MouseUpEvent(std::array<double, 2> pos,
                           MouseButton button, Mod mod)
    : MouseEvent(pos), button(button), mod(mod) {}

EventType MouseUpEvent::GetType() const {
  return EventType::MouseUp;
}

MouseScrollEvent::MouseScrollEvent(std::array<double, 2> pos,
                                   std::array<double, 2> offset)
    : MouseEvent(pos), offset(offset) {}

EventType MouseScrollEvent::GetType() const {
  return EventType::MouseScroll;
}

}  // namespace light
