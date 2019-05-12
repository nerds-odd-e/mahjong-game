set(Main_SRCS evaluator.cpp terry_evaluator.c terry_evaluator.h tiles.c tiles.h)

include_directories(${PROJECT_SOURCE_DIR}/mahjong_evaluator/include)
include_directories(${PROJECT_SOURCE_DIR}/include)

add_library(mahjong_evaluator ${Main_SRCS})
