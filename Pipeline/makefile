# makefile
# use to compile and test 

DEBUG_FLAG= -DDEBUG -g -Wall
CCFLAGS= -DDEBUG -g -Wall

.SUFFIXES: .cpp .o

.cpp.o:
	g++ $(CCFLAGS) -c $<

Final: Final.o ALU.o ALUControl.o ControlUnit.o DataMemory.o InstructionMemory.o Multiplexor.o Opcode.o PC.o Parser.o Processor.o RegisterTable.o ShiftLeftTwo.o SignExtend.o Utility.o
	g++ -std=c++11 -o Final Final.o ALU.o ALUControl.o ControlUnit.o DataMemory.o InstructionMemory.o Multiplexor.o Opcode.o PC.o Parser.o Processor.o RegisterTable.o ShiftLeftTwo.o SignExtend.o Utility.o

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

Processor.o: Processor.h
	g++ -o Parser.o PC.o InstructionMemory.o RegisterTable.o DataMemory.o Multiplexor.o ControlUnit.o ALUControl.o ALU.o ShiftLeftTwo.o SignExtend.o

RegisterTable.o: RegisterTable.h

ShiftLeftTwo.o: ShiftLeftTwo.h

SignExtend.o: SignExtend.h

Utility.o: Utility.h

clean:
	/bin/rm -f Final *.o core

