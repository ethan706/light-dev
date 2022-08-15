#include <light/event/window.h>

namespace light {

EventType WindowCloseEvent::GetType() const {
  return EventType::WindowClose;
}

WindowResizeEvent::WindowResizeEvent(std::array<int, 2> size)
    : size(size) {}

EventType WindowResizeEvent::GetType() const {
  return EventType::WindowResize;
}

}  // namespace light
