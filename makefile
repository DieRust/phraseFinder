SRC_DIR   := src
NAME := -o lab
GCC_FLAGS := -g -Wall

all: $(SRC_DIR)/labTwo.c $(SRC_DIR)/mylib.c
	gcc $(SRC_DIR)/labTwo.c $(SRC_DIR)/mylib.c $(NAME) $(GCC_FLAGS)