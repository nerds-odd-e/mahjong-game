set(Main_SRCS agent.h ai_agent.c ai_agent.h evaluator.c evaluator.h game_builder.c game_builder.h mahjong_game.h mj_table.c mj_table.h player.c player.h tile_pool.c tile_pool.h tiles.c tiles.h ui_agent.c ui_agent.h)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_library(mahjong_game ${Main_SRCS})
