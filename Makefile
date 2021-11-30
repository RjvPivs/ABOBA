task: main.cpp Riddle.cpp Aphorism.cpp Error_Informing.cpp Proverb.cpp nasm.o BinSort.o
	g++ -g -o task main.cpp Riddle.cpp Aphorism.cpp Error_Informing.cpp Proverb.cpp nasm.o BinSort.o -no-pie
nasm.o: nasm.asm
	nasm -f elf64 -g -F dwarf nasm.asm -l nasm.lst
BinSort.o: BinSort.asm
	nasm -f elf64 -g -F dwarf BinSort.asm -l BinSort.lst
