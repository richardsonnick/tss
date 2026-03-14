CXX = g++
CXX_FLAGS = -std=c++23 -MMD -Iinclude
SRCS = src/types.cpp
OBJS = $(patsubst src/%.cpp,obj/%.o,$(SRCS))
DEPS = $(patsubst src/%.cpp,obj/%.d,$(SRCS))

-include $(DEPS)

all: $(OBJS)

say: 
	echo "hello!"

obj/%.o: src/%.cpp
	$(CXX) $(CXX_FLAGS) -c $< -o $@

