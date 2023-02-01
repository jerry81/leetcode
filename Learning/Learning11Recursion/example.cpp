#include <string>
#include <iostream>

using namespace std;

void printRev(const char * str) {
  if (!*str) return;

  printRev(str+1);
  cerr << *str;
}

int main() {
  printRev("Hello");
  cerr << endl;
  return 0;
}