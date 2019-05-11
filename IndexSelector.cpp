#include "IndexSelector.h"


std::size_t IndexSelector::getIndex(const std::vector<int>::iterator begin, const std::vector<int>::iterator end)
{
    int result = 0;
    auto current = begin;
    while (current != end) {
        current++;

        result+=*current;
    }
    return result;
}
