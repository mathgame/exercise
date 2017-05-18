#ifndef TIC_TAC_VIEW_H
#define TIC_TAC_VIEW_H
#include "app/IView.h"

#include <vector>
#include "tools/Tools.h"
#include "../common/Board.h"

class TicTacView : public IView
{
private:
    Board m_board;

//    void DrawComputerDiffculty();
    void DrawChoiceFrame();
    void DrawBoard();
public:
    TicTacView() = default;

    void OnMousePressed(const Point& pos);

    void Update() final override;
    void Draw() final override;
    void Show() final override;
    void Hide() final override;
    void RecieveMsg( const Msg& msg ) final override;
};

#endif //TIC_TAC_VIEW_H
