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
  head = 0;
}


void Tape::moveRight(void) {
  if (head == (symbols.size() - 1)) {
    symbols.push_back(".");
  }
  ++head;
}

void Tape::moveLeft(void) {
  if (head == 0) {
    symbols.insert(symbols.begin(), ".");
  } else {
    --head;
  }
}

std::string Tape::getSymbol(void) {
  return symbols[head];
}

int Tape::getCurrentSize(void) {
  return symbols.size();
}

void Tape::writeSymbol(std::string symb) {
  symbols[head] = symb;
}

std::ostream& Tape::write(std::ostream &os) {
  os << ".";
  for (size_t i = 0; i < symbols.size(); i++) {
    if (i == head)
      os << "|\033[4m" << symbols[i] << "\033[0m";
    else
      os << "|" << symbols[i];
  }
  os << "  ";
  return os;
}