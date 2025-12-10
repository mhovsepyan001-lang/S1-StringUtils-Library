#include "stringutils.h"

// Declare test functions
void test_split();
void test_trim();
void test_upper();

int main() {
    printf("Running StringUtils Tests...\n\n");

    test_split();
    test_trim();
    test_upper();

    printf("\nAll tests finished.\n");
    return 0;
}
