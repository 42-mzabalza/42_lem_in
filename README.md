# lem-in

## Introduction
Lem-in is a path finder tool.

• The goal of this project is to find the quickest way to get n ants across the farm.

• Obviously, there are some basic constraints. To be the first to arrive, ants will need
to take the shortest path (and that isn’t necessarily the simplest). They will also
need to avoid traffic jams as well as walking all over their fellow ants.

• At the beginning of the game, all the ants are in the room ##start. The goal is
to bring them to the room ##end with as few turns as possible. Each room can
only contain one ant at a time. (except at ##start and ##end which can contain
as many ants as necessary.)

• We consider that all the ants are in the room ##start at the beginning of the game.

• At each turn the ants that moved will be displayed.

• The results will be displayed on the standard output in the following format:
```
number_of_ants
the_rooms
the_links
Lx-y Lz-w Lr-o ...
```

EXAMPLE: 
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
The parsed input is displayed first, followed by the moves of the ant in each turn:
- ##Turn 1 (L1-3 L2-2) -> Ant1 moves from room0(start) to room3, Ant2 moves from room0(start) to room2.
- Turn 2 (L1-1 L2-1 L3-3) -> Ant1 moves from room3 to room1(end), Ant2 moves from room2 to room1(end), Ant3 moves from room0(start) to room3.
- Turn 3 (L1-1 L2-1 L3-3) -> Ant3 moves from room3 to room1(end).

## Instalation
```
git clone https://github.com/mzabalza/42_lem_in.git; cd 42_lem_in; make
```

## Project Usage
```
./lem-in < maps/big
```

# Technical Implementation
this program was created without much help from standard libraries, these are all the standard function used:
◦ malloc
◦ free
◦ read
◦ write
◦ exit
