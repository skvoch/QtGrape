#include "QtGrape.h"

QtGrape::QtGrape()
{

}

QImage QtGrape::generate(const QString &name)
{

    auto result = m_getBits(name);
    for(auto r:result) {
        std::cout << r;
    }
    std::cout << std::endl;

    return QImage();
}

std::vector<int> QtGrape::m_getBits(const QString &str)
{
    std::vector<int> result;
    const auto hash = m_getHash(str);
    const auto size = CHAR_BIT;
    result.reserve(hash.size() * size);

    for(const auto & symbol:hash) {
        std::bitset<size> bitset(static_cast<unsigned long long>(symbol));
        for(std::size_t i = 0; i < size;i++){
            result.push_back(bitset[i]);
        }
    }
    return result;
}

std::string QtGrape::m_getHash(const QString &str,QCryptographicHash::Algorithm algorithm)
{
    QCryptographicHash crypt(algorithm);
    crypt.addData(str.toLatin1());

    return crypt.result().toStdString();
}
