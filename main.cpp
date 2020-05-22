#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <set>
using namespace std;


int main() {
    map<string, pair<vector<string>, vector<int> > > dict;
    vector<string> names, repls;
    vector<int> nums;
    string s, name, repl, filename_in, filename_out;
    ifstream fin;
    ofstream fout;

    //cout << "Enter the input file path:\n";
    //cin >> filename_in;
    //cout << "Enter the output file path:\n";
    //cin >> filename_out;

    fin.open("input.txt");
    fout.open("output.txt");//, ios_base::trunc);

    getline(fin, s);
    getline(fin,s); // пропускаем строчку roles:
    while (s != "textLines:") {
        names.push_back(s);
        getline(fin,s);
    }
    int num = 1;
    int i = 0;
    while (getline(fin, s)){
        name = "";
        repl = "";
        while (s[i] != ':'){ // получаем имя
            name += s[i];
            i++;
        }
        i ++; // пропускаем пробел после двоеточия
        while (i < s.size()){ // получаем реплику
            repl += s[i];
            i ++;
        }
        i = 0;
        // заносим реплику в map и ее номер для определенного чела
        dict[name].first.push_back(repl);
        dict[name].second.push_back(num);
        num++;
    }
    // выписываем реплики для всех имен из roles, если реплик нет – ничего не выведется
    for (vector<string>::iterator it = names.begin(); it != names.end(); it++){
        repls = dict[*it].first;
        nums = dict[*it].second;
        fout << *it << '\n';
        for (int j = 0; j < repls.size(); ++j) {
            fout << nums[j] << ") " << repls[j] << '\n';
        }
        fout << '\n';
    }
    fin.close();
    fout.close();
    return 0;
}
