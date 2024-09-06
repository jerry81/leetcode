
#include <string>
#include <iostream>
using namespace std;
#include <vector>

// Function to split a string into tokens
std::vector<std::string> split(const std::string& str, const std::string& delimiter) {
    std::vector<std::string> tokens;
    size_t start = 0, end = 0;
    while ((end = str.find(delimiter, start)) != std::string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + delimiter.length();
    }
    tokens.push_back(str.substr(start));
    return tokens;
}

// Greeting interface
class IGreeting {
public:
    virtual void greet() const = 0;
    virtual ~IGreeting() = default;
};

// HelloWorld class implementing IGreeting
class HelloWorld : public IGreeting {
public:
    void greet() const override {
        std::cout << "Hello, World!" << std::endl;
    }
};

// GoodbyeWorld class implementing IGreeting
class GoodbyeWorld : public IGreeting {
public:
    void greet() const override {
        std::cout << "Goodbye, World!" << std::endl;
    }
};

class HelloWorld {
public:
  void sayHello() {
    string s = "hello world";
    cout << s << endl;
  }
  void sayGoodbye() {
    cout << "goodbye world" << endl;
  }
};

int main() {
  HelloWorld hello;
  hello.sayHello();
  return 0;
}

