Battleship Console Game – C++ Project Wiki
1. Project Overview

This project is a console-based Battleship game developed using basic C++ programming.

The game follows a procedural programming approach and does not use Object-Oriented Programming (OOP).

It is designed to strengthen core programming concepts such as arrays, loops, functions, and conditional logic.

The game supports two modes:

Player vs Player (PvP)

Player vs Computer (PvC)

2. Technologies & Tools Used

Programming Language: C++

Platform: Console / Terminal

Programming Paradigm: Procedural Programming

Compiler: Any standard C++ compiler (GCC, MinGW, etc.)

3. Core Programming Concepts Used

2D Arrays for game board representation

Functions for modular code design

Loops (for, while) for game flow control

Conditional statements (if-else) for decision making

Random number generation (rand()) for computer moves

Standard input/output (cin, cout)

4. Game Board Structure

The game board is represented using 2D arrays.

Each player has:

A personal board containing ship positions

A tracking board to record attacks on the opponent

Board symbols are used to represent:

Ships

Hits

Misses

Empty cells (water)

5. Game Modes
5.1 Player vs Player (PvP)

Two players play alternately on the same system.

Each player enters attack coordinates during their turn.

The game checks whether the attack results in a hit or a miss.

Turns continue until one player destroys all opponent ships.

5.2 Player vs Computer (PvC)

The player competes against a computer-controlled opponent.

The computer:

Generates random attack coordinates using rand()

Avoids repeating previously attacked positions

This mode demonstrates basic artificial intelligence logic.

6. Game Logic and Flow

Game boards are initialized at the start.

Ships are placed on the boards.

Players take turns attacking by entering row and column values.

The program validates input and checks board positions.

Hits and misses are recorded and displayed.

The game continuously checks win conditions.

The game ends when all ships of one player are destroyed.

7. Functions Used

Board initialization

Board display

Player input handling

Attack processing

Computer move generation

Win condition checking

Functions help in reducing code repetition and improving readability.

8. Input Validation & Error Handling

Ensures coordinates are within board limits.

Prevents attacking the same position multiple times.

Invalid inputs prompt the user to re-enter values.

9. Win Condition

A player wins when all opponent ships are destroyed.

A winning message is displayed on the console.

The game terminates after declaring the winner.

10. Limitations

No use of Object-Oriented Programming

Basic computer attack logic (random-based)

Console-based interface only

11. Future Improvements

Smarter computer AI logic

Dynamic ship placement

Difficulty levels

Use of OOP concepts

Graphical User Interface (GUI)

12. Learning Outcomes

Improved understanding of procedural programming in C++

Hands-on experience with arrays and game logic

Enhanced problem-solving and logical thinking skills

Experience building a complete playable game from scratch

13. Conclusion

This Battleship Console Game demonstrates how a fully functional game can be developed using only basic C++ concepts. It serves as a strong beginner-level project and highlights fundamental programming skills and logical implementation.
