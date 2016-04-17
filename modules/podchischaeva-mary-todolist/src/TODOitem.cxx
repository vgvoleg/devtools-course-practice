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

int TODOitem::getPriority() const {
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

string TODOitem::getTitle() const {
    return this->title;
}

void TODOitem::setText(string value) {
    this->text = value;
}

string TODOitem::getText() const {
    return this->text;
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

bool TODOitem::operator==(const TODOitem &a) const {
    if (this->title != a.getTitle()) {
        return false;
    } else if (this->text != a.getText()) {
        return false;
    } else if (this->priority != a.getPriority()) {
        return false;
    } else {
        return true;
    }
}

TODOitem::~TODOitem() {
}
