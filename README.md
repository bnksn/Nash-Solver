# 2x2 Nash Equilibrium Solver
A 2x2 Nash Equilibrium solver that solves for both mixed and pure NE.

### How to run
Download the "nash_solver.cpp" file and compile it using your favourite C++ compiler.\
Navigate to the binary file in the terminal and run it.\
For example, on Windows, type "./nash_solver.exe".

### Mathematical background

- In our game, p1 (Player 1) is playing UP or DOWN and p2 (Player 2) is playing LEFT or RIGHT.
- The payoff $x,y$ is such that p1 recieves $x$ utility and p2 receives $y$ utility.
- The strategy $p\text{UP} + (1-p)\text{DOWN}$ is a strategy that involves playing UP with probabilty $p$ and DOWN with probability $1-p$.
 
Consider the following 2x2 game:

|       | LEFT    | RIGHT   |
| :---: | :---:   | :---:   |
| UP    | $x1,y1$ | $x2,y2$ |
| DOWN  | $x3,y3$ | $x4,y4$ |

To find Nash Equilibria we will assume p1 plays $p\text{UP} + (1-p)\text{DOWN}$ and p2 plays $q\text{LEFT} + (1-q)\text{RIGHT}$.

Indifference occurs for p1 if the payoff from UP is equal the payoff from DOWN, that is, if $(x1)q + (x2)(1-q) = (x3)q + (x4)(1-q).$
This holds if and only if $q(x1 - x2 - x3 + x4) = (x4 - x2)$, if and only if $q = (x4 - x2) / (x1 - x2 - x3 + x4)$ (on the assumption that we are not dividing by 0).

Indifference occurs for p2 if the payoff from LEFT is equal the payoff from RIGHT, that is, if $(y1)p + (y3)(1-p) = (y2)p + (y4)(1-p).$
This holds if and only if $p(y1 - y3 - y2 + y4) = (y4 - y3)$, if and only if $p = (y4 - y3)  / (y1 - y3 - y2 + y4)$ (on the assumption that we are not dividing by 0).

In our game, p1 is indifferent between UP and DOWN for any $q$ if both $x1 = x3$ and $x2 = x4$.
Also, p2 is indifferent between LEFT and RIGHT for any $p$ if both $y1 = y2$ and $y3 = y4$.
Therefore there are infinitely many NE if both $x1 = x3$ and $x2 = x4$, or both $y1 = y2$ and $y3 = y4$. This follows from the fact that there exists at least one NE for our game (Nash Existance Theorem), and from this one NE we can generate infinitely many more NE by mixing over the interval $[0,1]$.

If the $p$ and $q$ that we generated by solving for indifference satisfy $p, q \in [0,1]$, then $(p\text{UP} + (1-p)\text{DOWN}, q\text{LEFT} + (1-q)\text{RIGHT})$ is a Nash Equilibrium. This is because the players would be mutually indifferent.

We know that p1 plays UP if $q(x1 - x2 - x3 + x4) > (x4 - x2)$ and p1 plays DOWN if $q(x1 - x2 - x3 + x4) < (x4 - x2)$. Also, p2 plays LEFT if $p(y1 - y3 - y2 + y4) > (y4 - y3)$ and p2 plays RIGHT if $p(y1 - y3 - y2 + y4) < (y4 - y3)$. Therefore, the following holds:

$(1\text{UP} + 0\text{DOWN}, 1\text{LEFT} + 0\text{RIGHT})$ is a NE if $x1 - x2 - x3 + x4 > x4 - x2$ and $y1 - y3 - y2 + y4 > y4 - y3$.

$(1\text{UP} + 0\text{DOWN}, 0\text{LEFT} + 1\text{RIGHT})$ is a NE if $0 > x4 - x2$ and $y1 - y3 - y2 + y4 < y4 - y3$.

$(0\text{UP} + 1\text{DOWN}, 1\text{LEFT} + 0\text{RIGHT})$ is a NE if $x1 - x2 - x3 + x4 < x4 - x2$ and $0 > y4 - y3$.

$(0\text{UP} + 1\text{DOWN}, 0\text{LEFT} + 1\text{RIGHT})$ is a NE if $0 < x4 - x2$ and $0 < y4 - y3$.

### Project Limitations

In the case of there being infinitely many NE, the general form of these NE is not displayed.\
The solver only solves NxN games for N = 2.
