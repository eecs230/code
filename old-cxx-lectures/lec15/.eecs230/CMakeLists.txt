# Turn on CTest
enable_testing()

include_directories(src)

# Catch
include_directories(.eecs230/lib/catch)

# Adds a program with the given name and source files, and sets the
# language to C++ 14
macro (add_program name)
    add_executable(${name} ${ARGN})
    set_property(TARGET ${name} PROPERTY CXX_STANDARD 14)
    set_property(TARGET ${name} PROPERTY CXX_STANDARD_REQUIRED On)
endmacro (add_program)

# Adds a Catch-based test program with the given name and source files
macro (add_test_program name)
    add_program(${name} .eecs230/lib/catch-main.cpp ${ARGN})
    add_test(Test_${name} ${name})
endmacro (add_test_program)

