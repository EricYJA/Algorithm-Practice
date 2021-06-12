SRC = main.cc sort.cc 
OBJ = main.o sort.o
TARGET = test
CC = g++ -std=c++11

$(TARGET): $(OBJ)
		$(CC) $(OBJ) -o $(TARGET) 

$(OBJ): $(SRC)
		$(CC) -c $(SRC) 

.PHONY: clean  
clean:  
		rm -rf $(OBJ) $(TARGET)
