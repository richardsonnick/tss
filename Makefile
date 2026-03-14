CXX = g++
CXX_FLAGS = -std=c++23 -MMD -Iinclude -Wall
TARGET = bin/tss
SRCS = src/types.cpp src/main.cpp
OBJS = $(patsubst src/%.cpp,obj/%.o,$(SRCS))
DEPS = $(patsubst src/%.cpp,obj/%.d,$(SRCS))

all: $(TARGET)

-include $(DEPS)

$(TARGET) : $(OBJS)
	$(CXX) $(CXX_FLAGS) $(OBJS) -o $(TARGET)


obj/%.o: src/%.cpp
	$(CXX) $(CXX_FLAGS) -c $< -o $@

tags:
	ctags -R . /usr/include/c++/15.2.1/

clean:
	rm ./obj/*
