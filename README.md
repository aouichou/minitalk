<h1 align="center">minitalk</h1>
<h3 align="center">42Paris School Project</h3>

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue.svg" alt="Language">
  <img src="https://img.shields.io/badge/Status-Completed-brightgreen.svg" alt="Status">
</p>

## About the Project

`minitalk` is a lightweight client-server communication program that uses UNIX signals (`SIGUSR1` and `SIGUSR2`) for data transmission. Developed as part of the 42Paris curriculum, this project demonstrates low-level signal handling, bit manipulation, and inter-process communication (IPC) in C. The server can receive messages from multiple clients sequentially without restarting.

## Features

- **Signal-Based Communication**: Uses only `SIGUSR1` and `SIGUSR2` for data transmission.
- **Client-Server Architecture**:
  - Server displays its PID on startup.
  - Client sends messages or files to the server using the server's PID.
- **Efficient Transmission**: Handles large messages quickly (e.g., 10,000+ characters).
- **Error Handling**: Robust error checking for invalid PIDs, signal failures, and memory leaks.
- **Bonus Features**:
  - Server acknowledges received messages with return signals.
  - Support for Unicode characters.

## Technical Details

- **Language**: C
- **System Calls**: `sigaction`, `kill`, `getpid`, `malloc`, `pause`
- **Libraries**: Custom `libft` for utilities (e.g., `ft_printf`, `ft_atoi`)

## Getting Started

### Prerequisites

- C compiler (e.g., `gcc`)
- GNU Make

### Installation

1. Clone the repository:
   ```sh
   git clone https://github.com/<your-username>/minitalk.git
   cd minitalk
   ```

2. Compile the project:
   ```sh
   make
   ```

### Usage

1. Start the server:
   ```sh
   ./server
   ```
   The server will print its PID (e.g., `PID: 12345`).

2. Send a message from the client:
   ```sh
   ./client 12345 "Hello, World!"
   ```
   or send a file:
   ```sh
   ./client 12345 file.txt
   ```

## Project Structure

```
.
├── includes/       # Header files
│   ├── minitalk.h  # Shared definitions
│   └── libft.h     # Custom library utilities
├── libft/          # Custom C library (42's libft)
├── srcs/
│   ├── client/     # Client source code
│   ├── server/     # Server source code
│   └── utils.c     # Shared error-handling functions
└── Makefile        # Build script
```

## Key Components

- **Signal Handling**: Uses `sigaction` to capture and process bits sent via `SIGUSR1` (bit `1`) and `SIGUSR2` (bit `0`).
- **Bitwise Transmission**: Messages are sent character-by-character using bit-shifting operations.
- **Memory Management**: Zero memory leaks ensured with strict `free()` checks.
- **Unicode Support**: Bonus feature encodes extended ASCII/Unicode characters.

## Acknowledgements

Developed as part of the 42Paris curriculum. Special thanks to the 42 network for foundational systems programming knowledge.

---

<p align="left">
  <a href="https://www.linkedin.com/in/your-profile" target="blank">
    <img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/linked-in-alt.svg" alt="Your Name" height="30" width="40" />
  </a>
</p>
