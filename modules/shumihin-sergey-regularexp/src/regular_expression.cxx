// Copyright 2016 Sergey Shumihin

#include <string>

#include "include/regular_expression.h"

using std::string;


Regex::Regex(const string& str) {
    for (auto iter = str.begin(); iter != str.end(); ++iter) {
        if ((*iter == '\\') && (next(iter) != str.end())) {
            ++iter;
            switch (*iter) {
            case('d') :
                functVect.push_back([](char symb)->bool {
                return isdigit(symb) != 0; });
                break;
            case('D') :
                functVect.push_back([](char symb)->bool {
                return isdigit(symb) == 0; });
                break;
            case('s') :
                functVect.push_back([](char symb)->bool {
                return isblank(symb) != 0; });
                break;
            case('S') :
                functVect.push_back([](char symb)->bool {
                return isblank(symb) == 0; });
                break;
            case('w') :
                functVect.push_back([](char symb)->bool {
                return isalnum(symb) != 0 || symb == '_'; });
                break;
            case('W') :
                functVect.push_back([](char symb)->bool {
                return isalnum(symb) == 0 && symb != '_'; });
                break;
            case('\\') :
                functVect.push_back([](char symb)->bool {
                return symb == '\\'; });
                break;
            }
        //  Sequences can be set only in format (amount) {a}
        } else if (*iter == '{' && *next(iter, 2) == '}' && iter != str.begin()
            && isdigit(*next(iter)) ) {
            ++iter;
            functVect.resize(
                functVect.size() + *iter -'0' - 1, functVect.back() );
            ++iter;
        } else {
            auto templSymbol = *iter;
            functVect.push_back([templSymbol](char symb)->bool {
                return templSymbol == symb; });
        }
    }
}

bool Regex::search(const string& str) const {
    bool result = false;
    if (functVect.size() != 0) {
        auto iter = functVect.begin();

        for (const char symb : str) {
            if ((*iter)(symb)) {
                ++iter;
                if (iter == functVect.end()) {
                    result = true;
                    break;
                }
            } else {
                iter = functVect.begin();
            }
        }
    }
    return result;
}

bool Regex::search(const string& str, Smatch * match) const {
    bool result = false;
    string buf = "";
    auto iter = functVect.begin();

    if ( !functVect.empty() ) {
        for (char symb : str) {
            if ((*iter)(symb)) {
                buf += symb;
                ++iter;
                if (iter == functVect.end()) {
                    iter = functVect.begin();
                    (*match).push_back(buf);
                    buf.clear();
                    result = true;
                }
            } else {
                iter = functVect.begin();
                buf.clear();
            }
        }
    }
    return result;
}

bool Regex::match(const string & str) const {
    bool result = true;
    auto iter = functVect.begin();

    if (!functVect.empty()) {
        for (auto symb = str.begin(); symb != str.end(); ++symb) {
            if ((*iter)(*symb)) {
                ++iter;
                if (iter == functVect.end()) {
                    if (next(symb) != str.end())
                        result = false;
                    iter = functVect.begin();
                }
            } else {
                iter = functVect.begin();
                result = false;
            }
        }
    }
    return result;
}

bool Regex::match(const string & str, Smatch* match) const {
  bool result = true;
  string buf = "";

  auto iter = functVect.begin();

  if ( !functVect.empty() ) {
    for (auto symb = str.begin(); symb != str.end(); ++symb) {
      if ((*iter)(*symb)) {
        buf += *symb;
        ++iter;
        if (iter == functVect.end()) {
          if (next(symb) != str.end())
            result = false;
          iter = functVect.begin();
          (*match).push_back(buf);
          buf.clear();
        }
      } else {
        iter = functVect.begin();
        buf.clear();
        result = false;
      }
    }
  }
  return result;
}

ostream& operator<< (ostream& os, const Smatch& sm) {
    for (const string str : sm)
      os << str << " ";
    return os;
}
