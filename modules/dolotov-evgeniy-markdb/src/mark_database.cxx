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

bool MarkDatabase::isStudentExist(Student student) {
    if (find(students.begin(), students.end(), student) == students.end()) {
        return false;
    } else {
        return true;
    }
}

bool MarkDatabase::isSubjectExist(Subject subject) {
    if (find(subjects.begin(), subjects.end(), subject) == subjects.end()) {
        return false;
    } else {
        return true;
    }
}

int MarkDatabase::addStudent(Student student) {
    if (!isStudentExist(student)) {
        students.push_back(student);
        return ReturnCode::Success;
    } else {
        return ReturnCode::StudentAlreadyExist;
    }
}

int MarkDatabase::addSubject(Subject subject) {
    if (!isSubjectExist(subject)) {
        subjects.push_back(subject);
        return ReturnCode::Success;
    } else {
        return ReturnCode::SubjectAlreadyExist;
    }
}

int MarkDatabase::deleteStudent(Student student) {
    if (isStudentExist(student)) {
        students.erase(find(students.begin(), students.end(), student));
        vector<Record>::iterator record = records.begin();
        for ( ; record != records.end(); ) {
            if (record->student == student) {
                record = records.erase(record);
            } else {
                record++;
            }
        }
        return ReturnCode::Success;
    } else {
        return ReturnCode::StudentNotFound;
    }
}


int MarkDatabase::deleteSubject(Subject subject) {
    if (isSubjectExist(subject)) {
        subjects.erase(find(subjects.begin(), subjects.end(), subject));
        vector<Record>::iterator record = records.begin();
        for ( ; record != records.end(); ) {
            if (record->subject == subject) {
                record = records.erase(record);
            } else {
                record++;
            }
        }
        return ReturnCode::Success;
    } else {
        return ReturnCode::SubjectNotFound;
    }
}

bool MarkDatabase::isRecordExist(Student student, Subject subject) {
    Record record(student, subject);
    if (find(records.begin(), records.end(), record) == records.end()) {
        return false;
    } else {
        return true;
    }
}

int MarkDatabase::addNewRecord(Student student, Subject subject, Mark mark) {
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

int MarkDatabase::deleteRecord(Student student, Subject subject) {
    if (isRecordExist(student, subject)) {
        Record record(student, subject);
        records.erase(find(records.begin(), records.end(), record));
        return ReturnCode::Success;
    } else {
        return ReturnCode::RecordNotFound;
    }
}

int MarkDatabase::search(Student student, Subject subject) {
    if (isRecordExist(student, subject)) {
        vector<Record>::iterator record;
        record = find(records.begin(), records.end(), Record(student, subject));
        return std::distance(records.begin(), record);
    } else {
        return ReturnCode::RecordNotFound;
    }
}

int MarkDatabase::getRecord(unsigned int indexOfRecord, Record* record) {
    if (indexOfRecord < numberOfRecords()) {
        *record = records[indexOfRecord];
        return ReturnCode::Success;
    } else {
        return ReturnCode::WrongIndex;
    }
}

int MarkDatabase::deleteRecord(unsigned int indexOfRecord) {
    if (indexOfRecord < numberOfRecords()) {
        records.erase(records.begin()+indexOfRecord);
        return ReturnCode::Success;
    } else {
        return ReturnCode::WrongIndex;
    }
}

int MarkDatabase::marksOfStudent(Student student,
                                 vector< pair<Subject, Mark> >* marks) {
    if (isStudentExist(student)) {
        for (unsigned int recID = 0; recID < numberOfRecords(); recID++) {
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

int MarkDatabase::marksOnSubject(Subject subject,
                                 vector< pair<Student, Mark> >* marks) {
    if (isSubjectExist(subject)) {
    for (unsigned int recordID = 0; recordID < numberOfRecords(); recordID++) {
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

vector<Student> MarkDatabase::getStudentsList() {
    return students;
}

vector<Subject> MarkDatabase::getSubjectsList() {
    return subjects;
}

vector<Record> MarkDatabase::getRecordsList() {
    return records;
}

size_t MarkDatabase::numberOfStudents() {
    return students.size();
}

size_t MarkDatabase::numberOfSubjects() {
    return subjects.size();
}

size_t MarkDatabase::numberOfRecords() {
    return records.size();
}

