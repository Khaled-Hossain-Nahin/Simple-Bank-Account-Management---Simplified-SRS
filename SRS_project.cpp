#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>

using namespace std;

//Coloring Text with ANSCII Esacpe colors
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

bool Program_running=true;

//---------------------------------Creating the position of the cursor----------------------------------------------
void set_position(int x,int y)
{
    COORD axis;
    axis.X= x;//for the column
    axis.Y= y;//row

    SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE),axis);
}
void loading_screen()
{
    system("cls");

    set_position(35,6);
    cout <<"          Welcome to Mugdha Bank LTD.";

    set_position(67,27);
    cout<<"Please wait while the system is loading . . .\n";

    set_position(35,7);
    for(int i=1; i<=50; i++)
    {
        Sleep(29);
        cout <<B_GREEN;
        printf("%c",219);
        cout<<RESET;
    }

    system("cls");
}

struct account_info
{
    string account_number;
    string account_name;
    double opening_balance;
    double transaction_amounts[3];
};
int max_info=110;
account_info accounts_info[max_info];

//to count the number of accounts added
int account_counter=0;


void load_Records() {
    system("cls");
    ifstream file("accounts.txt");


    if (!file.is_open())
    {
        set_position(20,3);
        cout<<RED << "Add & Save Records before loading them"<<RESET;
        _getch();
        return;
    }

    account_counter = 0;
    while (1)
    {
        account_info file_data;

        if (!(file >> file_data.account_number))
            break; 
        file.ignore();  //to ignore \n

       
        file.getline(file_data.account_name, 109);
        
        
        file >> file_data.opening_balance;
        
        for (int i = 0; i < 3; i++)
            file >> file_data.transaction_amounts[i];

        // add record to array
        accounts_info[account_counter++] = file_data;
    }

    file.close();
    
    set_position(67,27);
        cout <<RED<<"Press any button on the keyboard to return to main menu"<<RESET;

    _getch();


}

void save_records() {
    /*Save Records: Write all current bank account records from memory to accounts.txt.*/
}

void add_new_accounts()
{
    /*Add New Account: Prompt for account number, holder name, opening balance, 
    and 3 transaction amounts, then add to the records.*/
    system("cls");
    
    if (account_counter>=max_info)
    {
        cout <<RED<<"You can not add anymore."<<RESET;
        _getch();
        return;
    }
    
    account_info &file_data =accounts_info[account_counter];
    
    set_position(20,3);
        cout<<CYAN<<"======================Add New Account======================"<<RESET;
    
    
    set_position(20,4);
        cout <<"Enter your account name: ";
        getline(cin, file_data.account_name);
        
    cin.ignore();
    set_position(20,5);
        cout <<"Enter your account number: ";
        cin >>file_data.account_number;
    
    set_position(20,6);
        cout <<"Enter opening balance: ";
        cin >>file_data.opening_balance;

    set_position(20,7);
        cout <<"Enter 3 transaction amounts: ";
        for (int i=0;i<3;i++)
            cin >>file_data.transaction_amounts[i];
    account_counter++;
    
    set_position(20,8);
        cout <<GREEN<<"You have successfully added the accounts!!"<<RESET;

    
    set_position(67,27);
        cout <<RED<<"Press any button on the keyboard to return to main menu"<<RESET;

    _getch();   

    system("cls");
}

void view_all__accounts()
{
    /*View All Accounts: Display details (Account Number, Holder Name, 
    Opening Balance, and all 3 Transaction Amounts) for all registered accounts.*/
}

void search_account()
{
    /*Search Account: Prompt for an Account Number and display that account's 
    details if found.*/
}


void calculate_current_balance()
{
    /*Calculate Current Balance: For each account, calculate and display 
    its current balance (opening balance + sum of transaction_amounts).*/
}

int main_menu()
{
    system("cls");
    int button =1;
    while(true)
    {
        system("cls");

        set_position(20,4);
        cout<<B_CYAN;
        cout<<"======================Thanks for chosing Mugdha Bank Ltd.======================"<<RESET;
        set_position(48,7);
        cout << "Manage your accounts";

        set_position(48,8);
        if (button==1)
            cout <<B_BLUE <<"1."<<RESET<<"Load Records"<<RED<<"<--"<<RESET;
        else
            cout <<B_BLUE<<"1."<<RESET<<"Load Records";

        set_position(48,9);
        if (button==2)
            cout <<B_BLUE<<"2."<<RESET<<"Save Records"<<B_RED<<"<--"<<RESET;
        else
            cout <<B_BLUE<<"2."<<RESET<<"Save Records";

        set_position(48,10);
        if (button==3)
            cout <<B_BLUE<<"3."<<RESET<<"Add New Account"<<B_RED<<"<--"<<RESET;
        else
            cout <<B_BLUE<<"3."<<RESET<<"Add New Account";

        set_position(48,11);
        if (button==4)
            cout <<B_BLUE<<"4."<<RESET<<"View All Accounts"<<B_RED<<"<--"<<RESET;
        else
            cout <<B_BLUE<<"4."<<RESET<<"View All Accounts";

        set_position(48,12);
        if (button==5)
            cout <<B_BLUE<<"5."<<RESET<<"Search Account"<<B_RED<<"<--"<<RESET;
        else
            cout <<B_BLUE<<"5."<<RESET<<"Search Account";

        set_position(48,13);
        if (button==6)
            cout <<B_BLUE<<"6."<<RESET<<"Calculate Current Balance"<<B_RED<<"<--"<<RESET;
        else
            cout <<B_BLUE<<"6."<<RESET<<"Calculate Current Balance";

        set_position(48,14);
        if (button==7)
            cout <<B_BLUE<<"7."<<RESET<<"Exit Program"<<B_RED<<"<--"<<RESET;
        else
            cout <<B_BLUE<<"7."<<RESET<<"Exit Program";

        //Reads a Key from the keyboard
        char key = _getch();
        if(key=='1') return 1;
        if(key=='2') return 2;
        if(key=='3') return 3;
        if(key=='4') return 4;
        if(key=='5') return 5;
        if(key=='6') return 6;
        if(key=='7') return 7;

        if (key == 'w' || key == 'W')
        {
            if (button ==1) button = 7;
            else button--;
        }

        else if (key == 's' || key == 'S')
        {
            if (button ==7) button = 1;
            else button++;
        }

        //key 13 is equal to pressing Enter on keyboard and  other character is space
        else if (key==13 || key == ' ') return button;
    }
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

    system("cls");
    loading_screen();
    int choice = 1;

    while (1)
    {
        choice = main_menu();
        if (choice ==1 )
        {
            Program_running=true;
            load_Records();
        }

        else if (choice ==2)
        {
            save_records();
        }

        else if (choice ==3)
        {
            add_new_accounts();
        }

        else if (choice ==4)
        {
            view_all__accounts();
        }

        else if (choice ==5)
        {
            search_account();
        }

        else if (choice==6)
        {
            calculate_current_balance();
        }

        else if (choice==7)
        {
            break;
        }

    }
    return 0;
}
