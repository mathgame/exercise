#ifndef I_VIEW_H
#define I_VIEW_H

#include "geometry/Point.h"
#include <memory>

class Context;
class InputMgr;
class Msg;


class IView
{
private:
    Context* m_context = nullptr;
    bool m_updateScene;
public:
    IView() = default;
    virtual ~IView() = default;

    virtual void OnKeyPressed(int keyID);
    virtual void OnKeyReleased(int keyID);

    virtual void OnMousePressed(Point mousePos);
    virtual void OnMouseReleased(Point mousePos);

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
using IViewPtr = std::shared_ptr<IView>;

#endif //I_VIEW_H
