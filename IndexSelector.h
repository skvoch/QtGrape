#ifndef INDEXSELECTOR_H
#define INDEXSELECTOR_H

#include <vector>
#include <numeric>
class IndexSelector
{
public:
    IndexSelector() = default;
    virtual ~IndexSelector() = default;

    virtual std::size_t getIndex(const std::vector<int>::iterator begin,const std::vector<int>::iterator end);
};

#endif // INDEXSELECTOR_H
