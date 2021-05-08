TARGET = evoctl$(EXEEXT)
SOURCES = main.cxx transfer_matrix_table.cxx
OBJECTS = $(SOURCES:.cxx=.o)

ifeq '$(OS)' "Windows_NT"
EXEEXT = .exe
endif

LIBUSBFLAGS  = -I/usr/include/libusb-1.0 -lusb-1.0 
FLTKCONFIG   = ../fltk/fltk-config
CXX          = $(shell $(FLTKCONFIG) --cxx)
CXXFLAGS     = $(shell $(FLTKCONFIG) --cxxflags) -Wall -I. $(LIBUSBFLAGS)
LINKFLTK     = $(shell $(FLTKCONFIG) --ldstaticflags) $(LIBUSBFLAGS)
LINKFLTK_GL  = $(shell $(FLTKCONFIG) --use-gl --ldstaticflags)
LINKFLTK_IMG = $(shell $(FLTKCONFIG) --use-images --ldstaticflags)
LINKFLTK_ALL = $(shell $(FLTKCONFIG) --use-images --use-gl --ldstaticflags)
.SUFFIXES: .cxx .h .fl .o $(EXEEXT)

RM    = rm -f
SHELL = /bin/sh
.SILENT:

default all: $(TARGET)

clean:
	$(RM) $(TARGET)
	$(RM) *.o
	$(RM) core

# HOW TO LINK
$(TARGET): $(OBJECTS)
	@echo "*** Linking $@..."
	$(CXX) $(OBJECTS) $(LINKFLTK) $(LINKFLTK_IMG) -o $@

# HOW TO COMPILE
.cxx.o:
	@echo "*** Compile $<..."
	$(CXX) -I.. $(CXXFLAGS) -c $< -o $@

