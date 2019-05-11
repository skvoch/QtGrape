#include "Painter.h"

Painter::Painter()
{
    m_index = std::make_shared<IndexSelector>();

    m_pallete = std::make_shared<ColorSelector>(m_index);
    m_center  = std::make_shared<CenterPainter>(m_index);
    m_background.setRgb(255,255,255);
    m_size = 255;
}

QImage Painter::input(std::vector<int> data)
{
    QImage result(m_size, m_size, QImage::Format_RGB888);

    auto current = data.begin();
    const auto color = m_pallete->getColor(current, current += m_pallete->getpalleteSize());
    const auto bound = (m_size / 100) * 20;
    const auto center_rect = QRect(bound,bound,m_size - bound*2, m_size - bound*2);


    QPainter painter(&result);
    painter.fillRect(result.rect(),m_background);

    m_center->draw(painter,center_rect,color,current,current+=m_center->getStylesCount());

    result.save("/home/home/image.png","png",100);


    return QImage();
}

void Painter::setSize(int value)
{
    m_size = value;
}

int Painter::getSize() const
{
    return m_size;
}
