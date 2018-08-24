# 42_lem_in

## Introduction
Lem-in is a finding shortest path problem.

• The goal of this project is to find the quickest way to get n ants across the farm.

• Obviously, there are some basic constraints. To be the first to arrive, ants will need
to take the shortest path (and that isn’t necessarily the simplest). They will also
need to avoid traffic jams as well as walking all over their fellow ants.

• At the beginning of the game, all the ants are in the room ##start. The goal is
to bring them to the room ##end with as few turns as possible. Each room can
only contain one ant at a time. (except at ##start and ##end which can contain
as many ants as necessary.)

• We consider that all the ants are in the room ##start at the beginning of the game.

• At each turn you will only display the ants that moved.
• At each turn you can move each ant only once and through a tube (the room at
the receiving end must be empty).

• You must to display your results on the standard output in the following format:
```
number_of_ants
the_rooms
the_links
Lx-y Lz-w Lr-o ...
```

Example:

     [2]

   /  |  \

[0]   |   [1]

   \  |  /

     [3]

```
./lem-in < subjet2.map
3
2 5 0
##start
0 1 2
##end
1 9 2
3 5 4
0-2
0-3
2-1
3-1
2-3
L1-3 L2-2
L1-1 L2-1 L3-3
L3-1 
```
## Project Usage
```
make
```
+ **PUSH SWAP**
```
./lem-in 4 5 3 1
```
