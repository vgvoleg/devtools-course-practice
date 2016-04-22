// Copyright 2016 Dolotov Evgeniy

#ifndef MODULES_DOLOTOV_EVGENIY_MARKDB_INCLUDE_RECORD_H_
#define MODULES_DOLOTOV_EVGENIY_MARKDB_INCLUDE_RECORD_H_

#include <string>

enum Mark {
    A = 5,
    B = 4,
    C = 3,
    D = 2,
    E = 1
};

typedef std::string Student;
typedef std::string Subject;

class Record {
 public:
    Record(Student student, Subject subject, Mark mark = A);
    Student student;
    Subject subject;
    Mark mark;
    bool operator==(const Record& record) const;
};

#endif  // MODULES_DOLOTOV_EVGENIY_MARKDB_INCLUDE_RECORD_H_
