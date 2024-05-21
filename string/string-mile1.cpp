#include "string.hpp"

String::String(){ //Default Constructor
  str[0] = '\0';
}

String::String(char letter){ //Character Constructor
  str[0] = letter;
  str[1] = '\0';
}

String::String(const char strArray[]){ //charArray Constructor
 
  for(int i = 0; i < STRING_SIZE; ++i){
    str[i] = strArray[i];
  }
}

int String::length() const{ //Length Check
  int size = 0;
  while(str[size] != '\0') {++size;}
  return size;
} 

int String::capacity() const{ //255
  return STRING_SIZE-1;
}

bool String::operator==(const String& s2) const{ //==
  if(length() != s2.length()) {return false;}
  for(int i = 0; i < length(); ++i){
    //std::cout << str[i] << "|" << s2.str[i] << std::endl;
    if(str[i] != s2.str[i])
      return false;
  }
  return true;
}

char String::operator[](int place) const{ //Accessor
  return str[place];
}

char& String::operator[](int place){ //Modifier
  return str[place];
}

String String::operator+(const String& rhs)const{ //Addition Concatination
  String combined;
  int word1 = length();
  int word2 = rhs.length();
  
  for(int i = 0; i < word1; ++i){
    combined[i] = str[i]; 
  }
  for(int j = word1; j < word1 + word2; ++j){
    //std::cout << j << std::endl;
    combined[j] = rhs.str[j - word1];
  } 
  combined.str[word1 + word2] = '\0';
  return combined;
}

String String::operator+=(const String& rhs){ //Compound Concatination
  int word1 = length();
  int word2 = rhs.length();
 
  for(int j = word1; j < word1 + word2; ++j){
    //std::cout << j << std::endl;
    str[j] = rhs.str[j - word1];
  }
  str[word1 + word2] = '\0';
  return str;
}

bool String::operator<(const String& rhs) const{
  int cnt = 0;
  while(str[cnt] == rhs.str[cnt]){
    ++cnt;
    }
  if(str[cnt] < rhs.str[cnt]) {return true;}
  else return false;
}

std::ostream& operator<<(std::ostream& out, const String& word){
  int i = 0;
  while(i < STRING_SIZE && word[i] != '\0'){
    out << word[i];
    ++i;
  }
  return out;
}

std::istream& operator>>(std::istream& in, String& text){
  char x[STRING_SIZE];
  in >> x;
  text = String(x);
  return in;
  
}

int String::findch(int start, char ch){
  int pos;
  for(int i = start; i < length(); ++i){
    if(str[i] == ch){
      pos = i;
      return pos;
    }
  }
  return -1;
}

String String::substr(int start, int end) {
  String sub;
  if (start == end) return str[start];
  for (int i = 0; i <= end - start; ++i) {
    sub.str[i] = str[i + start];
  }
  return sub;
}

int String::findstr(int pos, const String& text){
  while (str[pos] != 0) {
    if (str[pos] == text[0]) {
      int i = 0;
      for (; i < text.length(); ++i) {
	if (str[i + pos] != text[i]) break;
      }
      if (text[i] == 0) return pos;
    }
    ++pos;
  }
  return -1;
}

//Free Functions

String operator+(const char lhs[], const String& rhs){
  return String(lhs) + rhs;
}

String operator+(char lhs, const String& rhs){
  return String(lhs) + rhs;
}

bool operator==(const char lhs[], const String& rhs){
  return String(lhs) == rhs;
}

bool operator==(char lhs, const String& rhs){
  return String(lhs) == rhs;
}

bool operator<(const char lhs[], const String& rhs){
  return String(lhs) < rhs;
}

bool operator<(char lhs, const String& rhs){
  return String(lhs) < rhs;
}

bool operator>(const String& lhs, const String& rhs){
  return rhs < lhs;
}

bool operator<=(const String& lhs, const String& rhs){
  return lhs < rhs || lhs == rhs;
}

bool operator!=(const String& lhs, const String& rhs){
  return lhs != rhs;
}

bool operator>=(const String& lhs, const String& rhs){
  return rhs < lhs || rhs == lhs;
}
