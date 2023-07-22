#include <iostream>

int main(){
    std::cout << "\n       LEFT    RIGHT\n";
    std::cout << "UP     x1,y1   x2,y2\n";
    std::cout << "DOWN   x3,y3   x4,y4\n\n";

    float x1, x2, x3, x4, y1, y2, y3, y4;
    std::cout << "Input values in the form \"x1 y1 x2 y2 x3 y3 x4 y4\":\n";
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    std::cout << "\n";

    //Check for infinite NE
    if ( (x1 == x3 && y2 == y4) || (y1 == y2) && (y3 == y4) ){
        std::cout << "Infinitely many Nash Equilibria\n\n";
        return 0;
    }
    
    float q = (x4 - x2) / (x1 - x2 - x3 + x4);
    float p = (y4 - y3)  / (y1 - y3 - y2 + y4);

    //Check for finite NE
    if (0 <= q && q <= 1 && 0 <= p && p <= 1){
        std::cout << "(" << p << "UP + "<< 1-p << "DOWN, "<< q << "LEFT + "<< 1-q << "RIGHT)\n";
    }
    if (x1 - x2 - x3 + x4 > x4 - x2 && y1 - y3 - y2 + y4 > y4 - y3){
        std::cout << "(1UP + 0DOWN, 1LEFT + 0RIGHT)\n";
    }
    if (0 > x4 - x2 && y1 - y3 - y2 + y4 < y4 - y3){
        std::cout << "(1UP + 0DOWN, 0LEFT + 1RIGHT)\n";
    }
    if (x1 - x2 - x3 + x4 < x4 - x2 && 0 > y4 - y3){
        std::cout << "(0UP + 1DOWN, 1LEFT + 0RIGHT)\n";
    }
    if (0 < x4 - x2 && 0 < y4 - y3){
        std::cout << "(0UP + 1DOWN, 0LEFT + 1RIGHT)\n";
    }

    std::cout << "\n";
    return 0;
}