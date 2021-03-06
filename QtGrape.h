#ifndef QTGRAPE_H
#define QTGRAPE_H

#include "Painter.h"

#include <iostream>
#include <bitset>

#include <QCryptographicHash>
#include <QStringView>
#include <QDebug>
#include <QImage>


class QtGrape
{
public:
    QtGrape();

    /// \brief Generate avater string
    /// \param [in] const ref QString
    /// \return QImage
    QImage generate(const QString &str);

private:
    /// \brief Getting binary sequence by string
    /// \param [in] const ref QString
    /// \return std::vector<int>
    std::vector<int> m_getBits(const QString &str );

    /// \brief Getting hash string
    /// \param [in] const ref QStirng
    /// \param [in] Hash algorithm
    /// \return std::string
    std::string m_getHash(const QString &str, QCryptographicHash::Algorithm algorithm = QCryptographicHash::Md5);

    Painter m_painter;
};

#endif // QTGRAPE_H
