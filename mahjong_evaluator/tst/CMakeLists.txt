set(Test_SRCS AllTests.cpp test_evaluator.cpp test_terry_evaluator.cpp)

include_directories($ENV{CPPUTEST_HOME_INCLUDE})
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/mahjong_evaluator/include)
include_directories(${PROJECT_SOURCE_DIR}/mahjong_evaluator/src)

add_library(cpputest STATIC IMPORTED)
set_property(TARGET cpputest PROPERTY
        IMPORTED_LOCATION $ENV{CPPUTEST_HOME_LIB}/libCppUTest.a)

add_library(cpputest_ext STATIC IMPORTED)
set_property(TARGET cpputest_ext PROPERTY
        IMPORTED_LOCATION $ENV{CPPUTEST_HOME_LIB}/libCppUTestExt.a)

add_executable(mahjong-evaluator-test ${Test_SRCS})
target_link_libraries(mahjong-evaluator-test cpputest cpputest_ext mahjong_evaluator)


