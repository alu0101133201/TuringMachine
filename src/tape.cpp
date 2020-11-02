/** 
 * Fichero que implementa la clase cinta
 * ULL - Complejidad Computaciones
 * Sergio Guerra Arencibia
 * 02/11/2020
 */
#include "tape.hpp"

Tape::Tape() {}


Tape::~Tape() {}

void Tape::loadString(std::string newString) {
  symbols.clear();
  symbols.resize((newString.length() + 1));
  for (size_t i = 0; i < newString.length(); i++)
    symbols[i] = newString[i];
  head = symbols.begin();
}

void Tape::moveRight(void) {
    head = std::next(head);
}

void Tape::moveLeft(void) {
  head = std::prev(head);
}

int Tape::getSymbol(void) {
  return *head;
}

int Tape::getCurrentSize(void) {
  return symbols.size();
}

void Tape::writeSymbol(char symb) {
  *head = symb;
}

std::ostream& Tape::write(std::ostream &os) {
  os << ".";
  for (std::vector<char>::iterator it = symbols.begin(); it != symbols.end(); it++) {
    if (it == head)
      os << "[" << *it << "]";
    else
      os << *it;
  }
  os << ".\n";
  return os;
}