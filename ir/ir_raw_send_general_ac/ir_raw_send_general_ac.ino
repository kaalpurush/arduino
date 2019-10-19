#include <IRremote.h>

IRsend irsend;

unsigned int IR_OFF[] = {3360, 1684, 460, 424, 504, 416, 460, 1212, 488, 448, 460, 1212, 484, 444, 460, 420, 484, 444, 460, 1220, 488, 1216, 480, 412, 488, 424, 524, 368, 488, 1236, 456, 1212, 488, 440, 484, 392, 488, 444, 460, 416, 488, 444, 460, 420, 488, 440, 464, 416, 488, 444, 460, 416, 488, 444, 460, 416, 488, 444, 484, 1188, 492, 440, 460, 416, 488, 444, 460, 420, 484, 444, 460, 416, 488, 440, 460, 1212, 488, 444, 460, 416, 488, 420, 484, 412, 488, 1236, 460, 416, 488, 444, 480, 392, 488, 440, 480, 396, 484, 444, 460, 1212, 532, 392, 460, 1212, 488, 1244, 460, 1212, 488, 1236, 460, 1208, 488, 1236, 460};

unsigned int IR_ON[] = {3388, 1660, 456, 412, 508, 396, 480, 1168, 488, 440, 460, 1208, 488, 440, 460, 408, 488, 436, 460, 1200, 488, 1232, 460, 420, 484, 440, 460, 412, 488, 1232, 460, 1196, 488, 436, 460, 396, 504, 440, 460, 412, 488, 436, 460, 412, 488, 440, 460, 408, 488, 436, 460, 408, 488, 436, 460, 388, 508, 436, 460, 1200, 488, 436, 460, 412, 484, 436, 460, 412, 484, 436, 464, 388, 504, 436, 460, 1200, 488, 436, 460, 408, 488, 436, 460, 408, 488, 1228, 460, 1200, 488, 1204, 480, 1204, 484, 1224, 460, 1200, 488, 1224, 460, 1200, 484, 436, 460, 404, 488, 1224, 460, 412, 484, 436, 460, 412, 484, 436, 460, 412, 488, 436, 464, 408, 484, 436, 460, 1200, 488, 1224, 460, 408, 488, 436, 460, 1200, 484, 436, 460, 412, 484, 436, 460, 412, 484, 1224, 460, 1200, 488, 1224, 460, 412, 488, 436, 460, 412, 488, 416, 480, 408, 488, 436, 460, 408, 488, 436, 460, 1200, 488, 1224, 460, 408, 488, 436, 460, 408, 488, 436, 460, 408, 488, 436, 460, 408, 488, 436, 460, 408, 488, 436, 460, 408, 488, 432, 460, 412, 488, 440, 460, 408, 488, 432, 464, 408, 484, 436, 464, 408, 484, 436, 464, 404, 488, 436, 460, 408, 488, 436, 460, 408, 488, 436, 460, 408, 488, 436, 460, 408, 488, 436, 460, 408, 488, 432, 460, 412, 484, 436, 460, 412, 488, 1228, 460, 408, 488, 436, 460, 408, 488, 436, 460, 1200, 488, 1228, 460, 408, 488, 436, 460, 1196, 488, 1228, 460};

int khz = 38;

void setup()
{
  Serial.begin(9600);
}

void loop() {

  Serial.println("Sending OFF");

  irsend.sendRaw(IR_OFF, sizeof(IR_OFF) / sizeof(int), khz);

  delay(5000);

  Serial.println("Sending ON");

  irsend.sendRaw(IR_ON, sizeof(IR_ON) / sizeof(int), khz);

  delay(5000);
}