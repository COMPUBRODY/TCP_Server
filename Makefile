CC := g++ # Compiler
SRC_DIR := Network/src/ # Source directory
BUILD_DIR := Network/bin/ # Build directory
TARGET_FILE_SERVER := server.cpp
TARGET_SERVER := server.a # Output executable for server
TARGET_CLIENT := client.a # Output executable for client

# Flags
FLAGS := -std=c++11

.PHONY: all

all:

	mkdir -p $(BUILD_DIR)
	
server: 

	$(CC) Network/src/server.cpp -o Network/bin/server.a $(FLAGS)


client: 

	$(CC) Network/src/client.cpp -o Network/bin/client.a $(FLAGS)



clean:
	rm -rf $(BUILD_DIR) $(TARGET_SERVER) $(TARGET_CLIENT)
