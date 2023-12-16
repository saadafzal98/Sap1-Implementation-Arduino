void executeALU(int opcode, int operand) {
  switch (opcode) {
    case 1:
      loadAccumulator(operand);
      break;
    case 2:
      addToAccumulator(operand);
      break;
    case 3:
      // Subtract A with value
      digitalWrite(A4, HIGH);
      digitalWrite(A8, HIGH);
      for (int i = 22; i <= 29; ++i) {
        digitalWrite(i, ram[operand][i - 22]);
      }
      digitalWrite(A7, HIGH);
      digitalWrite(A7, LOW);
      break;
    case 4:
      jumpToAddress();
      break;
    default:
      // NOP (No Operation)
      break;
  }
}
