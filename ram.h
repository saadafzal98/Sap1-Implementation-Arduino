// Memory Module

// RAM of the SAP-1
int ram[16][8] = {
  //   opcode  |  operand
  {0, 0, 0, 0, 0, 0, 0, 0}, // address: 0
  {0, 0, 0, 0, 0, 0, 0, 0}, // address: 1
  {0, 0, 0, 0, 0, 0, 0, 0}, // address: 2
  {0, 0, 0, 0, 0, 0, 0, 0}, // address: 3
  {0, 0, 0, 0, 0, 0, 0, 0}, // address: 4
  {0, 0, 0, 0, 0, 0, 0, 0}, // address: 5
  {0, 0, 0, 0, 0, 0, 0, 0}, // address: 6
  {0, 0, 0, 0, 0, 0, 0, 0}, // address: 7
  {0, 0, 0, 0, 0, 0, 0, 0}, // address: 8
  {0, 0, 0, 0, 0, 0, 0, 0}, // address: 9
  {0, 0, 0, 0, 0, 0, 0, 0}, // address: 10
  {0, 0, 0, 0, 0, 0, 0, 0}, // address: 11
  {0, 0, 0, 0, 0, 0, 0, 0}, // address: 12
  {0, 0, 0, 0, 1, 0, 0, 0}, // address: 13 (Load A with 2)
  {0, 0, 0, 0, 1, 0, 0, 1}, // address: 14 (Add A with 2)
  {0, 0, 0, 0, 0, 0, 0, 0}, // address: 15 (NOP)
};