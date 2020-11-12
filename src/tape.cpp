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
  symbols[0].clear();
  for (size_t i = 1; i < symbols.size(); i++) {
    symbols[i].clear();
    symbols[i].push_back(".");
  }
  for (size_t i = 0; i < stringsToLoad.size(); i++) {
    for (size_t j = 0; j < stringsToLoad[i].length(); j++) {
      std::string dummy(1, stringsToLoad[i][j]);
      symbols[0].push_back(dummy);
    }
    symbols[0].push_back(white);
  }
  for (size_t i = 0; i < symbols.size(); i++) {
    head[i] = 0;
  }
}

void Tape::setNumberOfTapes(int tapes) {
  symbols.resize(tapes);
  head.resize(tapes);
  for (size_t i = 0; i < symbols.size(); i++) {
    head[i] = 0;
  }
}


void Tape::moveRight(int tape) {
  if (head[tape] == (int)(symbols[tape].size() - 1)) {
    symbols[tape].push_back(".");
  }
  head[tape]++;
}

void Tape::moveLeft(int tape) {
  if (head[tape] == 0) {
    symbols[tape].insert(symbols[tape].begin(), ".");
  } else {
    head[tape]--;
  }
}

std::string Tape::getSymbol(int tape) {
  return symbols[tape][head[tape]];
}

std::vector<std::string> Tape::getAllPositionSymbols(void) {
  std::vector<std::string> result;
  for (size_t i = 0; i < symbols.size(); i++) 
    result.push_back(symbols[i][head[i]]);
  return result;
}

int Tape::getCurrentSize(int tape) {
  return symbols[tape].size();
}

void Tape::writeSymbol(int tape, std::string symb) {
  symbols[tape][head[tape]] = symb;
}

void Tape::writeNSymbols(std::vector<std::string> toWrite) {
  for (size_t i = 0; i < toWrite.size(); i++) {
    writeSymbol(i, toWrite[i]);
  }
}
void Tape::NMoves(std::vector<std::string> toMove) {
  for (size_t i = 0; i < toMove.size(); i++) {
      if (toMove[i] == "R")  // Realizamos el movimiento del cabezal
        moveRight(i);
      else if (toMove[i] == "L")
        moveLeft(i);
  }
}


std::ostream& Tape::write(std::ostream &os) {
  for (size_t numberTape = 0; numberTape < symbols.size(); numberTape++) {
  os << ".";
    for (size_t i = 0; i < symbols[numberTape].size(); i++) {
      if (i == head[numberTape])
        os << "|\033[4m" << symbols[numberTape][i] << "\033[0m";
      else
        os << "|" << symbols[numberTape][i];
    }
    if (symbols[numberTape].size() == 1)
      os << "|";
    os << " - ";
  }
  return os;
}