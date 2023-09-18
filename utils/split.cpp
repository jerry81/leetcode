#include <string>
#include <vector>

using namespace std;

vector<string> split(string str, string delimiter) {
  // Returns first token
  vector<string> ret;
  char *token = strtok(str.data(), delimiter.c_str());

  // Keep printing tokens while one of the
  // delimiters present in str[].
  while (token != nullptr) {
    ret.push_back(token);
    token = strtok(nullptr, "/");
  }

  return ret;
}