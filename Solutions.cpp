
#include "Solutions.h"
/*
    Write an application that will ask the user for their name and output it to a file called
    name.txt.
 */
void question1()
{
    string name;
    cout << "Please enter your name: " <<endl;
    getline(cin, name);
    ofstream fout("name.txt");
    if(fout)
    {
        fout << name <<endl;
        fout.close();
    }
    else
    {
        cout << "error opening file." <<endl;
    }

}
/**
    Write an application that will read in the name from “name.txt” and display in a frame of
    stars. Refer to introductory exercises
 */
void question2()
{
    string name;
    ifstream fin("name.txt");
    if(fin)
    {
        getline(fin, name);
        string::size_type len = name.length();
        string top(len+4, '*');
        cout << top <<endl;
        cout << "* " << name << " *"<<endl;
        cout << top <<endl;
        fin.close();
    }
    else
    {
        cout << "error opening file." <<endl;
    }
}

/**
Write an application to read in a number of integers and find the average of these numbers.
Create a file called num.txt to use for this exercise
 */
void question3()
{
    int count=0;
    double total=0.0;
    double avg=0.0;
    double num;
    ifstream fin("nums.txt");
    if(fin)
    {
        while(!fin.eof())
        {
            fin >> num;
            total +=num;
            count++;
        }
        fin.close();
        avg = total/count;
        cout << "The average of these numbers is " << avg<<endl;
    }
    else
    {
        cout <<"Error opening file."<<endl;
    }
}
/*

    Write an application that will read in a students’ name followed by two marks (ints), one
    their final exam mark and one their CA mark and find the total grade. You can assume that
    the final exam is worth 60% and their CA is worth 40%. Output the students name and their
    final mark to a file called “Final Results.txt”.
 */
void question4()
{
    ifstream fin("Students.txt");
    ofstream fout("Final Results.txt");
    string temp;
    if(fin && fout)
    {
        while(!fin.eof())
        {
            string name;
            int ca, fe;
            getline(fin, name);
            fin >> ca;
            fin >> fe;
            getline(fin, temp);
            fout << name << endl;
            double finalResult = (ca*.4) + (fe*.6);
            fout << finalResult << endl;
        }
        fin.close();
        fout.close();
    }
    else
    {
        cout << "error opening file"<<endl;
    }
}
/**
Write an application that reads in a menu from the file menu.txt. Each item contains a
description on one line and its price on the line immediately following it. Then increase the
price of each item in line with the following rules and output the new menu (description plus
updated price) to the file new_menu.txt.
a. Items over €5.00 should increase by €1.50
b. Items under €5.00 should increase by €0.50
 */
void question5()
{
    ifstream fin("menu.txt");
    ofstream fout("new menu.txt");
    if(fin && fout)
    {
        string name;
        double price;
        string temp;
        while(!fin.eof())
        {
            getline(fin, name);
            fin >> price;
            getline(fin, temp);
            if(price < 5.00)
                price += 0.5;
            else
                price+=1.5;

            fout << name << endl;
            fout << price <<endl;
        }
        fin.close();
        fout.close();
    }
    else
    {
        cout << "Error opening file. " <<endl;
    }
}