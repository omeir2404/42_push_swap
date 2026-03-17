*This project has been created as part of the 42 curriculum by oharoon.*

# push_swap

## Description
`push_swap` is a sorting project where a list of integers must be sorted in ascending order using two stacks (`a` and `b`) and a restricted set of operations.

Program usage:

```bash
./push_swap 2 1 3 6 5 8
```

Output:
- A sequence of stack operations (`sa`, `pb`, `ra`, ...), one per line.
- The sequence should sort stack `a` with as few moves as possible.

Subject-mandated behavior:
- If no parameters are provided, the program must print nothing.
- In case of invalid input, it must print `Error` followed by `\n`.
- Instructions must be separated only by newline characters.

Accepted inputs in this implementation:
- Multiple CLI arguments: `./push_swap 3 2 1`
- Single quoted argument (split by spaces): `./push_swap "3 2 1"`

## Project Structure
- `push_swap/push_swap.c`: input parsing path, stack initialization, strategy selection.
- `push_swap/srcs/check_input.c`: validation (`numeric`, `int` range, duplicates).
- `push_swap/srcs/swap.c`, `push.c`, `rotate.c`, `reverse_rotate.c`: primitive stack operations with printed op names.
- `push_swap/srcs/sort_2_3.c`, `sort_4_5.c`: dedicated small-size sorters.
- `push_swap/srcs/to_b.c`, `put_back.c`, `put_back_utils*.c`: chunk/median push-to-b then insertion-like return to `a`.
- `push_swap/srcs/radix_try.c`: radix-based strategy for large stacks.
- `push_swap/srcs/array.c`: temporary array helpers (copy, selection sort, median/quartile pick).
- `push_swap/srcs/ft_split.c`, list/atoi helpers: local utility/libft-style support.

## Instructions
### Build
From project root:

```bash
make -C push_swap
```

Binary generated:
- `push_swap/push_swap`

### Clean / Rebuild

```bash
make -C push_swap clean
make -C push_swap fclean
make -C push_swap re
```

### Run
From inside `push_swap/`:

```bash
./push_swap 5 2 3 1 4
./push_swap "5 2 3 1 4"
```

### Optional checker usage
This repository already contains `checker_linux` inside `push_swap/`.
Example test:

```bash
ARG="5 2 3 1 4"; ./push_swap $ARG | ./checker_linux $ARG
```

## Algorithm (Detailed and Justified)
### 1. Input handling and safety checks
The project builds stack `a` from arguments and rejects invalid input through:
- non-numeric tokens (`check_alpha`)
- out-of-int-range values (`ft_atoi_ps`)
- duplicates (`duplicates`)

If stack `a` is already sorted (`ordered`), the program exits without operations.

Why:
- Early validation avoids undefined behavior.
- Avoiding unnecessary operations improves score and runtime.

### 2. Strategy switch by input size
`main_aux` chooses different algorithms depending on stack length:
- `< 6` elements: dedicated hardcoded sorters (`sort_2`, `sort_3`, `sort_4`, `sort_5`)
- `6..151` elements: chunk-based push to `b` (`to_b`) then reinsertion (`put_back`)
- `> 152` elements: bitwise radix pass (`try_radix`)

Why:
- Small fixed sizes are best solved with minimal deterministic move patterns.
- Mid-size inputs benefit from chunk partitioning and controlled reinsertion.
- Large sizes are handled robustly with radix behavior using stack ops only.

### 3. Small stack sorting (2 to 5)
For tiny sets, the code uses direct comparisons and minimal operation sequences:
- `sort_2`: one `sa` if needed.
- `sort_3`: branch table based on relative order.
- `sort_4`/`sort_5`: move smallest candidates to `b`, sort remaining 3/4, then `pa` back.

Why:
- Minimal branching gives low operation count for tiny inputs.
- Avoids heavier generic logic for cases where optimal-ish sequences are known.

### 4. Mid-size chunking (`to_b` + `put_back`)
`to_b` repeatedly:
- copies stack `a` to an array (`make_array`),
- sorts that array (`array_sort`),
- computes thresholds (`quart_val`, then `mid_val`),
- pushes lower portions to `b` while rotating others in `a`.

After reducing `a` (and sorting small remainder), `put_back` reinserts from `b` to `a` by:
- choosing forward/reverse rotation path,
- placing elements between proper neighbors,
- using helper checks for top/next opportunities.

Why:
- Partitioning by quantiles reduces disorder progressively.
- Reinsertion keeps `a` close to sorted as elements return from `b`.

### 5. Large-size radix (`try_radix`)
`try_radix` performs bitwise passes over node values:
- for each bit position, rotate `a` when bit is `1`, push to `b` when bit is `0`.
- push everything back from `b` to `a` between passes.

Why:
- Deterministic and scalable for larger input counts.
- Uses only allowed operations (`ra`, `pb`, `pa`) and gives predictable complexity.

## Operations Implemented
- Swap: `sa`, `sb`, `ss`
- Push: `pa`, `pb`
- Rotate: `ra`, `rb`, `rr`
- Reverse rotate: `rra`, `rrb`, `rrr`

## Notes
- This implementation stores values directly in linked-list nodes (`t_list.value`).
- The radix path assumes values are usable for bitwise ranking behavior in current data flow.
- Bonus `checker` source is not part of this mandatory implementation (binary helper is included).

## Subject Benchmarks
According to `42_push_swap/en.subject.pdf` (Version 10.1), evaluation includes operation-count benchmarks.

For maximum validation (100%) and bonus eligibility:
- 100 numbers: fewer than 700 operations
- 500 numbers: no more than 5500 operations

For minimal mandatory validation (80% threshold), alternative benchmark pairs are listed in the subject, including:
- 100 numbers under 1100 and 500 numbers under 8500
- 100 numbers under 700 and 500 numbers under 11500
- 100 numbers under 1300 and 500 numbers under 5500

The evaluator compares both correctness and instruction count.

## Resources
- 42 project subject: `42_push_swap/en.subject.pdf`
- `man 2 write`
- `man 3 atoi`
- `man 3 malloc`
- Linked-list and stack operation references
- Sorting strategy references: insertion/chunking/radix ideas for `push_swap`
- Visual aid in repository: `push_swap/push_swap_visualizer/`

AI usage for this repository:
- AI was used to draft and structure this `README.md`.
- Content was adapted to the local implementation by reading the source files under `push_swap/`.
- Subject constraints and benchmark details were verified against `42_push_swap/en.subject.pdf`.
