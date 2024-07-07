#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>

char getSoundexCode(char c) {
    static const char soundexTable[26] = {
        // A, B, C, D, E, F, G, H, I, J, K, L, M
        '0', '1', '2', '3', '0', '1', '2', '0', '0', '2', '2', '4', '5',
        // N, O, P, Q, R, S, T, U, V, W, X, Y, Z
        '5', '0', '1', '2', '6', '2', '3', '0', '1', '0', '2', '0', '2'
    };

    c = toupper(c);
    if (c < 'A' || c > 'Z') {
        return '0';
    }
    return soundexTable[c - 'A'];
}

void initializeSoundex(char *soundex, char firstChar) {
    soundex[0] = toupper(firstChar);
    soundex[1] = soundex[2] = soundex[3] = '0';
    soundex[4] = '\0';
}

void processCharacter(const char *name, char *soundex, int *sIndex, int i) {
    char code = getSoundexCode(name[i]);

    // Check if the character should be added to soundex
    if (shouldAddToSoundex(code, soundex, *sIndex)) {
        soundex[*sIndex] = code;
        (*sIndex)++;
    }
}

// Function to check if a character should be added to soundex
int shouldAddToSoundex(char code, char *soundex, int sIndex) {
    return sIndex < 4 && code != '0' && code != soundex[sIndex - 1];
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
