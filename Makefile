CC := g++ # Compiler
SRC_DIR := Network/src/ # Source directory
INC_DIR := Network/include/ # Source directory
BUILD_DIR := Network/bin/ # Build directory

LINKOBJ  = main.o Network/bin/client.o Network/bin/server.o Network/bin/network.o 
BIN      = TCP_Echo_Server.a

# Flags
FLAGS := -std=c++11
INCLUDES := -I$(INC_DIR) #Add the include directory

.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) all-after
	mkdir -p $(BUILD_DIR)
	
$(BIN): $(LINKOBJ)
	$(CC) $(LINKOBJ) -o $(BIN)

main.o: main.cpp
	$(CC) -c main.cpp -o main.o $(FLAGS)

Network/bin/client.o: Network/src/client.cpp
	$(CC) -c Network/src/client.cpp -o Network/bin/client.o $(FLAGS)


Network/bin/server.o: Network/src/server.cpp
	$(CC) -c Network/src/server.cpp -o Network/bin/server.o $(FLAGS)

Network/bin/network.o: Network/src/network.cpp
	$(CC) -c Network/src/network.cpp -o Network/bin/network.o $(FLAGS)


clean: clean-custom
	${RM} $(OBJ) $(BIN)
