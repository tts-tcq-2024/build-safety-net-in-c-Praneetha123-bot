#include <gtest/gtest.h>
#include "Soundex.h"
TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
//AAA
  char soundex[5];
  generateSoundex("AX", soundex);
  ASSERT_STREQ(soundex,"A200");
}

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits_Negative) {
//AAA
  char soundex[5];
  generateSoundex("A1CDFe", soundex);
  ASSERT_STREQ(soundex,"A231");
}

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits_Neg) {
//AAA
  char soundex[5];
  generateSoundex("A[", soundex);

}

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits_Neg1) {
//AAA
  char soundex[5];
  generateSoundex("", soundex);

}
