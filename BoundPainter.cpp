#include "BoundPainter.h"

BoundPainter::BoundPainter(const std::shared_ptr<IndexSelector> &selector)
    :m_selector(selector)
{
    m_styles = 2;
}

void BoundPainter::draw(QPainter &painter,
                        const QRect &rect,
                        const QColor &color,
                        int bound,
                        std::vector<int>::iterator begin,
                        std::vector<int>::iterator end)
{
    auto index = m_selector->getIndex(begin,end);

    if(index > m_styles)
        index = 0;

    switch (index) {

        case 0:
        {
            Utils::Drawing::Bound::_0(painter,rect,bound,color);
        }
        break;


        case 1:
        {
            Utils::Drawing::Bound::_1(painter,rect,bound,color);
        }
        break;

        case 2:
        {
            Utils::Drawing::Bound::_2(painter,rect,bound,color);
        }
        break;









    }

}

std::size_t BoundPainter::getStylesCount()
{
    return m_styles;
}
