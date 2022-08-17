#ifndef LIGHT_LIGHT_H_
#define LIGHT_LIGHT_H_

#include <light/config.h>

#include <light/event/event.h>
#include <light/event/keyboard.h>
#include <light/event/listener.h>
#include <light/event/mouse.h>
#include <light/event/window.h>

#include <light/window/window.h>

namespace light {

LIGHT_API void Init();
LIGHT_API void Shutdown();

}  // namespace light

#endif  // LIGHT_LIGHT_H_
