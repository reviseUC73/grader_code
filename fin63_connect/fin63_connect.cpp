#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

const int MAX_N = 1000;
unordered_map<string, unordered_set<string>> graph;

int L, N, T;
void read_input() {
  cin >> L >> N >> T;
  for (int i = 0; i < N; i++) {
    string word;
    cin >> word;
    graph[word] = unordered_set<string>();
    for (const auto& [key, value] : graph) {
      if (key == word) continue;
      if (key.substr(0, L - 1) == word.substr(1)) {
        graph[word].insert(key);
      }
      if (word.substr(0, L - 1) == key.substr(1)) {
        graph[key].insert(word);
      }
    }
  }
}

bool can_form_sequence(const string& w1, const string& w2) {
  unordered_set<string> visited;
  queue<string> q;
  q.push(w1);
  visited.insert(w1);
  while (!q.empty()) {
    string word = q.front();
    q.pop();
    if (word == w2) {
      return true;
    }
    for (const string& neighbor : graph[word]) {
      if (visited.count(neighbor) == 0) {
        visited.insert(neighbor);
        q.push(neighbor);
      }
    }
  }
  return false;
}

int main() {
  read_input();
  for (int i = 0; i < T; i++) {
    string w1, w2;
    cin >> w1 >> w2;
    if (can_form_sequence(w1, w2)) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }
  return 0;
}