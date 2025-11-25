Sort Method Comparison (Selection vs. Merge)
===========================================

A C++ console program that builds an unordered linked list of random
9-digit integers and sorts it using either selection sort, merge sort,
or both for timing comparison. Lists up to 100 elements are printed
before and after sorting. The program reports runtimes in microseconds
or milliseconds.

Files
-----
- `sortCompare.cpp` — main program (builds list, runs selected sort(s), times them)
- `utilities.h` — input helpers, `buildRandomIntList`, `waitLine`
- `linkedList.h`, `unorderedLinkedList.h` — linked list class templates

Considerations
--------------
- Elements are random 9-digit integers.
- If the list size is greater than 100, the list is not printed.
- Timings are taken with `std::chrono` and displayed for each sort.
- Menu options:
  - `1` — Selection sort only
  - `2` — Merge sort only
  - `3` — Run both and compare times
- Enter `0` at the size prompt to quit.

Usage
-----
1. Compile `sortCompare.cpp`

2. Run the program:


3. At the prompts:
   - Enter the number of elements to generate and sort (0 to quit).
   - Choose the sort method (1–3) when prompted.
   - Press Enter when prompted to continue after each run.

Contact
-------
Bruce Nebergall
