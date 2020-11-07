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
#include "transition.hpp"
#include <fstream>
#include <sstream>

void getWords(std::string initialString, std::vector<std::string> &words);
void vectorToSet(std::vector<std::string> &initialVector, std::set<std::string> &destinationSet);
void storeLine(std::string &line, std::vector<std::string> &words, std::set<std::string> &setToStore);

class TuringMachine {
  private:
      std::vector<State> allStates; // Cjto de estados
      std::set<std::string>  turingAlphabet;  // Alfabeto de la máquina
      std::set<std::string>  tapeAlphabet;  // Alfabeto de la cinta
      State* initialState; // Estado inicial
      std::string whiteSymbol; // símbolo blanco
      std::vector<std::string> finalStates; // Estados finales
      Tape turingTape;


      State* currentState; 

      bool checkTuringMachine(void);
      bool checkTransitions(void);
      bool existState(std::string state);
      bool isFinal(std::string state);

  public:
    TuringMachine(char* turingFile);
    ~TuringMachine();

    bool test(std::vector<std::string> stringsToTest);
    
    std::ostream& write (std::ostream& os);
    std::ostream& writeCurrentMachine (std::ostream& os);
};