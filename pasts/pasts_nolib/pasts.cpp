#include<fstream>
#include<iostream>

using namespace std;

class pastins{
struct node {
    char letter;
    string* input;
    node *next;
    node *prev;
    node(int val) : data(val), next(nullptr), prev(nullptr) {}
};
string* arr;

public:
    pastins();
    ~pastins(){
        delete [] arr;
    }
    void CreateArray(string line){
        arrSize = getWordNr(line);
        arr = new string[arrSize];

        string word = "";
        int index = 0;

        for (char ch : line) {
            if (ch != ' ') {
                word += ch;
            } else {
                if (!word.empty()) {
                    arr[index++] = word;
                    word = "";
                }
            }
        }
        if (!word.empty()) {
            arr[index++] = word;
    }
    }
    string tolower(string s){
        int val = 'a' - 'A';
        for(char& c : s){
            if(c >= 'A' && c <= 'Z'){
                c+=val;
            }
        }
        return s;
    }
    char getFirstChar(string s){
        return s[0];
    }
    int getWordNr(string line){
        int count = 0;
        bool inWord = false;

        for (char ch : line) {
            if (ch != ' ') {
                if (!inWord) {
                    count++;
                    inWord = true;
                }
            } else {
                inWord = false;
            }
        }
        return count;
    }
    void charLinkedList(){
        string prev = "";
        char c;
        if
        for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
            c = getFirstChar(arr[i]);
            for(char d : prev) if(d == c) continue;

            //create nodes for each new char

            prev += c;
        }
    }
    string* sortAlphabet();
    string* formatOutput();
};


int main(){

    pastins p;

    string fName = "post.in.txt";
    string line;

    ifstream fin(fName);
    ofstream fout("post.out.txt");

    if(!fin){
        cout << "nevar atvērt failu " << fName << endl;
        return 1;
    }

    while (getline(fin, line)) {
        fout << p.CreateInput(line) << endl;
    }

    fin.close();
    fout.close();

}
