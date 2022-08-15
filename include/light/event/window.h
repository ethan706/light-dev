#ifndef LIGHT_EVENT_WINDOW_H_
#define LIGHT_EVENT_WINDOW_H_

#include <array>
#include <light/config.h>
#include <light/event/event.h>

namespace light {

class LIGHT_API WindowEvent : public Event {};

class LIGHT_API WindowCloseEvent : public WindowEvent {
 public:
  WindowCloseEvent() = default;
  EventType GetType() const override;
};

class LIGHT_API WindowResizeEvent : public WindowEvent {
 public:
  WindowResizeEvent(std::array<int, 2> size);
  EventType GetType() const override;

  std::array<int, 2> size;
};

}  // namespace light

#endif  // LIGHT_EVENT_WINDOW_H_
