#include <bits/stdc++.h>

using namespace std;

void loadCPPKeywords(set<string> &keywords);
void readFile(vector<string> &input);
void takeInput(vector<string> &input);
void printVector(vector<string> &input);
void separateWord(vector<string> &input, vector<string> &words);
void findKeyword(set<string> &keywords, vector<string> &words, set<string> &found);
void printSet(set<string> &values);

int main()
{
    set<string> keywords;
    set<string> found;
    vector<string> input;
    vector<string> words;

    loadCPPKeywords(keywords);
    // printSet(keywords);

    readFile(input); // competetive programming setup
    // takeInput(input); // run in terminal
    // printVector(input);

    separateWord(input, words);
    // printVector(words);
    findKeyword(keywords, words, found);
    printSet(found);

    return 0;
}

void loadCPPKeywords(set<string> &keywords)
{
    string kw[] = {
        "alignas", "alignof", "and", "and_eq", "asm", "auto",
        "bitand", "bitor", "bool", "break",
        "case", "catch", "char", "char16_t", "char32_t", "class", "compl", "const", "constexpr", "const_cast", "continue",
        "decltype", "default", "delete", "do", "double", "dynamic_cast",
        "else", "enum", "explicit", "export", "extern",
        "false", "float", "for", "friend",
        "goto",
        "if", "inline", "int",
        "long",
        "mutable",
        "namespace", "new", "noexcept", "not", "not_eq", "nullptr",
        "operator", "or", "or_eq",
        "private", "protected", "public",
        "register", "reinterpret_cast", "return",
        "short", "signed", "string", "set", "vector", "include", "sizeof", "static", "static_assert", "static_cast", "struct", "switch",
        "template", "this", "thread_local", "throw", "true", "try", "typedef", "typeid", "typename",
        "union", "unsigned", "using",
        "virtual", "void", "volatile",
        "wchar_t", "while",
        "xor", "xor_eq"};

    int n = sizeof(kw) / sizeof(kw[0]);

    for (int i = 0; i < n; i++)
    {
        keywords.insert(kw[i]);
    }
}

void readFile(vector<string> &input)
{
    string temp;
    while (getline(cin, temp))
    {
        input.push_back(temp);
    }
}

void takeInput(vector<string> &input)
{

    string temp;
    string prev = "";

    while (true)
    {
        getline(cin, temp);
        if (temp.empty() && prev.empty())
        {
            break;
        }

        if (!temp.empty())
        {
            input.push_back(temp);
        }

        prev = temp;
    }
}

void printVector(vector<string> &input)
{
    for (auto &a : input)
    {
        cout << a << endl;
    }
}

void separateWord(vector<string> &input, vector<string> &words)
{
    string word = "";

    for (auto &a : input)
    {
        // int len = a.length();

        for (char ch : a)
        {
            if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
            {
                word += ch;
            }
            else if (!word.empty())
            {
                words.push_back(word);
                word = "";
            }
        }
        if (!word.empty())
        {
            words.push_back(word);
        }
    }
}

void findKeyword(set<string> &keywords, vector<string> &words, set<string> &found)
{
    for (auto &word : words)
    {
        if (keywords.count(word))
        {
            found.insert(word);
        }
    }
}

void printSet(set<string> &values)
{
    for (auto &value : values)
    {
        cout << value << endl;
    }
}