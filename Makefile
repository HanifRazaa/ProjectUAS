TARGET = test1
SRC = test1.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	g++ -o $(TARGET) $(SRC)

run: $(TARGET)
	@./$(TARGET)

.PHONY: all run