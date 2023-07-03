#include <Note.h>
#include <Sound.h>

void Sound::setBeeperDataPin(int beeper_data_pin) {
    PIN_BEEPER_DATA = beeper_data_pin;
    pinMode(PIN_BEEPER_DATA, OUTPUT);

}

void Sound::beep(int frequency, int duration) {
    tone(PIN_BEEPER_DATA, frequency, duration);
}

void Sound::melody(Note* noteList, int noteCount) {
    
    for (unsigned int i = 0; i < noteCount - 1; i++) {
        // In order to calculate the correct note length we take 1 second and divide it by the type of note
        // for example: a quarter note is 1000 / 4, an eighth note 1000 / 8 etc.
        int noteDuration = noteList[i].duration / 1.5 ;

        // Call tone() with the current note of the melody with the calculated duration of the note.
        tone(PIN_BEEPER_DATA, noteList[i].note, noteDuration);

        // in order to distinguish the notes, we set a minimal pause between two notes
        // it turned out the note length plus 30% works fine.
        int pauseBetweenNotes = noteDuration * 1.30;

        // pause for the calculated duration
        delay(pauseBetweenNotes);

        // stop playing the current note
        noTone(PIN_BEEPER_DATA);
    }
}