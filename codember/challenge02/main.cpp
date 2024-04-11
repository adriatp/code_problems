#include <bits/stdc++.h>

using namespace std;

int main() {
    size_t last = 0, next = 0;
    string delimiter = " ", phrase, word, letter;
    
    getline(cin, phrase);
    phrase += delimiter;
    while ((next = phrase.find(delimiter, last)) != string::npos) {
        word = phrase.substr(last, next-last);
        last = next + 1;
        letter = "";
        for (int i=0; i<word.length();) {
            if (word[i] == '1') {
                letter = word.substr(i,3);
                i+=3;
            }
            else {
                letter = word.substr(i,2);
                i+=2;
            }
            printf("%c", stoi(letter));
        }
        printf(" ");
    }

    cout << phrase.substr(last) << endl;

    return 0;
}