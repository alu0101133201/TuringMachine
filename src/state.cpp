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

std::vector<Transition> State::getPossibleTransitions(std::string stringSymbol) {
  std::cout << "MÉTODO PENDIENTE DE IMPLEMENTAR\n";
  std::vector<Transition> dummy;
  return dummy;
}

std::ostream& State::writeTransitions(std::ostream& os) {
  for (size_t i = 0; i < transitions.size(); i++)
    transitions[i].write(os);
  return os;
}

