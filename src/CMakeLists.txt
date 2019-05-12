set(Main_SRCS main.c)

add_subdirectory(exercise)
add_subdirectory(html_ui)
add_subdirectory(mahjong_game)

include_directories(${PROJECT_SOURCE_DIR}/src/html_ui)

file(COPY ../htdocs DESTINATION ${CMAKE_BINARY_DIR}/src)

add_executable(game main.c)
target_link_libraries(game mahjong_game mahjong_evaluator exercise html_ui)

