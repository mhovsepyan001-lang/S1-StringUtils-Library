#ifndef STRINGUTILS_H
#define STRINGUTILS_H

#include <stdlib.h>

// Split string by delimiter, returns NULL-terminated array of strings
char **split(const char *str, char delimiter);

// Free the result of split()
void split_free(char **result);

// Join array of strings with separator
char *join(char **strings, const char *separator);

// Trim leading and trailing whitespace
char *trim(const char *str);

// Convert string to uppercase (returns new allocated string)
char *upper(const char *str);

// String buffer struct for dynamic appending
typedef struct {
    char *data;
    size_t length;
    size_t capacity;
} string_buffer;

// Initialize string buffer (returns NULL on failure)
string_buffer *sb_create(size_t initial_capacity);

// Append string to buffer (returns 0 on success, -1 on failure)
int sb_append(string_buffer *sb, const char *str);

// Free string buffer
void sb_free(string_buffer *sb);

#endif // STRINGUTILS_H

