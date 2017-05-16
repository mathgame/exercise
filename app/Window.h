#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <memory>
#include "utils/Utils.h"

using WindowPtr = std::unique_ptr<SDL_Window, Utils::SDL_Deiniter>;
class Window
{
private:
    WindowPtr m_window;
    static const int m_width = 720;
    static const int m_height = 680;
public:
    Window() = default;
    void Init();
    int GetHeight();
    int GetWidth();
    SDL_Window* GetWindow() const;
};

#endif //WINDOW_H
