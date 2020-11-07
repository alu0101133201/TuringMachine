/** 
 * Fichero que implementa la clase cinta
 * ULL - Complejidad Computaciones
 * Sergio Guerra Arencibia
 * 02/11/2020
 */
#include "tape.hpp"

Tape::Tape() {}


Tape::~Tape() {}

void Tape::loadStrings(std::vector<std::string> stringsToLoad, std::string white) {
  symbols.clear();

  for (size_t i = 0; i < stringsToLoad.size(); i++) {
    for (size_t j = 0; j < stringsToLoad[i].length(); j++) {
      std::string dummy(1, stringsToLoad[i][j]);
      symbols.push_back(dummy);
    }
    symbols.push_back(white);
  }
  head = symbols.begin();
}

void Tape::moveRight(void) {
    head = std::next(head);
}

void Tape::moveLeft(void) {
  head = std::prev(head);
}

std::string Tape::getSymbol(void) {
  return *head;
}

int Tape::getCurrentSize(void) {
  return symbols.size();
}

void Tape::writeSymbol(std::string symb) {
  *head = symb;
}

std::ostream& Tape::write(std::ostream &os) {
  os << ".";
  for (std::vector<std::string>::iterator it = symbols.begin(); it != symbols.end(); it++) {
    if (it == head)
      os << "[" << *it << "]";
    else
      os << *it;
  }
  os << ".\n";
  return os;
}