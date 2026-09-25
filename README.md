🎮 Tic-Tac-Toe

A console-based Tic-Tac-Toe game written in C++, built from scratch as a programming project to practice program flow, input validation, functions, arrays, loops, and game-state management.

The project started as a simple idea and evolved into a complete playable game with turn handling, board management, occupied-slot checking, and win/draw detection.

---

📌 Features

- 👥 Two-player local gameplay
- ❌ Player 1 uses "X"
- ⭕ Player 2 uses "O"
- 🎯 3×3 game board
- 🔄 Automatic turn switching
- 🚫 Prevents players from selecting occupied positions
- 🏆 Detects winning combinations
- 🤝 Detects draws
- ⌨️ Handles invalid input
- 🔁 Allows the game flow to continue without restarting the program
- 🧩 Modular C++ source structure

---

🛠️ Built With

- C++
- Standard C++ library
- Console/terminal interface
- Compiled as a native executable

No external libraries or game engines are required.

---

🎮 How to Play

The game uses a numbered 3×3 board.

 1 | 2 | 3
---+---+---
 4 | 5 | 6
---+---+---
 7 | 8 | 9

Players select a position by entering its corresponding number.

For example:

Player 1: 5

The selected position is then occupied by the current player's symbol.

Players continue taking turns until one player wins or all positions are filled.

---

🏆 Win Conditions

A player wins by occupying three positions in a row.

Possible winning combinations include:

1 2 3
4 5 6
7 8 9

and the corresponding columns and diagonals.

The program checks the current board state to determine whether a winning combination has been completed.

---

📂 Project Structure

The project is organized into separate source files rather than keeping the entire program inside "main.cpp".

TIC-TAC-TOE/
│
└── tic_tac_toe/
    ├── main.cpp
    ├── function.cpp
    └── functiondecl.h

"main.cpp"

Contains the main program flow and coordinates the different parts of the game.

"function.cpp"

Contains the game's supporting functions and more complex logic, including board/game operations.

"functiondecl.h"

Contains function declarations and provides the interface between the implementation files.

This separation keeps the project easier to navigate and gives the project a more modular structure.

---

⚙️ Building From Source

Requirements

You need a C++ compiler such as:

- GCC / MinGW
- Clang
- MSVC

Compile

From the project directory:

g++ main.cpp function.cpp -o tic_tac_toe

Run

Linux/macOS:

./tic_tac_toe

Windows:

tic_tac_toe.exe

---

🧠 Concepts Practiced

This project was primarily built as a learning project and focuses on applying C++ concepts to an actual program.

C++ fundamentals

- Variables
- Data types
- "if" / "else"
- "switch"
- "while" and "for" loops
- Functions
- Function parameters
- Arrays
- References
- Input/output
- "cin" validation
- Boolean state

Programming concepts

- Game-state management
- Input validation
- Control flow
- Reusable functions
- Board representation
- Position validation
- Win-condition checking
- Turn management
- Separating declarations from implementations

---

🐛 Input Validation

The game validates player input before allowing a move to proceed.

Invalid input and already-occupied positions are handled so that a player does not accidentally overwrite an existing move.

This is an important part of the project because a playable game needs to account for more than just the normal input path.

---

🚧 Current Status

Playable / Development Project

The core Tic-Tac-Toe gameplay is implemented and functional.

The project may continue to receive improvements, refactoring, bug fixes, and additional features as development continues.

---

🔮 Possible Future Improvements

Potential additions for future versions include:

- [ ] Cleaner terminal UI
- [ ] Improved input validation
- [ ] Replay/rematch option
- [ ] Score tracking
- [ ] Player name support
- [ ] Better game-state abstraction
- [ ] Single-player mode
- [ ] Computer opponent
- [ ] Difficulty levels
- [ ] Improved code organization
- [ ] Automated testing

These are potential ideas rather than guaranteed features.

---

📚 Why I Built This

This project was created to move beyond simply learning C++ syntax and start using C++ to build something with real program flow.

Tic-Tac-Toe looks simple on the surface, but implementing it requires handling multiple interacting states:

Input
  ↓
Validate input
  ↓
Check selected position
  ↓
Update board
  ↓
Check win
  ↓
Check draw
  ↓
Switch player
  ↓
Repeat

Building the project helped reinforce how individual C++ concepts combine into a larger program.

---

📈 Project Progress

The project evolved from a basic idea into a significantly more structured program.

Some of the main challenges during development were:

- Designing the board representation
- Determining how positions map to the board
- Managing player turns
- Preventing invalid moves
- Checking winning combinations
- Keeping the program flow organized
- Splitting the project across multiple source files

Rather than relying entirely on tutorials, the project was developed by solving these problems while building the game.

---

📜 License

This project is available for learning and personal use.

If you use or modify the code, attribution is appreciated.

---

👤 Author

assassin-cloud

GitHub:
https://github.com/assassin-cloud

---

⭐ If you found the project interesting, consider starring the repository.

«Built with C++, debugging, experimentation, and a lot of trial and error.»
