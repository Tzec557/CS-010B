#ifndef SORTEDSET_H
#define SORTEDSET_H

#include <ostream>
using namespace std;

#include"IntList.h"

class SortedSet : public IntList {
    public:
        SortedSet();
        SortedSet(const SortedSet &);
        SortedSet(const IntList &);
        ~SortedSet();

        bool in(int value);
        SortedSet operator|(const SortedSet &rhs);
        SortedSet operator&(const SortedSet &rhs);

        void add(int value);
        void push_front(int value);
        void push_back(int value);
        void insert_ordered(int value);
        SortedSet operator|=(const SortedSet &rhs);
        SortedSet operator&=(const SortedSet &rhs);
};

#endif