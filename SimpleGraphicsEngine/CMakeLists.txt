cmake_minimum_required (VERSION 3.8)

project(SimpleGraphicsEngine)

#get_filename_component(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)

#list(APPEND CMAKE_MODULE_PATH ${ROOT_DIR})

#message(STATUS "MENSAGEM AQUI:")
#message(STATUS ${CMAKE_MODULE_PATH})

set(SDL2_DIR "E:/Programacao/SDL2/SDL2-2.0.22")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable (SimpleGraphicsEngine "SimpleGraphicsEngine.cpp" "SimpleGraphicsEngine.h" "GraphicsAPI/GraphicsAPI.h"   "GraphicsAPI/GraphicsAPI.cpp" "GraphicsAPI/SDL2/SDL2API.h" "GraphicsAPI/SDL2/SDL2API.cpp")
target_link_libraries(SimpleGraphicsEngine ${SDL2_LIBRARIES})

