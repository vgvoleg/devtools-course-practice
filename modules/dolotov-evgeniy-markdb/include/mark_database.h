// Copyright 2016 Dolotov Evgeniy

#ifndef MODULES_DOLOTOV_EVGENIY_MARKDB_INCLUDE_MARK_DATABASE_H_
#define MODULES_DOLOTOV_EVGENIY_MARKDB_INCLUDE_MARK_DATABASE_H_

#include <string>
#include <vector>
#include <utility>
#include <exception>

#include "include/mark_database_exception.h"
#include "include/record.h"

class MarkDatabase {
 public:
    void addStudent(Student student);
    void deleteStudent(Student student);
    void addSubject(Subject subject);
    void deleteSubject(Subject subject);
    void addNewRecord(Student student, Subject subject, Mark mark);
    void deleteRecord(Student student, Subject subject);
    int search(Student student, Subject subject);
    Record getRecord(unsigned int indexOfRecord);
    void deleteRecord(unsigned int indexOfRecord);
    std::vector< std::pair<Subject, Mark> > marksOfStudent(Student student);
    std::vector< std::pair<Student, Mark> > marksOnSubject(Subject subject);
    std::vector<Student> getStudentsList();
    std::vector<Subject> getSubjectsList();
    std::vector<Record> getRecordsList();
    size_t numberOfStudents();
    size_t numberOfSubjects();
    size_t numberOfRecords();

 private:
    bool isRecordExist(Student student, Subject subject);
    bool isStudentExist(Student student);
    bool isSubjectExist(Subject subject);
    std::vector<Student> students;
    std::vector<Subject> subjects;
    std::vector<Record> records;
};

#endif  // MODULES_DOLOTOV_EVGENIY_MARKDB_INCLUDE_MARK_DATABASE_H_
