TARGET = main
SRC = main.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	g++ -o $(TARGET) $(SRC)

run: $(TARGET)
	@./$(TARGET)

jawa:
	@echo "Jawa jawa jawa jawa jawa jawa jawa jawa jawa"

.PHONY: all run