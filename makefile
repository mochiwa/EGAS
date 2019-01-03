

# $@ : the file being generated
# $< : the name of the first prerequisite
# $^ : the name of all prerequisites a b c d ....


##########--- File and Directory ----##########
BUILD_DIRECTORY := build

HEADER_DIRECTORY := include     									
HEADER_DIRECTORIES := $(shell find $(HEADER_DIRECTORY) -type d)

SOURCE_DIRECTORY := src
SOURCE_FILES := $(shell find $(SOURCE_DIRECTORY) -type f -name *.cpp)
OBJECT_FILES := $(patsubst $(SOURCE_DIRECTORY)/%,$(BUILD_DIRECTORY)/%,$(SOURCE_FILES:.cpp=.o))

TARGET := bin/main

##########--- Include and Directive ---##########
CC := g++
CFLAGS := -g -Wall -Wextra
INCLUDE_DIRECTIVE := $(addprefix -I , $(HEADER_DIRECTORIES))

main : build_tree $(TARGET)

$(TARGET):	$(OBJECT_FILES)
	@echo " Linking..."
	@$(CC) $^ -o $(TARGET)


$(BUILD_DIRECTORY)/%.o:	$(SOURCE_DIRECTORY)/%.cpp
	@echo "Compiling of " $@
	@$(CC) $(CFLAGS) $(INCLUDE_DIRECTIVE) -c -o $@ $<

build_tree:
	@echo "Making builder tree directory"; 
	@mkdir -p $(patsubst include%,$(BUILD_DIRECTORY)%,$(HEADER_DIRECTORIES)); 

clean:
	@echo " Cleaning..."; 
	@$(RM) -r $(BUILD_DIRECTORY) $(TARGET)

run:
	cd bin && ./main
	#@echo $(patsubst $(A),$(BUILD_DIRECTORY)/%,$(A)); 