🎮 Tic-Tac-Toe

A console-based Tic-Tac-Toe game written in C++, built as a hands-on programming exercise to practice functions, arrays, loops, input validation, references, global state, game logic, and basic project organization.

The game supports two local players, customizable player names, configurable settings, win/draw detection, an optional numbered board, a customizable exit code, and a session scoreboard.

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

🔄 Reset player names to their defaults

📊 Session scoreboard

🔁 Multiple rounds without restarting the program

⚙️ Configurable gameplay options

🧩 Separate .cpp and .h files

🛠️ Built With

C++

Standard C++ library

Console/terminal interface

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

The board contains nine positions:

1 | 2 | 3
---------
4 | 5 | 6
---------
7 | 8 | 9


For example, entering:

PLAYER 1 (X) type your slot number:
5


places X in the center of the board.

Players continue taking turns until somebody wins, the board becomes full, or the configured exit code is entered.

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

If an occupied position is selected, the program displays:

Slot Occupied!


The current player can then enter another position.

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

The option is disabled by default.

Disabled
| | | |
-------
| | | |
-------
| | | |

Enabled
|1|2|3|
-------
|4|5|6|
-------
|7|8|9|


After a move, the selected position is replaced by X or O.

2. Custom Exit Code

The default exit code is:

404


During an active round, entering the configured exit code leaves the current round.

Custom exit codes must be greater than 9.

The exit-code menu also provides:

0 — Return to the Options menu

1 — Reset the exit code to 404

Any number greater than 9 — Set a new exit code

The program does not allow normal board positions (1–9) to be used as exit codes.

3. Custom Player Names

Both player names can be changed independently.

Default names:

PLAYER 1
PLAYER 2


The menu provides options to:

Change Player 1's name

Change Player 2's name

Reset names

Return to the previous menu

For example:

Alice (X) type your slot number:


Empty names are rejected.

4. Reset Scores

The Reset scores after going to main menu option controls whether the scoreboard is cleared after returning from a game session.

This setting is disabled by default.

The scoreboard can also be reset directly from the Scoreboard menu.

5. Reset All Options

The Reset all options to default option restores:

Show slot numbers: Disabled
Exit code:          404
Player 1 name:      PLAYER 1
Player 2 name:      PLAYER 2
Reset scores:       Disabled

📊 Scoreboard

The program maintains scoreboard information during the current application session.

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


The scoreboard can be viewed from the main menu.

It also provides an option to reset all scores and round statistics.

🔄 Playing Multiple Rounds

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


For example:

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
    └── function.h

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

Contains the implementation of the game's functions and shared game state.

Responsibilities include:

Menu display

Board rendering

Board resetting

Player input

Move validation

Win detection

Draw detection

Marker placement

Player-name management

Exit-code management

Scoreboard display

Invalid-input handling

function.h

Contains function declarations and extern declarations for shared global variables.

It provides the interface between main.cpp and function.cpp.

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

Configuration/state management

🐛 Input Validation

The program handles several invalid-input situations, including:

Non-numeric input where a number is expected

Board positions outside 1–9

Selecting an occupied position

Invalid menu selections

Invalid custom exit codes

Empty player names

When std::cin enters a failed state, the program uses cinfail() to clear the error state and discard invalid input.

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


This works for the current project, but a future version could encapsulate this state inside dedicated classes or structures.

Large Game Function

putmarker() currently handles many responsibilities:

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

Input validation is implemented throughout the program, but the handling could be made more consistent by centralizing numeric input and menu validation.

Scoreboard Scope

The scoreboard is maintained through global variables during the running application.

This means the statistics are not saved after the executable closes.

No Persistent Storage

Scores, names, and settings are stored only in memory.

Closing the program resets the application state.

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

The project is still suitable for further refactoring and experimentation.

🔮 Possible Future Improvements

Some potential improvements for future versions include:

🧹 Cleaner terminal UI

🛡️ More robust input handling

💾 Persistent scoreboard storage

📦 Dedicated game-state class

⚙️ Dedicated settings class

🌎 Reduced use of global variables

✂️ Smaller, more focused functions

🧪 Automated tests

🔁 Improved replay/rematch system

📈 Player statistics

✍️ Improved player-name validation

🤖 Single-player mode

🧠 Computer opponent

🎚️ Difficulty levels

🗂️ Improved project organization

These are planned or possible improvements rather than currently implemented features.

📚 Why I Built This

This project was created as a practical way to learn C++ by building an interactive program rather than only studying individual language features.

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


The project provided practice with managing these interacting states while also introducing a basic multi-file C++ project structure.

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

g++ main.cpp function.cpp -o tic_tac_toe


Or from the project root:

g++ tic_tac_toe/main.cpp tic_tac_toe/function.cpp -o tic_tac_toe

Run
Linux / macOS
./tic_tac_toe

Windows
tic_tac_toe.exe

📜 License

This project is available for learning and personal use.

If you use or modify the code, attribution is appreciated.

👤 Author

assassin-cloud

GitHub:
https://github.com/assassin-cloud

⭐ If you find the project interesting, consider starring the repository.

Built with C++, debugging, experimentation, and a lot of trial and error. 🎮
