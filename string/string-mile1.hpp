//File:        string-interface.hpp
//       
//Version:     1.0
//Date:        Fall 2019
//Author:      Dr. J. Maletic
//
//Description: Interface definition of String class for Project 2, milestone 1.
//
// To use the supplied test oracles you will need to use this interface and namings.
// You must also have all of these methods and functions defined for your string class.
//
// You will either have use this interface or call your methods through this interface.
//
// You need to implement all of the methods and funcitons declared here.
//

#ifndef CS23001_STRING_INTERFACE_HPP
#define CS23001_STRING_INTERFACE_HPP

#include <iostream>

const int STRING_SIZE = 256;                      //The size of the String.

////////////////////////////////////////////////////
// CLASS INV:   str[length()] == 0 &&
//              0 <= length() <= capacity() &&
//              capacity() == STRING_SIZE - 1
//
class String {
public:
            String        ();                     //Empty string DONE
            String        (char);                 //String('x') DONE
            String        (const char[]);         //String("abcd") DONE
    char&   operator[]    (int);                  //Accessor/Modifier DONE
    char    operator[]    (int)            const; //Accessor DONE
    int     capacity      ()               const; //Max chars that can be stored (not including null terminator) DONE
    int     length        ()               const; //Number of char in string DONE
    String  operator+     (const String&)  const; //Addition Concatenation DONE
    String  operator+=    (const String&);        //Compound Concatination DONE
    bool    operator==    (const String&)  const; //== Comparison Operator DONE
    bool    operator<     (const String&)  const; //< Comparison Operator

    int     findch        (int, char); //Finds character, returns position DONE
    String  substr        (int, int); //Finds a String in a String
    int     findstr       (int, const String&);

    friend  std::istream& operator>>(std::istream&, String&); //Output Operator DONE
    friend  std::ostream& operator<<(std::ostream&, const String&); //Done
private:
    char str[STRING_SIZE];
};

String  operator+       (const char[],  const String&); //DONE
String  operator+       (char,          const String&); //DONE
bool    operator==      (const char[],  const String&); //DONE
bool    operator==      (char,          const String&); //DONE
bool    operator<       (const char[],  const String&); //DONE
bool    operator<       (char,          const String&); //DONE
bool    operator<=      (const String&, const String&); //DONE
bool    operator!=      (const String&, const String&); //DONE
bool    operator>=      (const String&, const String&); //DONE
bool    operator>       (const String&, const String&); //DONE

#endif
