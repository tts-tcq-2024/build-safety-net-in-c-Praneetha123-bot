#include <gtest/gtest.h>
#include "Soundex.h"
TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
//AAA
  char soundex[5];
initializeSoundex(soundex, "A");
  generateSoundex("AX", soundex);
  ASSERT_STREQ(soundex,"A200");
}
