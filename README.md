# An efficient algorithm for sorting a stack with a limited set of instructions.

A C project from the 42 Tokyo core curriculum. The program generates
a sequence of stack operations for sorting integers in ascending order.

I implemented two stacks using circular doubly linked lists and used
binary radix sort for inputs with more than five elements.

## Build and run

```sh
make
./push_swap 3 1 2
```

Expected output:

```text
ra
```

`ra` moves the top of stack A to the bottom, turning `[3, 1, 2]` into `[1, 2, 3]`.

