cmake_minimum_required(VERSION 3.15)
project(Compiler-Mx_star)
set(CMAKE_CXX_STANDARD 14)
# SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")
include_directories(
        ${PROJECT_SOURCE_DIR}/third_party/antlr4_runtime/
        ${PROJECT_SOURCE_DIR}/lexer_parser/
        ${PROJECT_SOURCE_DIR}/AST/
        ${PROJECT_SOURCE_DIR}/IR/
        ${PROJECT_SOURCE_DIR}/Codegen/
        ${PROJECT_SOURCE_DIR}/utility/
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
        ${PROJECT_SOURCE_DIR}/AST/Types.cpp
        ${PROJECT_SOURCE_DIR}/AST/ASTVisitor.cpp
        ${PROJECT_SOURCE_DIR}/AST/TypeChecker.cpp
        ${PROJECT_SOURCE_DIR}/AST/SemanticIssue.cpp
        ${PROJECT_SOURCE_DIR}/AST/Builtin.cpp
        ${PROJECT_SOURCE_DIR}/AST/Env.cpp
        ${PROJECT_SOURCE_DIR}/AST/SymbolTable.cpp)
set(IR_src
        ${PROJECT_SOURCE_DIR}/IR/IR.cpp
        ${PROJECT_SOURCE_DIR}/IR/IRBuilder.cpp
        ${PROJECT_SOURCE_DIR}/IR/IRProgram.cpp
        ${PROJECT_SOURCE_DIR}/IR/DominatorTree.cpp
        ${PROJECT_SOURCE_DIR}/IR/SSAConstructor.cpp
        ${PROJECT_SOURCE_DIR}/IR/SSADestructor.cpp)
set(Codegen_src
        ${PROJECT_SOURCE_DIR}/Codegen/RVInst.cpp
        ${PROJECT_SOURCE_DIR}/Codegen/RVProgram.cpp
        ${PROJECT_SOURCE_DIR}/Codegen/InstSelector.cpp
        ${PROJECT_SOURCE_DIR}/Codegen/RegAllocation.cpp)
add_executable(Compiler-Mx_star ${lexer_parser_src} ${AST_src} ${IR_src} ${Codegen_src} main.cpp)
target_link_libraries(Compiler-Mx_star antlr4_static)