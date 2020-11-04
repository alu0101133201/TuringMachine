/**
 * Fichero que define la clase transición. Esta clase representará
 * una transición de nuestra máquina de turing
 * Fecha: 18/10/2020
 * Autor: Sergio Guerra Arencibia
 * Universidad de La Laguna (ULL)
 **/

#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <string.h>
#include <sstream>
#include <set>


class Transition {
  private:
    std::string initialState; // Estado inicial
    std::string readSymbol;  // Símbolo de la cinta que se lee
    std::string nextState;  // Estado destino de la transición
    std::string writeSymbol; // Símbolo a escribir en la cinta
    std::string move; // movimiento a realizar

  public:
    Transition(std::string iniSt, std::string readSymb, std::string nextState,
        std::string writeSymb, std::string movement);
    ~Transition();

    /* Getters */
    int getID(void) const;
    std::string getInitialState(void) const;
    std::string getReadSymbol(void) const;
    std::string getWriteSymbol(void) const;
    std::string getNextState(void) const;
    std::string getMove(void) const;

    // Método de impresión
    std::ostream& write(std::ostream &os);
};