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

    int getPriority() const;
    void setPriority(int value);

    string getTitle() const;
    void setTitle(string value);

    string getText() const;
    void setText(string value);

    void increasePriority();
    void decreasePriority();

    bool operator==(const TODOitem &a) const;

    ~TODOitem();
};

#endif  // MODULES_PODCHISCHAEVA_MARY_TODOLIST_INCLUDE_TODOITEM_H_
