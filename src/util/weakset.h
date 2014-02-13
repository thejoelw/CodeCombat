#ifndef WEAKSET_H
#define WEAKSET_H

#include <vector>

// Supports constant-time insertion and erasure. Makes no guarantees about duplicates.

template <typename Type>
class WeakSet
{
public:
    typedef typename std::vector<Type>::iterator iterator;
    typedef typename std::vector<Type>::const_iterator const_iterator;

    void insert(Type &item)
    {
        arr.push_back(item);
    }
    template <typename... Args>
    void insert(Type &item, iterator &i, Args... args)
    {
        int n = i - arr.begin();
        insert(item, args...);
        i = arr.begin() + n;
    }

    template <typename... Args>
    void erase(iterator &i, Args... args)
    {
        _erase(i, args...);
        *i = arr.back();
        arr.pop_back();
    }

    void shrink() {arr.shrink_to_fit();}

    void clear() {arr.clear();}

    iterator begin() {return arr.begin();}
    iterator end() {return arr.end();}

    const_iterator cbegin() const {return arr.cbegin();}
    const_iterator cend() const {return arr.cend();}

    Type &first() {return arr.front();}
    Type &last() {return arr.back();}

    typename std::vector<Type>::size_type empty() {return arr.empty();}
    bool size() {return arr.size();}

protected:
    std::vector<Type> arr;

private:
    template <typename... Args>
    void _erase(iterator &erased, iterator &i, Args... args)
    {
        if (i > erased) {i--;}
        _erase(erased, args...);
    }
    void _erase(iterator &erased) {}
};

#endif // WEAKSET_H
