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
    std::vector<int> head;
    std::vector<std::vector<std::string>> symbols;

  public:
    Tape();
    ~Tape();
    void loadStrings(std::vector<std::string> stringsToLoad, std::string white);
    void setNumberOfTapes(int tapes);

    void moveRight(int tape);
    void moveLeft(int tape);

    std::string getSymbol(int tape);
    std::vector<std::string> getAllPositionSymbols(void);
    int getCurrentSize(int tape);
    void writeSymbol(int tape, std::string symb);

    std::ostream& write(std::ostream &os);
};