file ?= none
compile:
	g++ $(file).cpp -m32 -Wall -o $(file) 
