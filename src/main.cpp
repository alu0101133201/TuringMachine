#include <iostream>

#include "tape.hpp"

int main() {
    Tape prueba;
    prueba.loadString("aabb");
    prueba.write(std::cout);    
    prueba.moveRight();
    prueba.moveRight();
    prueba.write(std::cout);  
    prueba.moveLeft();  
    prueba.write(std::cout);  
    prueba.writeSymbol('w');
    prueba.write(std::cout);  
    prueba.moveRight();
    prueba.write(std::cout);  
}