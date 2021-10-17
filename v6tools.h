//
//  v6tools.h
//  validateIPv6
//
//  Created by Darrell Root on 10/17/21.
//

#ifndef v6tools_h
#define v6tools_h

#include <stdio.h>
#include <stdbool.h>

// This function receives a string and converts each character to lowercase
void lowercase(char* line);

/* This function receives a string, possibly with one newline at the end
* and converts the newline to a 0.  This shortens the string by length 1
* without freeing any memory.
*
* A newline in the middle will result in a drastically shorter string
*/
void stripNewline(char* line);

/* This function takes a string and returns true if all the characters
* are valid in IPv6 addresses and the length of the string is 39 or less
* otherwise the string is identified as not valid for IPv6 and false is returned
* it is assumed that the string has already been lowercased and stripped of newlines
*/
bool validIPv6Characters(const char* line);


/* This function returns the number of consecutive double colons detected
 ::: counts as two double colons
*/
int numberDoubleColons(const char* line);

/* This function returns the number of colons in the string*/
int numberOfColons(const char* line);

/* This accepts a string with an IPv6 address.  It returns false if any hextet
* has more than 4 digits (making the IPv6 address invalid
* otherwise true*/
bool validHextets(const char* line);

/*this accepts a lowercase string already stripped of newlines.  It returns true if it is a valid IPv6 address, false otherwise*/
bool validIPv6Address(const char* candidate);

#endif /* v6tools_h */
