#ifndef LIGHT_EVENT_EVENT_H_
#define LIGHT_EVENT_EVENT_H_

#include <light/config.h>

namespace light {

enum class EventType {
  KeyDown,
  KeyUp,
  KeyRepeat,
  MouseMove,
  MouseDown,
  MouseUp,
  MouseScroll
};

class LIGHT_API Event {
 public:
  class Mod {
   public:
    Mod() = default;
    Mod(int mods);

    int ToInt();

    bool shift;
    bool control;
    bool alt;
    bool super;
    bool caps_lock;
    bool num_lock;
  };

  virtual EventType GetType() const = 0;

  bool handled;
};

}  // namespace light

#endif  // LIGHT_EVENT_EVENT_H_
