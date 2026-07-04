# README - SENTRY RELAIS

A minimalist security system combining a C program and a Shell script.

---

## Objectives

Simulate a disconnector. The program monitors a frequency stream: if it goes out of bounds, the Shell intercepts the alert and shuts everything down to protect the machine.

---

## 1. The C Part

Systematic keyboard input flushing (`getchar`) to prevent the program from crashing or running out of control.

---

## 2. The Shell Part

It compiles the C code cleanly (`-Wall -Wextra`) and monitors its execution. It catches the C exit codes on the fly and triggers the appropriate action (restart or emergency shutdown).

---

## Exit Codes

* **0: OK** -> Everything is normal, monitoring continues.
* **10: Input Error** -> The Shell cleans up and restarts the program (Terminal Locked).
* **20: Critical Alert** -> Threshold exceeded, the Shell shuts down the system.

---

<details>
<summary>📜 <b>Project Specifications</b></summary>

### [1] C Core Architecture
- Implementation of a custom `Balise` struct (`frequence` as float, `statut_signal` as int).
- Secure 4-digit PIN authentication lock limited to 3 failed attempts before returning code `10`.

### [2] Shell Automation
- File existence verification (`-f main.c`).
- Compilation with strict quality flags (`gcc -Wall -Wextra`) and immediate exit on failure.
- Auto-clearing terminal (`clear`) before launching the binary.

### [3] IPC Signaling & Bounds
- Interactive menu to modify frequency or disconnect (Option 2 = exit code `0`).
- Frequency boundaries tracking ($[100.0, 500.0]$). Out-of-bounds inputs switch signal status to 0 and trigger code `20`.
- Shell intercepts code via `$?` to display the corresponding emergency messages.

### [4] Input Sanitization
- Prevents infinite loops or crashes on char inputs by cleaning the `stdin` buffer with a `getchar()` loop.
</details>
