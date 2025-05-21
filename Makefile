CXX = g++

INCLUDEDIR := include
BUILDDIR := build
SRC_DIR := src
OBJ_DIR := $(BUILDDIR)
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))
INCS := $(wildcard $(INCLUDEDIR)/*.hpp)

.PHONY: clean all

all: $(BUILDDIR)/stat

$(BUILDDIR)/stat: $(OBJS)
	$(CXX) $(OBJS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(INCS)
	@mkdir -p build
	$(CXX) -I $(INCLUDEDIR) -c $< -o $@

clean:
	rm -rf build
