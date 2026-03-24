CXX = g++
CXXFLAGS = -std=c++17 -Wall -O3 -Iinclude

SRC_DIR = src
TEST_DIR = tests
INC_DIR = include

TARGET = autodiff_solver
TEST_TARGET = run_tests
TEST_FUNC_TARGET = test_function

all: $(TARGET) $(TEST_TARGET) $(TEST_FUNC_TARGET)

$(TARGET): $(SRC_DIR)/main.cpp $(INC_DIR)/jet.hpp $(INC_DIR)/function.hpp
	$(CXX) $(CXXFLAGS) $(SRC_DIR)/main.cpp -o $(TARGET)

$(TEST_TARGET): $(TEST_DIR)/test_jet.cpp $(INC_DIR)/jet.hpp
	$(CXX) $(CXXFLAGS) $(TEST_DIR)/test_jet.cpp -o $(TEST_TARGET)

$(TEST_FUNC_TARGET): $(TEST_DIR)/test_function.cpp $(INC_DIR)/jet.hpp $(INC_DIR)/function.hpp
	$(CXX) $(CXXFLAGS) $(TEST_DIR)/test_function.cpp -o $(TEST_FUNC_TARGET)

test: all
	./$(TEST_TARGET)
	./$(TEST_FUNC_TARGET)

clean:
	rm -f $(TARGET) $(TEST_TARGET) $(TEST_FUNC_TARGET)

.PHONY: all clean test