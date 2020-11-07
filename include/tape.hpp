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
    std::vector<std::string> symbols;
    std::vector<std::string>::iterator head;

  public:
    Tape();
    ~Tape();
    void loadStrings(std::vector<std::string> stringsToLoad, std::string white);

    void moveRight(void);
    void moveLeft(void);

    std::string getSymbol(void);
    int getCurrentSize(void);
    void writeSymbol(std::string symb);

    std::ostream& write(std::ostream &os);
};