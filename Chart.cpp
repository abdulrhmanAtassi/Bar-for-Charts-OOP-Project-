#include "Chart.h"
using namespace std;

Chart::Chart(Bar bars[], int n, string title, int MAX_SIZE)
{
    if (bars == NULL || n <= 0 || MAX_SIZE <= 0)
    {
        throw string("the one of the paramiters is empty or equal zero");
    }
    arrBar = new Bar[MAX_SIZE];
    for (int i = 0; i < n; i++)
    {
        arrBar[i] = bars[i];
    }

    this->n = n;
    this->max_size = MAX_SIZE;
    this->title = title;
}

// copy constructor
Chart::Chart(const Chart &other)
{

    this->arrBar = new Bar[other.max_size];
    for (int i = 0; i < other.max_size; i++)
    {
        arrBar[i] = other.arrBar[i];
    }
    this->n = other.n;
    this->max_size = other.max_size;
    this->title = other.title;
}

// destructor
Chart::~Chart()
{
    delete[] arrBar;
}

// sorts the bars in the chart in "descending" order based on their length.
void Chart::sort()
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arrBar[j].get_size() < arrBar[j + 1].get_size())
            {
                swap(arrBar[j], arrBar[j + 1]);
            }
        }
    }
    //
    for (int i = 0; i < 15; i++)
    {
        if (i < 15)
        {
            arrBar[i].set_color(i + 1);
        }
    }
}

void Chart::display(string caption, int m) const
{
    if (m <= 0)
    {
        throw string("ERROR");
    }

    cout << this->title << endl;
    cout << endl;

    float max = -111;
    for (int i = 0; i < m; i++)
    {
        if (this->arrBar[i].get_size() > max)
        {
            max = arrBar[i].get_size();
        }
    }

    float x = max_size / max;
    for (int i = 0; i < m; i++)
    {
        this->arrBar[i].show(x);
        cout << endl;
    }

    cout << caption << endl;
}