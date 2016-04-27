// Copyright 2016 Dolotov Evgeniy

#ifndef MODULES_DOLOTOV_EVGENIY_MARKDB_INCLUDE_MARK_DATABASE_H_
#define MODULES_DOLOTOV_EVGENIY_MARKDB_INCLUDE_MARK_DATABASE_H_

#include <string>
#include <vector>
#include <utility>
#include <exception>

#include "include/record.h"

enum class ReturnCode {
    StudentNotFound,
    StudentAlreadyExist,
    SubjectNotFound,
    SubjectAlreadyExist,
    RecordNotFound,
    RecordAlreadyExist,
    WrongIndex,
    Success
};

class MarkDatabase {
 public:
    ReturnCode addStudent(Student student);
    ReturnCode deleteStudent(Student student);
    ReturnCode addSubject(Subject subject);
    ReturnCode deleteSubject(Subject subject);
    bool isStudentExist(Student student) const;
    bool isSubjectExist(Subject subject) const;
    ReturnCode addNewRecord(Student student, Subject subject, Mark mark);
    ReturnCode deleteRecord(Student student, Subject subject);
    ReturnCode search(Student student, Subject subject, size_t* index) const;
    ReturnCode getRecord(unsigned int indexOfRecord, Record* record) const;
    ReturnCode deleteRecord(unsigned int indexOfRecord);
    ReturnCode marksOfStudent(Student student,
                       std::vector< std::pair<Subject, Mark> >* marks) const;
    ReturnCode marksOnSubject(Subject subject,
                       std::vector< std::pair<Student, Mark> >* marks) const;
    std::vector<Student> getStudentsList() const;
    std::vector<Subject> getSubjectsList() const;
    std::vector<Record> getRecordsList() const;
    size_t numberOfStudents() const;
    size_t numberOfSubjects() const;
    size_t numberOfRecords() const;

 private:
    bool isRecordExist(Student student, Subject subject) const;
    std::vector<Student> students;
    std::vector<Subject> subjects;
    std::vector<Record> records;
};

#endif  // MODULES_DOLOTOV_EVGENIY_MARKDB_INCLUDE_MARK_DATABASE_H_
