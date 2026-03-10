# **Building Chess Board:**

- Building the Chess Board from the scratch step by step

## Project Goal:

* ###### Functional Requirements:

  1. Represent a chess board (8x8)
  2. Represent all chess pieces
  3. Initialize starting position
  4. Print board to console
  5. Accept moves (e2 → e4)
  6. Validate legal moves
  7. Detect check
  8. Detect checkmate
  9. Maintain game state
* ###### Non-functional requirements:

  * Clean C++ architecture
  * Modular design
  * Unit testable
  * Built with **CMake**
  * Extensible (later add AI)

## System Architecture (High Level Design):

- Core modules:

  ```
  Chess Engine
  │
  ├── Board
  ├── Piece
  ├── Move
  ├── Game Controller
  ├── Move Validator
  └── Utilities
  ```
- Responsibility of each:

  - Board:
    - Represents the state of the game.
    - It contains 8x8 squares, pieces, piece positions.
  - Piece:
    - Represents type of piece, color, symbol
    - Example: Pawn, Knight, Bishop, Rook, Queen, King.
  - Move:
    - Represents one move.
    - Example: e2 -> e4
    - It contains source square, destination square and optional promotion.
  - Game Controller:
    - It controls game flow.
    - It responsibilities are current player, read move, apply move, check game state and switch player.
  - Move Validator:
    - Responsible for rules of chess
    - Examples: Pawn movement rules, knight movement rules, castling, check detection,and etc.
    - This separation is important. Otherwise everything becomes messy.

## Data Model Design:

* Now we define core data structure.
* Square:

  * row, column
  * example: (6,4)) = e2
* Piece:

  ```cpp
  enum class PieceType
  {
      Pawn,
      Knight,
      Bishop,
      Rook,
      Queen,
      King,
      None
  };

  enum class Color
  {
      White,
      Black,
      None
  };
  ```
* Move:

  ```cpp
  struct Move
  {
      int fromRow;
      int fromCol;
      int toRow;
      int toCol;
  };
  ```
* Board Representation:

  * Simplest representation: 8x8 grid
  * Implementation : std::array<std::array<Piece,8 >, 8>
  * Why?
    * Fixed size.
    * Fast.
    * Safe.
    * no heap allocations.

## Development Phases

* Phase 1 -- Board System

  * Goal : Represent board, initialize board and print board.
  * Concepts learned: enum class, struct, std::array and class design
  * Deliverable: board printed correctly
  * Example output:

  ```notepad
  8 r n b q k b n r
  7 p p p p p p p p
  6 . . . . . . . .
  5 . . . . . . . .
  4 . . . . . . . .
  3 . . . . . . . .
  2 P P P P P P P P
  1 R N B Q K B N R
    a b c d e f g h
  ```
* Phase 2 -- Move Representation

  * Goal: parse move input.
  * Example input: e2 e4
  * Convert to: (6,4) -> (4,4)
  * Concepts learned: string parsing, mapping and coordinate systems
* Phase 3 -- Move Execution

  * Goal: move piece, update board and switch player.
  * Concepts learned: state management and game logic
* Phase 4 -- Move Validation

  * Goal: prevent illegal moves
  * Examples: pawn can't move backward, bishop moves diagonally and knight moves in L and etc.
  * Concepts learned: algorithm design and rule engines
* Phase 5 -- Check Detection

  * Goal: detect if king is attacked
  * Concepts: board scanning and threat detection
* Phase 6 -- Checkmate

  * Goal: detect game end.
  * Concepts: search space and move simulation.
* Phase 7 -- Chess AI

  * Implement: Minimax, Alpha-Beta pruning and Evaluation function.
  * Concepts learned: game theory, recursive algorithms and performance optimization.

## Project Folder Structure

```notepad
    chess-engine
    │
    ├── include
    │   ├── board.hpp
    │   ├── piece.hpp
    │   ├── move.hpp
    │   ├── game.hpp
    │
    ├── src
    │   ├── board.cpp
    │   ├── move.cpp
    │   ├── game.cpp
    │
    ├── tests
    │   ├── board_test.cpp
    │
    ├── main.cpp
    └── CMakeLists.txt
```

## Testing Strategy

* Testing is where most beginners fail.
* Example tests:
  1. board initialization correct.
  2. pawn move correct.
  3. knight move correct.
  4. illegal move rejected.
* Use: Google Test

## Engineering Practices Should Follow

Rules:

1. Write header first.
2. Then implement .cpp file.
3. Compiler frequently.
4. Write tests for each module.
5. Commit often.
