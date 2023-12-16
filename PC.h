// Counter Module
extern boolean JUMP;
void jumpToAddress() {
  digitalWrite(12, LOW);
  digitalWrite(2, 0);
  digitalWrite(3, 1);
  digitalWrite(4, 0);
  digitalWrite(5, 1);
  digitalWrite(11, HIGH);
  digitalWrite(11, LOW);
  JUMP = true;
  digitalWrite(12, HIGH);
}
