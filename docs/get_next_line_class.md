# Get Next Line: A Full Class (C Teacher's Lecture)

This is a complete, teacher-style class on the 42 `get_next_line` project. It is written to be read as a lesson: from the problem statement, to design, to edge cases, to memory management, and a clean implementation structure.

## 1) The Goal of the Project
`get_next_line(int fd)` returns **one line per call** from a file descriptor.

- A **line** is a sequence of characters ending with `\n`.
- The **returned string includes the `\n`** if it exists.
- At EOF, if there is leftover data **without** `\n`, return that as the last line.
- After that, return `NULL`.

So repeated calls give you:
- Call 1 -> line 1  
- Call 2 -> line 2  
- ...  
- After last line -> `NULL`

## 2) Why This Is Not Trivial
`read(fd, buf, BUFFER_SIZE)` does not know about lines. It returns chunks of bytes:

- A line may be smaller than one read.
- A line may span multiple reads.
- A line may be larger than `BUFFER_SIZE`.

You must **store leftover bytes** between calls. This is why a **static stash buffer** is needed.

## 3) Core Idea: A Persistent Stash
We keep a `static char *stash` that persists between calls.

High-level flow:
1. Read data and append to stash until we see a `\n` or reach EOF.
2. Split stash:
   - Return the line (up to and including `\n`).
   - Keep the leftover as new stash.
3. On EOF: if stash still has data, return it once, then `NULL`.

## 4) Important Rules and Edge Cases
- `fd < 0` or `BUFFER_SIZE <= 0` -> return `NULL`.
- `read` returns `-1` (error) -> free stash and return `NULL`.
- Empty file -> return `NULL`.
- File ends with `\n` -> last call returns line with `\n`, next call returns `NULL`.
- File ends without `\n` -> last call returns leftover without `\n`.
- No memory leaks: all temporary allocations must be freed or stored properly.

## 5) Required Helper Functions
- `ft_strlen`
- `ft_strchr` (find `\n`)
- `ft_strdup`
- `ft_strjoin` (append read buffer to stash)
- `ft_substr`

These are usually implemented in `get_next_line_utils.c`.

## 6) Memory Ownership and Lifetime
- `stash` belongs to `get_next_line` and persists between calls.
- Returned `line` is a new allocation owned by the caller.
- When stash changes, old stash must be freed.
- On error, free stash and return `NULL`.

This is the hardest part for many students: **who owns what memory, and when it is freed**.

## 7) Step-by-Step Algorithm

```
get_next_line(fd):
    if invalid fd or BUFFER_SIZE <= 0:
        return NULL

    stash = read_and_append(fd, stash)
    if stash == NULL:
        return NULL

    line = extract_line(stash)
    stash = keep_remainder(stash)

    return line
```

Where:
- `read_and_append` reads until `\n` or EOF
- `extract_line` creates the line to return
- `keep_remainder` keeps what is after the line

## 8) Reading and Appending
```
read_and_append(fd, stash):
    if stash is NULL:
        stash = strdup("")
    while stash has no '\n':
        bytes = read(fd, buf, BUFFER_SIZE)
        if bytes < 0:
            free stash
            return NULL
        if bytes == 0:
            break
        buf[bytes] = '\0'
        stash = join(stash, buf)
    return stash
```

Key points:
- You must stop once you see a `\n`.
- If `read` returns 0, you hit EOF.
- You must always null-terminate the buffer before joining.

## 9) Extracting the Line
If stash is empty, return `NULL`.

If stash contains `\n`:
- Return substring from start to that `\n` inclusive.

If stash has no `\n`:
- Return all of it (EOF case).

## 10) Keeping the Remainder
If stash contains `\n`:
- The new stash is everything *after* the `\n`.

If not:
- All data was consumed -> stash becomes `NULL`.

## 11) Common Mistakes
- Not including `\n` in the returned line.
- Losing leftover data when splitting stash.
- Infinite loop if EOF is reached and stash has no `\n`.
- Forgetting to free old stash on update.
- Returning a pointer into stash instead of a new allocation.

## 12) Minimal File Layout
- `get_next_line.c`
- `get_next_line_utils.c`
- `get_next_line.h`

## 13) Minimal Header
```c
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char    *get_next_line(int fd);

size_t  ft_strlen(const char *s);
char    *ft_strchr(const char *s, int c);
char    *ft_strjoin(char const *s1, char const *s2);
char    *ft_strdup(const char *s);
char    *ft_substr(char const *s, unsigned int start, size_t len);

#endif
```

## 14) Logic Skeleton (Core Function)
```c
static char *read_and_append(int fd, char *stash);
static char *extract_line(char *stash);
static char *keep_remainder(char *stash);

char *get_next_line(int fd)
{
    static char *stash;
    char        *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    stash = read_and_append(fd, stash);
    if (!stash)
        return NULL;
    line = extract_line(stash);
    stash = keep_remainder(stash);
    return line;
}
```

## 15) Walkthrough Example
File content: `"hello\nworld\n42"`  
BUFFER_SIZE = 4

- Call 1:
  - read "hell", stash = "hell"
  - read "o\nwo", stash = "hello\nwo"
  - return "hello\n"
  - stash = "wo"

- Call 2:
  - read "rld\n", stash = "world\n"
  - return "world\n"
  - stash = ""

- Call 3:
  - read "42", stash = "42" (EOF)
  - return "42"
  - stash = NULL

- Call 4: return NULL

## 16) Why Static Matters
Because each call must remember what was already read. Only static (or global) storage persists between calls. Without it, you would lose leftover bytes.

## 17) Bonus: Multiple FDs
If you do the bonus, you need one stash per file descriptor:
```
static char *stash[OPEN_MAX];
```
Then use `stash[fd]` instead of a single `stash`.

## 18) Testing Advice
Test with:
- Empty file
- Single line with `\n`
- Single line without `\n`
- Multiple lines
- Very long line (larger than BUFFER_SIZE)
- Different BUFFER_SIZE values

Use memory tools (like valgrind) to ensure no leaks.

---

If you want, I can also add a full implementation or build a test suite.