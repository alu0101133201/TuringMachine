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
    std::vector<std::string> readSymbol;  // Símbolo de la cinta que se lee
    std::string nextState;  // Estado destino de la transición
    std::vector<std::string> writeSymbol; // Símbolo a escribir en la cinta
    std::vector<std::string> move; // movimiento a realizar

  public:
    Transition(std::string iniSt, std::vector<std::string> readSymb, std::string nextState,
        std::vector<std::string> writeSymb, std::vector<std::string> movement);
    ~Transition();

    /* Getters */
    std::string getInitialState(void) const;
    std::vector<std::string> getReadSymbol(void) const;
    std::vector<std::string> getWriteSymbol(void) const;
    std::string getNextState(void) const;
    std::vector<std::string> getMove(void) const;

    // Método de impresión
    std::ostream& write(std::ostream &os);
};