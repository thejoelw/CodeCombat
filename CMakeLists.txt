project(CodeCombat)
cmake_minimum_required(VERSION 2.8)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
#    set(CMAKE_BUILD_TYPE "Release")
endif(NOT CMAKE_BUILD_TYPE)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
if (APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
endif()


set(CodeCombat_sources
    src/arena.cpp
    src/window.cpp
)

set(CodeCombat_headers
    src/arena.h
    src/defs.h
    src/gl.h
    src/util/weakset.h
    src/window.h
)

include_directories(src)
add_executable(${PROJECT_NAME} src/main.cpp ${CodeCombat_sources} ${CodeCombat_headers})


# X11 dependency
find_package(X11 REQUIRED)
include_directories(${X11_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${X11_LIBRARIES})

# OpenGL dependency
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES})

# GLEW dependency
find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${GLEW_LIBRARIES})

# GLFW dependency
find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)
include_directories(${GLFW_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${OPENGL_glu_LIBRARY} ${GLFW_STATIC_LIBRARIES})
