#include<iostream>
#include<string>
#include<vector>

using namespace std;

void getCFG();
void getCFG_ ();

int main(){

    
    getCFG_();

    return 0;
}

void getCFG () {
    vector<string> cfg;
    string s;

    while (true) {
        getline(cin, s);
        if (s == "END") {
            break;
        }

        if (!s.empty()) {
            cfg.push_back(s);
        }
    }

    for (auto &production : cfg) {
        cout << production << endl;
    }
}

void getCFG_ ()
{
    string rule;
    string prevLine;
    vector<string> cfg;

    while (true) 
    {
        getline(cin, rule);
        
        if (rule.empty() && prevLine.empty())
        {
            break;
        }

        if (!rule.empty())
        {
            cfg.push_back(rule);
        }
        
        prevLine = rule;
    }

    for (auto &production : cfg) {
        cout << production << endl;
    }

    vector<string> symbols;
    for (auto & production: cfg){
        int len = production.length();
        for (int i=0;i<len;i++){
            if (production[i]=='>'){

                string temp="";
                for (int j=i+1;j<len;j++)
                {
                    if (production[j]!=' ' && production[j]!='|'){
                        temp+=production[j];
                    }
                    else if (!temp.empty())
                    {
                        symbols.push_back(temp);
                        temp="";
                    }
                }
                if (!temp.empty()){
                    symbols.push_back(temp);
                }

                continue;
            }
        }
    }

    for (auto &a: symbols)
    {
        cout<<a<<endl;
    }

}