#include "Grid.h"
#include "app/Context.h"
void Grid::SetSize(int rows, int columns, int padding)
{
    m_rows = rows;
    m_columns = columns;
    m_padding = padding;
}

void Grid::SetFieldSize(int size)
{
    m_fieldSize = size;
}

void Grid::AddElement(const std::string &element)
{
    m_elements.push_back(element);
}
