#ifndef GRID_H
#define GRID_H

#include <SDL2/SDL.h>
#include <vector>
#include <string>

//TODO grid

class Grid
{
public:
    Grid() = default;

    void SetSize( int rows, int columns, int padding = 0);
    void SetFieldSize( int size );
    void AddElement( const std::string& element );

private:
    int m_fieldSize;
    int m_rows;
    int m_columns;
    int m_padding;
    std::vector<std::string> m_elements;

};

#endif //GRID_H
