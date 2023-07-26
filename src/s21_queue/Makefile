.PHONY: all clean rebuild
CXX = g++ -std=c++17
CXXFLAGS = -Wall -Werror -Wextra -g
PROJECT = s21_queue
OS = $(shell uname -s)
TEST_FLAGS = -o test.out -lgtest

ifeq ($(OS), Linux)
	TEST_FLAGS += -lpthread
endif

all: $(PROJECT).a test gcov_report check

$(PROJECT).a: $(PROJECT).hpp
	$(CXX) $(CXXFLAGS) -c $(PROJECT).hpp -o $(PROJECT).o
	ar rcs $(PROJECT).a $(PROJECT).o
	ranlib $(PROJECT).a

test: $(PROJECT)_tests.cc $(PROJECT).a
	$(CXX) $(CXXFLAGS) $(PROJECT)_tests.cc $(PROJECT).a $(TEST_FLAGS)
	./test.out

gcov_report:  
	$(CXX) $(CXXFLAGS) -fprofile-arcs -ftest-coverage $(PROJECT)_tests.cc -c
	$(CXX) $(CXXFLAGS) -fprofile-arcs -ftest-coverage $(PROJECT).hpp -c 
	$(CXX) $(CXXFLAGS) -fprofile-arcs -ftest-coverage $(PROJECT)_tests.o $(PROJECT).o $(TEST_FLAGS)
	./test.out
	lcov -t "test" -o test.info --no-external -c -d . --ignore-errors inconsistent
	genhtml -o report test.info --ignore-errors inconsistent
ifeq ($(OS), Darwin)
	open ./report/index.html
else
	xdg-open ./report/index.html
endif

clean:
	rm -rf *.out *.gcda *.gcno *.a *.info *.o report *.dSYM *.gch

check:
	clang-format -style=google -n *.cc *.h
	cppcheck *.cc
ifeq ($(OS), Darwin)
	CK_FORK=no leaks --atExit -- ./test.out
else
	valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./test.out
endif

rebuild: clean all
