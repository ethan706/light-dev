#include <light/event/keyboard.h>

namespace light {

KeyEvent::KeyEvent(KeyCode key, Mod mod)
    : key(key), mod(mod) {}

KeyDownEvent::KeyDownEvent(KeyCode key, Mod mod)
    : KeyEvent(key, mod) {}

EventType KeyDownEvent::GetType() const {
  return EventType::KeyDown;
}

KeyUpEvent::KeyUpEvent(KeyCode key, Mod mod)
    : KeyEvent(key, mod) {}

EventType KeyUpEvent::GetType() const {
  return EventType::KeyUp;
}

KeyRepeatEvent::KeyRepeatEvent(KeyCode key, Mod mod)
    : KeyEvent(key, mod) {}

EventType KeyRepeatEvent::GetType() const {
  return EventType::KeyRepeat;
}

}  // namespace light
