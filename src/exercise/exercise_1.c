#include "tile.h"
#include <string.h>
#include <stdbool.h>

bool containNeighbors(const tile_t *tiles, int tile_count, int firstNeighbor, int secondNeighbor);

int tiles_is_able_to_chow(tile_t tiles[], int tile_count, tile_t tile)
{
    if (containNeighbors(tiles, tile_count, tile + 1, tile + 2) || containNeighbors(tiles, tile_count, tile - 1, tile + 1) ||
    containNeighbors(tiles, tile_count, tile - 1, tile - 2)) {
        return 1;
    }
	return 0;
}

bool containNeighbors(const tile_t *tiles, int tile_count, int firstNeighbor, int secondNeighbor) {
    return memchr(tiles, firstNeighbor, tile_count) && memchr(tiles, secondNeighbor, tile_count);
}
