// Copyright 2016 Dolotov Evgeniy

#include <string>

#include "include/mark_database_exception.h"

MarkDatabaseException::MarkDatabaseException(const std::string& message) {
    this->message = message;
}

RecordAlreadyExist::RecordAlreadyExist(const std::string &message) {
    this->message = message;
}

RecordNotExist::RecordNotExist(const std::string &message) {
    this->message = message;
}

StudentAlreadyExist::StudentAlreadyExist(const std::string &message) {
    this->message = message;
}

StudentNotExist::StudentNotExist(const std::string &message) {
    this->message = message;
}

SubjectAlreadyExist::SubjectAlreadyExist(const std::string &message) {
    this->message = message;
}

SubjectNotExist::SubjectNotExist(const std::string &message) {
    this->message = message;
}
