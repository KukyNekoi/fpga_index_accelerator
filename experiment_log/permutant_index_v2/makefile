CC = gcc
CFLAGS = -Wall

TEST_SOURCES := $(shell find $(SOURCEDIR) -name '*.test.c')
BUILD_DIR = build
SOURCE_DIR = src
HEADER_DIR = src

$(BUILD_DIR)/%.o : %.c
    $(CC) $(CFLAGS) -c -o $@ $<
