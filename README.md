# OSTEP Projects Solutions

This repository contains solutions to projects from the book [Operating Systems: Three Easy Pieces (OSTEP)](https://pages.cs.wisc.edu/~remzi/OSTEP/).

## Project List

- [Initial Key-Value Store](01%20-%20initial-kv/solution.c)
  - Implements a minimal persistent key-value store supporting put, get, delete, all, and clear operations via command-line arguments.

_More projects and solutions will be added to this repository over time._

## How to Run (for each project)

1. Navigate to the project directory and compile the solution, for example:
   ```sh
   gcc -o kv "01 - initial-kv/solution.c" --Wall
   ```
2. Run the program with the required arguments, for example:
   ```sh
   ./kv p,5,bar g,5 d,5 a d
   ```

## Files

- `solution.c` — Main implementation for each project.
- `test-kv.sh` — Test script for the key-value store project.
- `tests/` — Directory containing test cases and expected outputs for the key-value store.

## More Information

- These projects are for educational purposes and demonstrate concepts such as file I/O, memory management, concurrency, and more in C.
- For more details on the OSTEP projects, see the [OSTEP Projects GitHub](https://github.com/remzi-arpacidusseau/ostep-projects).
- For questions or improvements, refer to the book or open an issue in your own repository fork.
