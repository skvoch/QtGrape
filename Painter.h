#ifndef PAINTER_H
#define PAINTER_H

#include <vector>
#include <iostream>

#include <QImage>
#include <QPainter>

#include "Utils.h"
#include "ColorSelector.h"
#include "BoundPainter.h"
#include "CenterPainter.h"

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


    QColor m_background;
    std::shared_ptr<IndexSelector> m_index;
    std::shared_ptr<ColorSelector> m_pallete;
    std::shared_ptr<CenterPainter> m_center;
    std::shared_ptr<BoundPainter>  m_bound;
};

#endif // PAINTER_H
