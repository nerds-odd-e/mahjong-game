set(Main_SRCS html_game.c html_game.h httpd.c httpd.h)

include_directories(${PROJECT_SOURCE_DIR}/src/mahjong_game)
include_directories(${PROJECT_SOURCE_DIR}/include)

add_library(html_ui ${Main_SRCS})

