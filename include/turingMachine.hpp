/** 
 * Fichero que define la clase máquina de turing
 * ULL - Complejidad Computaciones
 * Sergio Guerra Arencibia
 * 02/11/2020
 */
#pragma once

#include <set>

#include "tape.hpp"
#include "state.hpp"

void getWords(std::string initialString, std::vector<std::string> &words);
void vectorToSet(std::vector<std::string> &initialVector, std::set<std::string> &destinationSet);
void storeLine(std::string &line, std::vector<std::string> &words, std::set<std::string> &setToStore);

class TuringMachine {
  private:
      std::vector<State> allStates; // Cjto de estados
      std::set<std::string>  turingAlphabet;  // Alfabeto de la máquina
      std::set<std::string>  tapeAlphabet;  // Alfabeto de la cinta
      std::string initialState; // Estado inicial
      char whiteSymbol;
      std::vector<std::string> finalStates; // Estados finales

  public:
    TuringMachine(char* turingFile);
    ~TuringMachine();

    std::ostream& write (std::ostream& os);
};