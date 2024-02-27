#include <iostream>
#include <map>
#include "Solutions.h"
using namespace std;
typedef void (*func)();

int main() {
    map<int, func> questions;
    questions[1] = question1;
    questions[2] = question2;
    questions[3] = question3;
    questions[4] = question4;
    questions[5] = question5;

    int choice = 0;
    string temp;
    do {
        cout << "Please enter question number to run, -1 to end"<<endl;
        cin >> choice;
        getline(cin, temp);
        cout << endl;
        if(questions.count(choice))
        {
            questions[choice]();
        }
        else if(choice!=-1)
        {
            cout << "invalid input."<<endl;
        }
        cout << "\n\n\n";
    }while(choice!=-1);




    return 0;
}
