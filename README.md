# Castle Battle Simulation - Phase 1

A C++ data-structures course project: a turn-based simulation of a medieval castle defended by four towers against waves of enemies. The goal is to choose, build and justify the right **data structures** (all written from scratch, **no STL containers**) and to apply **object-oriented design** (inheritance, polymorphism, encapsulation).

> **Status:** Phase 1 is delivered. Phase 2 (fighting logic, statistics and output file) is still to be done and is listed at the end of this document.

---

## Team

| Member | Contribution |
|---|---|
| **Malak** | Full data members of `Enemy` (abstract base), `Tower` and `Castle`. Status bar statistics in the GUI (tower information, active and killed counts per region). |
| **Youstena** | Data structures `Queue<T>` and `LinkedList<T>` (templates, no STL). Sample input (test) files. |
| **Mohamed** | Random kill of active enemies and moving them from the *Active* list to the *Killed* list. |
| **Mahmoud** (team leader) | Input file loading, enemy creation by type, inactive queue and arrival management, project integration and Git workflow. |

---

## The Game in Brief

- The castle has **4 towers**, one per region: **A, B, C, D**.
- Enemies arrive over time, start **60 m** from the tower of their region and move towards it (closest distance: **2 m**).
- Enemy types: **Fighter** (attacks the tower), **Healer** (heals other enemies), **Freezer** (freezes the tower with ice).
- Time advances in discrete **time steps**.

Phase 1 covers everything that is *not* fighting logic or statistics.

---

## What Phase 1 Delivers

- [x] **Full data members** for `Enemy` and its subclasses `Fighter`, `Healer`, `Freezer`, and for `Tower` and `Castle`
- [x] **Data structures from scratch**, as templates: `Queue<T>` and `LinkedList<T>` (with `Node<T>`)
- [x] **File loading**: reads tower data and all enemies from an input file, creates each enemy **once** with `new` according to its type, and fills the *Inactive* queue
- [x] **Simple simulator** (`Battle::RunSimulation`). At every time step it:
  1. moves enemies from *Inactive* to *Active* according to their arrival time,
  2. picks random active enemies and moves them to the *Killed* queue,
  3. moves the remaining enemies towards their tower,
  4. redraws the battle on the GUI,
  5. prints the status bar (see below),
  6. waits for a mouse click to go to the next time step.
- [x] **Status bar**: for each region it shows the tower information (health, power, max enemies per step), the number of currently active enemies and the number of enemies killed so far
- [x] **Three sample input files** in `TestFiles/`

No output file is produced in this phase, and there is no fighting or healing yet.

### Data structure choices

| List | Structure | Why |
|---|---|---|
| **Inactive** enemies | `Queue` | The input file is sorted by arrival time, so enemies leave in FIFO order and only the front is ever inspected. Enqueue and dequeue are O(1). |
| **Active** enemies | `LinkedList` | Enemies are removed from arbitrary positions (killed, later also frozen or moved), which is O(1) on a linked list once the node is found and would need shifting in an array. In Phase 1 one list serves all regions (at most 300 enemies); it will be split per region in Phase 2, because each tower only deals with its own region. |
| **Killed** enemies | `Queue` | Enemies are killed in chronological order, which matches the order needed for the output file. They are kept (not deleted) because the statistics need them. |

Enemy objects are **never copied**: every list stores `Enemy*`, so moving an enemy between lists only moves a pointer.

---

## Project Structure

```
CastleDSProject.sln / .vcxproj
Demo_Main.cpp                 main()
Battle.h / Battle.cpp         Controller: loading, arrivals, kills, drawing, status bar
FileReading.h / .cpp          Input file parser (ReadInputFile)
Defs.h                        Shared constants and enums
Castle/                       Castle.*, Tower.*
Enemies/                      Enemy.* (abstract), Fighter.*, Healer.*, Freezer.*
DSs/                          Node.h, Queue.h, LinkedList.h
GUI/                          GUI.* (provided; PrintLines added for the status bar)
CMUgraphicsLib/               Graphics library (provided, not modified)
TestFiles/                    Sample input files
```

---

## Build and Run

**Requirements:** Windows and Visual Studio 2022 (Desktop development with C++).

1. Clone the repository and open `CastleDSProject.sln`.
2. Build and run (`F5`). A GUI window opens.
3. Click anywhere in the window to advance one time step.

The input file is currently chosen inside `Battle::RunSimulation` (`TestFiles/TestFile1.txt`). Change that path to run another test file. Choosing the file and the mode from the GUI comes in Phase 2.

### Input file format

```
TH N TP
S TYP T H POW RLD REG
...
-1
```

| Field | Meaning |
|---|---|
| `TH` / `N` / `TP` | Tower health / max enemies a tower shoots per step / tower power |
| `S` | Enemy ID |
| `TYP` | `1` = Fighter, `2` = Healer, `3` = Freezer |
| `T` | Arrival time step |
| `H` / `POW` / `RLD` | Enemy health / power / reload period |
| `REG` | Region: `A`, `B`, `C` or `D` |

### Sample files

| File | Towers (`TH N TP`) | Enemies | Last arrival |
|---|---|---|---|
| `TestFile1.txt` | 200 3 14 | 21 | step 56 |
| `TestFile2.txt` | 150 2 10 | 25 | step 70 |
| `TestFile3.txt` | 250 4 18 | 25 | step 410 |

---

## Phase 2 (To Do)

### Combat logic
- [ ] Tower priority formula (at least 3 factors: distance, type, health, power, state, remaining reload, last attackers) and selection of the top `N` enemies per step
- [ ] Fighter damage: `(K / distance) x power` (`K = 1` healthy, `0.5` below half health)
- [ ] Tower damage: `(1 / distance) x tower power x (1 / K)` (`K = 2` for Healers, `1` otherwise)
- [ ] Enemy movement (half speed below half health) and reload handling
- [ ] Healer behaviour (heal enemies within 2 m, never the dead)
- [ ] Freezer behaviour (ice accumulation, tower freeze duration)
- [ ] Tower ice shots (at most 20% of all shots) and frozen-tower behaviour
- [ ] Tower destruction: move current and future enemies of that region to the next region clockwise (A, B, C, D, A)
- [ ] Game result: WIN / LOSS / DRAWN

### Statistics and output
- [ ] First-shot delay (FD), kill delay (KD) and lifetime (LT = FD + KD) per enemy
- [ ] Output file (killed enemies sorted by kill time then FD, total damage per tower, result, summary statistics)
- [ ] Interactive mode and Silent mode, with file selection from the GUI

### Deliverables
- [ ] Six test files (weak to strong scenarios) with their outputs
- [ ] Work distribution document

### Bonus (optional)
- [ ] Towers with different parameters and a rebuild ability
- [ ] Two new enemy types with non-trivial behaviour

### Planned improvements to the Phase 1 code
- [ ] Split the *Active* list into one list per region
- [ ] Replace the temporary kill rule used for testing (random kills only when many enemies are active) and the fixed 75-step limit with the real stopping condition (no inactive and no active enemies left)
- [ ] Free all enemies at the end of the simulation (destructor of `Battle`) and free list nodes on removal
- [ ] Use `Move()` polymorphically for every enemy and add `KillTime` to `Enemy` (needed for KD and LT)
- [ ] Remove the `<random>`, `<algorithm>` and `<chrono>` includes from `Battle.h` in favour of `rand()`
- [ ] Remove leftover files (`DSs_Test`, unused declarations) and unnecessary includes

---

## Development Rules

- **No STL containers**, no external data-structure libraries, **no global variables**.
- One class per `.h`/`.cpp` pair (templates live in headers).
- `Enemy` is abstract; each type overrides its behaviour.
- An enemy is allocated once; lists hold pointers.

## Git Workflow

```
main    stable versions (end of each phase)
 └── dev    integration branch
      └── <member>/<feature>    one branch per task
```

1. Create your branch from `dev`, commit often, and push it.
2. When a piece of work is complete and builds, open a **Pull Request into `dev`**.
3. Before opening the PR (and before a new task): `git checkout dev`, `git pull`, return to your branch, `git merge dev`.
4. The team leader reviews and merges. `dev` is merged into `main` when a phase is finished.
