#ifndef LIGHT_CONFIG_H_
#define LIGHT_CONFIG_H_

#ifdef _WIN32
  #define LIGHT_API __declspec(dllexport)
#else
  #define LIGHT_API __attribute__((visibility("default")))
#endif

#endif  // LIGHT_CONFIG_H_
