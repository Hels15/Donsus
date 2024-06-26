cmake_minimum_required(VERSION 3.22)

project(donsus_test)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()


add_executable(donsus_test
        parser/test_variables_parser.cc
        parser/test_functions.cc
        parser/test_if_statements.cc
        parser/test_expressions.cc
        parser/test_function_call.cc
        parser/test_return.cc
        parser/test_assignments.cc
        parser/test_print.cc
        parser/test_unary_expressions.cc
        parser/test_float.cc
        parser/test_arrays.cc
        parser/test_one_line_mul_var.cc
        parser/test_while_loops.cc
        parser/test_for_loops.cc

        # typecheck
        typecheck/test_return.cc
        typecheck/test_variables.cc
        typecheck/test_function.cc
        typecheck/test_assignment_type.cc
        typecheck/test_function_call_args.cc
        typecheck/test_function_call_rvalue.cc
        typecheck/test_identifier_rvalue.cc
        typecheck/test_if_statements_type.cc
        typecheck/test_unary_expressions_rvalue.cc
        typecheck/test_bools.cc
        typecheck/test_arrays_typecheck.cc
        typecheck/test_while_loops_typecheck.cc

        #symbol table
        symbol_table/test_variables.cc
        symbol_table/test_sym_functions.cc

        #codegen_test
        codegen_test/test_fulltest_codegen.cc
)


include(GoogleTest)
gtest_discover_tests(donsus_test)

target_link_libraries(donsus_test PUBLIC
        GTest::gtest_main
        ${llvm}
        donsus_lib
)