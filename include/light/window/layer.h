#ifndef LIGHT_WINDOW_LAYER_H_
#define LIGHT_WINDOW_LAYER_H_

#include <light/config.h>

namespace light {

class LIGHT_API Layer {
 public:
  std::function<void()> OnAttach;
  std::function<void()> OnDetach;
  std::function<void()> OnUpdate;
};

}  // namespace light

#endif  // LIGHT_WINDOW_LAYER_H_
