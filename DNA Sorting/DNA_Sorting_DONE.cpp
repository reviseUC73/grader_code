#include <iostream>
#include <algorithm>

using namespace std;

struct DNA {
  string text;
  int inversion;
};

bool compareDNA(DNA a, DNA b) {
  return a.inversion < b.inversion;
}

int main() {
  int m;
  cin >> m;

  for (int i = 0; i < m; i++) {
    int text_length, num_text;
    cin >> text_length >> num_text;
    DNA dna[num_text];
    for (int j = 0; j < num_text; j++) {
      cin >> dna[j].text;
      dna[j].inversion = 0;
      for (int k = 0; k < text_length - 1; k++) {
        // Count the number of inversions
        for (int l = k + 1; l < text_length; l++) {
          if (dna[j].text[k] > dna[j].text[l]) {
            dna[j].inversion++;
          }
        }
      }
    }
    sort(dna, dna + num_text, compareDNA);

    for (int j = 0; j < num_text; j++) {
      cout << dna[j].text << endl;
    }
    if (i + 1 < m) {
      cout << endl;
    }
  }
}