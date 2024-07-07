#include <gtest/gtest.h>
#include "Soundex.h"
 
TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
//AAA
  char soundex[5];
 initializeSoundex(
  generateSoundex("AX", soundex);
  ASSERT_EQ(soundex,"A200");
}
