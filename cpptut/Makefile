TOOLCHAIN_ROOT=../googletest/googletest
INCLUDE += -I$(TOOLCHAIN_ROOT)/include
#LIBS += -L$(TOOLCHAIN_ROOT)/lib
LIBS += -Wl,-Bstatic -lgtest -Wl,-Bdynamic

GTEST_DIR=../googletest/googletest
try:
	g++ -o ./try -std=c++11 -g try.cpp
clean:
	rm -rf ./try
	rm -rf ./test
x:
	./try
gtest:
	g++ -isystem $(GTEST_DIR)/include -I$(GTEST_DIR) \
    -pthread -c $(GTEST_DIR)/src/gtest-all.cc
	ar -rv libgtest.a gtest-all.o
test: gtest
	g++ -std=c++11 -isystem ${GTEST_DIR}/include -pthread test.cpp ${GTEST_DIR}/src/gtest_main.cc libgtest.a \
    -o test
runtest: test
	./test

