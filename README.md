# S1-StringUtils-Library

A lightweight C library for common string operations including splitting, joining, trimming, case conversion, and dynamic string buffers.

## Features

| Function | Description |
|----------|-------------|
| `split(str, delimiter)` | Split a string by delimiter into an array |
| `split_free(result)` | Free memory allocated by `split()` |
| `join(strings, separator)` | Join an array of strings with a separator |
| `trim(str)` | Remove leading and trailing whitespace |
| `upper(str)` | Convert string to uppercase |
| `sb_create(capacity)` | Create a dynamic string buffer |
| `sb_append(sb, str)` | Append to string buffer |
| `sb_free(sb)` | Free string buffer |

## Requirements

- C compiler (GCC, Clang, or MSVC)
- Windows, Linux, or macOS

## Installation

### Windows

1. Install MinGW (if you don't have a C compiler):
```powershell
winget install mingw
```

2. Clone the repository:
```powershell
git clone https://github.com/yourusername/S1-StringUtils-Library.git
cd S1-StringUtils-Library
```

### Linux/macOS

```bash
# Install gcc if needed
# Ubuntu/Debian: sudo apt install gcc
# macOS: xcode-select --install

git clone https://github.com/yourusername/S1-StringUtils-Library.git
cd S1-StringUtils-Library
```

## Building

### Windows (PowerShell)

**Build the demo:**
```powershell
gcc -Wall -Iinclude src/stringutils.c examples/main.c -o demo.exe
```

**Build the tests:**
```powershell
gcc -Wall -Iinclude src/stringutils.c tests/test_runner.c tests/test_split.c tests/test_trim.c tests/test_upper.c -o test_runner.exe
```

### Linux/macOS

**Using Make:**
```bash
make          # Build both demo and test_runner
make clean    # Remove built files
```

**Or manually:**
```bash
gcc -Wall -Iinclude src/stringutils.c examples/main.c -o demo
gcc -Wall -Iinclude src/stringutils.c tests/test_runner.c tests/test_split.c tests/test_trim.c tests/test_upper.c -o test_runner
```

## Running

### Run Demo

```powershell
# Windows
.\demo.exe

# Linux/macOS
./demo
```

**Expected output:**
```
Original: ' apple, banana , cherry '

Split & Trim:
[0]: 'apple'
[1]: 'banana'
[2]: 'cherry'

Joined: apple | banana | cherry

Upper: 'hello world' -> 'HELLO WORLD'

String Buffer: Hello, World!
```

### Run Tests

```powershell
# Windows
.\test_runner.exe

# Linux/macOS
./test_runner
```

**Expected output:**
```
test_split: PASS
test_split_empty: PASS
test_split_null: PASS
test_trim: PASS
test_trim_no_space: PASS
test_trim_all_space: PASS
test_trim_null: PASS
test_upper: PASS
test_upper_mixed: PASS
test_upper_null: PASS
```

## Usage Examples

### Include in Your Project

```c
#include "stringutils.h"
```

### Split a String

```c
char **parts = split("apple,banana,cherry", ',');
for (int i = 0; parts[i]; i++) {
    printf("%s\n", parts[i]);
}
split_free(parts);  // Don't forget to free!
```

### Join Strings

```c
char *fruits[] = {"apple", "banana", "cherry", NULL};
char *result = join(fruits, " - ");
printf("%s\n", result);  // "apple - banana - cherry"
free(result);
```

### Trim Whitespace

```c
char *trimmed = trim("   hello world   ");
printf("'%s'\n", trimmed);  // "'hello world'"
free(trimmed);
```

### Convert to Uppercase

```c
char *upper_str = upper("hello");
printf("%s\n", upper_str);  // "HELLO"
free(upper_str);
```

### Dynamic String Buffer

```c
string_buffer *sb = sb_create(16);
sb_append(sb, "Hello");
sb_append(sb, ", ");
sb_append(sb, "World!");
printf("%s\n", sb->data);  // "Hello, World!"
sb_free(sb);
```

## Project Structure

```
S1-StringUtils-Library/
├── include/
│   └── stringutils.h      # Header file with function declarations
├── src/
│   └── stringutils.c      # Implementation
├── examples/
│   └── main.c             # Demo program
├── tests/
│   ├── test_runner.c      # Test entry point
│   ├── test_split.c       # Split function tests
│   ├── test_trim.c        # Trim function tests
│   └── test_upper.c       # Upper function tests
├── Makefile               # Build configuration
└── README.md
```

## License

MIT License - feel free to use in your projects.
