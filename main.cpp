#include <iostream>
#include <string.h>
#include "MarsProject.h"

using namespace std;
int main(int argc, char *argv[])
{
    string a(argv[1]);
    if (a == string("1"))
    {
        task1();
    }
    else if (a == string("2"))
    {
        task2();
    }
    else if (a == string("3a"))
    {
        task3a();
    }
    else if (a == string("3b"))
    {
        task3b();
    }
    else if (a == string("4"))
    {
        task4();
    }
    else if (a == string("5"))
    {
        task5();
    }
    else if (a == string("6"))
    {
        task6();
    }
    return 0;
}