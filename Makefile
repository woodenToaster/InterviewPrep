CXX = g++
GTEST_DIR = /usr/src/gtest
GTEST_LIB_DIR = /usr/lib
CPPFLAGS += -isystem $(GTEST_DIR)/include
CXXFLAGS += -g -Wall -Wextra -pthread -std=c++11
TESTS = test
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h $(GTEST_DIR)/include/gtest/internal/*.h
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h 


all: $(TESTS)

clean:
	rm -f $(TESTS) *.o

gtest-all.o: $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o: $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c $(GTEST_DIR)/src/gtest_main.cc

gtest.a: gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a: gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

anagram.o: anagram.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c anagram.cpp

rotate90.o: rotate90.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c rotate90.cpp

decode.o: decode.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c decode.cpp

test.o: test.cpp test.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c test.cpp

test: anagram.o rotate90.o decode.o test.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@
