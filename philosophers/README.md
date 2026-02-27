*This project has been created as part of the 42 curriculum by acasper.*

# 🧠 Philosophers – 42 Berlin

##			Description
## 📌 Overview

The **Philosophers** project is part of the 42 core curriculum.  
It explores concurrent programming, synchronization, race conditions, and thread management through the classic *Dining Philosophers Problem*.

The goal is to simulate philosophers sitting at a table, alternating between eating, thinking, and sleeping — without causing deadlocks or data races.

---

## 🎯 Objectives

- Understand and implement **multithreading**
- Learn how to prevent:
  - Deadlocks
  - Race conditions
  - Starvation
- Work with:
  - `pthread`
  - `mutexes`
  - precise timing
- Write clean, norm-compliant C code

---

## 🧩 The Problem

Each philosopher:
- Has a fork on their left and right
- Must use **both forks** to eat
- Repeats:
  - 🍝 Eat
  - 😴 Sleep
  - 🤔 Think

The simulation stops when:
- A philosopher dies (doesn’t eat in time), or
- All philosophers have eaten the required number of times (optional argument).

---

## ⚙️ Program Arguments

```
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

| Argument | Description |
|----------|------------|
| `number_of_philosophers` | Number of philosophers (and forks) |
| `time_to_die` | Time (ms) before a philosopher dies without eating |
| `time_to_eat` | Time (ms) spent eating |
| `time_to_sleep` | Time (ms) spent sleeping |
| `number_of_times_each_philosopher_must_eat` | (Optional) Simulation stops when all have eaten this many times |

---

## 🛠️ Implementation Details

- Each philosopher is a **thread**
- Each fork is protected by a **mutex**
- Shared state is protected to avoid race conditions
- Timestamps are calculated using `gettimeofday`
- Precise sleep implementation to reduce timing drift

---

## 🧵 Synchronization Strategy

To prevent deadlocks:
- Fork locking order is controlled
- Philosophers may alternate fork pickup order
- Global state access is mutex-protected
- Death checking is handled by a monitor thread (if implemented)

---

## 🧪 Example

```
./philo 5 800 200 200
```

Expected behavior:
- 5 philosophers sit at the table
- A philosopher dies if they don’t eat within 800ms
- Eating takes 200ms
- Sleeping takes 200ms

---

## 📂 Project Structure

```
.
├── include/
│   └── philo.h
├── src/
│   ├── main.c
│   ├── init.c
│   ├── routine.c
│   ├── monitor.c
│   ├── utils.c
│   └── ...
├── Makefile
└── README.md
```

---

## 🧠 Key Concepts Learned

- Thread lifecycle management
- Mutex locking & unlocking discipline
- Shared memory protection
- Avoiding undefined behavior
- Handling edge cases (1 philosopher, high timing pressure)
- Writing concurrent-safe code under strict coding standards (Norminette)

---

##			Instructions
## 🚀 Compilation

```
make
./philo 5 800 200 200
```

---

##			Resources
## 📖 Dining Philosophers & Concurrency Concepts & POSIX Threads (pthreads)
- Dining Philosophers Problem (overview): https://en.wikipedia.org/wiki/Dining_philosophers_problem
- Deadlock (what it is / conditions): https://en.wikipedia.org/wiki/Deadlock
- Race condition: https://en.wikipedia.org/wiki/Race_condition
- Starvation (in scheduling/concurrency): https://en.wikipedia.org/wiki/Starvation_(computer_science)
- pthreads overview / API reference (Linux man pages): https://man7.org/linux/man-pages/man7/pthreads.7.html
- `pthread_create`: https://man7.org/linux/man-pages/man3/pthread_create.3.html
- `pthread_join`: https://man7.org/linux/man-pages/man3/pthread_join.3.html
- Mutexes:
  - `pthread_mutex_init`: https://man7.org/linux/man-pages/man3/pthread_mutex_init.3.html
  - `pthread_mutex_lock`: https://man7.org/linux/man-pages/man3/pthread_mutex_lock.3.html
  - `pthread_mutex_unlock`: https://man7.org/linux/man-pages/man3/pthread_mutex_unlock.3.html

---

## 🤖 Use of AI

AI was primarily used for:
- Clarifying concurrency concepts (deadlocks, race conditions, starvation)
- Understanding POSIX thread behavior and mutex best practices
- Debugging strategy discussions (segmentation faults, data races)
- Reviewing synchronization logic at a conceptual level

---

## 🏁 What I Learned

This project significantly deepened my understanding of:

- Low-level concurrency
- Debugging race conditions
- Timing precision in C
- How easily deadlocks can occur — and how to design around them

