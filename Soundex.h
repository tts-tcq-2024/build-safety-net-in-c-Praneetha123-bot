#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>

char getSoundexCode(char c) {
    static const char soundexTable[26] = {
        '0', '1', '2', '3', '0', '1', '2', '0', '0', '2', '2', '4', '5', '5', '0', '1', '2', '6', '2', '3', '0', '1', '0', '2', '0', '2'
    };
    if (isalpha(c)) {
        return soundexTable[toupper(c) - 'A'];
    }
    return '0';
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
