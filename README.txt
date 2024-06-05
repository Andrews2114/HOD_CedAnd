Snake problem
Andrés Alarcón Navarro - A01198777
Cedrick Patricio Treviño Ortiz - A01198868

This is a basic implementation of the famous game Snakes and Ladders, where the goal is to roll a dice to walk through the board until you reach the end. 
Of course the game uses ladders and snakes to make things interesting... being this objects rewards or penalties if you land in any tile with them on it.

To play, a .txt file is needed to input the turns of 2 players, C to continue and E to end, the game end until someone wins or an E is inputed.
The game allows you to follow the two players in the .txt Output file, which has the following structure, follow the example:
1 1 1 5 N 6 -> Output line
Turn 1:
Player 1 starts at tile 1
Rolls dice and gets 5
Moves to tile N
Ends at tile 6
-------------------------
Turn 1: Player 1 Tile 1 --dice roll(5)--> Tile N --end--> Tile 6

IMPORTANT:  to run in machines, changing PATHS in includes and reading .txt files is necessary!
Inheritance is used for the layout of a game, with a constructor that greets the user and a Display that thanks for the game.
Polymorphism is the core of this game, due to its flexible way of implementing customizable aspects of the game with the same funcion.

Class "Turns" was abstracted into a struct "Printing" due to simplicity and run-time effectiveness of the overloading of operator "<<" in the ofstream lib, 
it writes the outputs in the corresponding game format.
