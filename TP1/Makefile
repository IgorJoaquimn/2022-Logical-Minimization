# cc and flags
C++ = g++
C 	= gcc

espresso_input: 
	$(C) src/multipliyer_input_generator.c -o multipliyer_input_generator
	./multipliyer_input_generator > entrada_espresso_6bits.txt
	rm multipliyer_input_generator

espresso_output: espresso_input
	(./exec/espresso < entrada_espresso_6bits.txt) > saida_espresso_6bits.txt

verilog:
	$(C++) src/espresso_to_verilog.cpp -o espresso_to_verilog
	./espresso_to_verilog < saida_espresso_4bits.txt > design.sv
	rm espresso_to_verilog

all: espresso_input espresso_output verilog
