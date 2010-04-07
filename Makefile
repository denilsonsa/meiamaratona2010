CXXFLAGS =	-O2 -g -Wall -fmessage-length=0
SRC_DIR = src
USER = deboratads

tests/hipertenusa/sample.in: gerador.exe
	./gerador.exe > tests/hipertenusa/sample.in

%.exe:
	$(CXX) $(SRC_DIR)/$(USER)/$*.cpp -o $*.exe

%_test_sample: %.exe tests/%/sample.in
	./$*.exe < tests/$*/sample.in > $*_sample.out
	diff tests/$*/sample.out $*_sample.out

%_test_full: %.exe tests/%/full.in
	./$*.exe < tests/$*/full.in > $*_full.out
	diff tests/$*/full.out $*_full.out

all: contando_test_sample contando_test_full

clean:
	rm -f *.exe
