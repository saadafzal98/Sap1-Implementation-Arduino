// Instruction Register Module

void writeToInstructionRegister(int decimal) {
  digitalWrite(10, HIGH);
  for (int i = 6; i <= 33; ++i) {
    digitalWrite(i, ram[decimal][i - 6]);
  }
  digitalWrite(A0, HIGH);
  digitalWrite(A0, LOW);
}
