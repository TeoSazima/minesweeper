
# Minesweeper

## EN: Console game of Minesweeper in C++

### description

Minesweeper is a console game written in C++, where the player tries to uncover all the safe cells without stepping on a mine. The game works by randomly placing mines on a 10x10 grid, and the player must input coordinates to reveal cells.

### rules of the game

- The player sees a 10x10 grid, where each cell can either be a mine (`X`) or a number indicating how many mines are adjacent to it.
- In each round, the player inputs the X and Y coordinates to uncover a cell.
- If the player uncovers a cell with a mine, the game ends.
- If the player uncovers a cell with a number, it tells them how many mines are in the adjacent cells.
- The objective is to uncover all safe cells without hitting a mine.

### installation and startup

1. Clone the repository or download the `minesweeper.cpp` file.
2. Open the terminal and compile the program using:
   ```sh
   g++ -o minesweeper minesweeper.cpp
   ```
3. Start the program:
   ```sh
   ./minesweeper
   ```
4. Enter the X and Y coordinates to reveal a cell and watch the game progress.

### Example of the game

```
    0 1 2 3 4 5 6 7 8 9 Y
  ┌--------------------
0 | # # # # # # # # # # 
1 | # # # # # # # # # # 
2 | # # # # # # # # # # 
3 | # # # # # # # # # # 
4 | # # # # # # # # # # 
5 | # # # # # # # # # # 
6 | # # # # # # # # # # 
7 | # # # # # # # # # # 
8 | # # # # # # # # # # 
9 | # # # # # # # # # # 
X

Enter X: 4
Enter Y: 5

The game continues...

```

- The player enters `X: 4`, `Y: 5` → the game continues.
- The player enters `X: 6`, `Y: 3` → the game ends because they hit a mine.

### Structure of code

- `vypispole()`: Function to print the game grid and reveal cells.
- `main()`: Main game loop, random mine generation, player inputs, and win/loss checks.

### Author

This program was created as a demonstration project for practicing handling user input and output in C++.

If you have any questions or comments, feel free to contact me.


# Minesweeper

## CS: Konzolová hra Minesweeper v C++

### popis

Minesweeper je konzolová hra napsaná v jazyce C++, kde se hráč snaží odkryt všechny bezpečné buňky, aniž by šlápl na minu. Hra funguje na principu náhodně umístěných min na herní desce 10x10, přičemž hráč musí zadávat souřadnice, aby odkryl buňky.

### pravidla hry

- Hráč vidí herní pole o velikosti 10x10, kde každá buňka může být buď mina (`X`), nebo číslo, které označuje počet min v okolí dané buňky.
- V každém kole hráč zadá souřadnice X a Y pro odkrývání buňky.
- Pokud hráč odkryje buňku s minou, hra končí.
- Pokud hráč odkryje buňku s číslem, zjistí, kolik min je v okolí této buňky.
- Cílem hry je odkryt všechny bezpečné buňky, aniž by hráč narazil na minu.

### instalace a spuštění

1. Naklonujte repozitář nebo stáhněte soubor `minesweeper.cpp`.
2. Otevřete terminál a zkompilujte program pomocí:
   ```sh
   g++ -o minesweeper minesweeper.cpp
   ```
3. Spusťte program:
   ```sh
   ./minesweeper
   ```
4. Zadejte souřadnice X a Y pro odkrytí buňky a sledujte, jak hra pokračuje.

### příklad hry

```
    0 1 2 3 4 5 6 7 8 9 Y
  ┌--------------------┐
0 | # # # # # # # # # # 
1 | # # # # # # # # # # 
2 | # # # # # # # # # # 
3 | # # # # # # # # # # 
4 | # # # # # # # # # # 
5 | # # # # # # # # # # 
6 | # # # # # # # # # # 
7 | # # # # # # # # # # 
8 | # # # # # # # # # # 
9 | # # # # # # # # # # 
  └--------------------┘
Y

Zadejte X: 4
Zadejte Y: 5

Hra pokračuje...

```

- Hráč zadá `X: 4`, `Y: 5` → hra pokračuje.
- Hráč zadá `X: 6`, `Y: 3` → hra končí, protože šlápl na minu.

### struktura kódu

- `vypispole()`: Funkce pro vykreslení herního pole a odkrývání buněk.
- `main()`: Hlavní herní smyčka, generování náhodných min, zadávání vstupů hráče a kontrola výhry/prohry.

### autor

Tento program byl vytvořen jako demonstrační projekt pro procvičení práce s konzolovým vstupem a výstupem v jazyce C++.

Pokud máte jakékoli dotazy nebo připomínky, neváhejte mě kontaktovat.
```

Tento popis je v češtině, odpovídá požadovanému formátu a obsahuje všechny důležité informace pro uživatele.
