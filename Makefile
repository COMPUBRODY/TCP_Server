CC := g++ # Compiler
SRC_DIR := /Network/src/ # Source directory
BUILD_DIR := build # Build directory
TARGET_SERVER := server # Output executable for server
TARGET_CLIENT := client # Output executable for client

# Flags
FLAGS := -std=c++11

# Flags for x64 Intel Core
x64_FLAGS := -m64 -O2
x64_LIBS :=

# Flags for ARM Raspberry Pi
arm_FLAGS := -march=armv7-a -mfloat-abi=hard -mfpu=neon-vfpv4 -O2
arm_LIBS :=

# List of source files for server and client
SRCS_SERVER := $(wildcard $(SRC_DIR)/server.cpp)
SRCS_CLIENT := $(wildcard $(SRC_DIR)/client.cpp)

# Object files for server and client
OBJS_SERVER := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS_SERVER))
OBJS_CLIENT := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS_CLIENT))

.PHONY: all clean server client


all: server client

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

server: $(TARGET_SERVER)

$(TARGET_SERVER): $(OBJ_SERVER)
	$(CC) $(OBJ_SERVER) -o $(TARGET_SERVER) $(FLAGS)

$(OBJ_SERVER): $(SRC_SERVER) | $(BUILD_DIR)
	$(CC) -c $< -o $@ $(FLAGS)

client: $(TARGET_CLIENT)

$(TARGET_SERVER): $(OBJS_SERVER)
	$(CC) $(OBJS_SERVER) -o $(TARGET_SERVER) $(FLAGS) $(LIBS)

$(TARGET_CLIENT): $(OBJS_CLIENT)
	$(CC) $(OBJS_CLIENT) -o $(TARGET_CLIENT) $(FLAGS) $(LIBS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) -c $< -o $@ $(FLAGS)

# Condition for x64
ifeq ($(ARCH), x64)
FLAGS := $(x64_FLAGS)
LIBS := $(x64_LIBS)
endif

# Condition for ARM
ifeq ($(ARCH), arm)
CC := g++-arm-linux-gnueabihf
FLAGS := $(arm_FLAGS)
LIBS := $(arm_LIBS)
endif

clean:
	rm -rf $(BUILD_DIR) $(TARGET_SERVER) $(TARGET_CLIENT)