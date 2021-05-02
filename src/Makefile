ifeq '$(OS)' "Windows_NT"
EXEEXT = .exe
endif

FLTKCONFIG   = ../fltk//fltk-config
CXX          = $(shell $(FLTKCONFIG) --cxx)
CXXFLAGS     = $(shell $(FLTKCONFIG) --cxxflags) -Wall -I.
LINKFLTK     = $(shell $(FLTKCONFIG) --ldstaticflags)
LINKFLTK_GL  = $(shell $(FLTKCONFIG) --use-gl --ldstaticflags)
LINKFLTK_IMG = $(shell $(FLTKCONFIG) --use-images --ldstaticflags)
LINKFLTK_ALL = $(shell $(FLTKCONFIG) --use-images --use-gl --ldstaticflags)
.SUFFIXES: .cxx .h .fl .o $(EXEEXT)

# HOW TO COMPILE
.cxx.o:
	@echo "*** Compile $<..."
	$(CXX) -I.. $(CXXFLAGS) -c $< -o $@

# HOW TO LINK
.o$(EXEEXT):
	@echo "*** Linking $@..."
	$(CXX) $< $(LINKFLTK) $(LINKFLTK_IMG) -o $@

RM    = rm -f
SHELL = /bin/sh
.SILENT:

ALL = evoctl$(EXEEXT)

default all: $(ALL)

clean:
	$(RM) $(ALL)
	$(RM) *.o
	$(RM) core
