CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

SRC = src/stringutils.c
TEST_SRC = tests/test_runner.c tests/test_split.c tests/test_trim.c tests/test_upper.c

all: demo test

demo: $(SRC) examples/main.c
	$(CC) $(CFLAGS) $(SRC) examples/main.c -o demo

test: $(SRC) $(TEST_SRC)
	$(CC) $(CFLAGS) $(SRC) $(TEST_SRC) -o test_runner

run-test: test
	./test_runner

clean:
	rm -f demo test_runner *.o


.PHONY: all clean run-test
