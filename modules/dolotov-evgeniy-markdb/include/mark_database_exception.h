// Copyright 2016 Dolotov Evgeniy

#ifndef MODULES_DOLOTOV_EVGENIY_MARKDB_INCLUDE_MARK_DATABASE_EXCEPTION_H_
#define MODULES_DOLOTOV_EVGENIY_MARKDB_INCLUDE_MARK_DATABASE_EXCEPTION_H_

#include <exception>
#include <string>

class MarkDatabaseException : public std::exception {
 public:
    explicit MarkDatabaseException(const std::string& message = "Error!");
 protected:
    std::string message;
};

class RecordAlreadyExist : public MarkDatabaseException {
 public:
    explicit RecordAlreadyExist(const std::string& message);
};

class RecordNotExist : public MarkDatabaseException {
 public:
    explicit  RecordNotExist(const std::string& message);
};

class StudentNotExist : public MarkDatabaseException {
 public:
    explicit StudentNotExist(const std::string& message);
};

class StudentAlreadyExist : public MarkDatabaseException {
 public:
    explicit StudentAlreadyExist(const std::string& message);
};

class SubjectAlreadyExist : public MarkDatabaseException {
 public:
    explicit SubjectAlreadyExist(const std::string& message);
};

class SubjectNotExist : public MarkDatabaseException {
 public:
    explicit SubjectNotExist(const std::string& message);
};

#endif  // MODULES_DOLOTOV_EVGENIY_MARKDB_INCLUDE_MARK_DATABASE_EXCEPTION_H_
