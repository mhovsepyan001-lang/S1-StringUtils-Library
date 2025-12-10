#include <stdio.h>
#include <string.h>
#include "stringutils.h"

void test_trim() {
    char *t = trim("   hello  ");
    int pass = t && strcmp(t, "hello") == 0;
    printf("test_trim: %s\n", pass ? "PASS" : "FAIL");
    free(t);
    
    // Test no whitespace
    char *t2 = trim("hello");
    int pass2 = t2 && strcmp(t2, "hello") == 0;
    printf("test_trim_no_space: %s\n", pass2 ? "PASS" : "FAIL");
    free(t2);
    
    // Test all whitespace
    char *t3 = trim("   ");
    int pass3 = t3 && strcmp(t3, "") == 0;
    printf("test_trim_all_space: %s\n", pass3 ? "PASS" : "FAIL");
    free(t3);
    
    // Test NULL input
    char *t4 = trim(NULL);
    int pass4 = t4 == NULL;
    printf("test_trim_null: %s\n", pass4 ? "PASS" : "FAIL");
}
