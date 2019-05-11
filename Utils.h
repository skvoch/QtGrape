#ifndef UTILS_H
#define UTILS_H


#include <QPainter>

namespace Utils {

    namespace Drawing {

        class Center {
            public:

            static void _0(QPainter &painter, const QRect &rect, const QColor &color)
            {

                QPainterPath path;
                path.moveTo(rect.center().x(), rect.top());
                path.lineTo(rect.left(), rect.center().y());
                path.lineTo(rect.center().x(), rect.bottom());
                path.lineTo(rect.right(), rect.center().y());
                path.lineTo(rect.center().x(), rect.top());

                painter.fillPath(path, QBrush(color));
            }

            static void _1(QPainter &painter, const QRect &rect, const QColor &color)
            {
                const auto step = rect.width() / 3;

                QPainterPath path;
                path.moveTo(rect.left() + step, rect.top());
                path.lineTo(rect.center().x(), rect.center().y());
                path.lineTo(rect.left(), rect.top() + step);
                path.lineTo(rect.left(), rect.top());

                path.moveTo(rect.right() - step, rect.top());
                path.lineTo(rect.center().x(), rect.center().y());
                path.lineTo(rect.right(), rect.top() + step);
                path.lineTo(rect.right(), rect.top());

                path.moveTo(rect.right() - step, rect.bottom());
                path.lineTo(rect.center().x(), rect.center().y());
                path.lineTo(rect.right(), rect.bottom() - step);
                path.lineTo(rect.right(), rect.bottom());

                path.moveTo(rect.left() + step, rect.bottom());
                path.lineTo(rect.center().x(), rect.center().y());
                path.lineTo(rect.left(), rect.bottom() - step);
                path.lineTo(rect.left(), rect.bottom());

                painter.fillPath(path, QBrush(color));
            }

            static void _2(QPainter &painter, const QRect &rect, const QColor &color)
            {
                const auto step = rect.width() / 2;

                QPainterPath path;
                path.moveTo(rect.left(), rect.top());
                path.lineTo(rect.left() + step, rect.top());
                path.lineTo(rect.center());
                path.lineTo(rect.left(), rect.top());

                path.moveTo(rect.right(), rect.top());
                path.lineTo(rect.right(), rect.top() + step);
                path.lineTo(rect.center());
                path.lineTo(rect.right(), rect.top());

                path.moveTo(rect.center());
                path.lineTo(rect.right(), rect.bottom());
                path.lineTo(rect.right() - step, rect.bottom());
                path.lineTo(rect.center());

                path.moveTo(rect.center());
                path.lineTo(rect.left(), rect.bottom());
                path.lineTo(rect.left(), rect.bottom()  - step);
                path.lineTo(rect.center());



                painter.fillPath(path, QBrush(color));
            }


        };

    }

}




#endif // UTILS_H


