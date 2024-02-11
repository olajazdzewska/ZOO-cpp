#  Zoo

## Description
 The program makes a simulation of a nature. It prints out grid which represents world. It cointains Animals, Plants and Human, which all inherit after Organism class. Each organism makes a move each turn. The order of moves is based on initiative attribute, excpet for Human as it is controlled with arrows. If organism moves to an occoupied gird cell then fight or breed will hapen. If there are two different species on one grid cell, then one must kill the other and the winner stays on the grid. If on the cell are the same species, then they will breed. The Organism that made a move goes back to previous cell and the child is put on the closest cell to its parent. Plants don't move or breed but the sow. Human also has a special ability that can be turn on every couple turns and sets its strength attribute to 10. Then the strength is decreased with every turn until it reaches previous strength. The state of grid can be saved (in txt file) and loaded.

## Stack
 C++ with SLT for vectors

## Manual:
### MacOS:
 - open project in terminal
 - compile it with command: `g++ -o out Animal.cpp World.cpp guarana.cpp Human.cpp main.cpp main2.cpp Organism.cpp antelope.cpp sheep.cpp Plant.cpp belladonna.cpp sowThistle.cpp SosnowskyHogweed.cpp fox.cpp turtle.cpp Wolf.cpp grass.cpp`
 - run it with command `./out`

### Windows
 Run the `main.cpp` file.
