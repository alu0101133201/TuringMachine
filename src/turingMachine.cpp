/** 
 * Fichero que implementa la clase máquina de turing
 * ULL - Complejidad Computaciones
 * Sergio Guerra Arencibia
 * 02/11/2020
 */
#include "turingMachine.hpp"
#include <fstream>
#include <sstream>

// Función auxiliar que vuelva un vector en un set
void vectorToSet(std::vector<std::string> &initialVector, std::set<std::string> &destinationSet) {
  for (size_t i = 0; i < initialVector.size(); i++) {
    destinationSet.insert(initialVector[i]);
  }
}

// Función auxiliar que almacena una línea en un set
void storeLine(std::string &line, std::vector<std::string> &words, std::set<std::string> &setToStore) {
    getWords(line, words); // Leemos el alfabeto de entrada de la cadena
    vectorToSet(words, setToStore);
}  

// Función auxiliar para dividir una cadena por los espacios
void getWords(std::string initialString, std::vector<std::string> &words) {
  words.clear();
  std::istringstream ourString(initialString);
  do {
    std::string word;
    ourString >> word;
    if (word.length() > 0)
      words.push_back(word);
  } while(ourString);
}

TuringMachine::TuringMachine(char* turingFile) {
  std::string route = "./examples/";
  std::string line;
  std::vector<std::string> words;
  route += turingFile;
  std::ifstream file(route.c_str());

  if (file.is_open()) {
    while (getline(file, line)) {   // Eliminamos los comentarios
      if (line[0] != '#') break;
    }
    for (size_t i = 0; i < words.size(); i++) { // Leemos el cjto de estados
      allStates.push_back(*(new State(words[i])));
    }
    getline(file, line);  // Alfabeto de la máquina
    storeLine(line, words, turingAlphabet);
    getline(file, line);  // Alfabeto de la cinta
    storeLine(line, words, tapeAlphabet);
    getline(file, line);  // Estado inicial
    initialState = line;
    getline(file, line); // símbolo blanco
    whiteSymbol = line[0];
    getline(file, line); // Cjto de estados finales
    getWords(line, words);
    for (size_t i = 0; i < words.size(); i++) 
      finalStates.push_back(words[i]);
    
    // TRANSICIONES -----------------------

  } else {
    std::string s("ERROR EN TIEMPO DE EJECUCIÓN - No se pudo abrir el fichero\n");
    throw std::runtime_error(s);
  }

}

TuringMachine::~TuringMachine() {}


std::ostream& TuringMachine::write (std::ostream& os) {
  os << " - - - TURING MACHINE - - -\n ·Cjto de estados: ";
  for (size_t i = 0; i < allStates.size(); i++)
    os << allStates[i].getID() << " ";
  os << "\n ·Alfabeto de entrada: ";
  for (std::set<std::string>::iterator it = turingAlphabet.begin(); it != turingAlphabet.end(); it++)
    os << *it << " ";
  os << "\n ·Alfabeto de la cinta: ";
  for (std::set<std::string>::iterator it = tapeAlphabet.begin(); it != tapeAlphabet.end(); it++)
    os << *it << " ";
  os << "\n ·Estado inicial: " << initialState << "\n ·Estados finales: ";
  for (std::vector<std::string>::iterator it = finalStates.begin(); it != finalStates.end(); it++)
    os << *it << " ";
  os << "\n";

  return os;
}
