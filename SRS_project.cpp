#include <bits/stdc++.h> 
#include <conio.h>
#include <windows.h>

using namespace std;

//Colouring Text with ANSI Escape colours
    const char *RESET = "\033[0m";
    //0=darker shade
    const char *BLACK  = "\033[0;30m";
    const char *RED  = "\033[0;31m";
    const char *GREEN = "\033[0;32m";
    const char *YELLOW= "\033[0;33m";
    const char *BLUE = "\033[0;34m";
    const char *MAGENTA = "\033[0;35m";
    const char *CYAN = "\033[0;36m";
    const char *WHITE  = "\033[0;37m";
    //1=Bright
    const char *B_BLACK= "\033[1;30m";
    const char *B_RED= "\033[1;31m";
    const char *B_GREEN = "\033[1;32m";
    const char *B_YELLOW = "\033[1;33m";
    const char *B_BLUE = "\033[1;34m";
    const char *B_MAGENTA = "\033[1;35m";
    const char *B_CYAN = "\033[1;36m";
    const char *B_WHITE = "\033[1;37m";

//---------------------------------Creating the position of the cursor----------------------------------------------
void set_position(int x,int y)
{
    COORD axis;
    axis.X= x;//for the column
    axis.Y= y;//row

    SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE),axis);
}

//-------------------------The main Game Function------------------------------------------------------------------
int main()
{

    //Cursor Hiding: It retrieves the current console cursor settings,
    //sets the bVisible flag within the cursorInfo structure to false,
    //and then applies the change. This hides the annoying blinking cursor from the user,
    //which would otherwise flicker intensely during the game's continuous redrawing.
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);



    //hides the annoying cursor
    cursorInfo.bVisible = true;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    return 0;
}
