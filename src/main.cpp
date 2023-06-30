#include <Arduino.h>
#include <Pitches.h>
#include <Note.h>
#include <Light.h>
#include <Sound.h>

static const int PIN_BEEPER_DATA = 5;
static const int timeChange = 200;
char command;
boolean newData = false;
void playMelody();
void listenForCommand();
void receiveCommand();
Light lightLib;
Sound soundLib;

Note noteList[] = {
  Note(659, 120),
  Note(622, 120),
  Note(659, 120),
  Note(622, 120),
  Note(659, 120),
  Note(494, 120),
  Note(587, 120),
  Note(523, 120),
  Note(440, 120),
  Note(262, 120),
  Note(330, 120),
  Note(440, 120),
  Note(494, 120),
  Note(330, 120),
  Note(415, 120),
  Note(494, 120),
  Note(523, 120),
  Note(330, 120),
  Note(659, 120),
  Note(622, 120),
  Note(659, 120),
  Note(622, 120),
  Note(659, 120),
  Note(494, 120),
  Note(587, 120),
  Note(523, 120),
  Note(440, 120),
  Note(262, 120),
  Note(330, 120),
  Note(440, 120),
  Note(494, 120),
  Note(330, 120),
  Note(523, 120),
  Note(494, 120),
  Note(440, 120),

};


void setup() {
  Serial.begin(9600);
  Serial.println("Serial communication started.");
  
  lightLib.setPins(2, 3, 4);
  lightLib.setColor(0, 10, 50);

  soundLib.setBeeperDataPin(5);
  soundLib.melody(noteList, 35);
}

void loop() {
  receiveCommand();
  listenForCommand();
}

void receiveCommand() {
  if (Serial.available() > 0) {
    command = Serial.read();
    newData = true;
  }
}

void listenForCommand() {
  if (newData == true) {
    Serial.print("command received: ");

    Serial.println(command);

    if (command == 'p') {
      // nada
    } else if (command == 'b') {
      // do nothing
    } else {
      Serial.println("Unknown command.");
    }

    newData = false;
  }
}