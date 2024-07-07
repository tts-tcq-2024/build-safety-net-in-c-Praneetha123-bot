#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
//AAA
  char soundex[5];

char *name="AX";

int sIndex=1;

int i;
initializeSoundex(soundex, name[0] );

for(i=1;i<strlen(name);i++) {

processCharacter(name,soundex,$sIndex,i);

getSoundexCode(name[i]);

}
  generateSoundex("AX", soundex);
  //ASSERT_EQ(soundex,"A200");
}
