
#include <string>
#include <stack>
using namespace std;

class BrowserHistory {
stack<string> history;
stack<string> forwards;
stack<string> emptys;
public:
    BrowserHistory(string homepage) {
      history.push(homepage);
    }

    void visit(string url) {
      history.push(url);
      forwards=emptys;
    }

    string back(int steps) {
      string t = history.top();
      while (steps > 0) {
        if (history.size() <= 1) {
          return t;
        }
        history.pop();
        forwards.push(t);
        t = history.top();
        steps--;
      }
      return history.top();
    }

    string forward(int steps) {
      string f = history.top();
      while (steps > 0) {
        if (forwards.empty()) return f;
        f = forwards.top();
        history.push(f);
        forwards.pop();
        steps--;
      }
      return history.top();
    }
};