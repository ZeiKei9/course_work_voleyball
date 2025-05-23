CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Iinclude
LDFLAGS :=

SRCS := $(shell find src -name '*.cpp')
OBJS := $(patsubst src/%.cpp,obj/%.o,$(SRCS))
TARGET := volleyball-sim
APP_PATH := VolleyballSim.app/Contents/MacOS
APP_EXEC := $(APP_PATH)/volleyball-sim

all: create-dirs $(TARGET) copy-to-app

create-dirs:
	@mkdir -p $(dir $(OBJS))
	@mkdir -p $(APP_PATH)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

copy-to-app: $(TARGET)
	cp $(TARGET) $(APP_EXEC)
	chmod +x $(APP_EXEC)

obj/%.o: src/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf obj $(TARGET)

.PHONY: all clean create-dirs copy-to-app
