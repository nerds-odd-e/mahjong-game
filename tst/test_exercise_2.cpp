#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

extern "C" {
#include "exercise_3.h"
#include "stub_user_data.h"
}

TEST_GROUP(player_wins) {

    void setup() {
        reset();
    }

};

TEST(player_wins, addUserIfNotFound) {
    given_user_data_find(0);

    player_wins(0);

    CHECK_TRUE(addCalled)
}

TEST(player_wins, notAddUserIfFound) {
    given_user_data_find(1);

    player_wins(0);

    CHECK_FALSE(addCalled)
}

TEST(player_wins, plusOneToUserScore) {
    given_user_data_find(1);
    given_user_score(5);

    player_wins(0);

    CHECK_EQUAL(6, user_score)
}
