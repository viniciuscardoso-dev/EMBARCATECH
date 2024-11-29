CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TEST_DIR = tests
SRC_DIR = src
UNITY_DIR = $(TEST_DIR)/unity

all: test

test:
	gcc -Wall -Wextra -std=c99 -DUNITY_INCLUDE_DOUBLE tests/test_delta.c src/delta.c tests/unity/unity.c -o test_delta

clean:
	rm -f test_delta
