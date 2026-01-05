*This project has been created as part of the 42 curriculum by nixos.*

## Description
`get_next_line` provides a single function that reads from a file descriptor and returns one line at a time, preserving the trailing newline when present and returning `NULL` on end-of-input or error. The project explores buffered I/O using static storage to keep unread data between calls.

## Instructions
- Build the mandatory library: `make` (defaults to `BUFFER_SIZE=42`, override with `make BUFFER_SIZE=1024`).  
- Build with bonus multi-fd support: `make bonus`.  
- Clean objects: `make clean`; remove all outputs: `make fclean`; rebuild: `make re`.  
- Compile manually if preferred: `cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c`.  
- Usage example:
  ```c
  int fd = open("file.txt", O_RDONLY);
  char *line;
  while ((line = get_next_line(fd)))
  {
      /* process line */
      free(line);
  }
  close(fd);
  ```

## Resources
- `man 2 read`, `man malloc`, and POSIX file descriptor docs.  
- Articles on C static storage duration and buffer management.  
- Project subject PDF and 42 intranet guidance.  
- AI usage: GitHub Copilot CLI was used to draft boilerplate code, Makefile, and this README; all logic and wording were reviewed and adjusted manually.

## Algorithm
The function keeps a static stash of unread data, appending new `read` chunks until a newline or EOF is encountered. It slices and returns the next line, then trims the stash to retain only remaining data; the bonus version tracks a linked list keyed by file descriptor to preserve independent stashes while using a single static head pointer. This approach minimizes reads, avoids global variables, and frees intermediate buffers to prevent leaks.
