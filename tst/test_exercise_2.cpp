#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

extern "C" {
#include "exercise_3.h"
}

TEST_GROUP(player_wins) {

    int player_id;
    void setup() {
        player_id = 10;
        mock().ignoreOtherCalls();
    }

    void given_user_data_not_found() {
        mock().expectOneCall("user_data_find").withParameter("player_id", player_id).andReturnValue(0);
    }

    void given_user_data_found() {
        mock().expectOneCall("user_data_find").withParameter("player_id", player_id).andReturnValue(1);
    }

    void given_user_data_get_score(int score) {
        mock().expectOneCall("user_data_get_score").withParameter("player_id", player_id).andReturnValue(score);
    }

};

TEST(player_wins, addUserIfNotFound) {
    given_user_data_not_found();
    mock().expectOneCall("user_data_add").withParameter("player_id", player_id);

    player_wins(player_id);
}

TEST(player_wins, notAddUserIfFound) {
    given_user_data_found();
    mock().expectNoCall("user_data_add");

    player_wins(player_id);
}

TEST(player_wins, plusOneToUserScore) {
    given_user_data_found();
    given_user_data_get_score(5);
    mock().expectOneCall("user_data_set_score").withParameter("player_id", player_id).withParameter("score", 6);

    player_wins(player_id);
}

int user_data_find(int player_id) {
    return mock().actualCall("user_data_find").withParameter("player_id", player_id).returnValue().getIntValue();
}

void user_data_add(int player_id) {
    mock().actualCall("user_data_add").withParameter("player_id", player_id);
}

int user_data_get_score(int player_id) {
    return mock().actualCall("user_data_get_score").withParameter("player_id", player_id).returnValue().getIntValue();
}

void user_data_set_score(int player_id, int score) {
    mock().actualCall("user_data_set_score").withParameter("player_id", player_id).withParameter("score", score);
}
