/** 
 * Fichero que implementa la clase máquina de turing
 * ULL - Complejidad Computaciones
 * Sergio Guerra Arencibia
 * 02/11/2020
 */
#include "turingMachine.hpp"


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
    numberOfTapes = stoi(line);
    getline(file, line);  // leemos los estados
    getWords(line, words); 
    for (size_t i = 0; i < words.size(); i++) { // Almacenamos los estados
      allStates.push_back(*(new State(words[i])));
    }

    getline(file, line);  // Alfabeto de la máquina
    storeLine(line, words, turingAlphabet);
    getline(file, line);  // Alfabeto de la cinta
    storeLine(line, words, tapeAlphabet);
    getline(file, line);  // Estado inicial
    for (size_t i = 0; i < allStates.size(); i++) {
      if (allStates[i].getID() == line) {
        initialState = &allStates[i];
        currentState = &allStates[i];
      }
    }
    getline(file, line); // símbolo blanco
    whiteSymbol = line;
    getline(file, line); // Cjto de estados finales
    getWords(line, words);
    for (size_t i = 0; i < words.size(); i++) {
      finalStates.push_back(words[i]);
    }
    readTransitions(file);  // Leemos las transiciones
    
    // if (!checkTuringMachine()) {  // Comprobamos que la máquina de turing sea válida
    //   std::string s("ERROR EN TIEMPO DE EJECUCIÓN - El autómata no cumple con las restricciones formales\n");
    //   throw std::runtime_error(s);
    // }
  } else {
    std::string s("ERROR EN TIEMPO DE EJECUCIÓN - No se pudo abrir el fichero\n");
    throw std::runtime_error(s);
  }
}

TuringMachine::~TuringMachine() {}

void TuringMachine::readTransitions(std::ifstream& file) {
  std::string line;
  std::vector<std::string> words;
  std::string initialState;
  std::string nextState;
  std::vector<std::string> readSymbols;
  std::vector<std::string> writeSymbols;
  std::vector<std::string> moves;

  while (getline(file, line)) {   // Leemos la transiciones
    words.clear(); readSymbols.clear(); writeSymbols.clear(); moves.clear();
    getWords(line, words);
    int iter = 0;
    initialState = words[iter];
    iter++;
    if (!existState(initialState)) {  // compruebo que el estado de partida existe
      std::string s("ERROR EN TIEMPO DE EJECUCIÓN - El autómata no cumple con las restricciones formales\n");
      throw std::runtime_error(s);
    }
    readTapeElements(words, iter, readSymbols);
    nextState = words[iter];
    iter++;
    readTapeElements(words, iter, writeSymbols);
    readTapeElements(words, iter, moves);

    for (size_t i = 0; i < allStates.size(); i++) { // Almaceno al transición en su estado correspondiente
      if (allStates[i].getID() == words[0]) {
        Transition aux(initialState, readSymbols, nextState, writeSymbols, moves);
        allStates[i].pushTransition(aux);
      }
    }
  }
}

void TuringMachine::readTapeElements(std::vector<std::string> &source, 
    int &iterator, std::vector<std::string> &destination) {
  for (int i = 0; i < numberOfTapes; i++) { // Leemos los símbolos que leemos
    destination.push_back(source[iterator]);
    iterator++;
  }
}



bool TuringMachine::checkTuringMachine() {
  bool findInitialState = false;

  // Comprobamos que el estado inicial existe en el cjto de estados
  for (std::vector<State>::iterator it = allStates.begin(); it != allStates.end(); it++) {
    if ((*it).getID() == (*initialState).getID())
      findInitialState = true;
  }
  if (!findInitialState)
    return false;
  // Comprobamos el cjto de estados finales
  for (std::vector<std::string>::iterator it = finalStates.begin(); it != finalStates.end(); it++) {
    if (!existState(*it))
      return false;
  }
  return checkTransitions();
}

bool TuringMachine::checkTransitions(void) {
  // for (std::vector<State>::iterator it = allStates.begin(); it != allStates.end(); it++) {
  //   std::vector<Transition> currentTransitions = (*it).getTransitions();
  //   for (std::vector<Transition>::iterator secondIt = currentTransitions.begin(); 
  //       secondIt != currentTransitions.end(); secondIt++) {
  //     if (tapeAlphabet.find((*secondIt).getReadSymbol()) == tapeAlphabet.end() ||
  //         tapeAlphabet.find((*secondIt).getWriteSymbol()) == tapeAlphabet.end() ||
  //         (((*secondIt).getMove() != "L") && ((*secondIt).getMove() != "R") && ((*secondIt).getMove() != "S")) ||
  //         !existState((*secondIt).getNextState())) // El estado inicial ya se comprueba en la lectura del fichero
  //       return false;
  //   }
  // }
  return true;
}

bool TuringMachine::existState(std::string state) {
  for (std::vector<State>::iterator it = allStates.begin(); it != allStates.end(); it++) {
    if ((*it).getID() == state) {
      return true;
    }
  }
  return false;
}

bool TuringMachine::isFinal(std::string state) {
  for (std::vector<std::string>::iterator it = finalStates.begin(); it != finalStates.end(); it++) {
    if ((*it) == state) {
      return true;
    }
  }
  return false;
}

bool TuringMachine::test(std::vector<std::string> stringsToTest) {
  // turingTape.loadStrings(stringsToTest, whiteSymbol);
  // currentState = initialState;
  // writeCurrentMachine(std::cout);

  // while (!isFinal((*currentState).getID())) {
  //   Transition nextTransition = (*currentState).getTransition(turingTape.getSymbol());
  //   if (nextTransition.getInitialState() == " ")  // Si la transición está vacía, paramos la máquina
  //     return false;
  //   else {
  //     for (size_t i = 0; i < allStates.size(); i++) // Actualizamos el estado
  //       if (allStates[i].getID() == nextTransition.getNextState())
  //         currentState = &allStates[i];
  //     turingTape.writeSymbol(nextTransition.getWriteSymbol());  // Escribimos el símbolo correspondiente
  //     if (nextTransition.getMove() == "R")  // Realizamos el movimiento del cabezal
  //       turingTape.moveRight();
  //     else if (nextTransition.getMove() == "L")
  //       turingTape.moveLeft();
  //     writeCurrentMachine(std::cout);
  //   }
  // }
  return true;
}


std::ostream& TuringMachine::write (std::ostream& os) {
  os << " - - - TURING MACHINE - - -\n ·Número de cintas: " << numberOfTapes << "\n";
  os << " ·Cjto de estados: ";
  for (size_t i = 0; i < allStates.size(); i++)
    os << allStates[i].getID() << " ";
  os << "\n ·Alfabeto de entrada: ";
  for (std::set<std::string>::iterator it = turingAlphabet.begin(); it != turingAlphabet.end(); it++)
    os << *it << " ";
  os << "\n ·Alfabeto de la cinta: ";
  for (std::set<std::string>::iterator it = tapeAlphabet.begin(); it != tapeAlphabet.end(); it++)
    os << *it << " ";
  os << "\n ·Estado inicial: " << (*initialState).getID() << "\n ·Estados finales: ";
  for (std::vector<std::string>::iterator it = finalStates.begin(); it != finalStates.end(); it++)
    os << *it << " ";
  os << "\nTransiciones: \n"; 
  for (size_t i = 0; i < allStates.size(); i++) { 
    for (size_t j = 0; j < allStates[i].getTransitions().size(); j++) {
      os << " ·";
      allStates[i].getTransitions()[j].write(os);
    }
  }
  return os;
}

std::ostream& TuringMachine::writeCurrentMachine(std::ostream& os) {
  turingTape.write(os);
  std::cout << (*currentState).getID() << "\n";
  return os;
}
