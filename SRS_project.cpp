#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>

//to fix the issue of using cin and getline
#include <limits>
using std::numeric_limits;
using std::streamsize;

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
void set_position(int x,int y) {
    COORD axis;
    axis.X= x;//for the column
    axis.Y= y;//row

    SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE),axis);
}

//----------------------------------------------Just for Fun--------------------------------------------------------
void loading_screen() {

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

//----------------------------------------Struct to store the data--------------------------------------------------
struct account_info {
    string account_number;
    string account_name;
    double opening_balance;
    double transaction_amounts[3];
};

//structs ints
    int max_info=110;
    account_info accounts_info[110];
    //to count the number of accounts added
    int account_counter=0;
;

/*Load Records: Read existing bank account records from accounts.txt into memory.*/
void load_Records() {
    system("cls");
    ifstream file("accounts.txt");

    if (!file)
    {
        set_position(20,3);
        cout<<RED << "Add & Save Records before loading them"<<RESET;
        _getch();
        return;
    }

    account_counter = 0;
    while (file >> accounts_info[account_counter].account_number)
    {
        file.ignore();
        getline(file, accounts_info[account_counter].account_name);
        file >> accounts_info[account_counter].opening_balance;

        for (int i = 0; i < 3; i++)
            file >> accounts_info[account_counter].transaction_amounts[i];

        account_counter++;
    }    
    file.close();

    set_position(42,11);
        cout <<GREEN<<"Account Records Loaded Successfully!!";
    
    set_position(62,27);
        cout <<RESET<<"Press any button on the keyboard to return to main menu"<<RESET;
    _getch();
}

/*Save Records: Write all current bank account records from memory to accounts.txt.*/
void save_records() {
    system("cls");
    ofstream file("accounts.txt");

    if (!file.is_open())
    {
        set_position(20,3);
            cout<<RED<<"Failed to open file to save!!"<<RESET;
            _getch();
            return;
    }
    
    for (int i=0;i<account_counter;i++)
    {
        file << accounts_info[i].account_number << "\n";
        file << accounts_info[i].account_name << "\n";
        file << accounts_info[i].opening_balance << "\n";
        
        for (int j=0;j<3;j++)
        {
            file << accounts_info[i].transaction_amounts[j] << " ";
        }
        file <<"\n";
    }

    file.close();
    set_position(42,11);
        cout <<GREEN<<"You have saved your records!"<<RESET;
    
    set_position(62,27);
        cout <<RESET<<"Press any button on the keyboard to return to main menu"<<RESET;
    _getch();
    return;


}

void add_new_accounts() {
    /*Add New Account: Prompt for account number, holder name, opening balance,
    and 3 transaction amounts, then add to the records.*/
    system("cls");

    if (account_counter>=max_info)
    {
        cout <<RED<<"You can not add anymore."<<RESET;
        _getch();
        return;
    }

    account_info &fileData =accounts_info[account_counter];

    set_position(20,3);
        cout<<CYAN<<"======================Add New Account======================"<<RESET;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');//to clear buffer
    set_position(20,4);
        cout <<"Enter your account name: ";
        getline(cin, fileData.account_name);

    set_position(20,5);
        cout <<"Enter your account number: ";
        cin >>fileData.account_number;

    set_position(20,6);
        cout <<"Enter opening balance: ";
        cin >>fileData.opening_balance;

    set_position(20,7);
        cout <<"Enter 3 transaction amounts: ";
        for (int i=0;i<3;i++)
        {
            set_position(20,8+i);
            cout <<"Transaction no "<<i+1<<": ";
            cin >>fileData.transaction_amounts[i];
        }
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    account_counter++;

    system("cls");
    set_position(25,8);
        cout <<GREEN<<"You have successfully added the accounts!!"<<RESET;


    set_position(60,27);
        cout<<"Press any button on the keyboard to return to main menu"<<RESET;

    _getch();

    system("cls");
}

/*View All Accounts: Display details (Account Number, Holder Name,
Opening Balance, and all 3 Transaction Amounts) for all registered accounts.*/
void view_all__accounts(){
    system("cls");

    if (account_counter==0)
    {
        set_position(42,11);
            cout <<RED<<"Failed! Add accounts first to view added accounts!"<<RESET;
        
        _getch();
    }
    
    int row=10; 
    for (int i=0;i<account_counter;i++)
    {   
        
        set_position(30,row++);
            cout << B_BLUE<<"=======================Added Accounts=======================\n"<<RESET;
        
        set_position(42,row++);
            cout <<"Account Number: "<<accounts_info[i].account_number<<"\n";
        
        set_position(42,row++);
            cout <<"Account Name: "<<accounts_info[i].account_name<<"\n";

        set_position(42,row++);
            cout <<"Account's Opening Balance: "<<YELLOW<<accounts_info[i].opening_balance<<RESET<<"\n";
        
        for (int j=0 ;j<3;j++)
        {
            set_position(42,row++);
            cout <<"Transaction no "<<j+1 <<": "<<YELLOW<<accounts_info[i].transaction_amounts[j]<<RESET<<endl;
        }
        
    }

    _getch();
}
/*Search Account: Prompt for an Account Number and display that account's
details if found.*/
void search_account() {
    system("cls");
    string s; //s-->Account number
    
    set_position(30,9);
        cout <<B_BLUE <<"======================Search Section======================\n"<<RESET;

    set_position(42,10);
        cout <<"Enter your account number: ";
        cin >> s;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    int row=11;
    for (int i=0;i<account_counter;i++)
    {
        if (accounts_info[i].account_number == s)
        {
            set_position(42,row++);
                cout <<"Search Results: \n";

            set_position(42,row++);
                cout << "Account Number: "<<accounts_info[i].account_number<<"\n";

            set_position(42,row++);
                cout <<"Account Name: "<<accounts_info[i].account_name<<"\n";

            set_position(42,row++);
                cout  <<"Account's Opening Balance: "<<YELLOW<<accounts_info[i].opening_balance<<RESET<<"\n";

            set_position(42,row++);
                cout <<"3 Transactions: \n";

            for (int j=0 ;j<3;j++)
            {
            set_position(42,row++);
                    cout <<"Transaction no "<<j+1 <<": "<<YELLOW<<accounts_info[i].transaction_amounts[j]<<RESET<<"\n";
            }
            set_position(62,27);
                cout <<B_WHITE<<"Press any button on the keyboard to return to main menu"<<RESET;
            
            _getch();
            return;
        }
    }

    //else
    set_position(42,11);
        cout<<RED <<"No results containing all your search terms were found."<<RESET;
    set_position(62,27);
        cout <<RESET<<"Press any button on the keyboard to return to main menu"<<RESET;
    _getch();
    
}

/*Calculate Current Balance: For each account, calculate and display
 its current balance (opening balance + sum of transaction_amounts).*/
void calculate_current_balance() {
    system("cls");
    if(account_counter==0)
    {
        set_position(42,11);
            cout <<RED<<"Failed! Add accounts to calculate!"<<RESET;
        set_position(62,27);
            cout <<RESET<<"Press any button on the keyboard to return to main menu"<<RESET;
        _getch();
        return;
    }

    set_position(30,8);
        cout<<B_YELLOW<<"==============Current Account Balance=============="<<RESET;
    int row=10; 

    for (int i=0;i<account_counter;i++)
    {
        double sum =accounts_info[i].opening_balance;

        for (int j=0;j<3;j++)
            sum+= accounts_info[i].transaction_amounts[j];

        set_position(42,row++);
            cout <<"Account Number: "<<accounts_info[i].account_number;
        set_position(42,row++);
            cout <<"Account Name: "<<accounts_info[i].account_name;
        
        //Total Balance
        set_position(42,row++);
            cout <<"Your Current Balance is: "<<YELLOW<<sum<<RESET;

        row++;
    }

    _getch();
}

int main_menu() {
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
int main() {
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
