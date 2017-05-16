#ifndef INPUT_MGR_H
#define INPUT_MGR_H

#include <unordered_map>
#include "tools/Tools.h"
#include "deque"

enum class KeyState { Pressed, Holding, Released, Default };
enum class MouseState { Pressed, Holding, Released, Default };

using ActionKeyPair = std::pair<int, KeyState>;
using ActionMousePair = std::pair<Point, MouseState>;
class InputMgr
{
private:
    std::deque<ActionKeyPair> m_keyEventMap;
    ActionMousePair m_mouseEvent;
public:
    InputMgr() = default;

    //TODO - Holding event
    bool HandleEvent();

    bool HasKeyEvent();
    ActionKeyPair PopActionKeyEvent();

    bool HasMouseEvent();
    ActionMousePair PopMouseEvent();
};

#endif //INPUT_MGR_H
