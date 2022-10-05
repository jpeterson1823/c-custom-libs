SRC_DIR := ./src
INC_DIR := ./include
OBJ_DIR := ./obj

vector: $(SRC_DIR)/vector.c
	gcc -I $(INC_DIR) -lm -c $(SRC_DIR)/vector.c -o $(OBJ_DIR)/vector.o

clean:
	rm -f $(OBJ_DIR)/*

lib: vector
	make vector
	ar -cvq libvector.a $(OBJ_DIR)/vector.o

test:
	gcc -g -I $(INC_DIR) -lm $(SRC_DIR)/vector.c $(INC_DIR)/libmatrix.a $(SRC_DIR)/test.c -o vector_tests
