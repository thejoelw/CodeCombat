#ifndef WINDOW_H
#define WINDOW_H

#include "gl.h"

#include "defs.h"
#include "arena.h"

#include <iostream>
#include <unistd.h>

class Window
{
public:
    Window(Arena &arena);

    ~Window();

    bool run();

protected:
    bool error = false;

    GLFWwindow *window = 0;

    Arena &arena;
};

void window_error_callback(int code, const char *str);

#endif // WINDOW_H
