#include "CppUTest/TestHarness.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

extern "C" {
#include "tiles.h"
}

TEST_GROUP(tiles_is_able_to_chow) {
    void setup() {

    }

    void teardown() {

    }

};

TEST(tiles_is_able_to_chow, notAbleToChow) {
    tile_t tiles[] = {MJ_EAST, MJ_SOUTH, MJ_WEST, MJ_NORTH};

    int result = tiles_is_able_to_chow(tiles, sizeof(tiles), MJ_ZHONG);

    CHECK_TRUE(!result)
}

TEST(tiles_is_able_to_chow, chowWhenTileOnTheLeft) {
    tile_t tiles[] = {C(2), C(3), MJ_EAST, MJ_EAST};

    int result = tiles_is_able_to_chow(tiles, sizeof(tiles), C(1));

    CHECK_TRUE(result)
}

TEST(tiles_is_able_to_chow, chowWhenTileInTheMiddle) {
    tile_t tiles[] = {C(1), C(3), MJ_EAST, MJ_EAST};

    int result = tiles_is_able_to_chow(tiles, sizeof(tiles), C(2));

    CHECK_TRUE(result)
}

TEST(tiles_is_able_to_chow, chowWhenTileOnTheRight) {
    tile_t tiles[] = {C(1), C(2), MJ_EAST, MJ_EAST};

    int result = tiles_is_able_to_chow(tiles, sizeof(tiles), C(3));

    CHECK_TRUE(result)
}

TEST(tiles_is_able_to_chow, chowWhenTileAlreadyThere) {
    tile_t tiles[] = {C(1), C(2), C(3), MJ_EAST};

    int result = tiles_is_able_to_chow(tiles, sizeof(tiles), C(3));

    CHECK_TRUE(result)
}
