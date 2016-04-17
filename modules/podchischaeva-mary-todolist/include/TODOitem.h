// Copyright 2016 Pidchishaeva Mary
#ifndef MODULES_PODCHISCHAEVA_MARY_TODOLIST_INCLUDE_TODOITEM_H_
#define MODULES_PODCHISCHAEVA_MARY_TODOLIST_INCLUDE_TODOITEM_H_

#include <string>

using std::string;

class TODOitem {
 private:
    int priority;
    string title;
    string text;
    static const int MIN_PRIORITY_VALUE = 0;
    static const int MAX_PRIORITY_VALUE = 5;

 public:
    static const int DEFAULT_PRIORITY_VALUE = 3;

    TODOitem();

    int getPriority();
    void setPriority(int value);

    string getTitle();
    void setTitle(string value);

    string getText();
    void setText(string value);

    void increasePriority();
    void decreasePriority();

    ~TODOitem();
};

#endif  // MODULES_PODCHISCHAEVA_MARY_TODOLIST_INCLUDE_TODOITEM_H_
