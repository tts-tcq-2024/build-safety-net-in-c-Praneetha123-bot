#include <gtest/gtest.h>
#include "Soundex.h"

// Test replacing consonants with appropriate digits
TEST(SoundexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
    // Arrange
    char soundex[5];

    // Act
    generateSoundex("AX", soundex);

    // Assert
    ASSERT_STREQ(soundex, "A200");
}

// Test keeping the first letter as is
TEST(SoundexTestsuite, KeepsFirstLetterAsIs) {
    // Arrange
    char soundex[5];

    // Act
    generateSoundex("BFP", soundex);

    // Assert
    ASSERT_STREQ(soundex, "B110");
}

// Test handling different consonants
TEST(SoundexTestsuite, HandlesDifferentConsonants) {
    // Arrange
    char soundex[5];

    // Act
    generateSoundex("CGJKQSXZ", soundex);

    // Assert
    ASSERT_STREQ(soundex, "C222");
}

// Test handling vowels and special characters
TEST(SoundexTestsuite, HandlesVowelsAndSpecialCharacters) {
    // Arrange
    char soundex[5];

    // Act
    generateSoundex("AEIOUHWY", soundex);

    // Assert
    ASSERT_STREQ(soundex, "A000");
}

// Test truncating to four characters
TEST(SoundexTestsuite, TruncatesToFourCharacters) {
    // Arrange
    char soundex[5];

    // Act
    generateSoundex("ABCDEFGHIJKLMNOPQRSTUVWXYZ", soundex);

    // Assert
    ASSERT_STREQ(soundex, "A123");
}

// Test ignoring case
TEST(SoundexTestsuite, IgnoresCase) {
    // Arrange
    char soundex[5];

    // Act
    generateSoundex("aBcDeFg", soundex);

    // Assert
    ASSERT_STREQ(soundex, "A123");
}

// Test initializing soundex correctly
TEST(SoundexTestsuite, InitializesSoundexCorrectly) {
    // Arrange
    char soundex[5];

    // Act
    initializeSoundex(soundex, 'R');

    // Assert
    ASSERT_STREQ(soundex, "R000");
}

// Test processCharacter function
TEST(SoundexTestsuite, ProcessCharacterFunction) {
    // Arrange
    char soundex[5] = "R000";
    int sIndex = 1;

    // Act
    processCharacter("R1234567890", soundex, &sIndex, 1);

    // Assert
    ASSERT_EQ(soundex[1], '1');
    ASSERT_EQ(sIndex, 2);
}

// Test handling empty string
TEST(SoundexTestsuite, HandlesEmptyString) {
    // Arrange
    char soundex[5];

    // Act
    generateSoundex("", soundex);

    // Assert
    ASSERT_STREQ(soundex, "");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
