# 📚 Libft

![Score](https://img.shields.io/badge/Score-125%2F125-brightgreen)
![Language](https://img.shields.io/badge/Language-C-blue)
![42](https://img.shields.io/badge/42-Project-black)

## 📌 Project Goal

**Libft** is the very first 42 project: reimplement a set of standard C library functions from scratch, then add extra utility functions that you'll reuse in every subsequent project. The result is your own personal C library, compiled as `libft.a`.

---

## 🧠 Key Concepts

### Libc Functions — Character Checks & Conversion (`<ctype.h>`)
- `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint` — character classification using ASCII ranges, no magic library calls
- `ft_toupper`, `ft_tolower` — case conversion via ASCII offset (`'a' - 'A' == 32`)

### Libc Functions — String Manipulation (`<string.h>`)
- `ft_strlen` — iterate until `\0`, return count
- `ft_strchr`, `ft_strrchr` — scan forward/backward for a character; return pointer or `NULL`
- `ft_strncmp` — compare at most `n` bytes using `unsigned char` to avoid sign issues
- `ft_strlcpy`, `ft_strlcat` — safe copy/concat that always null-terminate and return intended length
- `ft_strnstr` — find a substring within at most `n` characters
- `ft_strdup` — `malloc` + copy; the first function where you allocate memory

### Libc Functions — Memory (`<string.h>` / `<strings.h>`)
- `ft_memset` — fill memory byte by byte (cast to `unsigned char *`)
- `ft_bzero` — `memset` to 0
- `ft_memcpy` — copy non-overlapping memory regions
- `ft_memmove` — safe copy for overlapping regions (copy from end if `dst > src`)
- `ft_memchr` — find a byte in memory
- `ft_memcmp` — compare memory blocks as `unsigned char`

### Libc Functions — Conversion & I/O
- `ft_atoi` — parse a decimal integer from a string: skip whitespace, handle sign, accumulate digits
- `ft_calloc` — `malloc(count * size)` + `memset(0)`; handle overflow and `size == 0` edge cases
- `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd` — write to any file descriptor using `write()`

### Additional Functions
- `ft_substr` — allocate and return a substring (`start` + `len`); handle out-of-bounds gracefully
- `ft_strjoin` — allocate and concatenate two strings
- `ft_strtrim` — remove leading and trailing characters present in a `set` string
- `ft_split` — split a string by a delimiter character, return a `NULL`-terminated array of strings; the most complex allocation in the project
- `ft_itoa` — convert an integer to a string; handle `INT_MIN` carefully (cannot negate it safely)
- `ft_strmapi` — apply a function `f(index, char)` to each character, return new string
- `ft_striteri` — same but in-place, no return value

### Bonus — Linked List
- `t_list` struct: `void *content` + `t_list *next`
- `ft_lstnew` — allocate a new node
- `ft_lstadd_front`, `ft_lstadd_back` — insert at head or tail
- `ft_lstsize`, `ft_lstlast` — count nodes / get last node
- `ft_lstdelone` — free one node's content and the node itself (does not touch `next`)
- `ft_lstclear` — free all nodes in the list recursively/iteratively
- `ft_lstiter` — apply a function to each node's content
- `ft_lstmap` — apply a function to each node, build a new list from the results; free on partial failure

### General C Concepts Reinforced
- **Pointer arithmetic**: `*(ptr + i)` vs `ptr[i]` — identical at the machine level
- **`unsigned char` casts**: many functions require casting to `unsigned char` to match standard behavior and avoid sign-extension bugs
- **`NULL`-termination contract**: every string function must respect and maintain the `\0` terminator
- **Memory ownership**: every `malloc` must have a corresponding `free`; partial allocation failures must free everything already allocated before returning `NULL`
- **Static library**: `ar rcs libft.a *.o` bundles object files; `ranlib` indexes them for the linker
