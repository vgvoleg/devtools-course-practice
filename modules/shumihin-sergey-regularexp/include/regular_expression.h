// Copyright 2016 Sergey Shumihin

#ifndef REGULAR_EXPRESSION_H_
#define REGILAR_EXPRESSION_H_

#include <string>
#include <vector>
#include <functional>
#include <cctype>
#include <ostream>

using std::string;
using std::vector;
using std::function;
using std::ostream;

class Regex;

class Smatch : private vector<string>
{
public:
  Smatch() : vector<string>() {};
  using vector<string>::~vector;

  using vector<string>::front;
  using vector<string>::back;
  using vector<string>::operator[];

  using vector<string>::begin;
  using vector<string>::end;

  using vector<string>::size;
  using vector<string>::empty;

  friend ostream& operator<< (ostream& os, const Smatch& sm);
  friend Regex;
};

class Regex
{
public:
    Regex(const string& str);
    bool search(const string& str) const;
    bool search(const string& str, Smatch& match) const;
    bool match(const string& str) const;
    bool match(const string& str, Smatch& match) const;
private:
    vector < function<bool(char)> > functVect;
};
#endif 
