CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -DUNITY_INCLUDE_DOUBLE -I$(SRC_DIR) -D_XOPEN_SOURCE=600 -lm
TEST_DIR = tests
SRC_DIR = src
UNITY_DIR = $(TEST_DIR)/unity
BUILD_DIR = build
UNITY_FILES = $(wildcard $(UNITY_DIR)/*.c)
TEST_SOURCES = $(wildcard $(TEST_DIR)/test_*.c)
TEST_BINS = $(patsubst $(TEST_DIR)/test_%.c, $(BUILD_DIR)/test_%, $(TEST_SOURCES))

all: setup $(TEST_BINS)

$(BUILD_DIR)/test_%: $(TEST_DIR)/test_%.c $(SRC_DIR)/%.c $(UNITY_FILES)
	$(CC) $(CFLAGS) $^ -o $@

setup:
	mkdir -p $(BUILD_DIR)

test: all
	@for test_bin in $(TEST_BINS); do \
		echo "Running $$test_bin..."; \
		$$test_bin; \
	done

clean:
	rm -rf $(BUILD_DIR)
