CXX 		= clang++
SRC_DIR 	= src
INCLUDE_DIR = include
TARGET		= LGEngine

SRCS 		= $(SRC_DIR)/main.mm $(SRC_DIR)/Engine.cpp $(SRC_DIR)/MetalRenderer.mm
OBJS		= $(SRCS:.cpp=.o)
CXXFLAGS	= -std=c++17 -Wall -Wextra -ObjC++ -fobjc-arc -I$(INCLUDE_DIR)
LDFLAGS		= -framework Metal -framework QuartzCore -framework Foundation

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $(SRCS) $(LDFLAGS)

clean:
	rm -f $(TARGET) *.o

.PHONY: all clean
