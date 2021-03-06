#ifndef CHECKERS_VIEW_H
#define CHECKERS_VIEW_H
#include "app/IView.h"
#include "tools/Tools.h"
#include "projects/Checkers/common/Board.h"

class CheckersView : public IView
{
private:
    Board m_board;
public:
    CheckersView() = default;

    void OnMousePressed(const Point& mousePos);

    void Update() final override;
    void Draw() final override;
    void Show() final override;
    void Hide() final override;
    void RecieveMsg( const Msg& msg ) final override;
};

#endif //CHECKERS_VIEW_H
