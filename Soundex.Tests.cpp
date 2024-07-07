#include <gtest/gtest.h>
#include "Soundex.h"
TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits_1) {
//AAA
  char soundex[5];
  generateSoundex("AX", soundex);
  ASSERT_STREQ(soundex,"A200");
}

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits_2) {
//AAA
  char soundex[5];
  generateSoundex("A1CDFe", soundex);
  ASSERT_STREQ(soundex,"A231");
}

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits_3) {
//AAA
  char soundex[5];
  generateSoundex("A[", soundex);

}

