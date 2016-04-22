// Copyright 2016 Magaziinik Ivan

#include <gtest/gtest.h>

#include "include/mine_sweeper.h"

TEST(MINEsweeper, can_create) {
    // Arrange
    MineSweeper* game;

    // Act
    game = new MineSweeper();

    // Assert
    EXPECT_NE(nullptr, game);
    delete game;
}

TEST(MINEsweeper, throwing_when_initialise_with_wrong_mine_count) {
    // Arrange & Act & Assert
    EXPECT_THROW(MineSweeper(10, 100), std::invalid_argument);
}

TEST(MINEsweeper, can_get_status) {
    // Arrange
    MineSweeper* game;

    // Act
    game = new MineSweeper();

    // Assert
    EXPECT_EQ(MineSweeper::GAME_STATUS_START, game->get_game_status());
    delete game;
}

TEST(MINEsweeper, can_finalise_game) {
    // Arrange
    MineSweeper* game;
    unsigned int mine_x_pos = 1;
    unsigned int mine_y_pos = 6;
    // Act
    game = new MineSweeper(10, 10, 0);
    game->open_cell(0, 0);
    game->open_cell(mine_x_pos, mine_y_pos);
    // Assert
    EXPECT_EQ(MineSweeper::GAME_STATUS_LOSE, game->get_game_status());
    delete game;
}

TEST(MINEsweeper, can_get_opened_field_cell) {
    // Arrange
    MineSweeper* game;
    unsigned int mine_x_pos = 1;
    unsigned int mine_y_pos = 6;

    // Act
    game = new MineSweeper(10, 10, 0);
    game->open_cell(0, 0);
    game->open_cell(mine_x_pos, mine_y_pos);
    game->get_opened_field_cell(mine_x_pos, mine_y_pos);
    // Assert
    EXPECT_EQ(0, 0);
    delete game;
}

TEST(MINEsweeper, throw_when_continue_game_after_ends) {
    // Arrange
    MineSweeper* game;
    unsigned int mine_x_pos = 1;
    unsigned int mine_y_pos = 6;

    // Act
    game = new MineSweeper(10, 10, 0);
    game->open_cell(0, 0);
    game->open_cell(mine_x_pos, mine_y_pos);

    // Assert
    EXPECT_THROW(game->open_cell(1, 1), std::invalid_argument);
}

TEST(MINEsweeper, throws_when_try_to_open_opened_cell) {
    // Arrange
    MineSweeper* game;

    // Act
    game = new MineSweeper();
    game->open_cell(0, 0);
    // Assert
    EXPECT_THROW(game->open_cell(0, 0), std::invalid_argument);
}

bool is_in_massive(int x, int y, int size) {
    int x_mine_poses[10] = {7, 2, 4, 3, 2, 4, 4, 6, 1, 9};
    int y_mine_poses[10] = {1, 2, 2, 3, 4, 3, 9, 7, 6, 1};
    for (int i = 0; i < size; ++i) {
        if (x == x_mine_poses[i] && y == y_mine_poses[i]) {
            return true;
        }
    }
    return false;
}

void win_game(MineSweeper* game, int size) {
    game->open_cell(0, 0);
    for (int x = 0; x < size; ++x) {
        for (int y = 0; y < size; ++y) {
            if (is_in_massive(x, y, size)) {
                continue;
            } else {
                if (x == 0 && y == 0) {
                    continue;
                } else {
                    game->open_cell(x, y);
                }
            }
        }
    }
}

TEST(MINEsweeper, can_win_game) {
    // Arrange
    MineSweeper* game;
    int size = 10;

    // Act
    game = new MineSweeper(size, size, 0);
    win_game(game, size);

    // Assert
    EXPECT_EQ(MineSweeper::GAME_STATUS_WIN, game->get_game_status());
}

TEST(MINEsweeper, can_get_played_status) {
    // Arrange
    MineSweeper* game;

    // Act
    game = new MineSweeper();
    game->open_cell(1, 1);

    // Assert
    EXPECT_EQ(MineSweeper::GAME_STATUS_PLAYING, game->get_game_status());
}

TEST(MINEsweeper, can_get_opened_fild_fill) {
    // Arrange
    MineSweeper* game;
    unsigned int x = 1;
    unsigned int y = 1;
    unsigned int expected_val = 0;
    // Act
    game = new MineSweeper();
    game->open_cell(x, y);

    // Assert
    EXPECT_NE(expected_val, game->get_opened_field_cell(x, y));
}
