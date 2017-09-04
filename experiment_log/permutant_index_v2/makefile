CC = gcc
CFLAGS = -I. -Wall
BUILD_DIR = build
SOURCE_DIR = src
LIB_DIR = lib
HEADER_DIR = include
TEST_DIR = test
DEPS = $(shell find $(HEADER_DIR) -name '*.h')

TEST_SRC = $(shell find $(TEST_DIR) -name '*.test.c')
TEST_OBJ = build/element.test

UNITY_SOURCE = lib/Unity/src/unity.c


$(BUILD_DIR)/%.test: $(TEST_DIR)/%.test.c $(SOURCE_DIR)/%.c $(UNITY_SOURCE)
	@mkdir -p $(BUILD_DIR)
	$(CC) $^ $(CFLAGS) -o $@

element.test: $(TEST_OBJ)
	$(CC) $(CFLAGS) -c -o $@ $<
	./$(BUILD_DIR)/element.test

clean:
	rm -rfv build
# gcc -o bin/tests/$@ $ $(CFLAGS)
# TEST_SOURCES := $(shell find $(SOURCEDIR) -name '*.test.c')
# $(BUILD_DIR)/%.o : $(TEST_SOURCES)
#     $(CC) $(CFLAGS) -c -o $@ $<
# tests: $(TEST_SOURCES)
