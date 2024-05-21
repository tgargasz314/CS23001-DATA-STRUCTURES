#ifndef CS_LOGENTRY_H_
#define CS_LOGENTRY_H_

////////////////////////////////////////////////////////////
//
// File:        logentry.hpp 
//       
// Version:     1.0
// Date:        03-04-20
// Author:      Tyler Gargasz
//
// Description: Class definition for a log entry.
//
//
//

////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>

#include "string.hpp" 

////////////////////////////////////////////////////////////
class Date { 
public:
  Date() : year(0) {};
  Date (String);
  String getDay() const {return day;}
  String getMonth() const {return month;}
  int getYear() const {return year;}

private:
    String  day, month;
    int     year;
};

////////////////////////////////////////////////////////////
class Time {
  public:
  Time() : hour(0), minute(0),second(0) {};
  Time(String);

  int getHour() const {return hour;}
  int getMinute() const {return minute;}
  int getSecond() const {return second;}
  
  //friend ostream& operator<<
  private:
    int     hour, minute, second;
};


////////////////////////////////////////////////////////////
class LogEntry {
public:
  LogEntry() : number_of_bytes(0) {};
  LogEntry(String);

  String getHost() const {return host;}
  int getBytes() const {return number_of_bytes;}
  //String getDay() {return date.day;}

  friend  std::ostream& operator<<(std::ostream&, const LogEntry&);

private:
    String  host;
    Date    date;
    Time    time;
    String  request;
    String  status;
    int     number_of_bytes;
};


////////////////////////////////////////////////////////////
//
// Free functions
//

std::vector<LogEntry>   parse       (std::istream&);
void                    output_all  (std::ostream&, const std::vector<LogEntry> &);
void                    by_host     (std::ostream&, const std::vector<LogEntry> &);
int                     byte_count  (const std::vector<LogEntry>&);

int                     string_to_int (String&);

#endif

