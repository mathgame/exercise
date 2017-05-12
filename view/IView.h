#ifndef I_VIEW_H
#define I_VIEW_H

class Context;
class InputMgr;
class Msg;
#include "../tools/Tools.h"

class IView
{
private:
    Context*  m_context = nullptr;
    bool m_updateScene;
public:
    IView() = default;
    virtual ~IView() = default;

    virtual void OnKeyPressed(int keyID);
    virtual void OnKeyReleased(int keyID);

    virtual void OnMousePressed(Tools::Point mousePos);
    virtual void OnMouseReleased(Tools::Point mousePos);

    virtual void Update() = 0;
    virtual void Draw() = 0;
    virtual void Show() = 0;
    virtual void Hide() = 0;
    virtual void RecieveMsg(const Msg& msg) = 0;

    virtual void SetContext(Context& context) noexcept;
    Context& GetContext() const noexcept;

    void UpdateScene();
    bool GetUpdateScene();
};

#endif //I_VIEW_H
