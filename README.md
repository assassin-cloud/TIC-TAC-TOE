🎮 Tic-Tac-Toe

A console-based Tic-Tac-Toe game written in C++, created as a hands-on programming project to practice functions, arrays, loops, input validation, references, global state, game logic, and multi-file project organization.

The game supports two local players, customizable player names, configurable gameplay options, win/draw detection, an optional numbered board, a customizable exit code, and a session scoreboard.

✨ Features

👥 Two-player local gameplay

❌ Player 1 uses X

⭕ Player 2 uses O

🎯 3×3 game board

🔄 Automatic turn switching

🚫 Prevents moves on occupied positions

🏆 Horizontal, vertical, and diagonal win detection

🤝 Draw detection

⌨️ Basic invalid-input handling

🔢 Optional slot numbers on the board

🚪 Configurable exit code during gameplay

👤 Custom names for both players

🔄 Reset player names to defaults

📊 Session scoreboard

🔁 Multiple rounds without restarting the program

⚙️ Configurable gameplay options

🧩 Separate .cpp and .h files

🛠️ Standard C++ library only

🛠️ Built With

C++

Standard C++ Library

Console / terminal interface

No external libraries or game engines are required.

🎮 How to Play

When the program starts, the main menu is displayed:

==================
   TIC TAC TOE
==================
Note: Type 404 in a ongoing round to exit

1. PLay
2. See Scoreboard
3. Options
4. Exit

Input:


Select 1 to start a game.

Board Layout

The board uses nine positions:

1 | 2 | 3
---------
4 | 5 | 6
---------
7 | 8 | 9


For example:

PLAYER 1 (X) type your slot number:
5


places X in the center of the board.

Players continue taking turns until:

A player wins

The board is full

The configured exit code is entered

🏆 Winning the Game

A player wins when their symbol occupies three positions in a row.

The game checks all eight possible winning combinations.

Rows
1 2 3
4 5 6
7 8 9

Columns
1 4 7
2 5 8
3 6 9

Diagonals
1 5 9
3 5 7


After every valid move, the program checks whether the move resulted in a win.

🤝 Draw Detection

If all nine positions are occupied and neither player has won, the game reports:

It's a draw!


The draw counter is then increased.

🚫 Occupied Positions

Players cannot overwrite an existing X or O.

If an occupied position is selected:

Slot Occupied!


The current player can then choose another position.

⚙️ Options

The Options menu provides several configuration settings.

==============
   OPTIONS
==============
Note: (0) means Disabled and (1) means Enabled

1. Show slot numbers on board(default:disabled): 0
2. Add Custom Exit Number: 404
3. Give custom name to PLAYER 1(X) and PLAYER 2(O)
4. Reset scores after going to main menu(default: Disabled): 0
5. Reset all options to default
6. Go back

1. Show Slot Numbers

Controls whether empty board positions display their corresponding slot numbers.

Disabled by default.

Disabled:

| | | |
-------
| | | |
-------
| | | |


Enabled:

|1|2|3|
-------
|4|5|6|
-------
|7|8|9|


After a move, the selected position is replaced with X or O.

2. Custom Exit Code

The default exit code is:

404


During an active round, entering the configured exit code leaves the current round.

Custom exit codes must be greater than 9, preventing normal board positions (1–9) from being used as exit codes.

The exit-code menu provides:

0 → Return to Options
1 → Reset exit code to 404
10+ → Set a custom exit code

3. Custom Player Names

Both player names can be changed independently.

Default names:

PLAYER 1
PLAYER 2


The menu allows you to:

Change Player 1's name

Change Player 2's name

Reset either or both names

Return to the Options menu

Example:

Alice (X) type your slot number:


Empty names are rejected.

4. Reset Scores

The Reset scores after going to main menu option controls whether the scoreboard is cleared after leaving a game session.

This option is disabled by default.

Scores can also be reset manually from the Scoreboard menu.

5. Reset All Options

The Reset all options to default option restores:

Setting	Default
Show slot numbers	Disabled
Exit code	404
Player 1 name	PLAYER 1
Player 2 name	PLAYER 2
Reset scores	Disabled
📊 Scoreboard

The game maintains scoreboard information during the current application session.

The scoreboard tracks:

Round number

Player X wins

Player O wins

Number of draws

Example:

| ROUND NUMBER: 1 |
| --------------- |
| SCORE(X): 1     |
| --------------- |
| SCORE(O): 0     |
| --------------- |
| DRAWS: 0        |


The Scoreboard menu also provides an option to reset all scores and round statistics.

🔄 Multiple Rounds

After a player wins or a draw occurs, the program asks:

Type anything to play another round! or (q) to quit:


Entering:

q


leaves the current game session.

Entering anything else resets the board and starts another round.

There is no need to restart the executable.

🚪 Exiting During a Round

The configured exit code can be entered at any point during an active round.

The default value is:

404


Example:

PLAYER 1 (X) type your slot number:
404


This stops the current round and returns control to the main program.

📂 Project Structure
assassin-cloud-tic-tac-toe/
│
├── README.md
│
└── tic_tac_toe/
    ├── main.cpp
    ├── function.cpp
    ├── function.h
    └── simplefunctions.cpp

main.cpp

Contains the main application loop and menu navigation.

Responsibilities include:

Main menu input

Starting games

Opening the scoreboard

Opening the Options menu

Changing configuration settings

Resetting configuration

Exiting the application

function.cpp

Contains the core game logic and shared game state.

Responsibilities include:

Board resetting

Player input

Move validation

Win detection

Draw detection

Marker placement

Turn management

Score updates

Round management

Replay handling

simplefunctions.cpp

Contains simpler UI and utility functions.

Responsibilities include:

Menu display

Options menu

Scoreboard display

Board rendering

Input handling

Invalid-input handling

Player-name input

Player-name menus

function.h

Contains function declarations and extern declarations for shared global variables.

It provides the interface between the implementation files.

🧠 Concepts Practiced

This project was built to practice fundamental C++ programming concepts.

C++ Fundamentals

Variables

Primitive data types

std::string

Boolean values

if / else

while loops

for loops

Functions

Function parameters

References

Arrays

std::cin

std::cout

std::to_string()

Programming Concepts

Game-state management

Input validation

Control flow

Turn management

Board representation

Position mapping

Win-condition checking

Draw detection

Reusable functions

Separating declarations from implementations

Configuration management

Shared application state

🛡️ Input Validation

The program handles several invalid-input situations, including:

Non-numeric input where a number is expected

Board positions outside 1–9

Selecting an occupied position

Invalid menu selections

Invalid custom exit codes

Empty player names

When std::cin enters a failed state, cinfail() clears the error state and discards the invalid input.

⚠️ Current Limitations

The project is functional, but there are several areas that could be improved.

Global State

Several settings and game values are stored as global variables:

game
firstoption
fourthoption
exitnumber
playeronename
playertwoname
round
scoreofx
scoreofo
numberofdraws


This works for the current project, but a future version could encapsulate the state inside dedicated classes or structures.

Large Game Function

gameflow() currently handles several responsibilities, including:

Turn management

User input

Move validation

Board updates

Win detection

Draw detection

Score updates

Round management

Replay handling

Breaking these responsibilities into smaller functions would make the code easier to test and maintain.

Input Handling

Input validation is implemented throughout the program, but numeric input and menu validation could be centralized into reusable functions.

Session-Only Scoreboard

The scoreboard exists only while the program is running.

Closing the application resets:

Scores

Round count

Draw count

Player names

Options

No persistent storage is currently implemented.

🚧 Current Status

Playable / Development Project

The core two-player Tic-Tac-Toe functionality is implemented.

Current functionality includes:

Two-player gameplay

Win detection

Draw detection

Configurable player names

Optional numbered board

Configurable exit code

Session scoreboard

Multiple rounds

Configuration reset options

Basic input validation

The project is still suitable for further refactoring, experimentation, and feature development.

🔮 Possible Future Improvements

Potential improvements include:

🧹 Cleaner terminal UI

🛡️ More robust input handling

💾 Persistent scoreboard storage

📦 Dedicated game-state class

⚙️ Dedicated settings class

🌎 Reduced use of global variables

✂️ Smaller, more focused functions

🧪 Automated tests

🔁 Improved replay/rematch system

📈 Additional player statistics

✍️ Improved player-name validation

🤖 Single-player mode

🧠 Computer opponent

🎚️ Difficulty levels

🗂️ Improved project organization

These are possible future improvements and are not currently implemented.

📚 Why I Built This

This project was created as a practical way to learn C++ by building an interactive program instead of only studying individual language features.

Although Tic-Tac-Toe has simple rules, implementing it requires several pieces of logic to work together:

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


The project provided practice with managing interacting states while also introducing a basic multi-file C++ project structure.

📈 Project Progress

The project started as a basic Tic-Tac-Toe implementation and gradually gained additional configuration and gameplay features.

Some of the main implementation challenges included:

Representing a 3×3 board with a two-dimensional array

Mapping positions 1–9 to array coordinates

Switching between players

Preventing occupied positions from being overwritten

Detecting all possible winning combinations

Detecting a full board without a winner

Handling invalid input

Adding configurable player names

Adding a customizable exit code

Adding optional board slot numbers

Implementing a session scoreboard

Separating function declarations from implementations

The project was developed through experimentation, debugging, and incremental improvements.

⚙️ Building From Source
Requirements

You need a C++ compiler such as:

GCC / MinGW

Clang

MSVC

The project uses only the standard C++ library.

Compile

From the tic_tac_toe directory:

g++ main.cpp function.cpp simplefunctions.cpp -o tic_tac_toe


Or from the project root:

g++ tic_tac_toe/main.cpp tic_tac_toe/function.cpp tic_tac_toe/simplefunctions.cpp -o tic_tac_toe


Note: simplefunctions.cpp must also be compiled because it contains functions declared in function.h.

Run
Linux / macOS
./tic_tac_toe

Windows
tic_tac_toe.exe

🐛 Known Development Issues

This project is primarily a learning exercise, so the codebase still contains areas that can be improved.

For example:

Some functions perform multiple responsibilities.

Global variables are used for shared state.

Input handling could be centralized.

Game logic could be separated from UI logic.

The project does not currently have automated tests.

Game statistics are not persisted between executions.

These limitations are intentional opportunities for future refactoring and learning.

📜 License

This project is available for learning and personal use.

If you use or modify the code, attribution is appreciated.

👤 Author

assassin-cloud

GitHub: https://github.com/assassin-cloud

⭐ If you find the project interesting, consider starring the repository.

Built with C++, debugging, experimentation, and a lot of trial and error. 🎮
