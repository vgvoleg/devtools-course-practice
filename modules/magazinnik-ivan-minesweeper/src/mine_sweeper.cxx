// Copyright 2016 Magaziinik Ivan

#include <ctime>
#include <stdexcept>
#include <iostream>
#include "include/mine_sweeper.h"

const int MineSweeper::GAME_STATUS_WIN = 1;
const int MineSweeper::GAME_STATUS_LOSE = -1;
const int MineSweeper::GAME_STATUS_PLAYING = 0;
const int MineSweeper::GAME_STATUS_START = 2;
const unsigned int MineSweeper::MINE = 9;
const unsigned int MineSweeper::CLOSED_CELL = 0;
const unsigned int MineSweeper::OPENED_CELL = 10;
MineSweeper::MineSweeper(unsigned int game_size,
                         unsigned int mine_count, int seed) {
    if (mine_count > game_size*game_size-1)
        throw std::invalid_argument("Invalid mine count");
    game_field = new Field(game_size);
    opened_field = new Field(game_size);
    game_status = GAME_STATUS_START;
    this->mine_count = mine_count;
    if (seed == -1)
        random_seed = (unsigned int)time(NULL);
    else
        random_seed = (unsigned int)seed;
}

MineSweeper::~MineSweeper() {
    delete game_field;
    delete opened_field;
}

void MineSweeper::place_mines(unsigned int curr_x, unsigned int curr_y) {
    unsigned int current_mine_count = 0;
    unsigned int field_size = game_field->get_field_size();
    unsigned int x = 0;
    unsigned int y = 0;
    while (current_mine_count < mine_count) {
        x = rand_r(&random_seed)%field_size;
        y = rand_r(&random_seed)%field_size;
        if (game_field->get_cell(x, y) != MINE && x != curr_x && y!= curr_y) {
            game_field->set_cell(x, y, MINE);
            current_mine_count++;
        }
    }
    fill_game_field_with_numbers();
    game_status = GAME_STATUS_PLAYING;
}

bool MineSweeper::mine(int x, int y) {
    if (x >= 0 && x < static_cast<int>(game_field->get_field_size())) {
        if (y >= 0 && y < static_cast<int>(game_field->get_field_size())) {
            if (game_field->get_cell((unsigned int)x,
                                     (unsigned int)y) == MINE) {
                return true;
            }
        }
    }
    return false;
}

bool MineSweeper::empty(int x, int y) {
    if (x >= 0 && x < static_cast<int>(game_field->get_field_size())) {
        if (y >= 0 && y < static_cast<int>(game_field->get_field_size())) {
            if (game_field->get_cell((unsigned int)x,
                                     (unsigned int)y) == OPENED_CELL) {
                return true;
            }
        }
    }
    return false;
}

void MineSweeper::fill_game_field_with_numbers() {
    unsigned int field_size = game_field->get_field_size();
    for (unsigned int i = 0; i < field_size; ++i) {
        for (unsigned int j = 0; j < field_size; ++j) {
            if (game_field->get_cell(i, j) != MINE) {
                int mines_around = 0;
                if (mine(i-1, j-1)) mines_around++;
                if (mine(i-1, j)) mines_around++;
                if (mine(i-1, j+1)) mines_around++;
                if (mine(i, j-1)) mines_around++;
                if (mine(i, j+1)) mines_around++;
                if (mine(i+1, j-1)) mines_around++;
                if (mine(i+1, j)) mines_around++;
                if (mine(i+1, j+1)) mines_around++;
                if (mines_around == 0) mines_around = 10;
                game_field->set_cell(i, j, mines_around);
            }
        }
    }
}

int MineSweeper::get_game_status() const {
    return game_status;
}

void MineSweeper::open_cell(unsigned int x, unsigned int y) {
    if (game_status == GAME_STATUS_LOSE || game_status == GAME_STATUS_WIN)
        throw std::invalid_argument("Game ended!");
    if (game_status == GAME_STATUS_START) {
        place_mines(x, y);
    }
    if (opened_field->get_cell(x, y) != 0) {
        throw std::invalid_argument("Field currently opened!");
    }
    if (mine(x, y)) {
        finalize_game();
    } else {
        clean(x, y);
        check_win();
    }
}

void MineSweeper::finalize_game() {
    for (unsigned int i = 0; i < game_field->get_field_size(); ++i) {
        for (unsigned int j = 0; j < game_field->get_field_size(); ++j) {
            if (mine(i, j)) {
                opened_field->set_cell(i, j, MINE);
            }
        }
    }
    game_status = GAME_STATUS_LOSE;
}

unsigned int MineSweeper::get_opened_field_cell(unsigned int x,
                                                unsigned int y) const {
    return opened_field->get_cell(x, y);
}

void MineSweeper::clean(int x, int y) {
    if ((x >= 0) && (x < static_cast<int>(game_field->get_field_size()))) {
        if ((y >= 0) && (y < static_cast<int>(game_field->get_field_size()))) {
            if (!opened_field->get_cell(x, y)) {
                opened_field->set_cell(x, y, game_field->get_cell(x, y));
                if (game_field->get_cell(x, y) == 10) {
                    clean(x-1, y-1);
                    clean(x-1, y);
                    clean(x-1, y+1);
                    clean(x, y-1);
                    clean(x, y+1);
                    clean(x+1, y-1);
                    clean(x+1, y);
                    clean(x+1, y+1);
                } else {
                    if (empty(x-1, y-1)) clean(x-1, y-1);
                    if (empty(x-1, y)) clean(x-1, y);
                    if (empty(x-1, y+1)) clean(x-1, y+1);
                    if (empty(x, y-1)) clean(x, y-1);
                    if (empty(x, y+1)) clean(x, y+1);
                    if (empty(x+1, y-1)) clean(x+1, y-1);
                    if (empty(x+1, y)) clean(x+1, y);
                    if (empty(x+1, y+1)) clean(x+1, y+1);
                }
            }
        }
    }
}

void MineSweeper::check_win() {
    bool is_closed_present = false;
    for (int x = 0; x < static_cast<int>(game_field->get_field_size()); ++x) {
        for (int y = 0;
             y < static_cast<int>(game_field->get_field_size()); ++y) {
            if (opened_field->get_cell(x, y) == CLOSED_CELL)
                if (game_field->get_cell(x, y) != MINE)
                    is_closed_present = true;
        }
    }
    if (!is_closed_present) {
        game_status = GAME_STATUS_WIN;
    }
}

Field MineSweeper::get_opened_field() const {
    return *opened_field;
}
