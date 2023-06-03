.PHONY: all clean rebuild exe
GXX = g++
CXXFLAGS = -std=c++17 -Wall -Werror -Wextra
OS = $(shell uname -s)
TEST_FLAGS = -o test.out -lgtest

ifeq ($(OS), Linux)
	TEST_FLAGS += -o -lpthread
endif


all: exe

src:
	g++ src.cc -std=c++17 && ./a.out   

exe:
	$(GXX) $(CXXFLAGS) s21_list.cc
	@./a.out && rm -rf a.out

s21_list.a: s21_list.cc s21_list.h
	$(CXX) $(CXXFLAGS) s21_list.cc -c
	ar rcs s21_list.a s21_list.o
	ranlib s21_list.a

test: s21_list_tests.cc s21_list.a
	$(CXX) $(CXXFLAGS) s21_list_tests.cc s21_list.a $(TEST_FLAGS)
	./test.out

gcov_report:
	$(CXX) $(CXXFLAGS) -fprofile-arcs -ftest-coverage s21_list_tests.cc s21_list.cc $(TEST_FLAGS)
	./test.out
	lcov -t "test" -o test.info --no-external -c -d . --ignore-errors inconsistent
	genhtml -o report test.info --ignore-errors inconsistent
ifeq ($(OS), Darwin)
	open ./report/index.html
else
	xdg-open ./report/index.html
endif

clean:
	rm -rf *.out
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.a
	rm -rf *.info
	rm -rf *.o
	rm -rf report


check:
	clang-format -style=google -n *.cc *.h
	cppcheck *.cc
ifeq ($(OS), Darwin)
	CK_FORK=no leaks --atExit -- ./test.out
else
	valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./test.out
endif


rebuild: clean all