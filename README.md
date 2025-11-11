# get_next_line (42 School Project)

<p align="center">
  <img src="https://github.com/42-world/42-badges/blob/main/badges/get_next_line_full.png" alt="42 get_next_line Project Badge" width="400" />
</p>

<p align="center">
  <strong>A C function that reads a file line by line.</strong>
  <br />
  This project is a fundamental introduction to static variables, file descriptors,
  <br />
  and buffer management in C.
</p>

---

## Overview

`get_next_line` is a 42 school project that requires writing a single function, `get_next_line()`. This function, when called in a loop, will read a text file (or any file descriptor) and return one line at a time, including the newline character (`\n`), until the end of the file is reached.

This project is a deep dive into several core C concepts:
* **File Descriptors:** Reading data from a file descriptor using the `read()` system call.
* **Static Variables:** Using a `static` variable to "remember" the remaining text from the last `read()` call that wasn't part of the previous line.
* **Buffer Management:** Efficiently reading data in chunks (defined by `BUFFER_SIZE`) and handling data that spans across buffer boundaries.
* **Memory Allocation:** Using `malloc()` and `free()` to manage the memory for the returned line and the static buffer.

The key challenge is to make the function robust and efficient, capable of handling any file type, any `BUFFER_SIZE`, and multiple file descriptors simultaneously (in the bonus part).

## Features

* **Sequential Reading:** When called repeatedly, the function returns each line of a file one by one.
* **Buffer-based:** Reads the file in chunks of `BUFFER_SIZE` bytes for efficiency.
* **Static Buffer:** Uses a static variable to store any "leftover" characters from a `read()` call that will be part of the next line.
* **EOF Handling:** Correctly handles the end of the file, returning the last line (if any) and then `NULL`.
* **Error Handling:** Returns `NULL` in case of a read error or memory allocation failure.
* **(Bonus) Multiple File Descriptors:** Can manage and read from multiple file descriptors at the same time without mixing up their data.

## Getting Started

### Prerequisites

You need a C compiler (like `gcc` or `clang`) and `make` to compile the project and its tests.

### Installation and Compiling

1.  **Clone the repository:**
    ```sh
    git clone [https://github.com/abdejl/get_next_line.git](https://github.com/abdejl/get_next_line.git)
    ```

2.  **Navigate to the project directory:**
    ```sh
    cd get_next_line
    ```

3.  **Compile the project:**
    * The `Makefile` will compile the library `get_next_line.a`.
    ```sh
    make
    ```

## Usage

To use `get_next_line` in your own C program, you need to:

1.  Include the header file: `#include "get_next_line.h"`
2.  Compile your program and link it with the `get_next_line` object files or the compiled library.

### Example `main.c` for testing:

Here is a simple `main.c` file to demonstrate how to use the function to read a file named `test.txt`.

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int     fd;
    char    *line;

    // Open a file
    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }

    // Read file line by line
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line); // Free the memory allocated by get_next_line
    }

    // Close the file
    close(fd);
    return (0);
}
```

# Compile the main.c and link it with the get_next_line library
# This command assumes 'make' created libgetnextline.a
gcc main.c -L. -lgetnextline -o test_gnl

# Create a test file
echo "Hello World\nLine 2\nLast line" > test.txt

# Run the test
./test_gnl

# Compile the main.c and link it with the get_next_line library
# This command assumes 'make' created libgetnextline.a
gcc main.c -L. -lgetnextline -o test_gnl

# Create a test file
echo "Hello World\nLine 2\nLast line" > test.txt

# Run the test
./test_gnl
Expected Output:

Hello World
Line 2
Last line
