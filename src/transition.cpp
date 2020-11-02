/**
 * Fichero que implementa la clase transición. Esta clase representará
 * una transición de nuestra máquina de turing
 * Fecha: 18/10/2020
 * Autor: Sergio Guerra Arencibia
 * Universidad de La Laguna (ULL)
 **/
 #include "transition.hpp"

Transition::Transition(std::string iniSt, std::string readSymb, std::string nextState,
    std::string writeSymb, std::string movement, int localId):
  id(localId),
  initialState(iniSt),
  readSymbol(readSymb),
  nextState(nextState),
  writeSymbol(writeSymb), 
  move(movement) {}


Transition::~Transition() {}

int Transition::getID(void) const {
  return id;
}
std::string Transition::getInitialState(void) const {
  return initialState;
}
std::string Transition::getReadSymbol(void) const {
  return readSymbol;
}
std::string Transition::getWriteSymbol(void) const {
  return writeSymbol;
}
std::string Transition::getNextState(void) const {
  return nextState;
}
std::string Transition::getMove(void) const {
  return move;
}


std::ostream& Transition::write(std::ostream &os) {
  std::cout << "MÉTODO PENDIENTE DE IMPLEMENTAR\n";
  return os;
}