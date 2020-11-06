cmake_minimum_required(VERSION 3.16)

project("AskFM")

add_library(user
    src/user/user.cpp
    src/database/database.cpp
)

add_executable(askfm
    src/askfm.cpp
)

include(FindSQLite3)

target_link_libraries(askfm
    PRIVATE SQLite::SQLite3
    PRIVATE user
)

if(MSVC)
target_compile_options(askfm
    PRIVATE /W4
    PRIVATE /WX
)
else()
target_compile_options(askfm
    PRIVATE -Wall
    PRIVATE -Wextra
    # PRIVATE -pedantic
    # PRIVATE -Werror
)
endif()