/** 
 * Fichero que define la clase cinta
 * ULL - Complejidad Computaciones
 * Sergio Guerra Arencibia
 * 02/11/2020
 */
#pragma once

#include <vector>
#include <iostream>
#include <string>

class Tape {
  private: 
    std::vector<char> symbols;
    std::vector<char>::iterator head;

  public:
    Tape();
    ~Tape();
    void loadString(std::string newString);

    void moveRight(void);
    void moveLeft(void);

    int getSymbol(void);
    int getCurrentSize(void);
    void writeSymbol(char symb);

    std::ostream& write(std::ostream &os);
};