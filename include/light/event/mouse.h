#ifndef LIGHT_EVENT_MOUSE_H_
#define LIGHT_EVENT_MOUSE_H_

#include <array>
#include <light/config.h>
#include <light/event/event.h>

namespace light {

enum class MouseButton {
  // using GLFW mouse buttons
  Left,
  Right,
  Middle,
  Button4,
  Button5,
  Button6,
  Button7,
  Button8
};

class LIGHT_API MouseEvent : public Event {
 public:
  MouseEvent(std::array<double, 2> pos);

  std::array<double, 2> pos;
};

class LIGHT_API MouseMoveEvent : public MouseEvent {
 public:
  MouseMoveEvent(std::array<double, 2> pos);
  EventType GetType() const override;
};

class LIGHT_API MouseDownEvent : public MouseEvent {
 public:
  MouseDownEvent(std::array<double, 2> pos, MouseButton button, Mod mod);
  EventType GetType() const override;

  MouseButton button;
  Mod mod;
};

class LIGHT_API MouseUpEvent : public MouseEvent {
 public:
  MouseUpEvent(std::array<double, 2> pos, MouseButton button, Mod mod);
  EventType GetType() const override;

  MouseButton button;
  Mod mod;
};

class LIGHT_API MouseScrollEvent : public MouseEvent {
 public:
  MouseScrollEvent(std::array<double, 2> pos, std::array<double, 2> offset);
  EventType GetType() const override;

  std::array<double, 2> offset;
};

}  // namespace light

#endif  // LIGHT_EVENT_MOUSE_H_
