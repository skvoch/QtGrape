#ifndef UTILS_H
#define UTILS_H


#include <QPainter>

namespace Utils {

    namespace Drawing {


        static void chessBoard(QPainter&painter, const QRect &rect, int size, const QColor & color)
        {
            int width = (rect.width() + rect.height())/2 / size;

            for(int y = 0; y < rect.height() / width;y++) {
            for(int x = 0; x < rect.width() / width;x++) {
                if(x % 2 == 0) {
                    int shift_x = rect.x();
                    int shift_y = rect.y();

                    if(y % 2 == 0)
                        shift_x += width;
                    painter.fillRect(x * width + shift_x, y * width + shift_y,width,width,color);
                }
            }
            }
        }

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

        class Bound
        {
            public:

            static void _0(QPainter &painter, const QRect &rect,int bound, const QColor &color)
            {
                QPainterPath path;
                path.moveTo(rect.left(), rect.top() + bound);
                path.lineTo(rect.left() + bound, rect.center().y());
                path.lineTo(rect.left(), rect.bottom() - bound);

                path.moveTo(rect.right(), rect.top() + bound);
                path.lineTo(rect.right() - bound, rect.center().y());
                path.lineTo(rect.right(), rect.bottom() - bound);

                path.moveTo(rect.left() + bound, rect.bottom());
                path.lineTo(rect.center().x(), rect.bottom() - bound);
                path.lineTo(rect.right() - bound, rect.bottom());

                path.moveTo(rect.left() + bound, rect.top());
                path.lineTo(rect.center().x(), rect.top() + bound);
                path.lineTo(rect.right() - bound, rect.top());



                painter.fillPath(path, QBrush(color));
            }

            static void _1(QPainter &painter, const QRect &rect,int bound, const QColor &color)
            {
                int width = rect.width() / 4;

                QPainterPath path;

                // left
                path.moveTo(rect.left(), rect.top() + bound);
                path.lineTo(rect.left() + bound, rect.top() + bound);
                path.lineTo(rect.left(), rect.top() + bound + width);

                path.moveTo(rect.left(), rect.bottom() - bound);
                path.lineTo(rect.left() + bound, rect.bottom() - bound);
                path.lineTo(rect.left(), rect.bottom() - bound - width);

                // right

                path.moveTo(rect.right() - bound, rect.bottom() - bound);
                path.lineTo(rect.right(), rect.bottom() - bound - width);
                path.lineTo(rect.right(), rect.bottom() - bound);

                path.moveTo(rect.right() - bound, rect.top() + bound);
                path.lineTo(rect.right(), rect.top() + bound + width);
                path.lineTo(rect.right(), rect.top() + bound );

                // top
                path.moveTo(rect.left() + bound, rect.top());
                path.lineTo(rect.left() + bound, rect.top() + bound);
                path.lineTo(rect.left()  + bound + width, rect.top());

                path.moveTo(rect.right() - bound, rect.top());
                path.lineTo(rect.right() - bound, rect.top() + bound);
                path.lineTo(rect.right()  - bound - width, rect.top());

                // bottom

                path.moveTo(rect.left() + bound, rect.bottom());
                path.lineTo(rect.left() + bound, rect.bottom() - bound);
                path.lineTo(rect.left()  + bound + width, rect.bottom());


                path.moveTo(rect.right() - bound, rect.bottom());
                path.lineTo(rect.right() - bound, rect.bottom() - bound);
                path.lineTo(rect.right()  - bound - width, rect.bottom());

                painter.fillPath(path, QBrush(color));
            }


            static void _2(QPainter &painter, const QRect &rect,int bound, const QColor &color)
            {
                int size = 10;
                QPainterPath path;

                // left
                chessBoard(painter,QRect(rect.left(),rect.top()+bound,bound,rect.width() - bound - bound),size,color);

                //right
                chessBoard(painter,QRect(rect.right() - bound,rect.top()+bound,bound,rect.width() - bound - bound),size,color);

                //top
                chessBoard(painter,QRect(rect.left() + bound,rect.top(),rect.width() - bound - bound,bound),size,color);

                //bottom
                chessBoard(painter,QRect(rect.left() + bound,rect.bottom() - bound,rect.width() - bound - bound,bound),size,color);



                painter.fillPath(path, QBrush(color));
            }

        };



    }

}




#endif // UTILS_H


