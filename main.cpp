#include <Arduino.h>

// Include separate modules
#include "ram.h"
#include "Accumulater.h"
#include "PC.h"
#include "Output.h"
#include "IR.h"
#include "ALU.h"
#include "Registerb.h"

// Variable managing clock state
int clockState = LOW;

// To keep track of jump
extern boolean JUMP = false;

void setup() {
  Serial.begin(115200);

  // Initializing output pins
  for (int i = 0; i < 34; i++) {
    pinMode(i, OUTPUT);
  }

  for (int i = 0; i < 13; i++) {
    pinMode(A0 + i, OUTPUT);
  }

  // Initializing input pins
  for (int i = 34; i < 54; i++) {
    pinMode(i, INPUT);
  }

  // Resetting flip-flops
  digitalWrite(A9, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(A8, LOW);
  digitalWrite(A1, HIGH);
  digitalWrite(A1, LOW);
  digitalWrite(A10, LOW);
  digitalWrite(A3, HIGH);
  digitalWrite(A3, LOW);

  // Set enable pin high for the PC
  digitalWrite(A12, HIGH);

  // Select line, active low
  digitalWrite(30, LOW);
  digitalWrite(31, LOW);
  digitalWrite(32, LOW);
  digitalWrite(33, LOW);
  delay(50);
  digitalWrite(A0, LOW);
  delay(50);
  digitalWrite(A0, HIGH);
  digitalWrite(A4, LOW);
  digitalWrite(A4, HIGH);
}

void loop() {
  if (!JUMP) {
    clockState = !clockState;
    digitalWrite(A0, clockState);
    delay(1000);
    clockState = !clockState;
    digitalWrite(A0, clockState);
  }

  JUMP = false;

  int input[4] = {digitalRead(42), digitalRead(43), digitalRead(44), digitalRead(45)};
  int decimal = 8 * input[3] + 4 * input[2] + 2 * input[1] + input[0];
  displayOutput(decimal);

  writeToInstructionRegister(decimal);

  // Separate opcode and operand
  int opcode = digitalRead(45) << 3 | digitalRead(44) << 2 | digitalRead(43) << 1 | digitalRead(42);
  int operand = digitalRead(41) << 3 | digitalRead(40) << 2 | digitalRead(39) << 1 | digitalRead(38);

  executeALU(opcode, operand);
}
