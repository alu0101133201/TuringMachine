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
      // Atributos
      std::vector<State> allStates; // Cjto de estados
      std::set<std::string>  turingAlphabet;  // Alfabeto de la máquina
      std::set<std::string>  tapeAlphabet;  // Alfabeto de la cinta
      State* initialState; // Estado inicial
      std::string whiteSymbol; // símbolo blanco
      std::vector<std::string> finalStates; // Estados finales
      Tape turingTape;


      State* currentState; 
      int numberOfTapes;
      // Métodos
      // Métodos para comprobar si la máquina está bien definida
      bool checkTuringMachine(void);
      bool checkTransitions(void);
      bool checkTapeSymbols(std::vector<std::string> elementsToCheck);
      bool checkMoves(std::vector<std::string> elementsToCheck);

      // Comprobar si un estado existe o es final
      bool existState(std::string state);
      bool isFinal(std::string state);

      // Métodos auxiliares para la carga de la máquina
      void readTransitions(std::ifstream& file);
      void readTapeElements(std::vector<std::string> &source, int &iterator, std::vector<std::string> &destination);
  
  public:
    TuringMachine(char* turingFile);
    ~TuringMachine();

    // Método de ejecución de la máquina
    bool test(std::vector<std::string> stringsToTest);
    
    // Métodos de impresión
    std::ostream& write (std::ostream& os);
    std::ostream& writeCurrentMachine (std::ostream& os);
};