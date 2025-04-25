# Компилятор
CXX := g++
# Флаги компиляции
CXXFLAGS := -std=c++17 -Wall -Wextra -Iinclude
# Флаги линковки
LDFLAGS := 

# Исходные файлы (рекурсивный поиск всех .cpp файлов)
SRCS := $(shell find src -name '*.cpp')
# Объектные файлы
OBJS := $(patsubst src/%.cpp,obj/%.o,$(SRCS))
# Исполняемый файл
TARGET := volleyball-sim

# Основная цель
all: create-dirs $(TARGET)

# Создание директорий для объектных файлов
create-dirs:
	@mkdir -p $(dir $(OBJS))

# Линковка
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

# Компиляция
obj/%.o: src/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Очистка
clean:
	rm -rf obj $(TARGET)

.PHONY: all clean create-dirs