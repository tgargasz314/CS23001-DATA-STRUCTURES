// String Test Program
//
// Tests:  length and capacity, uses ==
//
//
#include <iostream>
#include <cassert>
#include "string.hpp"

//===========================================================================
int main () {
  // Setup

  {

    // Test 1
    String Str("1234");

    // Verify
    std::cout << "String: " << Str << std::endl;
    std::cout << "Capacity: " << Str.capacity() << std::endl;
    assert(Str.capacity() == 4);

    std::cout << "Length: " << Str.length() << std::endl;
    assert(Str.length() == 4);

  }

  //==========================================================================
  {

    // Test 2
    String Str("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");

    // Verify
    std::cout << "String: " << Str << std::endl;
    std::cout << "Capacity: " << Str.capacity() << std::endl;
    assert(Str.capacity() == 69);

    std::cout << "Length: " << Str.length() << std::endl;
    assert(Str.length() == 69);

  }

  //==========================================================================
  {

    // Test 3
    String Str('c');

    // Verify
    std::cout << "String: " << Str << std::endl;
    std::cout << "Capacity: " << Str.capacity() << std::endl;
    assert(Str.capacity() == 1);

    std::cout << "Length: " << Str.length() << std::endl;
    assert(Str.length() == 1);

  }


  
  std::cout << "Done testing length and capacity." << std::endl;
}


