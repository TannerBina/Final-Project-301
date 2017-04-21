# makefile
# use to compile and test 

OBJS = ALU.o ALUControl.o ControlUnit.o DataMemory.o InstructionMemory.o Opcode.o Parser.o RegisterTable.o Utility.o PC.o Multiplexor.o ShiftLeftTwo.o SignExtend.o Processor.cpp
CC = g++ 
DEBUG = -g
CFLAGS = -Wall -std=c++11 -c $(DEBUG)
LFLAGS = -Wall  -std=c++11 $(DEBUG)


Processor: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o Processor

ALU.o: ALU.h ALU.cpp 
	$(CC) $(CFLAGS) ALU.cpp

ALUControl.o: ALUControl.h ALUControl.cpp Utility.h Utility.cpp
	$(CC) $(CFLAGS) ALUControl.cpp

ControlUnit.o: ControlUnit.h ControlUnit.cpp Utility.h Utility.cpp
	$(CC) $(CFLAGS) ControlUnit.cpp

DataMemory.o: DataMemory.h DataMemory.cpp
	$(CC) $(CFLAGS) DataMemory.cpp

InstructionMemory.o: InstructionMemory.h InstructionMemory.cpp Utility.h Utility.cpp
	$(CC) $(CFLAGS) InstructionMemory.cpp


Opcode.o: Opcode.h Opcode.cpp
	$(CC) $(CFLAGS) Opcode.cpp

Parser.o: Parser.h Parser.cpp Opcode.h Opcode.cpp Utility.h Utility.cpp
	$(CC) $(CFLAGS) Parser.cpp

RegisterTable.o: RegisterTable.h RegisterTable.cpp
	$(CC) $(CFLAGS) RegisterTable.cpp

Utility.o: Utility.h Utility.cpp
	$(CC) $(CFLAGS) Utility.cpp

PC.o: PC.h PC.cpp
	$(CC) $(CFLAGS) PC.cpp


Multiplexor.o: Multiplexor.h Multiplexor.cpp
	$(CC) $(CFLAGS) Multiplexor.cpp

ShiftLeftTwo.o: ShiftLeftTwo.h ShiftLeftTwo.cpp
	$(CC) $(CFLAGS) ShiftLeftTwo.cpp

SignExtend.o: SignExtend.h SignExtend.cpp
	$(CC) $(CFLAGS) SignExtend.cpp

clean:
	/bin/rm -f Processor *.o core



