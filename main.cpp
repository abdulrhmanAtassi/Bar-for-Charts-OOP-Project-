// ##############################################################
// **************************************************************
// Make sure to read the comment below before executing the code.
// **************************************************************
// ##############################################################
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Bar.h"
#include "Chart.h"
#include <fstream>
// For Replit and Mac/Unix users, keep this line as is. However, if you are using Windows, replace "<unistd.h>" with "<windows.h>".
#include <unistd.h>
using namespace std;

int main()
{
    ifstream fin;
    string file;
    cin >> file;
    file += ".txt";
    fin.open(file);

    string title;
    int n;
    fin >> title;
    while (fin >> n)
    {
        string cap;
        Bar *arrOfBars = new Bar[n];
        for (int i = 0; i < n; i++)
        {
            cap = "";
            fin >> cap;
            string x;
            int size;
            fin >> x;
            fin >> size;
            arrOfBars[i].set_size(size);
            arrOfBars[i].set_text(x);
        }

        Chart *citie = new Chart(arrOfBars, n, title, n);

        system("clear");
        citie->sort();

        citie->display(cap, 10);
        // For Replit and Mac/Unix users, keep this line as is. However, if you are using Windows, replace "usleep" with "Sleep".
        usleep(50000);
    }
}