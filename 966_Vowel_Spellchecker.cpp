#include <bits/stdc++.h>
using namespace std;

/**
 * 966. Vowel Spellchecker
 *
 * https://leetcode.com/problems/vowel-spellchecker/
 */
class Solution {
 public:
  vector<string> spellchecker(vector<string>& wordlist,
                              vector<string>& queries) {
    unordered_set<string> exact_words;
    unordered_map<string, string> upper_words, vowelless_words;

    for (const string& word : wordlist) {
      exact_words.insert(word);

      string upper = to_upper(word);
      if (!upper_words.contains(upper)) {
        upper_words[upper] = word;
      }

      string vowelless = to_vowelless(upper);
      if (!vowelless_words.contains(vowelless)) {
        vowelless_words[vowelless] = word;
      }
    }

    vector<string> result;
    for (const string& query : queries) {
      if (exact_words.contains(query)) {
        result.push_back(query);
        continue;
      }

      string upper = to_upper(query);
      if (upper_words.contains(upper)) {
        result.push_back(upper_words[upper]);
        continue;
      }

      string vowelless = to_vowelless(upper);
      if (vowelless_words.contains(vowelless)) {
        result.push_back(vowelless_words[vowelless]);
        continue;
      }

      result.push_back("");
    }

    return result;
  }

 private:
  string to_upper(const string& word) {
    string upper = word;
    transform(upper.begin(), upper.end(), upper.begin(), ::toupper);
    return upper;
  }

  string to_vowelless(const string& upper) {
    string vowelless = upper;

    for (size_t i = 0; i < vowelless.length(); i++) {
      char c = vowelless[i];
      if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
        vowelless[i] = '*';
      }
    }

    return vowelless;
  }
};

int main() {
  Solution sol;

  vector<string> wordlist{"KiTe", "kite", "hare", "Hare"};
  vector<string> queries{"kite", "Kite", "KiTe", "Hare", "HARE",
                         "Hear", "hear", "keti", "keet", "keto"};
  vector<string> result = sol.spellchecker(wordlist, queries);

  wordlist = {"yellow"};
  queries = {"YellOw"};
  result = sol.spellchecker(wordlist, queries);

  return 0;
}
