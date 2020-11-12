#include <iostream>
#include <fstream>
#include "tape.hpp"
#include "turingMachine.hpp"


void keyboardMode(TuringMachine turingMachine) {
	std::string keyboardString;
	std::vector<std::string> inputs;
  do {
		std::cout << "\nIntroduzca cadena a reconocer por el autómata (X para salir)\n >> ";
		getline(std::cin, keyboardString);
		getWords(keyboardString, inputs);
		if (keyboardString != "X") {
			if (!turingMachine.test(inputs))
				std::cout << "La cadena: " << keyboardString << " no ha sido aceptada\n";
			else 
				std::cout << "La cadena: " << keyboardString << " ha sido aceptada\n";
		}
	} while(keyboardString != "X");
}

void fileMode(TuringMachine turingMachine) {
	std::string fileName;
	std::cout << "\nIntroduzca nombre del fichero\n >> ";
	std::cin >> fileName;

  std::string line;
	std::vector<std::string> inputs;
	std::ifstream file(fileName);

	if (file.is_open()) {
    while (getline(file, line)) {
			getWords(line, inputs);
			if (!turingMachine.test(inputs))
				std::cout << "La cadena: " << line << " no ha sido aceptada\n";
			else
				std::cout << "La cadena: " << line << " ha sido aceptada\n";
		}
	} else {
		std::string s("ERROR EN TIEMPO DE EJECUCIÓN - No se pudo abrir el fichero\n");
    throw std::runtime_error(s);
	}
}


int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "Debe introducir el nombre del fichero que contiene al autómata\n";
		std::cerr << "./main EjemploX.txt\n";
    return(1);
  } else {
      try {
        int option;
				std::string dummy; // variable para limpiar el buffer de entrada

        TuringMachine testTuringMachine(argv[1]);
        testTuringMachine.write(std::cout);
        std::cout << "\n\nSeleccione método para introducir las cadenas:\n 1.- Teclado\n 2.- Fichero\n >> ";
        std::cin >> option;
				getline(std::cin, dummy);
				// limpiar el resto de la salida
        if (option == 1) {
          keyboardMode(testTuringMachine);
        } else {
          fileMode(testTuringMachine);
        }
      } catch(std::runtime_error &e) {
        std::cerr << e.what();
        return(2);
      }
  }
  return(0);
}