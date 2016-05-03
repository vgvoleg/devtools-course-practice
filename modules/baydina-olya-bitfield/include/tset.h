// Copyright 2016 Baydina Olya

#ifndef MODULES_BAYDINA_OLYA_BITFIELD_INCLUDE_TSET_H_
#define MODULES_BAYDINA_OLYA_BITFIELD_INCLUDE_TSET_H_

#include "include/tbitfield.h"

class TSet {
 private:
    int MaxPower;
    TBitField BitField;
 public:
    explicit TSet(int mp);
    TSet(const TSet &s);
    explicit TSet(const TBitField &bf);
    operator TBitField();

    int GetMaxPower(void) const;
    void InsElem(const int Elem);
    void DelElem(const int Elem);
    int IsMember(const int Elem) const;

    int operator!= (const TSet &s) const;
    TSet& operator=(const TSet &s);
    TSet operator+ (const TSet &s);
    int operator== (const TSet &s) const;
    TSet operator* (const TSet &s);
    TSet operator~ (void);
};
#endif  // MODULES_BAYDINA_OLYA_BITFIELD_INCLUDE_TSET_H_

