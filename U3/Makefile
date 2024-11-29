CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TEST_DIR = tests
SRC_DIR = src
UNITY_DIR = $(TEST_DIR)/unity

all: test

test:
	$(CC) $(CFLAGS) $(TEST_DIR)/test_delta.c $(SRC_DIR)/delta.c $(UNITY_DIR)/unity.c -o test_delta ./test_delta

clean:
	rm -f test_delta
