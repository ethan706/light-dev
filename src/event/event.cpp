#include <light/event/event.h>

namespace light {

Event::Mod::Mod(int mods) {
  shift     = mods & 0x0001;
  control   = mods & 0x0002;
  alt       = mods & 0x0004;
  super     = mods & 0x0008;
  caps_lock = mods & 0x0010;
  num_lock  = mods & 0x0020;
}

int Event::Mod::ToInt() {
  return (shift     << 0 |
          control   << 1 |
          alt       << 2 |
          super     << 3 |
          caps_lock << 4 |
          num_lock  << 5);
}

}  // namespace light
