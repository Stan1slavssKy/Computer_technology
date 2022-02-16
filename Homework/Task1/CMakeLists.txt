cmake_minimum_required(VERSION 3.8)
project(exercise1)
set(CMAKE_CXX_STANDART 11)

add_compile_options(
    -Wall
    -Wextra
    -Wpedantic

    -Wcast-align
    -Wcast-qual
    -Wconversion
    
    -Wenum-compare
    -Wfloat-equal
    -Wnon-virtual-dtor
    -Wold-style-cast
    -Woverloaded-virtual
    -Wredundant-decls
    -Wsign-conversion
    -Wsign-promo

    -fno-elide-constructors
)

set(OUTPUT output)
add_executable(${OUTPUT} ex1.cpp)

target_compile_options(${OUTPUT} PUBLIC -fsanitize=address -g)
set_target_properties(${OUTPUT}  PROPERTIES LINK_FLAGS "-fsanitize=address")

add_custom_target(run_${OUTPUT}
    COMMENT "Running code"
    COMMAND ${CMAKE_CURRENT_BINARY_DIR}/${OUTPUT}
)
add_dependencies(run_${OUTPUT} ${OUTPUT})  
