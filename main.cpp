#include <iostream>

#include "dice.hpp"
#include "condition_example.hpp"





int main ( const int argc, const char* const argv[] ){
  bool flag_print_candidate = false;
  if ( argc != 1 ) {
    flag_print_candidate = true;
  }
  std::cout << "==============================\n";
  std::cout << "Solving an example problem ...\n";
  std::cout << "==============================\n";
  Solve<Condition_Example>( std::vector<Dice>( 3, Dice({ 1, 1, 1, 1, 1, 1 }) ), flag_print_candidate );

  return EXIT_SUCCESS;
}
