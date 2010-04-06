CXXFLAGS =	-O2 -g -Wall -fmessage-length=0
SRC_DIR = ./

hipertenusa.in: gen_input_hipertenusa.exe
	./gen_input_hipertenusa.exe > hipertenusa.in
	rm gen_input_hipertenusa.exe

%.exe:
	$(CXX) $(SRC_DIR)/$*.cpp -o $*.exe


%_test: %.exe %.in
	./$*.exe < $*.in > $*.out 
	rm $*.exe

all: fracoes_test hipertenusa_test pizza_test robos_test

clean:
	rm -f *.exe
