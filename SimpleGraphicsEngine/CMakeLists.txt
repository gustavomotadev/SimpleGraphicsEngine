cmake_minimum_required (VERSION 3.8)

set(SDL2_DIR "E:/Programacao/SDL2/SDL2-2.0.22")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable (SimpleGraphicsEngine "SimpleGraphicsEngine.cpp" "SimpleGraphicsEngine.h" "GraphicsAPI/GraphicsAPI.h"   "GraphicsAPI/GraphicsAPI.cpp" "GraphicsAPI/SDL2/SDL2API.h" "GraphicsAPI/SDL2/SDL2API.cpp" "GraphicsLibrary/Canvas.h"  "GraphicsLibrary/RGB8BitColor.h" "GraphicsLibrary/Canvas.cpp" "GraphicsLibrary/RGB8BitColor.cpp" "Math/Math.h" "Math/Math.cpp" "Tests/Tests.h" "Tests/Tests.cpp" "GraphicsLibrary/Viewport.h" "GraphicsLibrary/Viewport.cpp")
target_link_libraries(SimpleGraphicsEngine ${SDL2_LIBRARIES})

