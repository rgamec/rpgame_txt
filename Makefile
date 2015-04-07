CXX=g++
CXXFLAGS=-I.
DEPS = enemies.h
OBJ = enemies.o rpgame.o
SRCDIR = src
BUILDDIR = build
TARGET = bin/rpgame
SRCEXT = cpp
RM = rm -f

SOURCES = $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
INC = -I include

$(TARGET): $(OBJECTS)
	@echo "Linking..."
	@echo "$(CXX) $^ -o $(TARGET) $(LIB)"
	$(CXX) $^ -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	mkdir -p $(BUILDDIR)
	@echo " $(CXX) $(CXXFLAGS) $(INC) -c -o $@ $<"
	$(CXX) $(CXXFLAGS) $(INC) -c -o $@ $<

clean:
	$(RM) -r $(BUILDDIR) $(TARGET)
