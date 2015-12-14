import sys
import os
from subprocess import call 

# Tell SCons to create our build files in the 'build' directory
VariantDir('build', 'cpptut', duplicate=0)

# Set our source files
source_files = Glob('build/*.cpp', 'build/*.hpp')

include_files = ['.','googletest/googletest/include/','googletest/googletest/','cpptut']
print "SOURCE_FILES= ", source_files
print "INCLUDE_FILES= ",include_files


# Set our required libraries
libraries = ['pthread']
library_paths = ''

#env = Environment()
env = Environment(CXX='g++-4.8')
env.Append(CPPPATH = ['.','googletest/googletest/include/','googletest/googletest/','cpptut'])
# Set our g++ compiler flags
env.Append( CPPFLAGS=['-std=c++11', '-pthread', '-Wall', '-g'] )
env.Prepend(LINKFLAGS = ['-pthread'])

# Tell SCons the program to build

env.Program(target = 'build/test', source = ["cpptut/test.cpp","googletest/googletest/src/gtest_main.cc","googletest/googletest/src/gtest-all.cc"])

from subprocess import call

def unit_test( target, source, env ):
    call(["build/test"]);

unit_test_command = Command( 'unit_test', [], unit_test )
Depends( unit_test_command, 'build/test')
Default( unit_test_command )

