# makefile
# use to compile and test 

DEBUG_FLAG= -DDEBUG -g -Wall
CCFLAGS= -std=c++11 -DDEBUG -g -Wall

.SUFFIXES: .cpp .o

.cpp.o:
	g++ $(CCFLAGS) -c $<


Processor: Processor.o Parser.o PC.h InstructionMemory.o RegisterTable.o DataMemory.o Multiplexor.h ControlUnit.o ALUControl.o ALU.o ShiftLeftTwo.o SignExtend.o Utility.h
	g++ $(CCFLAGS) -o Parser.o PC.h InstructionMemory.o RegisterTable.o DataMemory.o Multiplexor.h ControlUnit.o ALUControl.o ALU.o ShiftLeftTwo.o SignExtend.o Utility.h

ALU.o: ALU.h

ALUControl.o: ALUControl.h Utility.h

ControlUnit.o: ControlUnit.h Utility.h

DataMemory.o: DataMemory.h

InstructionMemory.o: InstructionMemory.h Utility.h

Opcode.o: Opcode.h

Parser.o: Parser.h Opcode.h Utility.h

RegisterTable.o: RegisterTable.h

ShiftLeftTwo.o: ShiftLeftTwo.h

SignExtend.o: SignExtend.h

clean:
	/bin/rm -f Processor *.o core

