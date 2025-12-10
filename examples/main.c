#include <stdio.h>
#include "stringutils.h"

int main() {
    const char *csv = " apple, banana , cherry ";
    printf("Original: '%s'\n", csv);

    // Split
    char **items = split(csv, ',');
    printf("\nSplit & Trim:\n");
    for (int i = 0; items[i]; i++) {
        char *t = trim(items[i]);
        printf("[%d]: '%s'\n", i, t);
        free(t);
    }
    split_free(items);  // Use the new helper function

    // Join example
    char *arr[] = {"apple", "banana", "cherry", NULL};
    char *joined = join(arr, " | ");
    printf("\nJoined: %s\n", joined);
    free(joined);

    // Upper example
    char *greeting = "hello world";
    char *upper_greeting = upper(greeting);
    printf("\nUpper: '%s' -> '%s'\n", greeting, upper_greeting);
    free(upper_greeting);

    // String buffer example
    string_buffer *sb = sb_create(16);
    if (sb) {
        sb_append(sb, "Hello");
        sb_append(sb, ", ");
        sb_append(sb, "World!");
        printf("\nString Buffer: %s\n", sb->data);
        sb_free(sb);
    }

    return 0;
}

