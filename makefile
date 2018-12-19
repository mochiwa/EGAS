CC := g++
SRCDIR := src
BUILDDIR := build
TARGET := bin/main
 
SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS := -g -Wall
INC := -I include -I include/SQLParser



$(TARGET):	$(OBJECTS)
	@echo " Linking..."
	$(CC) $^ -o $(TARGET)

$(BUILDDIR)/%.o:	$(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<


clean:
	@echo " Cleaning..."; 
	$(RM) -r $(BUILDDIR) $(TARGET)


.PHONY: clean

run:
	cd bin && ./main