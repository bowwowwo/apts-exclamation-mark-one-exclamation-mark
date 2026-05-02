#include<fstream>
#include<iostream>

using namespace std;

class pastins{
struct node {
    char letter;
    string* input;
    int arrLength;
    node *next;
    node *prev;
    node(int val, string* val2, int val3) : letter(val), input(val2), arrLength(val3), next(nullptr), prev(nullptr) {}

    ~node() {
        delete[] input;
    }
};
string* arr;
node* head;
node* tail;

public:
    pastins();
    ~pastins(){
        delete [] arr;
        deleteLlist();

    }
    void CreateArray(string line){
        int arrSize = getWordNr(line);
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
    void charLinkedList() {
        string prev = "";
        char c;
        int count;
        string* arr2;

        head = nullptr;
        node* last = nullptr;

        for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
            c = getFirstChar(arr[i]);

            bool exists = false;
            for (char d : prev) {
                if (d == c) {
                    exists = true;
                    break;
                }
            }

            if (exists) continue;

            count = countArraywords(c);
            arr2 = new string[count];

            int k = 0;
            for(int j = 0; j < sizeof(arr)/sizeof(arr[0]); j++){
                if(c == getFirstChar(arr[j])){
                    arr2[k] = arr[j];
                    k++;
                }
            }


            node* p = new node(c, arr2, count);

            if (head == nullptr) {
                head = last = p;
            }
            else {
                last->next = p;
                p->prev = last;
                last = p;
            }

            prev += c;
        }
    }
    int countArraywords(char c){
        int count = 0;
        char c1;
        for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
            c1 = getFirstChar(arr[i]);
            if(c == c1) count ++;
        }

        return count;
    }

    string* sortAlphabet();
    string* formatOutput();

    void deleteLlist(){
        node* current = head;

        while (current != nullptr) {
            node* temp = current;
            current = current->next;
            delete temp;
        }

        head = nullptr;
    }
};


int main(){

    string fName = "post.in.txt";
    string line;

    ifstream fin(fName);
    ofstream fout("post.out.txt");

    if(!fin){
        cout << "nevar atvērt failu " << fName << endl;
        return 1;
    }

    //while (getline(fin, line)) {
       // fout << (line) << endl;
    //}

    fin.close();
    fout.close();

}
