//
// Created by ivan on 4/22/16.
//

#include <mine_sweeper_field.h>
#include <include/mine_sweeper_field.h>
#include <stdexcept>
using std::invalid_argument;

//#include "mine_sweeper_field.h"
Field::Field(unsigned int size) {
    if (size > MAX_FIELD_LEN)
        throw invalid_argument("Invalid field len");
    field = new unsigned int*[size];
    field_size = size;
    for (unsigned int i = 0;i < size;i++) {
        field[i] = new unsigned int[size];
    }
    fill_field_with_zero_val();
}

Field::~Field() {
    for (unsigned int i = 0; i < field_size; ++i) {
        delete[] field[i];
    }
    delete[] field;
}

void Field::fill_field_with_zero_val() {
    for(unsigned int i = 0; i < field_size; i++){
        for(unsigned int j = 0; j < field_size; j++) {
            field[i][j] = 0;
        }
    }
}

unsigned int Field::get_field_size() {
    return field_size;
}

unsigned int Field::get_cell(unsigned int x, unsigned int y) {
    if(x>field_size||y>field_size)
        throw invalid_argument("invalid cell address");
    return field[x][y];
}

void Field::set_cell(unsigned int x, unsigned int y, unsigned int value) {
    if(x>field_size||y>field_size)
        throw invalid_argument("invalid cell address");
    if(value>5)
        throw invalid_argument("invalid value");
    field[x][y] = value;
}