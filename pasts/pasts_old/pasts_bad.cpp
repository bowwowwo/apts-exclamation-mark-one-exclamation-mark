#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<sstream>
#include<cctype>
#include<algorithm>

using namespace std;

string pasts(string line);
vector<string> getWords(string line);

int main(){

    string fName = "post.in.txt";
    string line;

    ifstream fin(fName);
    ofstream fout("post.out.txt");

    if(!fin){
        cout << "nevar atvērt failu " << fName << endl;
        return 1;
    }

    while (getline(fin, line)) {
        fout << pasts(line) << endl;
    }

    fin.close();
    fout.close();

}

string pasts(string line){
    string res;
    vector<string> v = getWords(line);
    map<char, vector<string>> m;

    char letter;

    for (auto i : v) {
        for (char &c : i) {
            c = tolower(c);
        }
      	letter = i[0];
      	m[letter].push_back(i);
    }

    for (auto& pair : m) {
        char key = pair.first;
        std::vector<std::string>& vec = pair.second;

        reverse(vec.begin(), vec.end());
    }

    for (auto it = m.begin(); it != m.end(); ++it){
        vector<string> v1 = it->second;

        for (auto s : v1) {
            res += s + " ";
        }

    }

    return res;
}

vector<string> getWords(string line) {

    stringstream ss(line);
    string word;
    vector<string> words;

    while (getline(ss, word, ' ')) {
        words.push_back(word);
    }

    return words;
}
