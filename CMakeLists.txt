cmake_minimum_required(VERSION 3.10)
project(light VERSION 0.1.0 LANGUAGES CXX)

option(BUILD_SHARED_LIBS "build shared libraries" ON)
option(BUILD_SHARED_DEPS "build shared dependencies" OFF)

# set external libs type
if (BUILD_SHARED_LIBS)
  set(LIGHT_LIB_TYPE SHARED)
else()
  set(LIGHT_LIB_TYPE STATIC)
endif()
set(BUILD_SHARED_LIBS BUILD_SHARED_DEPS)

add_subdirectory("external/glad")
add_subdirectory("external/glfw")

add_library(light ${LIGHT_LIB_TYPE}
  "src/light.cpp"
  "src/event/event.cpp"
  "src/event/keyboard.cpp"
  "src/event/mouse.cpp"
  "src/event/window.cpp"
  "src/window/window.cpp"
)

target_include_directories(light
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(light
  PRIVATE glad
  PRIVATE glfw
)

set_target_properties(light PROPERTIES
  CMAKE_CXX_STANDARD 17
  CMAKE_CXX_STANDARD_REQUIRED ON
  CMAKE_CXX_EXTENSIONS OFF
  CMAKE_CXX_VISIBILITY_PRESET hidden
)

if(MSVC)
  target_compile_options(light PRIVATE /W4)
else()
  target_compile_options(light PRIVATE -Wall -Wextra -pedantic)
endif()
