set(Test_SRCS AllTests.cpp mocks.cpp mocks.h names.h project_euler.cpp project_euler.h simple_evaluator.c test_ai_agent.cpp test_exercise_1.cpp test_exercise_3.cpp test_game_builder.cpp test_html_game.cpp test_player.cpp test_tile_pool.cpp test_tiles.cpp test_ui_agent.cpp words.h ./private/test_exercise_3.cpp ./private/test_tiles.cpp stub_user_data.h test_exercise_2.cpp fff.h)

include_directories($ENV{CPPUTEST_HOME_INCLUDE})
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/src/mahjong_game)
include_directories(${PROJECT_SOURCE_DIR}/src/exercise)
include_directories(${PROJECT_SOURCE_DIR}/src/html_ui)

add_library(cpputest STATIC IMPORTED)
set_property(TARGET cpputest PROPERTY
        IMPORTED_LOCATION $ENV{CPPUTEST_HOME_LIB}/libCppUTest.a)

add_library(cpputest_ext STATIC IMPORTED)
set_property(TARGET cpputest_ext PROPERTY
        IMPORTED_LOCATION $ENV{CPPUTEST_HOME_LIB}/libCppUTestExt.a)

add_executable(mahjong-test ${Test_SRCS})
target_link_libraries(mahjong-test cpputest cpputest_ext exercise html_ui mahjong_game)


