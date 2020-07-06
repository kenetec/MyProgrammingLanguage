# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kenetec/MyProgrammingLanguage

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kenetec/MyProgrammingLanguage

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target test
test:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running tests..."
	/usr/bin/ctest --force-new-ctest-process $(ARGS)
.PHONY : test

# Special rule for the target test
test/fast: test

.PHONY : test/fast

# Special rule for the target package
package: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Run CPack packaging tool..."
	/usr/bin/cpack --config ./CPackConfig.cmake
.PHONY : package

# Special rule for the target package
package/fast: package

.PHONY : package/fast

# Special rule for the target package_source
package_source:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Run CPack packaging tool for source..."
	/usr/bin/cpack --config ./CPackSourceConfig.cmake /home/kenetec/MyProgrammingLanguage/CPackSourceConfig.cmake
.PHONY : package_source

# Special rule for the target package_source
package_source/fast: package_source

.PHONY : package_source/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/kenetec/MyProgrammingLanguage/CMakeFiles /home/kenetec/MyProgrammingLanguage/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/kenetec/MyProgrammingLanguage/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named ContinuousSubmit

# Build rule for target.
ContinuousSubmit: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ContinuousSubmit
.PHONY : ContinuousSubmit

# fast build rule for target.
ContinuousSubmit/fast:
	$(MAKE) -f CMakeFiles/ContinuousSubmit.dir/build.make CMakeFiles/ContinuousSubmit.dir/build
.PHONY : ContinuousSubmit/fast

#=============================================================================
# Target rules for targets named ContinuousMemCheck

# Build rule for target.
ContinuousMemCheck: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ContinuousMemCheck
.PHONY : ContinuousMemCheck

# fast build rule for target.
ContinuousMemCheck/fast:
	$(MAKE) -f CMakeFiles/ContinuousMemCheck.dir/build.make CMakeFiles/ContinuousMemCheck.dir/build
.PHONY : ContinuousMemCheck/fast

#=============================================================================
# Target rules for targets named MyProgrammingLanguage

# Build rule for target.
MyProgrammingLanguage: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 MyProgrammingLanguage
.PHONY : MyProgrammingLanguage

# fast build rule for target.
MyProgrammingLanguage/fast:
	$(MAKE) -f CMakeFiles/MyProgrammingLanguage.dir/build.make CMakeFiles/MyProgrammingLanguage.dir/build
.PHONY : MyProgrammingLanguage/fast

#=============================================================================
# Target rules for targets named ContinuousConfigure

# Build rule for target.
ContinuousConfigure: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ContinuousConfigure
.PHONY : ContinuousConfigure

# fast build rule for target.
ContinuousConfigure/fast:
	$(MAKE) -f CMakeFiles/ContinuousConfigure.dir/build.make CMakeFiles/ContinuousConfigure.dir/build
.PHONY : ContinuousConfigure/fast

#=============================================================================
# Target rules for targets named ExperimentalSubmit

# Build rule for target.
ExperimentalSubmit: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ExperimentalSubmit
.PHONY : ExperimentalSubmit

# fast build rule for target.
ExperimentalSubmit/fast:
	$(MAKE) -f CMakeFiles/ExperimentalSubmit.dir/build.make CMakeFiles/ExperimentalSubmit.dir/build
.PHONY : ExperimentalSubmit/fast

#=============================================================================
# Target rules for targets named ExperimentalMemCheck

# Build rule for target.
ExperimentalMemCheck: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ExperimentalMemCheck
.PHONY : ExperimentalMemCheck

# fast build rule for target.
ExperimentalMemCheck/fast:
	$(MAKE) -f CMakeFiles/ExperimentalMemCheck.dir/build.make CMakeFiles/ExperimentalMemCheck.dir/build
.PHONY : ExperimentalMemCheck/fast

#=============================================================================
# Target rules for targets named ExperimentalTest

# Build rule for target.
ExperimentalTest: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ExperimentalTest
.PHONY : ExperimentalTest

# fast build rule for target.
ExperimentalTest/fast:
	$(MAKE) -f CMakeFiles/ExperimentalTest.dir/build.make CMakeFiles/ExperimentalTest.dir/build
.PHONY : ExperimentalTest/fast

#=============================================================================
# Target rules for targets named NightlyUpdate

# Build rule for target.
NightlyUpdate: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 NightlyUpdate
.PHONY : NightlyUpdate

# fast build rule for target.
NightlyUpdate/fast:
	$(MAKE) -f CMakeFiles/NightlyUpdate.dir/build.make CMakeFiles/NightlyUpdate.dir/build
.PHONY : NightlyUpdate/fast

#=============================================================================
# Target rules for targets named NightlyStart

# Build rule for target.
NightlyStart: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 NightlyStart
.PHONY : NightlyStart

# fast build rule for target.
NightlyStart/fast:
	$(MAKE) -f CMakeFiles/NightlyStart.dir/build.make CMakeFiles/NightlyStart.dir/build
.PHONY : NightlyStart/fast

#=============================================================================
# Target rules for targets named NightlyMemoryCheck

# Build rule for target.
NightlyMemoryCheck: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 NightlyMemoryCheck
.PHONY : NightlyMemoryCheck

# fast build rule for target.
NightlyMemoryCheck/fast:
	$(MAKE) -f CMakeFiles/NightlyMemoryCheck.dir/build.make CMakeFiles/NightlyMemoryCheck.dir/build
.PHONY : NightlyMemoryCheck/fast

#=============================================================================
# Target rules for targets named NightlyBuild

# Build rule for target.
NightlyBuild: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 NightlyBuild
.PHONY : NightlyBuild

# fast build rule for target.
NightlyBuild/fast:
	$(MAKE) -f CMakeFiles/NightlyBuild.dir/build.make CMakeFiles/NightlyBuild.dir/build
.PHONY : NightlyBuild/fast

#=============================================================================
# Target rules for targets named ExperimentalUpdate

# Build rule for target.
ExperimentalUpdate: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ExperimentalUpdate
.PHONY : ExperimentalUpdate

# fast build rule for target.
ExperimentalUpdate/fast:
	$(MAKE) -f CMakeFiles/ExperimentalUpdate.dir/build.make CMakeFiles/ExperimentalUpdate.dir/build
.PHONY : ExperimentalUpdate/fast

#=============================================================================
# Target rules for targets named ContinuousBuild

# Build rule for target.
ContinuousBuild: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ContinuousBuild
.PHONY : ContinuousBuild

# fast build rule for target.
ContinuousBuild/fast:
	$(MAKE) -f CMakeFiles/ContinuousBuild.dir/build.make CMakeFiles/ContinuousBuild.dir/build
.PHONY : ContinuousBuild/fast

#=============================================================================
# Target rules for targets named Continuous

# Build rule for target.
Continuous: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Continuous
.PHONY : Continuous

# fast build rule for target.
Continuous/fast:
	$(MAKE) -f CMakeFiles/Continuous.dir/build.make CMakeFiles/Continuous.dir/build
.PHONY : Continuous/fast

#=============================================================================
# Target rules for targets named Experimental

# Build rule for target.
Experimental: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Experimental
.PHONY : Experimental

# fast build rule for target.
Experimental/fast:
	$(MAKE) -f CMakeFiles/Experimental.dir/build.make CMakeFiles/Experimental.dir/build
.PHONY : Experimental/fast

#=============================================================================
# Target rules for targets named ExperimentalConfigure

# Build rule for target.
ExperimentalConfigure: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ExperimentalConfigure
.PHONY : ExperimentalConfigure

# fast build rule for target.
ExperimentalConfigure/fast:
	$(MAKE) -f CMakeFiles/ExperimentalConfigure.dir/build.make CMakeFiles/ExperimentalConfigure.dir/build
.PHONY : ExperimentalConfigure/fast

#=============================================================================
# Target rules for targets named NightlyTest

# Build rule for target.
NightlyTest: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 NightlyTest
.PHONY : NightlyTest

# fast build rule for target.
NightlyTest/fast:
	$(MAKE) -f CMakeFiles/NightlyTest.dir/build.make CMakeFiles/NightlyTest.dir/build
.PHONY : NightlyTest/fast

#=============================================================================
# Target rules for targets named NightlyCoverage

# Build rule for target.
NightlyCoverage: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 NightlyCoverage
.PHONY : NightlyCoverage

# fast build rule for target.
NightlyCoverage/fast:
	$(MAKE) -f CMakeFiles/NightlyCoverage.dir/build.make CMakeFiles/NightlyCoverage.dir/build
.PHONY : NightlyCoverage/fast

#=============================================================================
# Target rules for targets named ExperimentalCoverage

# Build rule for target.
ExperimentalCoverage: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ExperimentalCoverage
.PHONY : ExperimentalCoverage

# fast build rule for target.
ExperimentalCoverage/fast:
	$(MAKE) -f CMakeFiles/ExperimentalCoverage.dir/build.make CMakeFiles/ExperimentalCoverage.dir/build
.PHONY : ExperimentalCoverage/fast

#=============================================================================
# Target rules for targets named NightlyMemCheck

# Build rule for target.
NightlyMemCheck: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 NightlyMemCheck
.PHONY : NightlyMemCheck

# fast build rule for target.
NightlyMemCheck/fast:
	$(MAKE) -f CMakeFiles/NightlyMemCheck.dir/build.make CMakeFiles/NightlyMemCheck.dir/build
.PHONY : NightlyMemCheck/fast

#=============================================================================
# Target rules for targets named ContinuousStart

# Build rule for target.
ContinuousStart: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ContinuousStart
.PHONY : ContinuousStart

# fast build rule for target.
ContinuousStart/fast:
	$(MAKE) -f CMakeFiles/ContinuousStart.dir/build.make CMakeFiles/ContinuousStart.dir/build
.PHONY : ContinuousStart/fast

#=============================================================================
# Target rules for targets named NightlySubmit

# Build rule for target.
NightlySubmit: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 NightlySubmit
.PHONY : NightlySubmit

# fast build rule for target.
NightlySubmit/fast:
	$(MAKE) -f CMakeFiles/NightlySubmit.dir/build.make CMakeFiles/NightlySubmit.dir/build
.PHONY : NightlySubmit/fast

#=============================================================================
# Target rules for targets named ContinuousCoverage

# Build rule for target.
ContinuousCoverage: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ContinuousCoverage
.PHONY : ContinuousCoverage

# fast build rule for target.
ContinuousCoverage/fast:
	$(MAKE) -f CMakeFiles/ContinuousCoverage.dir/build.make CMakeFiles/ContinuousCoverage.dir/build
.PHONY : ContinuousCoverage/fast

#=============================================================================
# Target rules for targets named Nightly

# Build rule for target.
Nightly: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Nightly
.PHONY : Nightly

# fast build rule for target.
Nightly/fast:
	$(MAKE) -f CMakeFiles/Nightly.dir/build.make CMakeFiles/Nightly.dir/build
.PHONY : Nightly/fast

#=============================================================================
# Target rules for targets named NightlyConfigure

# Build rule for target.
NightlyConfigure: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 NightlyConfigure
.PHONY : NightlyConfigure

# fast build rule for target.
NightlyConfigure/fast:
	$(MAKE) -f CMakeFiles/NightlyConfigure.dir/build.make CMakeFiles/NightlyConfigure.dir/build
.PHONY : NightlyConfigure/fast

#=============================================================================
# Target rules for targets named ExperimentalStart

# Build rule for target.
ExperimentalStart: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ExperimentalStart
.PHONY : ExperimentalStart

# fast build rule for target.
ExperimentalStart/fast:
	$(MAKE) -f CMakeFiles/ExperimentalStart.dir/build.make CMakeFiles/ExperimentalStart.dir/build
.PHONY : ExperimentalStart/fast

#=============================================================================
# Target rules for targets named ContinuousTest

# Build rule for target.
ContinuousTest: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ContinuousTest
.PHONY : ContinuousTest

# fast build rule for target.
ContinuousTest/fast:
	$(MAKE) -f CMakeFiles/ContinuousTest.dir/build.make CMakeFiles/ContinuousTest.dir/build
.PHONY : ContinuousTest/fast

#=============================================================================
# Target rules for targets named ContinuousUpdate

# Build rule for target.
ContinuousUpdate: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ContinuousUpdate
.PHONY : ContinuousUpdate

# fast build rule for target.
ContinuousUpdate/fast:
	$(MAKE) -f CMakeFiles/ContinuousUpdate.dir/build.make CMakeFiles/ContinuousUpdate.dir/build
.PHONY : ContinuousUpdate/fast

#=============================================================================
# Target rules for targets named ExperimentalBuild

# Build rule for target.
ExperimentalBuild: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ExperimentalBuild
.PHONY : ExperimentalBuild

# fast build rule for target.
ExperimentalBuild/fast:
	$(MAKE) -f CMakeFiles/ExperimentalBuild.dir/build.make CMakeFiles/ExperimentalBuild.dir/build
.PHONY : ExperimentalBuild/fast

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/MyProgrammingLanguage.dir/build.make CMakeFiles/MyProgrammingLanguage.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/MyProgrammingLanguage.dir/build.make CMakeFiles/MyProgrammingLanguage.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/MyProgrammingLanguage.dir/build.make CMakeFiles/MyProgrammingLanguage.dir/main.cpp.s
.PHONY : main.cpp.s

src/ASTNode.o: src/ASTNode.cpp.o

.PHONY : src/ASTNode.o

# target to build an object file
src/ASTNode.cpp.o:
	$(MAKE) -f CMakeFiles/MyProgrammingLanguage.dir/build.make CMakeFiles/MyProgrammingLanguage.dir/src/ASTNode.cpp.o
.PHONY : src/ASTNode.cpp.o

src/ASTNode.i: src/ASTNode.cpp.i

.PHONY : src/ASTNode.i

# target to preprocess a source file
src/ASTNode.cpp.i:
	$(MAKE) -f CMakeFiles/MyProgrammingLanguage.dir/build.make CMakeFiles/MyProgrammingLanguage.dir/src/ASTNode.cpp.i
.PHONY : src/ASTNode.cpp.i

src/ASTNode.s: src/ASTNode.cpp.s

.PHONY : src/ASTNode.s

# target to generate assembly for a file
src/ASTNode.cpp.s:
	$(MAKE) -f CMakeFiles/MyProgrammingLanguage.dir/build.make CMakeFiles/MyProgrammingLanguage.dir/src/ASTNode.cpp.s
.PHONY : src/ASTNode.cpp.s

src/CodeGenerator.o: src/CodeGenerator.cpp.o

.PHONY : src/CodeGenerator.o

# target to build an object file
src/CodeGenerator.cpp.o:
	$(MAKE) -f CMakeFiles/MyProgrammingLanguage.dir/build.make CMakeFiles/MyProgrammingLanguage.dir/src/CodeGenerator.cpp.o
.PHONY : src/CodeGenerator.cpp.o

src/CodeGenerator.i: src/CodeGenerator.cpp.i

.PHONY : src/CodeGenerator.i

# target to preprocess a source file
src/CodeGenerator.cpp.i:
	$(MAKE) -f CMakeFiles/MyProgrammingLanguage.dir/build.make CMakeFiles/MyProgrammingLanguage.dir/src/CodeGenerator.cpp.i
.PHONY : src/CodeGenerator.cpp.i

src/CodeGenerator.s: src/CodeGenerator.cpp.s

.PHONY : src/CodeGenerator.s

# target to generate assembly for a file
src/CodeGenerator.cpp.s:
	$(MAKE) -f CMakeFiles/MyProgrammingLanguage.dir/build.make CMakeFiles/MyProgrammingLanguage.dir/src/CodeGenerator.cpp.s
.PHONY : src/CodeGenerator.cpp.s

src/Lexer.o: src/Lexer.cpp.o

.PHONY : src/Lexer.o

# target to build an object file
src/Lexer.cpp.o:
	$(MAKE) -f CMakeFiles/MyProgrammingLanguage.dir/build.make CMakeFiles/MyProgrammingLanguage.dir/src/Lexer.cpp.o
.PHONY : src/Lexer.cpp.o

src/Lexer.i: src/Lexer.cpp.i

.PHONY : src/Lexer.i

# target to preprocess a source file
src/Lexer.cpp.i:
	$(MAKE) -f CMakeFiles/MyProgrammingLanguage.dir/build.make CMakeFiles/MyProgrammingLanguage.dir/src/Lexer.cpp.i
.PHONY : src/Lexer.cpp.i

src/Lexer.s: src/Lexer.cpp.s

.PHONY : src/Lexer.s

# target to generate assembly for a file
src/Lexer.cpp.s:
	$(MAKE) -f CMakeFiles/MyProgrammingLanguage.dir/build.make CMakeFiles/MyProgrammingLanguage.dir/src/Lexer.cpp.s
.PHONY : src/Lexer.cpp.s

src/Parser.o: src/Parser.cpp.o

.PHONY : src/Parser.o

# target to build an object file
src/Parser.cpp.o:
	$(MAKE) -f CMakeFiles/MyProgrammingLanguage.dir/build.make CMakeFiles/MyProgrammingLanguage.dir/src/Parser.cpp.o
.PHONY : src/Parser.cpp.o

src/Parser.i: src/Parser.cpp.i

.PHONY : src/Parser.i

# target to preprocess a source file
src/Parser.cpp.i:
	$(MAKE) -f CMakeFiles/MyProgrammingLanguage.dir/build.make CMakeFiles/MyProgrammingLanguage.dir/src/Parser.cpp.i
.PHONY : src/Parser.cpp.i

src/Parser.s: src/Parser.cpp.s

.PHONY : src/Parser.s

# target to generate assembly for a file
src/Parser.cpp.s:
	$(MAKE) -f CMakeFiles/MyProgrammingLanguage.dir/build.make CMakeFiles/MyProgrammingLanguage.dir/src/Parser.cpp.s
.PHONY : src/Parser.cpp.s

src/Scanner.o: src/Scanner.cpp.o

.PHONY : src/Scanner.o

# target to build an object file
src/Scanner.cpp.o:
	$(MAKE) -f CMakeFiles/MyProgrammingLanguage.dir/build.make CMakeFiles/MyProgrammingLanguage.dir/src/Scanner.cpp.o
.PHONY : src/Scanner.cpp.o

src/Scanner.i: src/Scanner.cpp.i

.PHONY : src/Scanner.i

# target to preprocess a source file
src/Scanner.cpp.i:
	$(MAKE) -f CMakeFiles/MyProgrammingLanguage.dir/build.make CMakeFiles/MyProgrammingLanguage.dir/src/Scanner.cpp.i
.PHONY : src/Scanner.cpp.i

src/Scanner.s: src/Scanner.cpp.s

.PHONY : src/Scanner.s

# target to generate assembly for a file
src/Scanner.cpp.s:
	$(MAKE) -f CMakeFiles/MyProgrammingLanguage.dir/build.make CMakeFiles/MyProgrammingLanguage.dir/src/Scanner.cpp.s
.PHONY : src/Scanner.cpp.s

src/SymbolTable.o: src/SymbolTable.cpp.o

.PHONY : src/SymbolTable.o

# target to build an object file
src/SymbolTable.cpp.o:
	$(MAKE) -f CMakeFiles/MyProgrammingLanguage.dir/build.make CMakeFiles/MyProgrammingLanguage.dir/src/SymbolTable.cpp.o
.PHONY : src/SymbolTable.cpp.o

src/SymbolTable.i: src/SymbolTable.cpp.i

.PHONY : src/SymbolTable.i

# target to preprocess a source file
src/SymbolTable.cpp.i:
	$(MAKE) -f CMakeFiles/MyProgrammingLanguage.dir/build.make CMakeFiles/MyProgrammingLanguage.dir/src/SymbolTable.cpp.i
.PHONY : src/SymbolTable.cpp.i

src/SymbolTable.s: src/SymbolTable.cpp.s

.PHONY : src/SymbolTable.s

# target to generate assembly for a file
src/SymbolTable.cpp.s:
	$(MAKE) -f CMakeFiles/MyProgrammingLanguage.dir/build.make CMakeFiles/MyProgrammingLanguage.dir/src/SymbolTable.cpp.s
.PHONY : src/SymbolTable.cpp.s

src/Token.o: src/Token.cpp.o

.PHONY : src/Token.o

# target to build an object file
src/Token.cpp.o:
	$(MAKE) -f CMakeFiles/MyProgrammingLanguage.dir/build.make CMakeFiles/MyProgrammingLanguage.dir/src/Token.cpp.o
.PHONY : src/Token.cpp.o

src/Token.i: src/Token.cpp.i

.PHONY : src/Token.i

# target to preprocess a source file
src/Token.cpp.i:
	$(MAKE) -f CMakeFiles/MyProgrammingLanguage.dir/build.make CMakeFiles/MyProgrammingLanguage.dir/src/Token.cpp.i
.PHONY : src/Token.cpp.i

src/Token.s: src/Token.cpp.s

.PHONY : src/Token.s

# target to generate assembly for a file
src/Token.cpp.s:
	$(MAKE) -f CMakeFiles/MyProgrammingLanguage.dir/build.make CMakeFiles/MyProgrammingLanguage.dir/src/Token.cpp.s
.PHONY : src/Token.cpp.s

src/VirtualMachine.o: src/VirtualMachine.cpp.o

.PHONY : src/VirtualMachine.o

# target to build an object file
src/VirtualMachine.cpp.o:
	$(MAKE) -f CMakeFiles/MyProgrammingLanguage.dir/build.make CMakeFiles/MyProgrammingLanguage.dir/src/VirtualMachine.cpp.o
.PHONY : src/VirtualMachine.cpp.o

src/VirtualMachine.i: src/VirtualMachine.cpp.i

.PHONY : src/VirtualMachine.i

# target to preprocess a source file
src/VirtualMachine.cpp.i:
	$(MAKE) -f CMakeFiles/MyProgrammingLanguage.dir/build.make CMakeFiles/MyProgrammingLanguage.dir/src/VirtualMachine.cpp.i
.PHONY : src/VirtualMachine.cpp.i

src/VirtualMachine.s: src/VirtualMachine.cpp.s

.PHONY : src/VirtualMachine.s

# target to generate assembly for a file
src/VirtualMachine.cpp.s:
	$(MAKE) -f CMakeFiles/MyProgrammingLanguage.dir/build.make CMakeFiles/MyProgrammingLanguage.dir/src/VirtualMachine.cpp.s
.PHONY : src/VirtualMachine.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... test"
	@echo "... package"
	@echo "... ContinuousSubmit"
	@echo "... ContinuousMemCheck"
	@echo "... MyProgrammingLanguage"
	@echo "... ContinuousConfigure"
	@echo "... ExperimentalSubmit"
	@echo "... ExperimentalMemCheck"
	@echo "... ExperimentalTest"
	@echo "... NightlyUpdate"
	@echo "... NightlyStart"
	@echo "... NightlyMemoryCheck"
	@echo "... NightlyBuild"
	@echo "... ExperimentalUpdate"
	@echo "... ContinuousBuild"
	@echo "... Continuous"
	@echo "... Experimental"
	@echo "... package_source"
	@echo "... ExperimentalConfigure"
	@echo "... edit_cache"
	@echo "... NightlyTest"
	@echo "... NightlyCoverage"
	@echo "... ExperimentalCoverage"
	@echo "... NightlyMemCheck"
	@echo "... ContinuousStart"
	@echo "... NightlySubmit"
	@echo "... ContinuousCoverage"
	@echo "... Nightly"
	@echo "... NightlyConfigure"
	@echo "... ExperimentalStart"
	@echo "... ContinuousTest"
	@echo "... ContinuousUpdate"
	@echo "... ExperimentalBuild"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... src/ASTNode.o"
	@echo "... src/ASTNode.i"
	@echo "... src/ASTNode.s"
	@echo "... src/CodeGenerator.o"
	@echo "... src/CodeGenerator.i"
	@echo "... src/CodeGenerator.s"
	@echo "... src/Lexer.o"
	@echo "... src/Lexer.i"
	@echo "... src/Lexer.s"
	@echo "... src/Parser.o"
	@echo "... src/Parser.i"
	@echo "... src/Parser.s"
	@echo "... src/Scanner.o"
	@echo "... src/Scanner.i"
	@echo "... src/Scanner.s"
	@echo "... src/SymbolTable.o"
	@echo "... src/SymbolTable.i"
	@echo "... src/SymbolTable.s"
	@echo "... src/Token.o"
	@echo "... src/Token.i"
	@echo "... src/Token.s"
	@echo "... src/VirtualMachine.o"
	@echo "... src/VirtualMachine.i"
	@echo "... src/VirtualMachine.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
