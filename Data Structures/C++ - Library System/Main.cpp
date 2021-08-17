#include <iostream>
#include "LibrarySystem.h"
using namespace std;

int main(int argc, char** argv)
{
    LibrarySystem lib(argv[1],argv[2]);
    lib.executeCommands();


}