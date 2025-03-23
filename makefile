SRC_DIR   := src
NAME := -o finder
GCC_FLAGS := -g -Wall

all: $(SRC_DIR)/main.c $(SRC_DIR)/functions.c
	gcc $(SRC_DIR)/main.c $(SRC_DIR)/functions.c $(NAME) $(GCC_FLAGS)