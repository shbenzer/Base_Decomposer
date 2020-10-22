cc = g++  # use g++ compiler

flags = -std=c++11  # compile with C++ 11 standard
flags += -Wall      # compile with all warnings

link = $(cc) $(flags) -o  # final linked build to binary executable

compile = $(cc) $(flags) -c -o  # compilation to intermediary .o files

base-decomposer : base-decomposer.o
	$(link) $@ $^ 

base-decomposer.o : base_decomposer.cc
	$(compile) $@ $^ 

test1 : base-decomposer
	python3 test_decomposer.py 1

test2 : base-decomposer
	python3 test_decomposer.py 2

test : test1 test2
	@echo "Tests Ran!" 

clean:
	@rm -f base-decomposer.o base-decomposer
