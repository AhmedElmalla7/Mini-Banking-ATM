# 🏦 Mini Banking & ATM System

A robust, interactive console-based ATM simulator written in C. This project demonstrates secure memory handling, a strictly modular architecture, and a highly polished terminal user interface.

## ✨ Key Features

*   🔐 **Secure Authentication:** Complete Sign-Up and Sign-In flows featuring real-time, masked PIN input (hidden as `***` just like a real bank).
*   💰 **Core Banking Operations:** Reliable deposit and withdrawal transaction processing with strict balance verification.
*   🛡️ **Advanced Error Handling:** Bulletproof input validation that safely catches negative numbers, incorrect data types, out-of-bounds attempts, and perfectly handles `scanf` buffer clearing.
*   🎨 **Polished UI:** A vibrant, color-coded terminal interface utilizing ANSI escape sequences to provide clear, visually distinct menus and alerts.

## 📂 Project Architecture

The codebase is highly modular, separating business logic into distinct files for clean organization and easy maintenance:

*   `main.c` — The entry point, containing the main application loop and program initialization.
*   `auth.c` — Secure login validation and the dynamic PIN masking logic.
*   `signUp.c` — Account creation and struct array data management.
*   `atmMenu.c` — The stylized user session router and UI presentation.
*   `transaction.c` — Mathematical operations, balance safety checks, and function pointer implementations.

## 🚀 Getting Started

### Prerequisites
You will need a standard C compiler (like `gcc` or `clang`) installed on your system. 

### Compilation & Execution
To compile the project from your terminal, navigate to the `src` directory containing your files and run the following command to link all modules together:

```bash
gcc main.c auth.c signUp.c atmMenu.c transaction.c -o atm_system
```

Once compiled, run the executable:

```bash
./atm_system
```

## 🧠 Technical Highlights
*   **Function Pointers:** Utilizes function pointers to dynamically route transaction logic.
*   **Memory Management:** Demonstrates a deep understanding of arrays, pointers, and custom `struct` handling without relying on external databases.
*   **Buffer Safety:** Implements custom input consumption loops to prevent infinite terminal freezing caused by standard C input stream bugs.

---
