#include <bits/stdc++.h>
using namespace std;

void takeGrammer(vector<string> &grammer);
void separateProduction(vector<string> &grammer, vector<pair<char,string>> &productions);
void getFirsts(vector<string> &grammer, vector<pair<char,string>> &productions);
void printVector(vector<string> &grammer);
void printProductions(vector<pair<char,string>> &productions,map<char,vector<char>> &first);

int main()
{
    vector<string> grammer;
    vector<pair<char,string>> productions; 
    map<char,vector<char>> first;

    takeGrammer(grammer);
    printVector(grammer);

    separateProduction(grammer, productions);
    printProductions(productions);

    getFirsts(grammer,productions);

    return 0;
}

void takeGrammer(vector<string> &grammer)
{
    string rule;
    string prevLine;

    while (true)
    {
        getline(cin, rule);

        if (rule.empty() && prevLine.empty())
        {
            break;
        }

        if (!rule.empty())
        {
            grammer.push_back(rule);
        }

        prevLine = rule;
    }
}

void separateProduction(vector<string> &grammer, vector<pair<char,string>> &productions)
{
    for (auto &rule: grammer){
        int len = rule.length();
        char lhs = rule[0]; 

        for (int i=0;i<len;i++){
            if (rule[i]=='>'){
                string prd = "";
                for (int j=i+1;j<len;j++){
                    if (rule[j]!=' ' && rule[j]!='|'){
                        prd+=rule[j];
                    }
                    else if (!prd.empty())
                    {
                        productions.push_back({lhs, prd});
                        prd="";
                    }
                }
                if (!prd.empty()){
                    productions.push_back({lhs, prd});
                }
                break; 
            }
        }
    }
}

void getFirsts(vector<string> &grammer, vector<pair<char,string>> &productions,map<char,vector<char>> &first){
    for (auto &prd: productions){
        if (prd.second[0]>='a' && prd.second[0]<='z')
        {
            first[prd.first].push_back(prd.second[0]);
        }
        else{
            
        }
    }
}

void printVector(vector<string> &grammer)
{
    cout<<endl;
    for (auto &rule : grammer)
    {
        cout << rule << endl;
    }
}

void printProductions(vector<pair<char,string>> &productions)
{
    cout << endl;
    for (auto &entry : productions)
    {
        cout << entry.first << " -> " << entry.second << endl;
    }
}
