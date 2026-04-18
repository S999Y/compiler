#include <bits/stdc++.h>

#define print(x) cout << x << endl

using namespace std;

// take grammar from user input and print it
void takeGrammar(vector<string> &grammar);
void printVector(vector<string> &grammar);

// get production rules from grammar and print them
void getProductionRules(vector<string> &grammar, vector<pair<string, vector<string>>> &production_rules);
void printProductionRules(vector<pair<string, vector<string>>> &production_rules);

// get first sets from production rules and print them
bool isTerminal(string ch);
bool isTerminal(char ch);
void getFirst(vector<pair<string, vector<string>>> &production_rules, map<string, set<string>> &first_set);
void getFirst_set(string left, map<string, vector<string>> &grammar, map<string, set<string>> &first_set);
void printFirst(string left, map<string, set<string>> first_set);

int main()
{
    vector<string> grammar;
    vector<pair<string, vector<string>>> production_rules;
    map<string, set<string>> first_sets;

    takeGrammar(grammar);
    // printVector(grammar);

    getProductionRules(grammar, production_rules);
    printProductionRules(production_rules);

    print("======getFirst======");
    getFirst(production_rules, first_sets);

    for (auto &t : production_rules)
    {
        printFirst(t.first, first_sets);
    }

    return 0;
}

void takeGrammar(vector<string> &grammar)
{
    string rule;
    string prevLine;
    // change this to read from terminal
    // while(true)
    while (getline(cin, rule))
    {
        // getline(cin, rule);
        if (rule.empty() && prevLine.empty())
        {
            break;
        }

        if (!rule.empty())
        {
            grammar.push_back(rule);
        }

        prevLine = rule;
    }
}

void printVector(vector<string> &grammar)
{
    for (const auto &rule : grammar)
    {
        cout << rule << endl;
    }
    cout << endl;
}

void getProductionRules(vector<string> &grammar, vector<pair<string, vector<string>>> &production_rules)
{
    string left_side = "";
    vector<string> right_side;
    for (auto &rule : grammar)
    {
        int len = rule.length();
        for (int i = 0; i < len; i++)
        {
            if (rule[i] != ' ' && rule[i] != '-' && rule[i] != '>')
            {
                left_side += rule[i];
            }
            else
            {
                break;
            }
        }

        for (int i = 0; i < len; i++)
        {
            if (rule[i] == '>')
            {
                string production = "";
                for (int j = i + 1; j < len; j++)
                {
                    if (rule[j] != ' ' && rule[j] != '|')
                    {
                        production += rule[j];
                    }
                    else if (!production.empty())
                    {
                        right_side.push_back(production);
                        production = "";
                    }
                }
                if (!production.empty())
                {
                    right_side.push_back(production);
                }

                break;
            }
        }
        production_rules.push_back({left_side, right_side});
        left_side = "";
        right_side.clear();
    }
}

void printProductionRules(vector<pair<string, vector<string>>> &production_rules)
{
    for (const auto &rule : production_rules)
    {
        string left = rule.first;
        vector<string> right = rule.second;

        for (auto &production : right)
        {
            cout << left << " -> " << production << endl;
        }
    }
    cout << endl;
}

bool isTerminal(string ch)
{
    bool terminal = true;
    for (auto &a : ch)
    {
        if (a >= 'A' && a <= 'Z')
        {
            return terminal = false;
        }
    }
    return terminal;
}

bool isTerminal(char ch)
{
    return !(ch >= 'A' && ch <= 'Z');
}

void getFirst(vector<pair<string, vector<string>>> &production_rules, map<string, set<string>> &first_set)
{
    map<string, vector<string>> grammar;
    for (auto &rule : production_rules)
    {
        grammar[rule.first] = rule.second;
    }

    // print("=====grammar======");
    // for (auto &element : grammar)
    // {
    //     cout << element.first << " => ";
    //     for (auto &a : element.second)
    //     {
    //         cout << a << ", ";
    //     }
    //     cout << endl;
    // }

    for (auto &symbol : grammar)
    {
        getFirst_set(symbol.first, grammar, first_set);
    }
}

void getFirst_set(string left, map<string, vector<string>> &grammar, map<string, set<string>> &first_set)
{
    if (!first_set[left].empty())
    {
        return;
    }

    for (auto &production : grammar[left])
    {

        int index = 0;
        string symbol = string(1, production[index]);
        if (isTerminal(symbol))
        {
            first_set[left].insert(symbol);
        }
        else
        {
            getFirst_set(symbol, grammar, first_set);
        }

        for (auto &first : first_set[symbol])
        {
            // first_set[left].insert(first);
            if (first != "ε")
            {
                first_set[left].insert(first);
            }
            else if (first == "ε")
            {
                if (index < production.length() - 1)
                {
                    index++;
                    symbol = string(1, production[index]);

                    if (isTerminal(symbol))
                    {
                        first_set[left].insert(symbol);
                    }
                    else
                    {
                        getFirst_set(symbol, grammar, first_set);
                    }
                }
                else if (index == production.length() - 1)
                {
                    first_set[left].insert("ε");
                }
            }
        }
    }
}

void printFirst(string left, map<string, set<string>> first_set)
{
    cout << left << " => { ";

    int len = first_set[left].size();

    if (len == 1)
    {
        for (auto &a : first_set[left])
        {
            cout << a;
        }
    }
    else if (len >= 2)
    {
        int count = 0;
        for (const auto &a : first_set[left])
        {
            cout << a;
            if (++count < len)
            {
                cout << ", ";
            }
        }
    }

    cout << " }" << endl;
}
