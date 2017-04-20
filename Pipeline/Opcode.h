#ifndef __OPCODE_H__
#define __OPCODE_H__

using namespace std;

#include <iostream>
#include <string>


// Listing of all supported MIPS instructions
enum Opcode {
  ADD, 
  SUB, 
  ADDI,
  SLT,
  LW,
  SW,
  BEQ,
  J, 
  UNDEFINED
};

// Different types of MIPS encodings
enum InstType{
  RTYPE,
  ITYPE,
  JTYPE,
  UNDEF
};


/* This class represents templates for supported MIPS instructions.  For every supported
 * MIPS instruction, the OpcodeTable includes information about the opcode, expected
 * operands, and other fields.  
 */
class OpcodeTable {
 public:
  OpcodeTable();

  // Given a valid MIPS assembly mnemonic, returns an Opcode which represents a 
  // template for that instruction.
  string getOpcode(string str);

  // Given an Opcode, returns number of expected operands.
  int numOperands(string str);

  // Given an Opcode, returns the position of RS/RT/RD/IMM field.  If field is not
  // appropriate for this Opcode, returns -1.
  int RSposition(string str);
  int RTposition(string str);
  int RDposition(string str);
  int IMMposition(string str);

  // Given an Opcode, returns true if instruction expects a label in the instruction.
  // See "J".
  bool isIMMLabel(string str);

  // Given an Opcode, returns instruction type.
  InstType getInstType(string str);

  // Given an Opcode, returns a string representing the binary encoding of the function
  // field.
  string getFunctField(string str);


 private:
  struct OpcodeTableEntry{
    string name;
    int numOps;
    int rdPos;
    int rsPos;
    int rtPos;
    int immPos;
    bool immLabel;

    InstType instType;
    string op_field;
    string funct_field;

    OpcodeTableEntry(){
      numOps = 0; 
      rdPos = rsPos = rtPos = immPos = -1;
      immLabel = false;
    };
  };

  OpcodeTableEntry myTable[UNDEFINED];


};


#endif
