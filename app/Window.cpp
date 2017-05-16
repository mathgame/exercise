#include "Window.h"
#include "utils/Utils.h"

void Window::Init()
{
    m_window = WindowPtr(SDL_CreateWindow( "exercise", 100, 100, m_width, m_height, 0));
}

int Window::GetHeight()
{
    return m_height;
}

int Window::GetWidth()
{
    return m_width;
}

SDL_Window *Window::GetWindow() const
{
    return m_window.get();
}
