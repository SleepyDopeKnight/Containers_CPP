.PHONY: all clean rebuild exe
GXX = g++
CXXFLAGS= -std=c++17 -Wall -Werror -Wextra
OS = $(shell uname -s)

all: exe
	
exe:
	$(GXX) $(CXXFLAGS) s21_list.cc
	@./a.out && rm -rf a.out

s21_list.a: s21_list.cc s21_list.h
	$(CXX) $(CXXFLAGS) s21_list.cc -c
	ar rcs s21_list.a s21_list.o
	ranlib s21_list.a

test: s21_list_tests.cc s21_list.a
ifeq ($(OS), Darwin)
	$(CXX) $(CXXFLAGS) s21_list_tests.cc s21_list.a -o test.out -lgtest
else
	$(CXX) $(CXXFLAGS) s21_list_tests.cc s21_list.a -o test.out -lgtest -lpthread
endif
	./test.out

gcov_report:
ifeq ($(OS), Darwin)
	$(CXX) $(CXXFLAGS) -fprofile-arcs -ftest-coverage s21_list_tests.cc s21_list.cc -o test.out -lgtest
else
	$(CXX) $(CXXFLAGS) -fprofile-arcs -ftest-coverage s21_list_tests.cc s21_list.cc -o test.out -lgtest -lpthread
endif
	./test.out
	lcov -t "test" -o test.info --no-external -c -d .
	genhtml -o report test.info
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