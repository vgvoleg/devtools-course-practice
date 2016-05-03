// Copyright 2016 Baydina Olya

#include "include/tset.h"
#include "include/tbitfield.h"

TSet::TSet(int mp) : BitField(mp), MaxPower(mp) {
}

TSet::TSet(const TSet &s) : BitField(s.BitField), MaxPower(s.MaxPower) {
}

TSet::TSet(const TBitField &bf) : BitField(bf), MaxPower(bf.GetLength()) {
}

TSet::operator TBitField() {
	return TBitField(MaxPower);
}

int TSet::GetMaxPower(void) const {
	return MaxPower;
}

int TSet::IsMember(const int Elem) const {
	return BitField.GetBit(Elem);
}

void TSet::InsElem(const int Elem) {
	BitField.SetBit(Elem);
}

void TSet::DelElem(const int Elem) {
	BitField.ClrBit(Elem);
}

TSet& TSet::operator=(const TSet &s) {
	BitField = s.BitField;
	MaxPower = s.MaxPower;

	return *this;
}

int TSet::operator==(const TSet &s) const {
	return (BitField == s.BitField);
}

int TSet::operator!=(const TSet &s) const {
	return (BitField != s.BitField);
}

TSet TSet::operator+(const TSet &s) {
	return (BitField | s.BitField);
}

TSet TSet::operator*(const TSet &s) {
	return (BitField & s.BitField);
}

TSet TSet::operator~(void) {
	return (~BitField);
}


