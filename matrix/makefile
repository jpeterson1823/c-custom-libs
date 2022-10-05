SRC_DIR := ./src
INC_DIR := ./include
OBJ_DIR := ./obj

matrix: $(SRC_DIR)/matrix.c $(SRC_DIR)/__matrix.c
	gcc -I$(INC_DIR) -lm -c $(SRC_DIR)/matrix.c -o $(OBJ_DIR)/matrix.o
	gcc -I$(INC_DIR) -lm -c $(SRC_DIR)/__matrix.c -o $(OBJ_DIR)/__matrix.o

clean:
	rm -f $(OBJ_DIR)/*

lib:
	make matrix
	ar -cvq libmatrix.a $(OBJ_DIR)/matrix.o $(OBJ_DIR)/__matrix.o

test:
	gcc -g -I$(INC_DIR) -lm $(SRC_DIR)/matrix.c $(SRC_DIR)/__matrix.c $(SRC_DIR)/test.c -o matrix_tests
