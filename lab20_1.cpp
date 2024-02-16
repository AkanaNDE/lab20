#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}


void importDataFromFile(string a, vector<string> &x,vector<int> &y,vector<char> &z){
char format[] = "%[^:]:%d %d %d";
string line;
char name[100];
char grade;
int score,score1,score2,score3;
ifstream file(a);
while (getline (file,line)){
const char *line2 = line.c_str();
sscanf(line2,format,name,&score1,&score2,&score3);
score = score1+score2+score3;
grade = score2grade(score);
x.push_back(name);
y.push_back(score);
z.push_back(grade);

}

}

void getCommand(string &command, string &key){
cout << "Please input your command: ";
cin >> command;
if(toUpperStr (command) == "GRADE" || toUpperStr (command) == "NAME"){
cin.ignore();
getline(cin ,key);
}

}

void searchName(const vector<string>& names, const vector<int>& scores, const vector<char>& grades, const string& key){
bool found = false;
    for(unsigned i = 0; i < names.size(); i++){
        if(toUpperStr(names[i]) == toUpperStr(key)){
            found = true;
            cout << "---------------------------------\n";
            cout << names[i] << "'s score = " << scores[i] << endl;
            cout << names[i] << "'s grade = " << grades[i] << endl;
            cout << "---------------------------------\n";
        }
    }
    if(!found){
        cout << "---------------------------------\n";
        cout << "Cannot found.\n";
        cout << "---------------------------------\n";
    }
}

void searchGrade(const vector<string>& names, const vector<int>& scores, const vector<char>& grades, const string& key) {
    bool found = false;
    cout << "---------------------------------\n";
    for (unsigned i = 0; i < names.size(); ++i) {
        if (grades[i] == key[0]) {
            found = true;
            cout << names[i] << " (" << scores[i] << ")\n";
        }
    }
    if (!found) {
        cout << "Cannot found.\n";

    }
    cout << "---------------------------------\n";
}


int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}