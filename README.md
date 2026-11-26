# push_swap

## Description

**push_swap** is a C program that sorts a list of integers using two stacks (**A** and **B**) and a restricted set of stack operations.

Given an initial list of unique integers in stack **A** (with stack **B** empty), the program outputs the shortest possible sequence of instructions to sort stack **A** in ascending order, with the smallest number at the top.

### Allowed Operations

| Instruction | Description |
| :--- | :--- |
| `sa` / `sb` / `ss` | Swap the top two elements of stack A, stack B, or both. |
| `pa` / `pb` | Push the top element from B to A (`pa`) or from A to B (`pb`). |
| `ra` / `rb` / `rr` | Rotate stack A, stack B, or both upwards (top element becomes bottom). |
| `rra` / `rrb` / `rrr` | Reverse rotate stack A, stack B, or both downwards (bottom element becomes top). |

---

## Sorting Algorithm

To minimize the total number of operations, the program handles small inputs with dedicated routines (`sort_3` for up to 3 elements, `sort_5` for up to 5 elements) and uses a **two-phase algorithm combining LIS (Longest Increasing Subsequence) and Cost-Based Sorting** for larger stacks:

### 1. LIS Pre-Sort (`where_is_lis` & `sort_lis`)
Instead of pushing every element blindly to stack **B**, the algorithm first scans stack **A** to identify the **Longest Increasing Subsequence (LIS)** already present in the stack.
- The elements belonging to this subsequence are kept in stack **A** (rotated past with `ra`).
- All remaining elements are pushed to stack **B** (`pb`).

This preserves an already-ordered backbone in stack **A** and reduces the number of elements that need to be reinserted.

### 2. Cost-Based Insertion (`swap_sort`, `n_pos`, `n_cost`, `check`)
Once only the LIS remains in stack **A**, elements are moved back from stack **B** to stack **A** one by one in a greedy, cost-optimal order:
1. **Target position (`n_pos`)**: For each element in stack **B**, the algorithm finds its target position in stack **A** — the smallest element in **A** strictly greater than it (or the minimum element of **A** if it is greater than all elements currently in **A**).
2. **Move cost calculation (`n_cost`)**: For every element in stack **B**, the algorithm computes the exact number of rotations needed to bring both the element in **B** and its target in **A** to the top of their respective stacks, comparing four strategies:
   - Rotating both stacks upwards simultaneously (`rr`, then remaining `ra`/`rb` via `move_up`).
   - Reverse-rotating both stacks downwards simultaneously (`rrr`, then remaining `rra`/`rrb` via `move_d`).
   - Rotating stack **A** upwards and stack **B** downwards (or vice versa, via `move`).
3. **Cheapest move execution**: The element in stack **B** with the lowest total cost is selected, the optimal sequence of rotations is executed, and the element is pushed back onto stack **A** (`pa`).

This repeats until stack **B** is empty.

### 3. Final Alignment (`last_sort`)
After all elements are back in stack **A**, the stack is circularly sorted. The algorithm locates the minimum value (`where_is_min`) and rotates stack **A** in the shortest direction (`ra` or `rra`) to place the smallest number at the top.

---

## Instructions

### Compilation

The project is written in C and compiled with `cc` using the `-Wall -Wextra -Werror` flags (along with the included `libft`).

```bash
# Build push_swap
make

# Rebuild from scratch
make re

# Remove object files
make clean

# Remove object files and the executable
make fclean
```

### Usage

Pass a list of integers as separate arguments or as a quoted string:

```bash
./push_swap 4 67 3 87 23
./push_swap "4 67 3 87 23"
```

- If the input is already sorted or no arguments are provided, the program outputs nothing.
- If an argument is not a valid 32-bit integer or if duplicate numbers are detected, the program prints `Error`.

---

## Project Structure

```text
.
├── Makefile
├── includes/
│   └── push_swap.h       # Data structures and function prototypes
├── libft/                # Custom C library (including ft_printf)
└── srcs/
    ├── main.c            # Entry point, sort_3, sort_5
    ├── parsing.c         # Input validation (integers, limits, duplicates)
    ├── fill_tab_pars.c   # Argument parsing and LIS detection (where_is_lis)
    ├── split_swap.c      # String splitting utility for arguments
    ├── initialize.c      # Stack and metadata initialization
    ├── push_swap.c       # Core algorithm (sort_lis, swap_sort, last_sort)
    ├── n_move.c          # Target lookup, cost calculation, and combined moves
    ├── operation.c       # Low-level stack operations
    ├── instruction.c     # sa, sb, ss, pa, pb
    ├── instruction_next.c# ra, rb, rr, rra, rrb
    ├── rev_rotate.c      # rrr
    └── stack_verrif.c    # Stack state helpers (empty, full, sorted)
```

---

## Resources

### Documentation & References
- [Implement Stack in C — GeeksforGeeks](https://www.geeksforgeeks.org/c/implement-stack-in-c/)
- [Algorithmes de tri — BCPST TP07 (CNRS)](https://mpegon.perso.math.cnrs.fr/documents/BCPST/TP07.pdf)
- [Algorithme de tri — Wikipédia](https://fr.wikipedia.org/wiki/Algorithme_de_tri)
- Peer discussions and guidance from students at **42 Perpignan**.

### AI Usage
- **No AI was used for writing code.**
- AI was only used to discuss algorithmic concepts, simplify approaches, and compare sorting strategies.
