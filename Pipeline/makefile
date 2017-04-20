# makefile
# use to compile and test 

DEBUG_FLAG= -DDEBUG -g -Wall
CCFLAGS= -DDEBUG -g -Wall

.SUFFIXES: .cpp .o

.cpp.o:
	g++ $(CCFLAGS) -c $<


Processor: Processor.h
	g++ -std=c++11 -o Parser.o PC.o InstructionMemory.o RegisterTable.o DataMemory.o Multiplexor.o ControlUnit.o ALUControl.o ALU.o ShiftLeftTwo.o SignExtend.o

ALU.o: ALU.h

ALUControl.o: ALUControl.h

ControlUnit.o: ControlUnit.h

DataMemory.o: DataMemory.h

InstructionMemory.o: InstructionMemory.h

Multiplexor.o: Multiplexor.h

Opcode.o: Opcode.h

PC.o: PC.h

Parser.o: Parser.h
	g++ -o Opcode.o

RegisterTable.o: RegisterTable.h

ShiftLeftTwo.o: ShiftLeftTwo.h

SignExtend.o: SignExtend.h

Utility.o: Utility.h

clean:
	/bin/rm -f Final *.o core

