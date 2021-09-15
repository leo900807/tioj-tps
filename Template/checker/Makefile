SOURCES := $(wildcard *.cpp)
EXECUTABLES := $(SOURCES:%.cpp=%.exe)

.PHONY: all clean

all: $(EXECUTABLES)

clean:
	rm -f *.exe

%.exe: %.cpp
	g++ -DTIOJ -std=gnu++14 -O2 -pipe -static -s $< -o $@

compile_outputs_list:
	@echo $(COMPILE_OUTPUTS)
