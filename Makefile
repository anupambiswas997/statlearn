CXX = g++

INCLUDEDIR := include
BUILDDIR := build
SRC_DIR := src
OBJ_DIR := $(BUILDDIR)
SRCS1 := $(wildcard $(SRC_DIR)/*.cpp)
SRCS2 := $(wildcard $(SRC_DIR)/models/*.cpp)
OBJS1 := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS1))
OBJS2 := $(patsubst $(SRC_DIR)/models/%.cpp, $(OBJ_DIR)/models/%.o, $(SRCS2))
OBJS := $(OBJS1) $(OBJS2)
INCS := $(wildcard $(INCLUDEDIR)/*.hpp)

.PHONY: clean all

all: $(BUILDDIR)/stat

$(BUILDDIR)/stat: $(OBJS)
	$(CXX) $(OBJS) -o $@

$(OBJ_DIR)/models/%.o: $(SRC_DIR)/models/%.cpp $(INCS)
	@mkdir -p $(dir $@)
	$(CXX) -I $(INCLUDEDIR) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(INCS)
	@mkdir -p $(dir $@)
	$(CXX) -I $(INCLUDEDIR) -c $< -o $@

clean:
	rm -rf build