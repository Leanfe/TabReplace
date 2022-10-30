cmake_minimum_required(VERSION 3.22)
project(TabReplace C)

set(CMAKE_C_STANDARD 17)

add_executable(TabReplace src/main.c src/reader/reader.c src/reader/reader.h src/editor/editor.c src/editor/editor.h src/util/messages.h)

#[[
# set output target
set_target_properties(TabReplace
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "/usr/util/"
        LIBRARY_OUTPUT_DIRECTORY "/usr/util/"
        RUNTIME_OUTPUT_DIRECTORY "/usr/bin/"
        )

# find the math library
find_library(MATH_LIBRARY m)
if(MATH_LIBRARY)
    # link target with math library
    target_link_libraries(TabReplace PUBLIC ${MATH_LIBRARY})
endif()

# define header file path
target_include_directories(TabReplace PRIVATE include)

# set to use C17 features
target_compile_features(TabReplace PRIVATE c_std_17)

# set compiler options
target_compile_options(TabReplace PRIVATE -Wall -O3)

# specify what to install when we run 'make install'
install(TARGETS TabReplace DESTINATION bin)]]
