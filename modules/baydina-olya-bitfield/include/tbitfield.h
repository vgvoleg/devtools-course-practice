//Copyright 2016 Baydina Olya

#ifndef __BITFIELD_H__
#define __BITFIELD_H__

#include <iostream>

using namespace std;

typedef unsigned int TELEM;

class TBitField
{
private:
    int  BitLen;
    TELEM *pMem;
    int  MemLen;
public:
    TBitField(int len);  
    TBitField(const TBitField &bf);
    ~TBitField(); 

    int   GetMemIndex(const int n) const;
    TELEM GetMemMask(const int n) const;
    int GetMemLen(void) const;
    int GetLength(void) const;  
    void SetBit(const int n);
    void ClrBit(const int n);
    int  GetBit(const int n) const;

    bool operator==(const TBitField &bf) const;
    bool operator!=(const TBitField &bf) const;
    TBitField& operator=(const TBitField &bf);
    TBitField  operator|(const TBitField &bf);
    TBitField  operator&(const TBitField &bf);
    TBitField  operator~(void);
};

#endif
