#ifndef SELECT_SCREEN_VIEW_H
#define SELECT_SCREEN_VIEW_H
#include "IView.h"

#include <vector>
#include "../common/GameInfo.h"
#include "../tools/Tools.h"
using namespace Tools;

class SelectScreenView : public IView
{
private:
    std::vector<GameInfo> m_gameInfos;

    Rect CalculateFrameRect( int xPos, int yPos, int orderCount );

public:
    SelectScreenView() = default;

    void OnMousePressed(Point mousePos) final override;
    void OnMouseReleased(Point mousePos) final override;

    void OnKeyPressed(int keyID) final override;
    void OnKeyReleased(int keyID) final override;

    void Update() final override;
    void Draw() final override;
    void Show() final override;
    void Hide() final override;
    void RecieveMsg( const Msg& msg ) final override;
};

#endif //SELECT_SCREEN_VIEW_H
