#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    string s;
    getline(cin, s);

    vector<string> words;
    string temp = "";
    int len = s.length();

    for (int i=0;i<len;i++) {

        if (s[i]==' ' && temp!="")
        {
            words.push_back(temp);
            temp = "";
        }
        else if(s[i]!=' ')
        {
            temp += s[i];
        }
    }
    if (temp != "") {
        words.push_back(temp);
    }

    cout << "The words in the string are: " << endl;
    for (string word : words) {
        cout << word << endl;
    }

    return 0;
}