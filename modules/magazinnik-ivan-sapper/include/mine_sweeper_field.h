// Copyright 2016 Magaziinik Ivan

#ifndef MODULES_MAGAZINNIK_IVAN_MINE_SWEEPER_H_
#define MODULES_MAGAZINNIK_IVAN_MINE_SWEEPER_H_

class Field {
private:
    unsigned int **field;
    unsigned int field_size;
    void fill_field_with_zero_val();
public:
    int static const MAX_FIELD_LEN = 100;
    Field(unsigned int size = 10);
    ~Field();
    unsigned int get_field_size();
    unsigned int get_cell(unsigned int x, unsigned int y);
    void set_cell(unsigned int x, unsigned int y, unsigned int value);
};


#endif  //MODULES_MAGAZINNIK_IVAN_MINE_SWEEPER_H_
