#include "string.hpp"

String::String() {
  stringSize = 1;
  str = new char [stringSize];
  str[0] = '\0';
}

String::String(char letr) {
  stringSize = 2;
  str = new char [stringSize];
  str[0] = letr;
  str[1] = '\0';
}

String::String(const char word[]) {
  stringSize = 0;

  while (word[stringSize] != '\0') {++stringSize;}
  ++stringSize;
  str = new char [stringSize];
  str[stringSize] = '\0';

  for (int i = 0; i < stringSize; ++i){
    str[i] = word[i];
  } 
}

String::String(const String& rhs){
  //std::cout << "COPY START" << std::endl;
  stringSize = rhs.stringSize;
  //std::cout << "BEFORE ALLOC" << std::endl;
  str = new char [stringSize];

  //std::cout << "AFTER ALLOC" << std::endl;

  for (int i = 0; i < stringSize; ++i) {
    str[i] = rhs[i];
  }
  str[stringSize-1] = '\0';
  //std::cout << "DONE IN COPY" << std::endl;
}

String::~String() { //Destructor
  delete [] str;
}

void String::swap(String& str2) { //Swaps two Strings
  char *tmp = str2.str;
  str2.str = str;
  str = tmp;

  int temp = str2.stringSize;
  str2.stringSize = stringSize;
  stringSize = temp;

}

String& String::operator=(String rhs) { //Assignment Operator
  //rhs.swap(str);
  swap(rhs);
  return *this;
}

char String::operator[](int x) const { //Accessor
  return str[x];
}

char& String::operator[](int x) { //Modifier
  return str[x];
}

int String::capacity() const{ //Capacity
  return stringSize - 1;
}

int String::length() const{ //Length
  int len = 0;
  while(str[len] != '\0') {++len;}
  return len;
}

String String::operator+(const String& rhs) const { //Concatination
  int psize = length() + rhs.length();
  //std::cout << "RHS: " << rhs << std::endl;
  String result(psize, str);
  //std::cout << "PRINTING: " << result << std::endl;
  for (int i = length(); i < psize; ++i) {
    result[i] = rhs.str[i - length()];
  }
  result.str[psize] = '\0';
  //std::cout << "DONE: " << result << std::endl;
  return result;
}

String& String::operator+=(const String& rhs) { //Compound Concatination
  int nsize = length() + rhs.length();
  int l = length();
  resetCapacity(nsize);
  for (int i = l; i < nsize; ++i) {
    str[i] = rhs.str[i - l];
  }
  str[nsize] = '\0';
  return *this;
}

bool String::operator==(const String& rhs) const{ //Equivalence Operator
  if (length() != rhs.length()) { return false;}
  for (int i = 0; i < length(); ++i) {
    if (str[i] != rhs.str[i]) {return false;}
  }
  return true;
}

bool String::operator<(const String& rhs) const { //Less Than Operator
  //std::cout << "Comparing " << str << " ?< " << rhs << std::endl;
  int cnt = 0;
  while(str[cnt] == rhs.str[cnt]){
    if(str[cnt] == '\0') {break;}
    ++cnt;
  }
  //std::cout << "Returning: " << (str[cnt] < rhs.str[cnt] ? "True" : "False") << std::endl;
  return str[cnt] < rhs.str[cnt];
}

String String::substr(int start, int end) const { //Substring
  //std::cout << "|" << str << "|.substr(" << start << ", " << end << ")" << std::endl;
  if(start > end) return String();
  String sub(end - start + 1);
  for (int i = start; i <= end; ++i) {
    sub.str[i - start] = str[i];
  }
  sub.str[end - start + 1] = '\0';
  //std::cout << "DONE SUB" << std::endl;
  //std::cout << sub << "length: " << sub.length() << std::endl;
  return sub;
}

int String::findch(int start,  char find) const { //Finds Character
  for (int i = start; i < length(); ++i) {
    if (str[i] == find) {return i;}
  }
  return -1;
}

int String::findstr(int start,  const String& find) const { //Find String
  ///*
  for (int i = start; i < length() - find.length()+1; ++i) {
    if (find == substr(i, i + find.length() - 1)) {return i;}
  }
  return -1;
  //*/

  /*
  while (str[start] != 0) {
    if (str[start] == find[0]) {
      int i = 0;
      for (; i < find.length(); ++i) {
        if (str[i + start] != find[i]) break;
      }
      if (find[i] == 0) return start;
    }
    ++start;
  }
  return -1;
  //*/
  
}

std::ostream& operator<<(std::ostream& out, const String& word) { //Output Operator
  int i = 0;
  while(word[i] != '\0'){
    out << word[i];
    ++i;
  }
  return out;
}


std::istream& operator>>(std::istream& in, String& text){
  char x[512];
  in >> x;
  text = String(x);
  return in;
}

std::vector<String> String::split(char c) const {
  std::vector<String> victor;
  //std::cout << *this << "!!!" << c <<'!' <<std::endl;
  int start = 0;
  int end = findch(start, c);

  while(end != -1) { 
    //std::cout << start << "|" << end - 1 << "||"  << std::endl;
    String temp = substr(start, end-1);
    victor.push_back(temp);
    //std::cout << "Just pushed" << std::endl;
    start = end+1;
    end = findch(start, c);
  }
  //std::cout << "LAST" << std::endl;
  victor.push_back(substr(start, length()));
  //std::cout << "DONE" << std::endl;
  return victor;
}


// Private Functions

String::String(int x) { //Private int constructor
  str = new char [x+1];
  stringSize = x+1;
}

String::String(int size, const char arr[]) { //Private char array constructor
  str = new char [size+1];
  stringSize = size+1;
  int i = 0;
  while (arr[i] != '\0') {
    str[i] = arr[i];
    ++i;
  }
  str[i] = '\0';
}

void String::resetCapacity(int ncap) { //Set new, probably larger capacity
  char *nstr = new char [ncap + 1];
  int i = 0;
  for (; i < length(); ++i) {
    nstr[i] = str[i];
  } 
  nstr[length()] = '\0';
  stringSize = ncap + 1;
  delete [] str;
  str = nstr;
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
  return !(lhs == rhs);
}

bool operator>=(const String& lhs, const String& rhs){
  return rhs < lhs || rhs == lhs;
}


