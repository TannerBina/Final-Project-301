#include "Opcode.h"

OpcodeTable::OpcodeTable(){
	myTable[ADD].name = "add"; myTable[ADD].numOps = 3; myTable[ADD].rdPos = 0; myTable[ADD].rsPos = 1; myTable[ADD].rtPos = 2; myTable[ADD].immPos = -1; myTable[ADD].instType = RTYPE; myTable[ADD].op_field = "000000"; myTable[ADD].funct_field = "100000";
	myTable[SUB].name = "sub"; myTable[SUB].numOps = 3; myTable[SUB].rdPos = 0; myTable[SUB].rsPos = 1; myTable[SUB].rtPos = 2; myTable[SUB].immPos = -1; myTable[SUB].instType = RTYPE; myTable[SUB].op_field = "000000"; myTable[SUB].funct_field = "100010";
	myTable[ADDI].name = "addi"; myTable[ADDI].numOps = 3; myTable[ADDI].rdPos = 0; myTable[ADDI].rsPos = 1; myTable[ADDI].rtPos = -1; myTable[ADDI].immPos = 2; myTable[ADDI].instType = ITYPE; myTable[ADDI].op_field = "001000"; myTable[ADDI].funct_field = "000000"; 
	myTable[SLT].name = "slt"; myTable[SLT].numOps = 3; myTable[SLT].rdPos = 0; myTable[SLT].rsPos = 1; myTable[SLT].rtPos = 2; myTable[SLT].immPos = -1; myTable[SLT].instType = RTYPE; myTable[SLT].op_field = "000000"; myTable[SLT].funct_field = "101010"; 
	myTable[LW].name = "lw"; myTable[LW].numOps = 3; myTable[LW].rdPos = -1; myTable[LW].rsPos = 2; myTable[LW].rtPos = 0; myTable[LW].immPos = 1; myTable[LW].instType = ITYPE; myTable[LW].op_field = "100011"; myTable[LW].funct_field = "000000";
	myTable[SW].name = "sw"; myTable[SW].numOps = 3; myTable[SW].rdPos = -1; myTable[LW].rsPos = 2; myTable[SW].rtPos = 0; myTable[SW].immPos = 1; myTable[SW].instType = ITYPE; myTable[LW].op_field = "101011"; myTable[SW].funct_field = "000000";
	myTable[BEQ].name = "beq"; myTable[BEQ].numOps = 3; myTable[BEQ].rdPos = -1; myTable[BEQ].rsPos = 0; myTable[BEQ].rtPos = 1; myTable[BEQ].immPos = 2; myTable[BEQ].instType = ITYPE; myTable[BEQ].op_field = "000100"; myTable[BEQ].funct_field = "000000";
	myTable[J].name = "j"; myTable[J].numOps = 0; myTable[J].rdPos = -1; myTable[J].rsPos = -1; myTable[J].rtPos = -1; myTable[J].immPos = -1; myTable[J].instType = JTYPE; myTable[J].op_field = "000010"; myTable[J].funct_field = "000000"; myTable[J].immLabel = true;
}

string OpcodeTable::getOpcode(string str)
// Given a valid MIPS assembly mnemonic, returns an Opcode which represents a 
// template for that instruction.
{
  for(int i = 0; i < (int )UNDEFINED; i++){
    if(myTable[i].name == str){
      return myTable[i].op_field;
    }
  }
  return '\0';
}

<<<<<<< HEAD
int OpcodeTable::numOperands(Opcode o)
=======
long OpcodeTable::numOperands(string str)
>>>>>>> 6e8850a34e79551e499cf58d894a45bf091843eb
// Given an Opcode, returns number of expected operands.
{
 for(long i = 0; i < (long )UNDEFINED; i++){
    if(myTable[i].name == str){
      return myTable[i].numOps;
    }
  }
  return -1;
}


<<<<<<< HEAD
int OpcodeTable::RSposition(Opcode o)
=======
long OpcodeTable::RSposition(string str)
>>>>>>> 6e8850a34e79551e499cf58d894a45bf091843eb
// Given an Opcode, returns the position of RS field.  If field is not
// appropriate for this Opcode, returns -1.
{
  for(long i = 0; i < (long )UNDEFINED; i++){
    if(myTable[i].name == str){
      return myTable[i].rsPos;
    }
  }
  return -1;
}

<<<<<<< HEAD
int OpcodeTable::RTposition(Opcode o)
=======
long OpcodeTable::RTposition(string str)
>>>>>>> 6e8850a34e79551e499cf58d894a45bf091843eb
// Given an Opcode, returns the position of RT field.  If field is not
// appropriate for this Opcode, returns -1.
{
  for(long i = 0; i < (long )UNDEFINED; i++){
    if(myTable[i].name == str){
      return myTable[i].rtPos;
    }
  }
  return -1;
}

<<<<<<< HEAD
int OpcodeTable::RDposition(Opcode o)
=======
long OpcodeTable::RDposition(string str)
>>>>>>> 6e8850a34e79551e499cf58d894a45bf091843eb
// Given an Opcode, returns the position of RD field.  If field is not
// appropriate for this Opcode, returns -1.
{
  for(long i = 0; i < (long )UNDEFINED; i++){
    if(myTable[i].name == str){
      return myTable[i].rdPos;
    }
  }
  return -1;
}

<<<<<<< HEAD
int OpcodeTable::IMMposition(Opcode o)
=======
long OpcodeTable::IMMposition(string str)
>>>>>>> 6e8850a34e79551e499cf58d894a45bf091843eb
// Given an Opcode, returns the position of IMM field.  If field is not
// appropriate for this Opcode, returns -1.
{
  for(long i = 0; i < (long )UNDEFINED; i++){
    if(myTable[i].name == str){
      return myTable[i].immPos;
    }
  }
  return -1;
}

InstType OpcodeTable::getInstType(string str)
// Given an Opcode, returns instruction type.
{
  for(long i = 0; i < (long )UNDEFINED; i++){
    if(myTable[i].name == str){
      return myTable[i].instType;
    }
  }
  return UNDEF;
}


string OpcodeTable::getFunctField(string str)
// Given an Opcode, returns a string representing the binary encoding of the function
// field.
{
  for(long i = 0; i < (long )UNDEFINED; i++){
    if(myTable[i].name == str){
      return myTable[i].funct_field;
    }
  }
  return '\0';
}

bool OpcodeTable::isIMMLabel(string str)
// Given an Opcode, returns true if instruction expects a label in the instruction.
// See "J".
{
  for(long i = 0; i < (long )UNDEFINED; i++){
    if(myTable[i].name == str){
      return myTable[i].immLabel;
    }
  }
  return false;
}
