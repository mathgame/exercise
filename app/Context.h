#ifndef CONTEXT_H
#define CONTEXT_H

#include "Window.h"
#include "Renderer.h"
#include "ResourceMgr.h"

class Context
{
public:
    Context() = default;

    Window window;
    Renderer renderer;
    ResourceMgr resourceMgr; // TODO - make resourceMgr for everygame
};

#endif //CONTEXT_H
