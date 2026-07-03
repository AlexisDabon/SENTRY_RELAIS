# SENTRY RELAIS

A minimalist security system combining a C program and a Shell script.

## Objectives

Simulate a disconnector. The program monitors a frequency stream: if it goes out of bounds, the Shell intercepts the alert and shuts everything down to protect the machine.

### 1. The C Part
Systematic keyboard input flushing (getchar) to prevent the program from crashing or running out of control.

### 2. The Shell Part
It compiles the C code cleanly (-Wall -Wextra) and monitors its execution in a loop.
It catches the C exit codes on the fly and triggers the appropriate action (restart or emergency shutdown).

---

## Exit Codes

* 0: OK -> Everything is normal, monitoring continues.
* 10: Input Error -> The Shell cleans up and restarts the program.
* 20: Critical Alert -> Threshold exceeded, the Shell shuts down the system.
