/**
 * Fichero que define la clase estado
 * Fecha: 23/10/2020
 * Autor: Sergio Guerra Arencibia
 * Universidad de La Laguna (ULL)
 **/

#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "transition.hpp"

class State {
  private:
    std::string id; // identificador del estado
    std::vector<Transition> transitions;  // Cjto de transiciones del estado

  public:
    State(std::string);
    ~State();

  /* Getters*/
  std::string getID (void) const;
  std::vector<Transition> getTransitions();
  /* Metodo para añadirle una transición al autómata*/
  void pushTransition(Transition);
  /* Método que devuelve las transiciones posibles dado un símbolo de entrada y un símbolo de pila */
  Transition getTransition(std::vector<std::string> stringSymbol);
  /* Método de impresión del autómata */
  std::ostream& writeTransitions(std::ostream&) ;
};