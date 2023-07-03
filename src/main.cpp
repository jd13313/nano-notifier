#include <Arduino.h>
#include <Pitches.h>
#include <Note.h>
#include <Light.h>
#include <Sound.h>

static const int PIN_BEEPER_DATA = 5;
static const int timeChange = 200;
char command;
boolean newData = false;
Light lightLib;
Sound soundLib;
void listenForCommand();
void receiveCommand();
void playTune();


Note noteList[] = {
Note(659, 460),
Note(784, 340),
Note(659, 230),
Note(659, 110),
Note(880, 230),
Note(659, 230),
Note(587, 230),
Note(659, 460),
Note(988, 340),
Note(659, 230),
Note(659, 110),
Note(104, 230),
Note(988, 230),
Note(784, 230),
Note(659, 230),
Note(988, 230),
Note(131, 230),
Note(659, 110),
Note(587, 230),
Note(587, 110),
Note(494, 230),
Note(740, 230),
Note(659, 460),
};


void setup() {
  Serial.begin(9600);
  Serial.println("Serial communication started.");
  
  lightLib.setPins(2, 3, 4);
  lightLib.setColor(0, 10, 50);
}

void loop() {
  receiveCommand();
  listenForCommand();
}

void playTune() {
  soundLib.setBeeperDataPin(5);
  soundLib.melody(noteList, sizeof(noteList) / sizeof(noteList[0]));
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
      playTune();
    } else if (command == 'b') {
      // do nothing
    } else {
      Serial.println("Unknown command.");
    }

    newData = false;
  }
}