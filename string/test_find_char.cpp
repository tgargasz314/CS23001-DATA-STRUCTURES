// String Test Program
//
// Tests:  findch
//
//
#include <iostream>
#include <cassert>
#include "string.hpp"

//===========================================================================
int main () {
  // Setup

  // Test
  String Str("Can you find the letter c in this sentence?");

  // Verify
  Str.findch(0, 'c');
  std::cout << "Found c At: " << Str.findch(0, 'c') << std::endl;
	     
  assert(Str.findch(0, 'c') == 24);

  Str.findch(0, 'C');
  std::cout << "Found C At: " << Str.findch(0, 'C') << std::endl;

  assert(Str.findch(0, 'C') == 0);

  Str.findch(16, 'e');
  std::cout << "Found e At: " << Str.findch(16, 'e') << std::endl;

  assert(Str.findch(16, 'e') == 18);

  
  std::cout << "Done testing findch." << std::endl;
}
