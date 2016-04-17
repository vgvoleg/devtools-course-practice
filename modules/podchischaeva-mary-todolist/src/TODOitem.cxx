// Copyright 2016 Podchischaeva Mary

#include <string>

#include "TODOitem.h"

using std::string;

const int TODOitem::DEFAULT_PRIORITY_VALUE;

TODOitem::TODOitem() {
    this->priority = DEFAULT_PRIORITY_VALUE;
    this->title = "";
    this->text = "";
}

int TODOitem::getPriority() {
    return this->priority;
}

void TODOitem::setPriority(int value) {
    if (value >= MIN_PRIORITY_VALUE && value <= MAX_PRIORITY_VALUE) {
        this->priority = value;
    }
}

void TODOitem::setTitle(string value) {
    this->title = value;
}

string TODOitem::getTitle() {
    return this->title;
}

void TODOitem::setText(string value) {
    this->title = value;
}

string TODOitem::getText() {
    return this->title;
}

void TODOitem::increasePriority() {
    if (this->priority > MIN_PRIORITY_VALUE) {
        this->priority--;
    }
}

void TODOitem::decreasePriority() {
    if (this->priority < MAX_PRIORITY_VALUE) {
        this->priority++;
    }
}

TODOitem::~TODOitem() {
}
