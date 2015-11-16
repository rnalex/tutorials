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

env = Environment()
env.Append(CPPPATH = ['.','googletest/googletest/include/','googletest/googletest/','cpptut'])
# Set our g++ compiler flags
env.Append( CPPFLAGS=['-std=c++11', '-pthread', '-Wall', '-g'] )
env.Prepend(LINKFLAGS = ['-pthread'])

# Tell SCons the program to build
#env.Program('build/test', source_files, LIBS = libraries, LIBPATH = library_paths)

env.Program(target = 'build/test', source = ["cpptut/test.cpp","googletest/googletest/src/gtest_main.cc","googletest/googletest/src/gtest-all.cc"])

