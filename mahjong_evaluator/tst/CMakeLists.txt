set(Test_SRCS AllTests.cpp test_evaluator.cpp test_terry_evaluator.cpp)

include_directories($ENV{CPPUTEST_HOME_INCLUDE})
include_directories(../include)

add_library(cpputest STATIC IMPORTED)
set_property(TARGET cpputest PROPERTY
        IMPORTED_LOCATION $ENV{CPPUTEST_HOME_LIB}/libCppUTest.a)

add_executable(mahjong-evaluator-test ${Test_SRCS})
target_link_libraries(mahjong-evaluator-test cpputest mahjong-evaluator)


