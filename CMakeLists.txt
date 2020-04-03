cmake_minimum_required(VERSION 3.15)
project(Compiler-Mx_star)
set(CMAKE_CXX_STANDARD 14)
# SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")
include_directories(
        ${PROJECT_SOURCE_DIR}/third_party/antlr4_runtime/
        ${PROJECT_SOURCE_DIR}/lexer_parser/
        ${PROJECT_SOURCE_DIR}/AST/
)
add_subdirectory(${PROJECT_SOURCE_DIR}/third_party/antlr4_runtime)
set(lexer_parser_src
        ${PROJECT_SOURCE_DIR}/lexer_parser/Mx_starLexer.cpp
        ${PROJECT_SOURCE_DIR}/lexer_parser/Mx_starParser.cpp
        ${PROJECT_SOURCE_DIR}/lexer_parser/Mx_starVisitor.cpp
        ${PROJECT_SOURCE_DIR}/lexer_parser/Mx_starBaseVisitor.cpp
        )
set(AST_src
        ${PROJECT_SOURCE_DIR}/AST/ASTBuilder.cpp
        ${PROJECT_SOURCE_DIR}/AST/ASTNode.cpp
        ${PROJECT_SOURCE_DIR}/AST/types.cpp
        ${PROJECT_SOURCE_DIR}/AST/ASTVisitor.cpp)
add_executable(Compiler-Mx_star ${lexer_parser_src} ${AST_src} main.cpp)
target_link_libraries(Compiler-Mx_star antlr4_static)