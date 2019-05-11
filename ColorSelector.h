#ifndef COLORSELECTOR_H
#define COLORSELECTOR_H

#include <vector>
#include <memory>

#include <QColor>
#include <QtDebug>
#include "IndexSelector.h"

class ColorSelector
{
public:
    ColorSelector(const std::shared_ptr<IndexSelector> & selector);

    QColor getColor(std::vector<int>::iterator begin, std::vector<int>::iterator end);

    std::size_t getpalleteSize();
private:
    std::vector<QColor> m_pallete;
    std::shared_ptr<IndexSelector> m_selector;
};

#endif // COLORSELECTOR_H
