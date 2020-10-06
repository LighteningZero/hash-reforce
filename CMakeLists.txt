CMAKE_MINIMUM_REQUIRED(VERSION 3.16)

PROJECT(HashReforce)

INCLUDE_DIRECTORIES(
    include/
)

SET(CMAKE_CXX_STANDARD 17)

SET(SRC_LIST 
    ${PROJECT_SOURCE_DIR}/src/main.cc
    ${PROJECT_SOURCE_DIR}/src/lib/hash.cc
    ${PROJECT_SOURCE_DIR}/src/lib/lfunction.cc
    ${PROJECT_SOURCE_DIR}/src/lib/random.cc
)

LINK_LIBRARIES(
    lua
    fmt
    dl
)

ADD_EXECUTABLE(hr ${SRC_LIST})
