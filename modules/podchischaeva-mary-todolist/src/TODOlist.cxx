// Copyright 2016 Podchischaeva Mary

#include "TODOlist.h"
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::exception;
using std::ifstream;
using std::ofstream;
using std::vector;
using std::string;

TODOlist::TODOlist() {
}

void TODOlist::addItem(TODOitem value) {
    this->data.push_back(value);
}

void TODOlist::addItem(string title) {
    TODOitem temp;
    temp.setTitle(title);
    this->data.push_back(temp);
}

size_t TODOlist::size() {
    return this->data.size();
}

TODOitem TODOlist::getItem(size_t pos) {
    if ((pos > data.size() - 1) || (pos < 0)) {
        throw std::out_of_range("Out of range!");
    } else {
        return data[pos];
    }
}

vector<TODOitem> TODOlist::getAll() {
    return this->data;
}

vector<TODOitem> TODOlist::getByPriority(int priority) {
    vector<TODOitem> res;
    for (size_t i = 0; i < data.size(); ++i) {
        if (data[i].getPriority() == priority) {
            res.push_back(data[i]);
        }
    }
    return res;
}

int TODOlist::search(string title) {
    int res = -1;
    for (size_t i = 0; i < data.size(); ++i) {
        if (data[i].getTitle() == title) {
            res = i;
            break;
        }
    }
    return res;
}

void TODOlist::save(string filename) {
    ofstream file;
    file.open(filename);
    file << data.size() << "\n";
    for (size_t i = 0; i < data.size(); ++i) {
        file << data[i].getPriority() << "\n";
        file << data[i].getTitle() << "\n";
        file << data[i].getText() << "\n";
    }
    file.close();
}

void TODOlist::load(string filename) {
    ifstream file;
    file.open(filename);
    size_t size;
    file >> size;
    file.get();
    data.clear();
    data.resize(size);
    for (size_t i = 0; i < size; ++i) {
        int p;
        file >> p;
        file.get();
        string line1, line2;
        std::getline(file, line1);
        std::getline(file, line2);
        TODOitem item;
        item.setPriority(p);
        item.setTitle(line1);
        item.setText(line2);
        data[i] = item;
    }
}

void TODOlist::deleteItem(size_t pos) {
    if ((pos > data.size() - 1) || (pos < 0)) {
        throw std::out_of_range("Out of range!");
    } else {
        vector<TODOitem>::iterator it = data.begin();
        std::advance(it, pos - 1);
        data.erase(it);
    }
}

TODOlist::~TODOlist() {
}
