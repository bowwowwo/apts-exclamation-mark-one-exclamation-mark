#include<fstream>
#include<iostream>

using namespace std;

class pastins{
    struct node {
        char letter;
        string* input;
        int arrLength;
        node *next;
        node(char val, string* val2, int val3) : letter(val), input(val2), arrLength(val3), next(nullptr) {}

        ~node() {
            delete[] input;
        }
    };
    string* arr;
    int arrSize;
    node* head;

    public:
        pastins(){
            arr = nullptr;
            arrSize = 0;
            head = nullptr;
        }
        ~pastins(){
            delete [] arr;
            deleteLlist();

        }
        void CreateArray(string line){
            arrSize = getWordNr(line);
            if(arrSize == 0) return;
            arr = new string[arrSize];

            string word = "";
            int index = 0;

            for (char ch : line) {
                if(ch != ' ' && ch != '\t' && ch != '\r')  {
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
                if (ch != ' ' && ch != '\t' && ch != '\r') {
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

            deleteLlist();
            head = nullptr;
            node* last = nullptr;

            for (int i = 0; i < arrSize; i++) {
                c = getFirstChar(tolower(arr[i]));
                cout << "creating node for char: " << c << endl;

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
                for(int j = 0; j < arrSize; j++){
                    if (c == getFirstChar(tolower(arr[j]))) {
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
                    last = p;
                }

                prev += c;
            }
        }
        int countArraywords(char c){
            int count = 0;
            char c1;
            for(int i = 0; i < arrSize; i++){
                c1 = getFirstChar(arr[i]);
                if(c == c1) count ++;
            }

            return count;
        }



        void callAll(string line){
            CreateArray(line);
            charLinkedList();
            head = sortAlphabet(head);
            reverseArray();
        }
        string formatOutput(string line){
            callAll(line);

            string newLine = "";
            node* p = head;

            while (p != nullptr) {
                for (int i = 0; i < p->arrLength; i++) {
                    newLine += p->input[i] + " ";
                }
                p = p->next;
            }

            if (!newLine.empty())
                newLine.pop_back();

            return newLine;
        }

        void reverseArray(){
            node* p = head;

            while (p != nullptr) {
                string* arr2 = new string[p->arrLength];
                for (int i = 0, j = p->arrLength - 1; i < p->arrLength; i++, j--) {
                    arr2[i] = p->input[j];
                }

                delete[] p->input;
                p->input = arr2;

                p = p->next;
            }

        }

        node* sortAlphabet(node* pp){
            /// merge sort mans milotais
            if (pp == nullptr || pp->next == nullptr) return pp;

            node *second = split(pp);

            pp = sortAlphabet(pp);
            second = sortAlphabet(second);

            return merge(pp, second);
        }

        //merge sort
        node* split(node* pp){
            node* fast = pp;
            node* slow = pp;
            while (fast != nullptr && fast->next != nullptr) {
                fast = fast->next->next;
                if (fast != nullptr) {
                    slow = slow->next;
                }
            }
            node* temp = slow->next;
            slow->next = nullptr;
            return temp;
        }
        node* merge(node* first, node* second){
            if (!first) return second;
            if (!second) return first;

            node* result = nullptr;

            if (first->letter < second->letter) {
                result = first;
                result->next = merge(first->next, second);
            } else {
                result = second;
                result->next = merge(first, second->next);
            }

            return result;
        }

        //atmina
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

    pastins p;

    string fName = "post.in.txt";
    string line;

    ifstream fin(fName);
    ofstream fout("post.out.txt");

    if(!fin){
        cout << "nevar atvērt failu " << fName << endl;
        return 1;
    }

    if (!getline(fin, line)) {
        fout << "nothing" << endl;
        return 0;
    }

    while (getline(fin, line)) {
        fout << p.formatOutput(line) << endl;
    }

    fin.close();
    fout.close();

}
