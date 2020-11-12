/**
 * Fichero que implementa la clase estado
 * Fecha: 23/10/2020
 * Autor: Sergio Guerra Arencibia
 * Universidad de La Laguna (ULL)
 **/
#include "state.hpp"

State::State(std::string myid) {
  id = myid;
}

State::~State() {}

std::string State::getID (void) const {
  return id;
}

std::vector<Transition> State::getTransitions() {
  return transitions;
}

void State::pushTransition(Transition newTransition) {
  transitions.push_back(newTransition);
}

Transition State::getTransition(std::vector<std::string> stringSymbol) {
  // for (size_t i = 0; i < transitions.size(); i++) {
  //   if ((transitions[i].getInitialState() == id) && (transitions[i].getReadSymbol() == stringSymbol))
  //     return transitions[i];
  // }
  // std::string voidString(" ");
  // Transition voidTransition(voidString, voidString, voidString, voidString, voidString);
  // return voidTransition;
}

std::ostream& State::writeTransitions(std::ostream& os) {
  for (size_t i = 0; i < transitions.size(); i++)
    transitions[i].write(os);
  return os;
}

