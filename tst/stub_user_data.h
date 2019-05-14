#include <stdbool.h>
#include "exercise_3.h"

bool addCalled = false;
int is_user_data_find = 1;
int user_score = 0;

void reset() {
    addCalled = false;
    is_user_data_find = 1;
    user_score = 0;
}

void given_user_data_find(int result) {
    is_user_data_find = result;
}

int user_data_find(int player_id) {
    return is_user_data_find;
}

void user_data_add(int player_id) {
    addCalled = true;
}

void given_user_score(int score) {
    user_score = score;
}

int user_data_get_score(int player_id) {
    return user_score;
}

void user_data_set_score(int player_id, int score) {
    user_score = score;
}

