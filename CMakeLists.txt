cmake_minimum_required(VERSION 3.10)

project(SoulOfTheWorld)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

# Source Dir
set(SRC_DIR src)
set(OBJ_DIR ${CMAKE_BINARY_DIR}/obj)

# Source Sub-Dir
set(SUBDIRS
    ${SRC_DIR}/core
    ${SRC_DIR}/entities
    ${SRC_DIR}/resources
    ${SRC_DIR}/roots
    ${SRC_DIR}/screens
    ${SRC_DIR}/spells
    ${SRC_DIR}/ui
    ${SRC_DIR}/world
)

file(GLOB_RECURSE SRCS
    ${SRC_DIR}/*.cpp
)

# Raylib
find_package(raylib REQUIRED)

# Include
include_directories(${SRC_DIR} ${CMAKE_SOURCE_DIR}/include)

# Bin
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Exe
add_executable(${PROJECT_NAME} ${SRCS})

# Linker
target_link_libraries(${PROJECT_NAME} raylib m pthread dl X11)

# Ruleset
add_custom_target(clean_project
    COMMAND rm -rf ${OBJ_DIR} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
    COMMENT "Cleaning Build files"
)
