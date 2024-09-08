# Makefile for compiling and linking .C files with asm files
# 26.08.2022 (Fredrik Mørstad & Fredrik Fasteraune): 
# Added docker sub-command
# 21.08.2023 Øyvind Nohr:
# + updated course to x64


# Makefile for compiling and linking .C files with asm files
# Variables
CC = gcc
ASM = nasm
CFLAGS = -Wall -O2 -m64 -g
ASMFLAGS = -f win64

all: quicksort_benchmark.exe

quicksort_benchmark.exe: main.o asm.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c
	$(CC) $(CFLAGS) -c $<

asm.o: asm.s
	$(ASM) $(ASMFLAGS) -o $@ $<

clean:
	del *.o quicksort_benchmark.exe
