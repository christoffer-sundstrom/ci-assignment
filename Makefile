CXX = g++
CXXFLAGS = -std=c++17
LDFLAGS = -lgtest -lgtest_main -lgmock

EXECUTABLE = program
SRCS = test.cpp
OBJS = $(SRCS:.cpp=.o)
BUILD_DIR = build/

all: build

build: $(OBJS)
		@echo "Building program..."
		@$(CXX) -o $(BUILD_DIR)$(EXECUTABLE) $(BUILD_DIR)$^ $(LDFLAGS)
		@echo "...done!"

run: test
		@echo "Running program:"
		@./$(BUILD_DIR)$(EXECUTABLE)

%.o: %.cpp
		@echo "Generating objects..."
		@mkdir -p $(BUILD_DIR)
		@$(CXX) $(CXXFLAGS) -c $< -o $(BUILD_DIR)$@
		@echo "...done!"

clean:
		@echo "Cleaning build folder."
		@rm -rf $(BUILD_DIR)

.PHONY: all clean
