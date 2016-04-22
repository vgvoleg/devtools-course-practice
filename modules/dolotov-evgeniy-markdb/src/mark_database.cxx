// Copyright 2016 Dolotov Evgeniy

#include "include/mark_database.h"
#include <algorithm>
#include <vector>
#include <string>
#include <stdexcept>
#include <utility>

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

void MarkDatabase::addStudent(Student student) {
    if (!isStudentExist(student)) {
        students.push_back(student);
    } else {
        throw StudentAlreadyExist("Student "+student+" already exist!");
    }
}

void MarkDatabase::addSubject(Subject subject) {
    if (!isSubjectExist(subject)) {
        subjects.push_back(subject);
    } else {
        throw SubjectAlreadyExist("Subject "+subject+" already exist!");
    }
}

void MarkDatabase::deleteStudent(Student student) {
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
    } else {
        throw StudentNotExist("Student "+student+" not exist!");
    }
}


void MarkDatabase::deleteSubject(Subject subject) {
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
    } else {
        throw SubjectNotExist("Subject "+subject+" not exist!");
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

void MarkDatabase::addNewRecord(Student student, Subject subject, Mark mark) {
    if (isStudentExist(student)) {
        if (isSubjectExist(subject)) {
            if (!isRecordExist(student, subject)) {
                records.push_back(Record(student, subject, mark));
            } else {
                throw RecordAlreadyExist("Record about student "
                                         +student+
                                         " and subject "
                                         +subject+
                                         " already exist!");
            }
        } else {
            throw SubjectNotExist("Subject "+subject+" not exist!");
        }
    } else {
        throw StudentNotExist("Student "+student+" not exist!");
    }
}

void MarkDatabase::deleteRecord(Student student, Subject subject) {
    if (isRecordExist(student, subject)) {
        Record record(student, subject);
        records.erase(find(records.begin(), records.end(), record));
    } else {
        throw RecordNotExist("Record about student "
                             +student+
                             " and subject "
                             +subject+
                             " not exist!");
    }
}

int MarkDatabase::search(Student student, Subject subject) {
    if (isRecordExist(student, subject)) {
        vector<Record>::iterator record;
        record = find(records.begin(), records.end(), Record(student, subject));
        return std::distance(records.begin(), record);
    } else {
        throw RecordNotExist("Record about student "
                             +student+
                             " and subject "
                             +subject+
                             " not exist!");
    }
}

Record MarkDatabase::getRecord(unsigned int indexOfRecord) {
    if (indexOfRecord < numberOfRecords()) {
        return records[indexOfRecord];
    } else {
        throw out_of_range("Index is out of range!");
    }
}

void MarkDatabase::deleteRecord(unsigned int indexOfRecord) {
    if (indexOfRecord < numberOfRecords()) {
        records.erase(records.begin()+indexOfRecord);
    } else {
        throw out_of_range("Index is out of range!");
    }
}

vector< pair<Subject, Mark> > MarkDatabase::marksOfStudent(Student student) {
    if (isStudentExist(student)) {
        vector< pair<Subject, Mark> > marks;
        for (unsigned int recID = 0; recID < numberOfRecords(); recID++) {
            Record record = records[recID];
            if (record.student == student) {
                marks.push_back(std::make_pair(record.subject, record.mark));
            }
        }
        return marks;
    } else {
         throw StudentNotExist("Student "+student+" not exist!");
    }
}

vector< pair<Student, Mark> > MarkDatabase::marksOnSubject(Subject subject) {
    if (isSubjectExist(subject)) {
    vector< pair<Student, Mark> > marks;
    for (unsigned int recordID = 0; recordID < numberOfRecords(); recordID++) {
        Record record = records[recordID];
        if (record.subject == subject) {
            marks.push_back(std::make_pair(record.student, record.mark));
        }
    }
    return marks;
    } else {
        throw SubjectNotExist("Subject "+subject+" not exist!");
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

