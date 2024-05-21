//
//
// File:        logentry.cpp  
//       
// Version:     1.0
// Date:        03-04-20
// Author: Tyler Gargasz     
//
// Description: Class implementation for a log entry.
//
//

////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>

#include "string.hpp" 
#include "logentry.hpp"

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
LogEntry::LogEntry(String s) : LogEntry() {

  std::vector<String> vec = s.split(' ');
  
  if(vec.size() == 10) {

  host = vec[0];

  date = Date(vec[3].substr(1, vec[3].findch(1,':') - 1));

  time = Time(vec[3].substr(vec[3].findch(1,':') + 1, vec[3].length()));

  request = vec[5] + ' ' + vec[6] + ' ' + vec[7];

  status = vec[8];

  number_of_bytes = string_to_int(vec[9]);
    
    }
}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
std::vector<LogEntry> parse(std::istream& in) {
    std::vector<LogEntry> result;
    String x;
    char c;
    
    while(!in.eof()) {
    in.get(c);
    if(in.eof()) {break;}
    if(c != '\n') {x += c;}
    else {result.push_back(LogEntry(x)); x = "";}
    }
    return result;
}


//////////////////////////////////////////////////////////
// REQUIRES:
// ENSURES:
//
std::ostream& operator<<(std::ostream& out, const LogEntry& line) {
  out << "HOST: " << line.host << std::endl;
  out << "\tDATE: " << line.date.getDay() << '/' << line.date.getMonth() << '/' << line.date.getYear() << std::endl;
  out << "\tTIME: " << line.time.getHour() << ':' << line.time.getMinute() << ':' << line.time.getSecond() << std::endl;
  out << "\tREQUEST: " << line.request << std::endl;
  out << "\tSTATUS: " << line.status << std::endl;
  out << "\tBYTES: " << line.number_of_bytes << std::endl;

  return out;
}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
void output_all(std::ostream& out, const std::vector<LogEntry>& wholeLog) {
  for(std::vector<LogEntry>::const_iterator it = wholeLog.cbegin(); it != wholeLog.cend(); ++it) {
    out << *it << std::endl;
  }
}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
void by_host(std::ostream& out, const std::vector<LogEntry>& hostOnly) {
  for(std::vector<LogEntry>::const_iterator it = hostOnly.cbegin(); it != hostOnly.cend(); ++it) {
    out << it -> getHost() << std::endl;
  }
}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
int byte_count(const std::vector<LogEntry>& bits) {
  
  int bytes = 0;

   for(std::vector<LogEntry>::const_iterator it = bits.cbegin(); it != bits.cend(); ++it) {
    bytes += it -> getBytes();
  } 
    return bytes;
}

//Things I Made

Date::Date(String str) {
  std::vector<String> victor = str.split('/');
  day = victor[0];
  month = victor[1];
  year = string_to_int(victor[2]); 
}

Time::Time(String t) {
   std::vector<String> victor = t.split(':');
   hour = string_to_int(victor[0]);
   minute = string_to_int(victor[1]);
   second = string_to_int(victor[2]);
}

int string_to_int (String& tint) {
  int num = 0;

  if (tint == '-') {return 0;}
  
  for (int i = 0; i < tint.length(); ++i) {
    num *= 10;
    num += tint[i] - '0';
  }
  return num;
}
