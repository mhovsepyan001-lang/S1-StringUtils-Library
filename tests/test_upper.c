#include <stdio.h>
#include <string.h>
#include "stringutils.h"

void test_upper() {
    char *result = upper("hello");
    int pass = result && strcmp(result, "HELLO") == 0;
    printf("test_upper: %s\n", pass ? "PASS" : "FAIL");
    free(result);
    
    // Test mixed case
    char *result2 = upper("HeLLo WoRLD");
    int pass2 = result2 && strcmp(result2, "HELLO WORLD") == 0;
    printf("test_upper_mixed: %s\n", pass2 ? "PASS" : "FAIL");
    free(result2);
    
    // Test NULL input
    char *result3 = upper(NULL);
    int pass3 = result3 == NULL;
    printf("test_upper_null: %s\n", pass3 ? "PASS" : "FAIL");
}

