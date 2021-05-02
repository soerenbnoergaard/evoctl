.PHONY: all clean cleanall

all: 
	make -C fltk all
	make -C src

clean:
	make -C src clean

cleanall: clean
	git submodule foreach git reset --hard
	git submodule foreach git clean -xdf
