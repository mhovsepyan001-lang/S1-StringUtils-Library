#include <stdio.h>
#include <string.h>
#include "stringutils.h"

void test_split() {
    char **result = split("a,b,c", ',');
    int pass = result &&
               strcmp(result[0], "a") == 0 &&
               strcmp(result[1], "b") == 0 &&
               strcmp(result[2], "c") == 0 &&
               result[3] == NULL;
    printf("test_split: %s\n", pass ? "PASS" : "FAIL");
    split_free(result);
    
    // Test empty string
    char **result2 = split("", ',');
    int pass2 = result2 && strcmp(result2[0], "") == 0 && result2[1] == NULL;
    printf("test_split_empty: %s\n", pass2 ? "PASS" : "FAIL");
    split_free(result2);
    
    // Test NULL input
    char **result3 = split(NULL, ',');
    int pass3 = result3 == NULL;
    printf("test_split_null: %s\n", pass3 ? "PASS" : "FAIL");
}

