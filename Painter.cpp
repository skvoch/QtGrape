#include "Painter.h"

Painter::Painter()
{
    m_index = std::make_shared<IndexSelector>();

    m_pallete = std::make_shared<ColorSelector>(m_index);

    m_size = 255;
}

QImage Painter::input(std::vector<int> data)
{
    auto current = data.begin();

    const auto color = m_pallete->getColor(current, current += m_pallete->getpalleteSize());

    std::cout << "r:" << color.red() << " g:" << color.green() << " b:" << color.blue() << std::endl;

    /*QImage result(m_size, m_size, QImage::Format_RGB888);
    QPainter painter(&result);
    QPen pen;
    pen.setWidth(20);
    pen.setColor(Qt::red);
    painter.setPen(pen);
    painter.drawPoint(5,5);
    painter.end();
    result.save("/home/home/image.jpg");
    */
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
