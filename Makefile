CXXFLAGS =	-O2 -g -Wall -fmessage-length=0
SRC_DIR = src
USER = deboratads

tests/%/sample_gen.in: gerador_%.exe
	./gerador_$*.exe > tests/$*/sample_gen.in

gerador_%.exe: tests/%/gerador.cpp
	$(CXX) tests/$*/gerador.cpp -o gerador_$*.exe

%.exe: $(SRC_DIR)/$(USER)/%.cpp
	$(CXX) $(SRC_DIR)/$(USER)/$*.cpp -o $*.exe

%_test_sample_gen: tests/%/sample_gen.in %.exe
	./$*.exe < tests/$*/sample_gen.in > $*_sample_gen.out

%_test_sample: %.exe tests/%/sample.in
	./$*.exe < tests/$*/sample.in > $*_sample.out
	diff $*_sample.out tests/$*/sample.out 

%_test_full: %.exe tests/%/full.in
	./$*.exe < tests/$*/full.in > $*_full.out
	diff $*_full.out tests/$*/full.out 

all: contando_test_sample contando_test_full

clean:
	rm -f *.exe
