#include "IView.h"
#include "app/Renderer.h"

void IView::SetContext(Context &context) noexcept
{
    m_context = &context;
}

Context &IView::GetContext() const noexcept
{
    return *m_context;
}

void IView::UpdateScene()
{
    m_updateScene = true;
}

bool IView::GetUpdateScene()
{
    if( m_updateScene )
    {
        m_updateScene = false;
        return true;
    }
    return false;
}
