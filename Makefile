CC := g++ # Compiler
SRC_DIR := Network/src/ # Source directory
INC_DIR := Network/include/ # Source directory
BUILD_DIR := Network/bin/ # Build directory

OBJ      = main.o Network/bin/Client.o Network/bin/Server.o Network/bin/Network.o 
LINKOBJ  = main.o Network/bin/client.o Network/bin/server.o Network/bin/network.o 
S_BIN      = TCP_Echo_Server.a
C_BIN      = TCP_Echo_Client.a

# Flags
FLAGS := -std=c++11
INCLUDES := -I$(INC_DIR) #Add the include directory

.PHONY: all all-before all-after clean clean-custom



all: all-before $(BUILD_DIR) server client all-after
	
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

server: $(LINKOBJ)
	$(CC) $(LINKOBJ) -o $(S_BIN)

client: $(LINKOBJ)
	$(CC) $(LINKOBJ) -o $(C_BIN)

main.o: main.cpp
	$(CC) -c main.cpp -o main.o $(FLAGS)

Network/bin/client.o: Network/src/client.cpp
	$(CC) -c Network/src/client.cpp -o Network/bin/client.o $(FLAGS)


Network/bin/server.o: Network/src/server.cpp
	$(CC) -c Network/src/server.cpp -o Network/bin/server.o $(FLAGS)

Network/bin/network.o: Network/src/network.cpp
	$(CC) -c Network/src/network.cpp -o Network/bin/network.o $(FLAGS)


clean: clean-custom
	${RM} -rf $(BUILD_DIR) $(BIN) $(OBJ)
