AoA - Code Report
=================

Generated: Oct 26, 2025

Summary
-------
This repository contains a set of C algorithm programs. I compiled and ran each program (short timeout) and produced per-file compile/run logs in `build/` and this top-level summary.

Overall results
---------------
- Built directory: `build/` (contains executables and per-file logs)
- Consolidated build report: `build/report.txt`

Per-file results and example inputs
----------------------------------

1) AllPairShortestPath.c
- Status: Compiled OK
- Notes: Program reads graph size and edges from stdin and prints shortest-path matrix.
- Example input (4 nodes, 5 edges):

```
4 5
1 2 3
1 3 8
2 3 2
3 4 1
4 2 -4
```
- Run (from repo root):

```bash
gcc -std=c99 -O2 AllPairShortestPath.c -o build/AllPairShortestPath
printf "4 5\n1 2 3\n1 3 8\n2 3 2\n3 4 1\n4 2 -4\n" | ./build/AllPairShortestPath
```


2) Knapsack.c
- Status: Compiled with warnings (OK)
- Notes: Uses fractional knapsack; program expects: n, weights[], profits[], capacity
- Example input:

```
3
10 20 30
60 100 120
50
```
- Run:

```bash
gcc -std=c99 -O2 Knapsack.c -o build/Knapsack
printf "3\n10 20 30\n60 100 120\n50\n" | ./build/Knapsack
```


3) LCS-problem.c
- Status: Compiled with warnings (OK)
- Notes: Reads two lines (strings) via fgets and prints the LCS.
- Example input:

```
AGGTAB
GXTXAYB
```
- Run:

```bash
gcc -std=c99 -O2 LCS-problem.c -o build/LCS-problem
printf "AGGTAB\nGXTXAYB\n" | ./build/LCS-problem
```


4) N-Queen-Probelm.c
- Status: Compiled with warnings (OK)
- Notes: Reads integer n (number of queens) and prints solutions.
- Example input: `4`
- Run:

```bash
gcc -std=c99 -O2 N-Queen-Probelm.c -o build/N-Queen-Probelm
printf "4\n" | ./build/N-Queen-Probelm
```


5) NaiveMethod.c (Naive pattern search)
- Status: Compiled with warnings (OK)
- Notes: Reads a text line and a pattern line then prints matches.
- Example input:

```
ABCABCABCD
ABC
```
- Run:

```bash
gcc -std=c99 -O2 NaiveMethod.c -o build/NaiveMethod
printf "ABCABCABCD\nABC\n" | ./build/NaiveMethod
```


6) binarySearch.c
- Status: Compiled with warnings (OK)
- Notes: Reads n, n sorted integers, then the key to search.
- Example input:

```
5
1 2 3 4 5
3
```
- Run:

```bash
gcc -std=c99 -O2 binarySearch.c -o build/binarySearch
printf "5\n1 2 3 4 5\n3\n" | ./build/binarySearch
```


7) insertionSort.c
- Status: FAILED to compile on Linux (uses <conio.h>)
- Notes: `conio.h` is a DOS/Windows header and not available on Linux. The file does not appear to use any conio functions (like getch), so remove `#include<conio.h>` and change `void main()` to `int main()` to compile cleanly.
- Suggested fix:
  - Remove the line `#include<conio.h>`
  - Replace `void main()` with `int main()` and add `return 0;` at the end.
- Example input (after fix):

```
5
5 2 9 1 5
```
- Run (after fix):

```bash
gcc -std=c99 -O2 insertionSort.c -o build/insertionSort
printf "5\n5 2 9 1 5\n" | ./build/insertionSort
```


8) mergeSort.c
- Status: Compiled with warnings (OK)
- Notes: Reads n and n integers and prints sorted array.
- Example input:

```
6
5 2 9 1 3 8
```
- Run:

```bash
gcc -std=c99 -O2 mergeSort.c -o build/mergeSort
printf "6\n5 2 9 1 3 8\n" | ./build/mergeSort
```


9) quicksort.c
- Status: FAILED to compile on Linux (uses <conio.h>)
- Notes: Same fix as insertionSort: remove `#include<conio.h>` and change `void main()` to `int main()` with `return 0;` at end.
- Example input (after fix):

```
5
5 2 9 1 5
```
- Run (after fix):

```bash
gcc -std=c99 -O2 quicksort.c -o build/quicksort
printf "5\n5 2 9 1 5\n" | ./build/quicksort
```


10) selectionSort.c
- Status: FAILED to compile on Linux (uses <conio.h>)
- Notes: Same fix: remove `#include<conio.h>` and use `int main()`.
- Example input (after fix):

```
5
5 2 9 1 5
```
- Run (after fix):

```bash
gcc -std=c99 -O2 selectionSort.c -o build/selectionSort
printf "5\n5 2 9 1 5\n" | ./build/selectionSort
```


How I tested
------------
- I compiled all files and placed executables and logs in `build/`.
- Each program was run for up to 3 seconds with no input to detect whether it prints output unprompted or waits for stdin. Most programs wait for input (run logs empty).
- A consolidated machine-readable report was generated at `build/report.txt`.

Next steps & suggestions
-----------------------
- Fix the 3 files that include `conio.h` (insertionSort.c, quicksort.c, selectionSort.c): remove the include and change `void main()` to `int main()` with `return 0;`.
- Re-run the compile step then run each program with the example inputs above to verify runtime output.
- Optionally, add minimal CLI usage notes to each source file's header (comment) so users know expected inputs.

If you want, I can:
- Apply the simple conio.h removals and main signature fixes automatically and re-run the build/tests.
- Run each program with the example inputs and capture their outputs into `build/` logs.

Artifacts created
----------------
- `build/` (executables and logs)
- `build/report.txt` (automatically generated)
- `CODE_REPORT.md` (this summary)

Thank you — tell me if you want me to apply the fixes for the 3 failing files and re-run everything.