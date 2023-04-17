#ifndef BAR_H
#define BAR_H

#include <string>
#include "colors.h"
using namespace std;

class Bar
{
private:
    int size;
    string text;
    int color;

public:
    Bar(int = 1, string = "", int = DARK_GREEN);
    // getters
    int get_size() const;
    string get_text() const;
    int get_color() const;

    // setters
    void set_size(int);
    void set_text(string);
    void set_color(int);

    // shows the bar to the screen after scaling it using "factor"
    void show(float = 1.0) const;
};
#endif