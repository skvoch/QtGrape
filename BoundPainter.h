#ifndef BOUNDPAINTER_H
#define BOUNDPAINTER_H

#include "IndexSelector.h"
#include "Utils.h"

#include <QPainter>

#include <vector>
#include <memory>

class BoundPainter
{
public:
    BoundPainter(const std::shared_ptr<IndexSelector>&selector);

    void draw(QPainter &painter,
              const QRect&rect,
              const QColor &color, int bound,
              std::vector<int>::iterator begin,
              std::vector<int>::iterator end);

    std::size_t getStylesCount();

private:
    std::shared_ptr<IndexSelector> m_selector;
    std::size_t m_styles;
};

#endif // BOUNDPAINTER_H
