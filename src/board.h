#include "entry.h"

class Board {
    public:
        virtual void add(Entry* entry) = 0;
        virtual void print() = 0;
};