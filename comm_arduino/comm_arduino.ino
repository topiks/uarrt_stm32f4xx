char incomingByte;

void setup() {
  Serial.begin(115200);
  Serial.print("setupp");
}

void loop() {
  int data_kirim = 6969;
  char data_kirim_char[4];

//  memcpy(data_kirim_char, &data_kirim, 4);
  Serial.write('i');
  Serial.write('t');
  Serial.write('s');
  Serial.write('g');

//  if (Serial.available() > 0) {
//    // read the incoming byte:
//    incomingByte = Serial.read();
//
//    // say what you got:
//    Serial.print("I received: ");
//    Serial.println(incomingByte, DEC);
//  }
//  else
//    Serial.println("kosong");
}
