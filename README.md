# Mastermind
Mastermind is a code breaking game similar to Bulls and Cows. 
This version of mastermind is run in the text editor using C++14. 
I only built this to practice my C++ and it turned out half decent.
Maybe I'll add the color support if i decide to not be lazy.

## How to Run
### Windows
1. Install g++
2. Navigate to the directory the files are in
3. Run `g++ -c main.cpp`
4. Confirm that the "main.o" file has been made
5. Run `g++ -o game main.o mastermind.cpp`
6. You can now play the game with `./game`
### Mac Os
1. Follow [this](https://clang.llvm.org/get_started.html)
### Linux
1. Install g++
2. Navigate to the directory the files are in
3. Run `g++ -c main.cpp`
4. Confirm that the "main.o" file has been made
5. Run `g++ -o game main.o mastermind.cpp`
6. You can now play the game with `./game`

## How to Play
Type in a guess by choosing from
* **R**ed
* **B**lue
* **G**reen
* **Y**ellow
* **M**agenta
* **C**yan

in a manner similar to `RGBC`. Yes, you can use lowercase or spaces but
for gods sake putting in `R gb C` runs fine but looks like ass god damn.

An output box will show up. It will show your guess. To the right it 
will either be empty or show a combination of `R` and `I`. An `R` 
signifies you have a letter in the correct place, but it doesn't say 
which one. An `I` means one of the letters is right but not in the 
correct spot. `#` is simply filler for if there were no matches.

Have fun.