#ifndef WORDS_IN_LINE_H
#define WORDS_IN_LINE_H

#include <iostream>
#include <map>

using namespace std;

inline void words_in_line() {
    map<string, int> words;
    string line;
    cout << "Enter some text: ";
    getline(cin, line);

    int start_index = 0;
    for(int i = 0; i <= line.length(); i++) {
        if(i == line.length() || line[i] == ' ') {
            string word = line.substr(start_index, i - start_index);
            if(!word.empty()) {
                if(words.contains(word)) {
                    words[word]++;
                } else {
                    words.insert({word, 1});
                }
            }

            start_index = i + 1;
        }
    }
    for(auto el : words) {
        cout << el.first << " - " << el.second << endl;
    }
}

#endif //WORDS_IN_LINE_H
