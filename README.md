# 2x2 Nash Equilibrium Solver
A 2x2 Nash Equilibrium solver that solves for both mixed and pure NE.

### How to use
Download the "nash_solver.cpp" file and compile it using your favourite C++ compiler.
Navigate to the binary file in the terminal, and run it.
For example, in Windows, type "./nash_solver.exe".

### Mathematical background

- Please read "<=>" as "if and only if".
- "p1" denotes Player 1 and "p2" denotes Player 2.
- In our game, p1 is playing UP or DOWN and p2 is playing LEFT or RIGHT.
- The payoff "x,y" is such that p1 recieves x utility and p2 receives y utility.
- The strategy "pUP + (1-p)DOWN" is a strategy that involves playing UP with probabilty p and DOWN with probability 1-p.
 
Consider the following 2x2 game:

        LEFT    RIGHT
UP      x1,y1   x2,y2
DOWN    x3,y3   x4,y4 

To find Nash Equilibria we will assume p1 plays pUP + (1-p)DOWN and p2 plays qLEFT + (1-q)RIGHT.

Indifference occurs for p1 if the payoff from UP is equal the payoff from DOWN, that is, if (x1)q + (x2)(1-q) = (x3)q + (x4)(1-q).
(x1)q + (x2)(1-q) = (x3)q + (x4)(1-q) <=> (x1)q + (x2) - (x2)q = (x3)q + (x4) - (x4)q 
                                      <=> (x1)q - (x2)q - (x3)q + (x4)q = (x4) - (x2)
                                      <=> q(x1 - x2 - x3 + x4) = (x4 - x2) 
                                      <=> q = (x4 - x2) / (x1 - x2 - x3 + x4)
Hence p1 plays UP if q(x1 - x2 - x3 + x4) > (x4 - x2) and p1 plays DOWN if q(x1 - x2 - x3 + x4) < (x4 - x2).

Indifference occurs for p2 if the payoff from LEFT is equal the payoff from RIGHT, that is, if (y1)p + (y3)(1-p) = (y2)p + (y4)(1-p).
(y1)p + (y3)(1-p) = (y2)p + (y4)(1-p) <=> (y1)p + (y3) - (y3)p = (y2)p + (y4) - (y4)p 
                                      <=> (y1)p - (y3)p - (y2)p + (y4)p = (y4) - (y3)
                                      <=> p(y1 - y3 - y2 + y4) = (y4 - y3) 
                                      <=> p = (y4 - y3)  / (y1 - y3 - y2 + y4)
Hence p2 plays LEFT if p(y1 - y3 - y2 + y4) > (y4 - y3) and p2 plays RIGHT if p(y1 - y3 - y2 + y4) < (y4 - y3).

In our game p1 is indifferent between UP and DOWN for any q if both x1 = x3 and y2 = y4.
In our game p2 is indifferent between LEFT and RIGHT for any p if both y1 = y2 and y3 = y4.
Hence there are infinitely many NE if both x1 = x3 and y2 = y4, or both y1 = y2 and y3 = y4.
This follows from the fact that there exists at least one NE for our game, since from this one NE we can generate infinitely many more NE via mixing.
For example, assume we have (0.1UP + 0.9DOWN, 0.2LEFT + 0.8RIGHT) as a NE, and that x1 = x3 and y2 = y4. Then (pUP + pDOWN, 0.2LEFT + 0.8RIGHT)
is a NE for any p in the interval [0,1], hence we have infinitely many NE.

If both p and q belong to the interval [0,1] then (pUP + (1-p)DOWN, qLEFT + (1-q)RIGHT) is a Nash (mixed or pure).

(1UP + 0DOWN, 1LEFT + 0RIGHT) is a NE if both x1 - x2 - x3 + x4 > x4 - x2 and y1 - y3 - y2 + y4 > y4 - y3.
(1UP + 0DOWN, 0LEFT + 1RIGHT) is a NE if both 0 > x4 - x2 and y1 - y3 - y2 + y4 < y4 - y3.
(0UP + 1DOWN, 1LEFT + 0RIGHT) is a NE if both x1 - x2 - x3 + x4 < x4 - x2 and 0 > y4 - y3.
(0UP + 1DOWN, 0LEFT + 1RIGHT) is a NE if both 0 < x4 - x2 and 0 < y4 - y3.


