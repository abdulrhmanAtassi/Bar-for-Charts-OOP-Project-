#include <iostream>
#include "Bar.h"
using namespace std;

Bar::Bar(int size, string text, int color)
{
    this->size = size;
    this->text = text;
    this->color = color;
}

// getters

int Bar::get_size() const { return this->size; }
string Bar::get_text() const { return this->text; }
int Bar::get_color() const { return this->color; }

// setters
void Bar::set_size(int size) { this->size = size; }
void Bar::set_text(string text) { this->text = text; }
void Bar::set_color(int color) { this->color = color; }

void Bar::show(float factor) const
{
    string space = "";
    for (int i = 0; i < this->size * factor; i++)
    {
        space += " ";
    }

    print(this->color, space);
    cout << this->text << "(" << this->size << ")" << endl;
}