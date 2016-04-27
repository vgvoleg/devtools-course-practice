// Copyright 2016 Dolotov Evgeniy

#include <algorithm>
#include <vector>
#include <string>
#include <stdexcept>
#include <utility>

#include "include/mark_database.h"

using std::find;
using std::string;
using std::vector;
using std::pair;
using std::out_of_range;

bool MarkDatabase::isStudentExist(const Student& student) const {
    if (find(students.begin(), students.end(), student) == students.end()) {
        return false;
    } else {
        return true;
    }
}

bool MarkDatabase::isSubjectExist(const Subject& subject) const {
    if (find(subjects.begin(), subjects.end(), subject) == subjects.end()) {
        return false;
    } else {
        return true;
    }
}

ReturnCode MarkDatabase::addStudent(const Student& student) {
    if (!isStudentExist(student)) {
        students.push_back(student);
        return ReturnCode::Success;
    } else {
        return ReturnCode::StudentAlreadyExist;
    }
}

ReturnCode MarkDatabase::addSubject(const Subject& subject) {
    if (!isSubjectExist(subject)) {
        subjects.push_back(subject);
        return ReturnCode::Success;
    } else {
        return ReturnCode::SubjectAlreadyExist;
    }
}

ReturnCode MarkDatabase::deleteStudent(const Student& student) {
    if (isStudentExist(student)) {
        students.erase(find(students.begin(), students.end(), student));
        for (auto record = records.begin() ; record != records.end(); ) {
            if (record->student == student) {
                record = records.erase(record);
            } else {
                ++record;
            }
        }
        return ReturnCode::Success;
    } else {
        return ReturnCode::StudentNotFound;
    }
}


ReturnCode MarkDatabase::deleteSubject(const Subject& subject) {
    if (isSubjectExist(subject)) {
        subjects.erase(find(subjects.begin(), subjects.end(), subject));
        for (auto record = records.begin() ; record != records.end(); ) {
            if (record->subject == subject) {
                record = records.erase(record);
            } else {
                ++record;
            }
        }
        return ReturnCode::Success;
    } else {
        return ReturnCode::SubjectNotFound;
    }
}

bool MarkDatabase::isRecordExist(const Student& student,
                                 const Subject& subject) const {
    Record record(student, subject);
    if (find(records.begin(), records.end(), record) == records.end()) {
        return false;
    } else {
        return true;
    }
}

ReturnCode MarkDatabase::addNewRecord(const Student& student,
                                      const Subject& subject,
                                      const Mark& mark) {
    if (isStudentExist(student)) {
        if (isSubjectExist(subject)) {
            if (!isRecordExist(student, subject)) {
                records.push_back(Record(student, subject, mark));
                return ReturnCode::Success;
            } else {
                return ReturnCode::RecordAlreadyExist;
            }
        } else {
            return ReturnCode::SubjectNotFound;
        }
    } else {
        return ReturnCode::StudentNotFound;
    }
}

ReturnCode MarkDatabase::deleteRecord(const Student& student,
                                      const Subject& subject) {
    if (isRecordExist(student, subject)) {
        Record record(student, subject);
        records.erase(find(records.begin(), records.end(), record));
        return ReturnCode::Success;
    } else {
        return ReturnCode::RecordNotFound;
    }
}

ReturnCode MarkDatabase::search(const Student& student,
                                const Subject& subject, size_t* index) const {
    if (isRecordExist(student, subject)) {
        *index = distance(records.begin(),
                          find(records.begin(), records.end(),
                               Record(student, subject)));
        return ReturnCode::Success;
    } else {
        *index = -1;
        return ReturnCode::RecordNotFound;
    }
}

ReturnCode MarkDatabase::getRecord(const size_t& indexOfRecord,
                                   Record* record) const {
    if (indexOfRecord < numberOfRecords()) {
        *record = records[indexOfRecord];
        return ReturnCode::Success;
    } else {
        return ReturnCode::WrongIndex;
    }
}

ReturnCode MarkDatabase::deleteRecord(const size_t& indexOfRecord) {
    if (indexOfRecord < numberOfRecords()) {
        records.erase(records.begin()+indexOfRecord);
        return ReturnCode::Success;
    } else {
        return ReturnCode::WrongIndex;
    }
}

ReturnCode MarkDatabase::marksOfStudent(const Student& student,
                                 vector< pair<Subject, Mark> >* marks) const {
    if (isStudentExist(student)) {
        for (size_t recID = 0; recID < numberOfRecords(); recID++) {
            Record record = records[recID];
            if (record.student == student) {
                marks->push_back(std::make_pair(record.subject, record.mark));
            }
        }
        return ReturnCode::Success;
    } else {
        return ReturnCode::StudentNotFound;
    }
}

ReturnCode MarkDatabase::marksOnSubject(const Subject& subject,
                                 vector< pair<Student, Mark> >* marks) const {
    if (isSubjectExist(subject)) {
    for (size_t recordID = 0; recordID < numberOfRecords(); recordID++) {
        Record record = records[recordID];
        if (record.subject == subject) {
            marks->push_back(std::make_pair(record.student, record.mark));
        }
    }
    return ReturnCode::Success;
    } else {
        return ReturnCode::SubjectNotFound;
    }
}

vector<Student> MarkDatabase::getStudentsList() const {
    return students;
}

vector<Subject> MarkDatabase::getSubjectsList() const {
    return subjects;
}

vector<Record> MarkDatabase::getRecordsList() const {
    return records;
}

size_t MarkDatabase::numberOfStudents() const {
    return students.size();
}

size_t MarkDatabase::numberOfSubjects() const {
    return subjects.size();
}

size_t MarkDatabase::numberOfRecords() const {
    return records.size();
}

