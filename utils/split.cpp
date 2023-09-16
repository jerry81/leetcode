vector<string> split(string str) {
  // Returns first token
  vector<string> ret;
  char *token = strtok(str.data(), "/");

  // Keep printing tokens while one of the
  // delimiters present in str[].
  while (token != nullptr) {
    ret.push_back(token);
    token = strtok(nullptr, "/");
  }

  return ret;
}