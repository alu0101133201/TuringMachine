/**
 * Fichero que implementa la clase transición. Esta clase representará
 * una transición de nuestra máquina de turing
 * Fecha: 18/10/2020
 * Autor: Sergio Guerra Arencibia
 * Universidad de La Laguna (ULL)
 **/
 #include "transition.hpp"

Transition::Transition(std::string iniSt, std::vector<std::string> readSymb, std::string nextState,
        std::vector<std::string> writeSymb, std::vector<std::string> movement):
  initialState(iniSt),
  readSymbol(readSymb),
  nextState(nextState),
  writeSymbol(writeSymb), 
  move(movement) {}


Transition::~Transition() {}

std::string Transition::getInitialState(void) const {
  return initialState;
}
std::vector<std::string> Transition::getReadSymbol(void) const {
  return readSymbol;
}
std::vector<std::string> Transition::getWriteSymbol(void) const {
  return writeSymbol;
}
std::string Transition::getNextState(void) const {
  return nextState;
}
std::vector<std::string> Transition::getMove(void) const {
  return move;
}

std::ostream& Transition::write(std::ostream &os) {  
  os << initialState << " ";
  for (size_t i = 0; i < readSymbol.size(); i++)
    os << readSymbol[i] << " ";
  os << nextState << " ";
  for (size_t i = 0; i < writeSymbol.size(); i++)
    os << writeSymbol[i] << " ";
  for (size_t i = 0; i < move.size(); i++)
    os << move[i] << " ";
  os << "\n";
  return os;
}