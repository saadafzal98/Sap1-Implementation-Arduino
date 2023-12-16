void loadAccumulator(int operand) {
  digitalWrite(A1, LOW);
  for (int i = 14; i <= 21; ++i) {
    digitalWrite(i, ram[operand][i - 14]);
  }
  digitalWrite(A1, HIGH);
  digitalWrite(A2, HIGH);
  digitalWrite(A2, LOW);
  Serial.println("Loaded into accumulator.");
}

void addToAccumulator(int operand) {
  digitalWrite(A4, LOW);
  digitalWrite(A8, HIGH);
  for (int i = 22; i <= 29; ++i) {
    digitalWrite(i, ram[operand][i - 22]);
  }
  digitalWrite(A7, HIGH);
  digitalWrite(A7, LOW);
  Serial.println("Loaded to B register and added.");
}
