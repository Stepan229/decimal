.PHONY: all s21_decimal.a
CC = gcc
FLAGS = -Wall -Wextra -Werror -std=c11
LIB = s21_decimal.a
LIB_DIR = *.c
TESTFILE = test
GCOV_FLAG = -fprofile-arcs -ftest-coverage
LIBS_FOR_CHECK_PCKG = -lcheck -lsubunit -lm -lpthread 
OS = $(shell uname -s)



all: s21_decimal

s21_decimal:
	$(CC) $(FLAGS) $(LIB_DIR) -o decimal
	rm -rf *.o
	./decimal

clean:
	rm -f *.a *.o *.so *.out $(TESTFILE) *.info *.gcno *.gcda
	rm -f *$(TEST_LIB)*.a *$(TEST_LIB)*.o
	rm -rf report
	rm -rf .clang-format
	rm -rf function/.clang-format
	rm -rf test-funct