set(Main_SRCS exercise_1.c exercise_3.c exercise_3.h)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_library(exercise ${Main_SRCS})

