🎮 Tic-Tac-Toe

A console-based Tic-Tac-Toe game written in C++. This project was built as a programming exercise to practice program flow, functions, arrays, loops, input validation, references, and basic game-state management.

The game supports two local players, configurable player names, a customizable exit code, optional board slot numbers, win/draw detection, and a basic scoreboard.

📌 Features

👥 Two-player local gameplay

❌ Player 1 uses X

⭕ Player 2 uses O

🎯 3×3 game board

🔄 Automatic turn switching

🚫 Prevents selecting an occupied position

🏆 Detects horizontal, vertical, and diagonal wins

🤝 Detects draws

⌨️ Handles invalid numeric input

🔢 Optional slot numbers displayed on the board

🚪 Customizable exit code during an active round

👤 Custom names for Player 1 and Player 2

🔄 Ability to reset player names to their defaults

📊 Displays round and score information

🔁 Allows additional rounds without restarting the executable

🧩 Uses separate .cpp and .h files

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
2. Options
3. Exit


Select 1 to start a game.

The board is represented internally as a 3×3 array. Players select positions using numbers from 1 to 9.

The default board starts as:

| | | |
-------
| | | |
-------
| | | |


The positions correspond to:

1 | 2 | 3
---------
4 | 5 | 6
---------
7 | 8 | 9


For example:

PLAYER 1 (X) type your slot number:
5


places X in the center position.

Players continue taking turns until there is a winner, a draw, or the configured exit code is entered.

🏆 Win Conditions

A player wins when their symbol occupies three positions in a row.

The game checks:

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


The program checks all eight possible winning combinations after each valid move.

🤝 Draw Detection

If all nine positions are occupied and no winning combination exists, the game reports:

It's a draw!


The draw counter is then increased.

🚫 Occupied Positions

A player cannot overwrite an existing X or O.

If a player selects an occupied position, the program displays:

Slot Occupied!


The same player gets another opportunity to enter a valid position.

⚙️ Options

The main menu provides an Options section with several configurable settings.

1. Show Slot Numbers

This option controls whether empty positions display their corresponding slot numbers.

The setting is disabled by default.

When enabled, the board can display:

|1|2|3|
-------
|4|5|6|
-------
|7|8|9|


After a move, occupied positions are replaced with X or O.

When disabled, empty positions are displayed as spaces.

2. Custom Exit Code

The default exit code is:

404


During an active round, entering the exit code immediately leaves the current round.

The custom exit-code menu allows the player to:

Set a new exit code

Reset the code to 404

Return to the options menu

The program requires custom exit codes to be greater than 9.

0 returns to the options menu, while 1 resets the code to the default 404.

3. Custom Player Names

Player names can be changed from the options menu.

The defaults are:

PLAYER 1
PLAYER 2


The names can be changed independently:

1. Player 1(X) name
2. Player 2(O) name
3. Set to default
4. Go back


The custom names are used when requesting moves during gameplay.

For example:

Alice (X) type your slot number:

4. Reset Player Names

The name settings also provide options to:

Reset both players

Reset Player 1

Reset Player 2

Resetting names restores the corresponding default names.

📊 Scoreboard

After a completed game, the program displays a scoreboard containing:

Round number

Player X score

Player O score

Number of draws

Example:

| ROUND NUMBER: 1 |
| --------------- |
| SCORE(X): 1     |
| --------------- |
| SCORE(O): 0     |
| --------------- |
| DRAWS: 0        |


The scoreboard values are maintained while the current gameplay session continues.

🔄 Playing Another Round

After a win or draw, the program asks:

Type anything to play another round! or (q) to quit:


Entering q exits the current game session.

Entering anything else resets the board and starts another round.

The program itself does not need to be restarted to play additional rounds.

🚪 Exiting a Round

The configured exit code can be entered during an active round.

By default:

404


Entering this value stops the current putmarker() game loop.

The main program then returns to the main menu.

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

Contains the main program loop and menu navigation.

It handles:

Main menu input

Starting a game

Opening the options menu

Changing configuration settings

Exiting the application

function.cpp

Contains the implementation of the game's functions and global game state.

It includes functionality for:

Displaying menus

Drawing the board

Resetting the board

Taking input

Detecting wins

Detecting draws

Placing player markers

Changing player names

Changing the exit code

Displaying the scoreboard

Handling invalid input

function.h

Contains function declarations and extern declarations for shared global variables.

It provides the interface between main.cpp and function.cpp.

🧠 Concepts Practiced

This project focuses on applying fundamental C++ concepts to a small interactive program.

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

Basic configuration/state management

🐛 Input Validation

The program checks for several invalid input cases.

For example:

Non-numeric input where a number is expected

Board positions outside 1–9

Selecting an occupied position

Invalid menu options

Invalid custom exit codes

When std::cin enters a failed state, the program calls cinfail() to clear the error state and discard the invalid input.

⚠️ Current Limitations

The current implementation is functional, but there are several areas that could be improved.

Scoreboard Scope

The scoreboard variables are created inside putmarker(). As a result, the scores and draw count belong to that particular game-session call and are reset when a new putmarker() call begins.

The displayed round/score information therefore does not function as persistent application-wide statistics.

Exit-Code Behavior

The exit code is checked during gameplay. However, changing the exit code to a value that overlaps with normal board positions is prevented because valid custom exit codes must be greater than 9.

Input Handling

The program handles many invalid-input cases, but input handling could be made more robust and consistent throughout every menu.

Global State

Several game settings and the board are stored as global variables:

game
firstoption
exitnumber
playeronename
playertwoname


This works for the current project but could eventually be replaced with a dedicated game/settings class or another form of encapsulation.

Game Logic Organization

Some responsibilities are currently combined inside putmarker(), including:

Turn handling

Input

Move validation

Board updates

Win detection

Draw detection

Score updates

Replay handling

Breaking these responsibilities into smaller functions could make the program easier to maintain.

🚧 Current Status

Playable / Development Project

The core two-player Tic-Tac-Toe functionality is implemented.

The current version includes gameplay, win and draw detection, configurable player names, an optional numbered board, a configurable exit code, and basic round/score display.

The project can continue to be refactored and expanded as a learning project.

🔮 Possible Future Improvements

Potential improvements include:

 Cleaner terminal UI

 More robust input handling

 Persistent scoreboard across games

 Dedicated game-state class

 Dedicated settings/configuration class

 Reduced use of global variables

 Smaller, more focused functions

 Automated tests

 Replay/rematch improvements

 Player statistics

 Player name validation

 Single-player mode

 Computer opponent

 Difficulty levels

 Improved project organization

These are potential future ideas rather than currently implemented features.

📚 Why I Built This

This project was created to practice using C++ to build an interactive program rather than only studying individual language features.

Although Tic-Tac-Toe has simple rules, implementing it requires several pieces of program logic to work together:

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


The project provided practice with managing these interacting states while also introducing a basic modular source-code structure.

📈 Project Progress

The project developed from a basic Tic-Tac-Toe implementation into a more configurable console game.

Some of the main implementation challenges included:

Representing a 3×3 board with a two-dimensional array

Mapping positions 1–9 to array coordinates

Switching between players

Preventing occupied positions from being overwritten

Detecting all possible winning combinations

Detecting a full board without a winner

Handling invalid input

Creating configurable player names

Adding a customizable exit code

Separating function declarations from implementations

The project was developed as a hands-on learning exercise using experimentation, debugging, and incremental improvements.

⚙️ Building From Source
Requirements

A C++ compiler such as:

GCC / MinGW

Clang

MSVC

Compile

From the tic_tac_toe directory:

g++ main.cpp function.cpp -o tic_tac_toe


Alternatively, from the project root:

g++ tic_tac_toe/main.cpp tic_tac_toe/function.cpp -o tic_tac_toe

Run

Linux/macOS:

./tic_tac_toe


Windows:

tic_tac_toe.exe

📜 License

This project is available for learning and personal use.

If you use or modify the code, attribution is appreciated.

👤 Author

assassin-cloud

GitHub:

https://github.com/assassin-cloud

⭐ If you find the project interesting, consider starring the repository.

Built with C++, debugging, experimentation, and a lot of trial and error.
