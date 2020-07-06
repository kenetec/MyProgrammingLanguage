cmake_minimum_required(VERSION 3.0.0)
project(MyProgrammingLanguage VERSION 0.1.0)

include(CTest)
enable_testing()

set(SOURCE_FILES
  ./src/ASTNode.cpp
  ./src/ASTNode.h
  ./src/Character.h
  ./src/CodeGenerator.cpp
  ./src/CodeGenerator.h
  ./src/Lexer.cpp
  ./src/Lexer.h
  ./src/Parser.cpp
  ./src/Parser.h
  ./src/Scanner.h
  ./src/Scanner.cpp
  ./src/Semantics.h
  ./src/Symbols.h
  ./src/SymbolTable.cpp
  ./src/SymbolTable.h
  ./src/Token.cpp
  ./src/Token.h
  ./src/VirtualMachine.cpp
  ./src/VirtualMachine.h
)

add_executable(MyProgrammingLanguage main.cpp ${SOURCE_FILES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
