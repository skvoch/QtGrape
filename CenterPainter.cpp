#include "CenterPainter.h"


CenterPainter::CenterPainter(const std::shared_ptr<IndexSelector> &selector)
    :m_selector(selector)
{
    m_styles = 2;
}

void CenterPainter::draw(QPainter &painter,
                         const QRect &rect,
                         const QColor &color,
                         std::vector<int>::iterator begin,
                         std::vector<int>::iterator end)
{
    auto index = m_selector->getIndex(begin,end);

    if(index > m_styles)
        index = 0;

    switch (index) {

        case 0:
        {
            Utils::Drawing::Center::_0(painter, rect, color);
        }
        break;

        case 1:
        {
            Utils::Drawing::Center::_1(painter, rect, color);
        }
        break;

        case 2:
        {
            Utils::Drawing::Center::_2(painter, rect, color);
        }
        break;
    }
}

std::size_t CenterPainter::getStylesCount()
{
    return m_styles;
}
