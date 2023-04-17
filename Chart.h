#ifndef CHART_H
#define CHART_H

#include <string>
#include "Bar.h"
using namespace std;

class Chart
{
private:
    Bar *arrBar;
    int n;
    string title;
    int max_size;

public:
    // constructor (n is the size of the array).
    Chart(Bar bars[], int n, string title, int MAX_SIZE);

    // copy constructor
    Chart(const Chart &other);

    // destructor
    ~Chart();

    // sorts the bars in the chart in "descending" order based on their length.
    void sort();

    // displays the first m bars in the chart (i.e. in the bars array)
    // the caption is some descriptive text that appears below the chart.
    void display(string caption, int m) const;
};

#endif