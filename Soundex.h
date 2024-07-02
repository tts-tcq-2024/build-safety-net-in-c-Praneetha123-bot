#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>

char getSoundexCode(char c) {
    switch (toupper(c)) {
        case 'B': case 'F': case 'P': case 'V': return '1';
        case 'C': case 'G': case 'J': case 'K': case 'Q': case 'S': case 'X': case 'Z': return '2';
        case 'D': case 'T': return '3';
        case 'L': return '4';
        case 'M': case 'N': return '5';
        case 'R': return '6';
        default: return '0'; // For A, E, I, O, U, H, W, Y
    }
}

void initializeSoundex(char *soundex, char firstChar) {
    soundex[0] = toupper(firstChar);
    soundex[1] = soundex[2] = soundex[3] = '0';
    soundex[4] = '\0';
}

void processCharacter(const char *name, char *soundex, int *sIndex, int i) {
    char code = getSoundexCode(name[i]);
    if (*sIndex < 4 && code != '0' && code != soundex[*sIndex - 1]) {
        soundex[*sIndex] = code;
        (*sIndex)++;
    }
}

void generateSoundex(const char *name, char *soundex) {
    initializeSoundex(soundex, name[0]);
    int sIndex = 1;
    int len = strlen(name);
    for (int i = 1; i < len; i++) {
        processCharacter(name, soundex, &sIndex, i);
    }
}

#endif // SOUNDEX_H
