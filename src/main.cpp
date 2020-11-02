#include <iostream>

#include "tape.hpp"
#include "turingMachine.hpp"

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "Debe introducir el nombre del fichero que contiene al autómata\n";
    return(1);
  } else {
    try {
      Tape prueba;
      TuringMachine testMachine(argv[1]);

      testMachine.write(std::cout);

    } catch(std::runtime_error &e) {
      std::cerr << e.what();
      return(2);
    }
  }
}