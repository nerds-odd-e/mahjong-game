#include "CppUTest/TestHarness.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

extern "C" {
#include "exercise_3.h"
#include "fff.h"
}

DEFINE_FFF_GLOBALS
FAKE_VALUE_FUNC1(int, user_data_find, int)
FAKE_VALUE_FUNC1(int, user_data_get_score, int)
FAKE_VOID_FUNC1(user_data_add, int)
FAKE_VOID_FUNC2(user_data_set_score, int, int)

TEST_GROUP(player_wins) {

    int player_id;
    void setup() {
        player_id = 10;
        RESET_FAKE(user_data_find)
    }

    void given_user_data_not_found() {
        user_data_find_fake.return_val = 0;
    }

    void given_user_data_found() {
        user_data_find_fake.return_val = 1;
    }

    void given_user_data_get_score(int score) {
        user_data_get_score_fake.return_val = score;
    }

};

TEST(player_wins, addUserIfNotFound) {
    given_user_data_not_found();

    player_wins(player_id);

    CHECK_EQUAL(1, user_data_add_fake.call_count)
}

TEST(player_wins, notAddUserIfFound) {
    given_user_data_found();

    player_wins(player_id);

    CHECK_EQUAL(0, user_data_add_fake.call_count)
}

TEST(player_wins, plusOneToUserScore) {
    given_user_data_found();
    given_user_data_get_score(5);

    player_wins(player_id);

    CHECK_EQUAL(1, user_data_set_score_fake.call_count)
    CHECK_EQUAL(6, user_data_set_score_fake.arg1_val)
}

