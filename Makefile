CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

# Default target - show usage
.PHONY: help
help:
	@echo "Usage: make <day-number>"
	@echo "Example: make 1  (compiles solution-1.cpp and solution-2.cpp in day-1/)"
	@echo "         make 2  (compiles solution-1.cpp and solution-2.cpp in day-2/)"

# Pattern rule for day numbers
%:
	@if [ ! -d "day-$@" ]; then \
		echo "Error: day-$@ directory does not exist"; \
		exit 1; \
	fi
	@$(MAKE) -f $(lastword $(MAKEFILE_LIST)) day-$@-build

# Build targets for a specific day
.PHONY: day-%-build
day-%-build:
	@DAY_DIR="day-$*"; \
	if [ -f "$$DAY_DIR/solution-1.cpp" ]; then \
		echo "Compiling $$DAY_DIR/solution-1.cpp -> $$DAY_DIR/1"; \
		$(CXX) $(CXXFLAGS) -o "$$DAY_DIR/1" "$$DAY_DIR/solution-1.cpp"; \
	else \
		echo "Warning: $$DAY_DIR/solution-1.cpp not found, skipping"; \
	fi; \
	if [ -f "$$DAY_DIR/solution-2.cpp" ]; then \
		echo "Compiling $$DAY_DIR/solution-2.cpp -> $$DAY_DIR/2"; \
		$(CXX) $(CXXFLAGS) -o "$$DAY_DIR/2" "$$DAY_DIR/solution-2.cpp"; \
	else \
		echo "Warning: $$DAY_DIR/solution-2.cpp not found, skipping"; \
	fi

# Clean target - removes executables from all day directories
.PHONY: clean
clean:
	@echo "Cleaning executables..."
	@for dir in day-*/; do \
		if [ -d "$$dir" ]; then \
			if [ -f "$$dir/1" ]; then \
				echo "Removing $$dir/1"; \
				rm -f "$$dir/1"; \
			fi; \
			if [ -f "$$dir/2" ]; then \
				echo "Removing $$dir/2"; \
				rm -f "$$dir/2"; \
			fi; \
		fi; \
	done
	@echo "Clean complete."

