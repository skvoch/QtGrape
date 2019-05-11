#ifndef PAINTER_H
#define PAINTER_H

#include <vector>
#include <iostream>

#include <QImage>
#include <QPainter>

#include "ColorSelector.h"

class Painter
{
public:
    Painter();

    /// \brief Drawing avatar by binary sequence
    /// \param [in] const ref std::vector<int>
    /// \return QImage
    QImage input(std::vector<int> data);

    /// \brief Setting result image size (width and height)
    /// \param [in] value
    void setSize(int value);

    /// \brief Getting current image size (width and height)
    /// \return value
    int getSize() const;
private:
    int m_size;

    std::shared_ptr<IndexSelector> m_index;
    std::shared_ptr<ColorSelector> m_pallete;
};

#endif // PAINTER_H
