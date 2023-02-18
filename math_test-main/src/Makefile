# CC=gcc -std=c11 -D_GNU_SOURCE
# CFLAGC=-c -Wall -Wextra -Werror
# TEST_LIBS=-lcheck -lm -lpthread
# GCOV_FLAGS=--coverage -Wall -Wextra -Werror
# SOURCES=$(wildcard s21_*.c)
# OBJECTS = $(patsubst %.c,%.o, ${SOURCE})
# TESTS_SOURCE = tests.c
# TESTS_OBJECTS = $(patsubst %.c,%.o, ${TESTS_SOURCE})

# ifeq ($(shell uname -s),Linux)
# 	TEST_LIBS += -lrt -lsubunit
# endif

# all: $(SOURCES) test

# .c.o:
# 	$(CC) $(CFLAGC) $< -o $@

# s21_math.a: $(OBJECTS)
# 	ar rcs s21_math.a $(OBJECTS)
# 	ranlib s21_math.a

# clean:
# 	rm -rf $(OBJECTS) $(TEST_OBJECTS) test *.gcov *.gcno *.gcda *.info report s21_math.a

# soft_clean:
# 	rm -rf $(OBJECTS) $(TEST_OBJECTS) test *.gcov *.gcno *.gcda *.info s21_math.a

# rebuild: clean all

# style:
# 	clang-format -n *.c *.h tests/*.c tests/*.h

# gcov_report: $(TEST_OBJECTS)
# 	$(CC) $(GCOV_FLAGS) $(TEST_OBJECTS) $(SOURCES) $(TEST_LIBS) -o test
# 	./test
# 	gcov *.gcno
# 	lcov -t "s21_math" -o s21_math.info -c -d . --rc lcov_branch_coverage=1
# 	genhtml -o report s21_math.info --rc lcov_branch_coverage=1

# test: $(TEST_OBJECTS) s21_math.a
# 	$(CC) $^ -o test $(TEST_LIBS)
# 	./test
GCC = gcc
CFLAGS = -c -Wall -Werror -Wextra -std=c11
LDFLAGS = -O2 -Wall -Werror -Wextra -std=c11
SOURCE = $(wildcard s21_*.c)
HEADER = $(wildcard s21_*.h)
OBJECTS = $(patsubst %.c,%.o, ${SOURCE})
TESTS_SOURCE = tests.c
TESTS_OBJECTS = $(patsubst %.c,%.o, ${TESTS_SOURCE})
UNAME_S := $(shell uname -s)

all: clean s21_math.a test

s21_math.a: ${SOURCE}
	$(GCC) $(CFLAGS) $(ADD_LIB) $(SOURCE)
	ar rc $@ $(OBJECTS)
	ranlib $@
	cp $@ lib$@

test: ${TESTS_SOURCE} s21_math.a
	${GCC} $(LDFLAGS) -o test $^ -lcheck -lm -lpthread
	./test

gcov_report: clean lcov ${SOURCE}
	gcc --coverage ${SOURCE} tests.c -o s21_test -lcheck -lm -lpthread
	./s21_test
	lcov -t "s21_test" -o s21_test.info -c -d .
	genhtml -o report s21_test.info
	$(OPEN_CMD) ./report/index.html

lcov:
ifeq ("", "$(shell PATH=$(PATH) which lcov)")
	$(error Need to install lcov)
endif



clean:
	-rm -rf *.o && rm -rf *.gcno
	-rm -rf *.a && rm -rf *.gcda
	-rm -rf *.info && rm -rf *.gcov
	-rm -rf ./test && rm -rf ./gcov_report
	-rm -rf ./report/
	-rm -rf ./s21_test
