#include "stringutils.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>

// ----------------- SPLIT -----------------
char **split(const char *str, char delimiter) {
    if (!str) return NULL;

    size_t count = 1;
    for (const char *s = str; *s; s++)
        if (*s == delimiter) count++;

    char **result = malloc((count + 1) * sizeof(char*));
    if (!result) return NULL;

    // Initialize all pointers to NULL for safe cleanup on failure
    for (size_t i = 0; i <= count; i++)
        result[i] = NULL;

    size_t idx = 0;
    const char *start = str;
    for (const char *s = str; ; s++) {
        if (*s == delimiter || *s == '\0') {
            size_t len = s - start;
            result[idx] = malloc(len + 1);
            if (!result[idx]) {
                // Cleanup on failure
                split_free(result);
                return NULL;
            }
            strncpy(result[idx], start, len);
            result[idx][len] = '\0';
            idx++;
            start = s + 1;
        }
        if (*s == '\0') break;
    }
    return result;
}

// ----------------- SPLIT FREE -----------------
void split_free(char **result) {
    if (!result) return;
    for (size_t i = 0; result[i]; i++)
        free(result[i]);
    free(result);
}

// ----------------- JOIN -----------------
char *join(char **strings, const char *separator) {
    if (!strings || !separator) return NULL;
    
    size_t sep_len = strlen(separator);
    size_t total_len = 0;
    size_t count = 0;

    for (size_t i = 0; strings[i]; i++) {
        total_len += strlen(strings[i]);
        count++;
    }
    if (count == 0) {
        char *empty = malloc(1);
        if (empty) empty[0] = '\0';
        return empty;
    }
    
    total_len += sep_len * (count - 1);

    char *result = malloc(total_len + 1);
    if (!result) return NULL;

    // Use pointer arithmetic instead of repeated strcat (O(n) vs O(n²))
    char *pos = result;
    for (size_t i = 0; i < count; i++) {
        size_t len = strlen(strings[i]);
        memcpy(pos, strings[i], len);
        pos += len;
        if (i < count - 1) {
            memcpy(pos, separator, sep_len);
            pos += sep_len;
        }
    }
    *pos = '\0';
    
    return result;
}

// ----------------- TRIM -----------------
char *trim(const char *str) {
    if (!str) return NULL;

    while (isspace((unsigned char)*str)) str++;

    if (*str == 0) return strdup("");

    const char *end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    size_t len = end - str + 1;
    char *result = malloc(len + 1);
    if (!result) return NULL;
    
    memcpy(result, str, len);
    result[len] = '\0';
    return result;
}

// ----------------- UPPER -----------------
char *upper(const char *str) {
    if (!str) return NULL;
    
    size_t len = strlen(str);
    char *result = malloc(len + 1);
    if (!result) return NULL;
    
    for (size_t i = 0; i < len; i++) {
        result[i] = toupper((unsigned char)str[i]);
    }
    result[len] = '\0';
    return result;
}

// ----------------- STRING BUFFER -----------------
string_buffer *sb_create(size_t initial_capacity) {
    if (initial_capacity == 0) initial_capacity = 16;
    
    string_buffer *sb = malloc(sizeof(string_buffer));
    if (!sb) return NULL;
    
    sb->data = malloc(initial_capacity);
    if (!sb->data) {
        free(sb);
        return NULL;
    }
    
    sb->length = 0;
    sb->capacity = initial_capacity;
    sb->data[0] = '\0';
    return sb;
}

int sb_append(string_buffer *sb, const char *str) {
    if (!sb || !str) return -1;
    
    size_t str_len = strlen(str);
    if (sb->length + str_len + 1 > sb->capacity) {
        size_t new_capacity = (sb->length + str_len + 1) * 2;
        char *new_data = realloc(sb->data, new_capacity);
        if (!new_data) return -1;
        sb->data = new_data;
        sb->capacity = new_capacity;
    }
    memcpy(sb->data + sb->length, str, str_len + 1);
    sb->length += str_len;
    return 0;
}

void sb_free(string_buffer *sb) {
    if (!sb) return;
    free(sb->data);
    free(sb);
}