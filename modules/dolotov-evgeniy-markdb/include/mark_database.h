// Copyright 2016 Dolotov Evgeniy

#ifndef MODULES_DOLOTOV_EVGENIY_MARKDB_INCLUDE_MARK_DATABASE_H_
#define MODULES_DOLOTOV_EVGENIY_MARKDB_INCLUDE_MARK_DATABASE_H_

#include <string>
#include <vector>
#include <utility>
#include <exception>

#include "include/record.h"

namespace ReturnCode {
enum {
    StudentNotFound = -7,
    StudentAlreadyExist = -6,
    SubjectNotFound = -5,
    SubjectAlreadyExist = -4,
    RecordNotFound = -3,
    RecordAlreadyExist = -2,
    WrongIndex = -1,
    Success = 0
};
};  // namespace ReturnCode

class MarkDatabase {
 public:
    int addStudent(Student student);
    int deleteStudent(Student student);
    int addSubject(Subject subject);
    int deleteSubject(Subject subject);
    int addNewRecord(Student student, Subject subject, Mark mark);
    int deleteRecord(Student student, Subject subject);
    int search(Student student, Subject subject);
    int getRecord(unsigned int indexOfRecord, Record* record);
    int deleteRecord(unsigned int indexOfRecord);
    int marksOfStudent(Student student,
                       std::vector< std::pair<Subject, Mark> >* marks);
    int marksOnSubject(Subject subject,
                       std::vector< std::pair<Student, Mark> >* marks);
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
