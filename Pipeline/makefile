# makefile
# use to compile and test 

DEBUG_FLAG= -DDEBUG -g -Wall
CCFLAGS= -DDEBUG -g -Wall

.SUFFIXES: .cpp .o

.cpp.o:
	g++ $(CCFLAGS) -c $<


ASM: ASM.o Instruction.o RegisterTable.o ASMParser.o Opcode.o
	g++ -o ASM ASM.o ASMParser.o Instruction.o RegisterTable.o Opcode.o

ASMParser.o: ASMParser.h RegisterTable.h Instruction.h Opcode.h

Opcode.o: Opcode.h

Instruction.o: Opcode.h RegisterTable.h Instruction.h 

RegisterTable.o: RegisterTable.h 

clean:
	/bin/rm -f ASM *.o core
