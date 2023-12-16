void loadToBRegister(int operand) {
  digitalWrite(A4, LOW);
  digitalWrite(A8, HIGH);
  for (int i = 29; i <= 36; ++i) {
    digitalWrite(i, ram[operand][i - 29]);
  }
  digitalWrite(A7, HIGH);
  digitalWrite(A7, LOW);
}
