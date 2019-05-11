#include "ColorSelector.h"


ColorSelector::ColorSelector(const std::shared_ptr<IndexSelector> & selector)
    :m_selector(selector)
{
    m_pallete.reserve(10);

    m_pallete.push_back(QColor(66, 134, 244));   // 0
    m_pallete.push_back(QColor(155, 62, 232));   // 1
    m_pallete.push_back(QColor(221, 67, 232));   // 2
    m_pallete.push_back(QColor(237, 21, 100));   // 3
    m_pallete.push_back(QColor(237, 168, 21));   // 4
    m_pallete.push_back(QColor(255, 25, 0));     // 5
    m_pallete.push_back(QColor(0, 255, 140));    // 6
    m_pallete.push_back(QColor(0, 229, 255));    // 7
    m_pallete.push_back(QColor(0,0,0));          // 8
    m_pallete.push_back(QColor(224, 163, 212));  // 9

}

QColor ColorSelector::getColor(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    auto index = m_selector->getIndex(begin,end);

    if(index > m_pallete.size()) {
        index = 0;
        qCritical() << "ColorSelector::out of index";
    }

    return m_pallete.at(index);
}

std::size_t ColorSelector::getpalleteSize()
{
    return m_pallete.size();
}
