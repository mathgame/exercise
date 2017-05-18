#ifndef SELECT_SCREEN_VIEW_H
#define SELECT_SCREEN_VIEW_H
#include "app/IView.h"

#include <vector>
#include "projects/SelectScreen/common/GameInfo.h"
#include "geometry/Rect.h"

class SelectScreenView : public IView
{
private:
    std::vector<GameInfo> m_gameInfos;
    //TODO make it in tools as ready structure.
    Rect CreateRectByOrderCount( int xPos, int yPos, int cellCount );

public:
    SelectScreenView() = default;

    void OnMousePressed(const Point& mousePos);

    void Update() final override;
    void Draw() final override;
    void Show() final override;
    void Hide() final override;
    void RecieveMsg( const Msg& msg ) final override;
};

#endif //SELECT_SCREEN_VIEW_H
