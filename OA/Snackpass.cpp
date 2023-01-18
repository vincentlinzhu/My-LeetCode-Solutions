// You have 20 minutes, you’re not expected to get to complete working code in that timeframe.

// Write and test a function    numIpAddresses(string str)    that accepts a string of decimal characters 

// and outputs the number of valid IPv4 addresses that can be represented with dot notation. 

// eg    numIpAddresses("090251")     should return the number 3 (returning just the number, not the permutations themselves)

// As a reminder, IPv4 addresses can be represented as a series of 4 decimal number segments separated by a '.' character. 

// Each of the 4 number segments is in the range [0-255]. For the above example, the valid permutations are:

// 0.9.0.251
// 0.90.2.51
// 0.90.25.1

// Invalid permutation examples:

// 0.902.5.1 — 902 is higher than 255
// 09.0.2.51 — 09 is not a number.
// 0.90.251. — only 3 segments

// Hint: the question can be solved with 3 nested for loops or with recursion. Choose the approach that’s easiest for you.

bool isValid(val) {
  if (val =< 255 && val >= 0) {
    return true;
  }
  return false;
}

int numIpAddresses(string str) {
  int count = 0;
  int a = 0; 
  int b = 0;
  int c = 0;
  int d = 0;
  
  for (int i = 0; i < str.size() - 3; i++) {
  	for (int j = i + 1; j < str.size() - 2; j++) {
    	for (int k = j + 1; k < str.size() - 1; k++) {
        a = stoi(str.substr(0, i));
        b = stoi(str.substr(j, j - i));
        c = stoi(str.substr(i, k - j));
        d = stoi(str.substr(k + 1, str.size() - k - 1));
    		if (isValid(a) && isValid(b) && isValid(c) && isValid(d)) {
                count++;
            }
  		}
  	}
  }
  
  return count;
}

