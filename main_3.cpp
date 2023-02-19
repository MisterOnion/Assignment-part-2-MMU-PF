// *********************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: TT7L
// Names: Lim Sir Yuean | HARRISH NAIR A/L RAMESH | Meor Imran Najmuddin
// IDs: 1211307746 | 1211103981 | 1211101518
// Emails: 1211307746@student.mmu.edu.my | 1211103981@student.mmu.edu.my | 1211101518@student.mmu.edu.my
// Phones: 01113070602 | 0163381763 | 0177699497
// *********************************************************

// TODO: Making the Alien move and interact with the object characters we put in for part 2

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>  // for system()
#include <ctime>    // for time()
#include <iomanip>  // for setw()
#include <fstream>  //for game save
#include <unistd.h> // for system pause
using namespace std;

// not functional atm
/*
void Save()
{
    // variables
    ifstream iFile; // input file
    ofstream oFile; // output file
                    // Open input file
    iFile.open("alienVSzombie.txt");
    if (!iFile.is_open())
    {
        cout << "Error opening input file!\n";
    }
    // Open output file
    oFile.open("alienVSzombie.txt");
    if (!oFile.is_open())
    {
        cout << "Error opening output file!\n";
    }

    // Read from input file
    int i_fromFile = 0;
    while (iFile >> i_fromFile)
    {
        // pull the txt.save file
        oFile << i_fromFile << endl;
    }

}
*/

/* stand by
class alien()
{
public:
private:
}

class pod()
{
    public:
    private:
}

class board()
{
    public:
    private:
}
*/

void alienStats()
{
    int life = 100;
    // int attack = pod

    cout << "#====================================#" << endl;
    cout << "Alien => " << setw(12) << "Health => " << life << endl;
}

/*
void zombieStat()
{
    int points[] = {'1', '2', '3', '4', '5'};

    int numofHealth = 5;
    int no = rand() % numofHealth;
    board[i][j] = points[no];
}
*/

// CHANGE SETTINGS
void changeSettings(int &x_axis, int &y_axis, int &zombie)
{
    system("CLS");

    cout << "|*****************************************| " << endl;
    cout << "|              Board Settings             |" << endl;
    cout << "|*****************************************|" << endl;
    cout << endl;
    cout << " Please enter odd numbers only. " << endl;
    cout << " Enter number of board rows     =>  ";
    cin >> x_axis;

    // Check if the x-axis dimension is an odd number
    while (x_axis % 2 == 0)
    {
        cout << "Please enter odd numbers only." << endl;
        cout << "Enter number of rows: ";
        cin >> x_axis;
    }

    cout << " Enter number of board columns  =>  ";
    cin >> y_axis;

    // Check if the y-axis dimension is an odd number
    while (y_axis % 2 == 0)
    {
        cout << "Please enter odd numbers only." << endl;
        cout << "Enter number of columns: ";
        cin >> y_axis;
    }

    cout << "|*****************************************|" << endl;
    cout << "|             Zombies Settings            |" << endl;
    cout << "|*****************************************|" << endl;
    cout << " Enter number of zombies (maximum 5)   =>  ";
    cin >> zombie;
    if (zombie > 5)
    {
        cout << "maximum zombies allowed is 5" << endl;
        sleep(1);
        changeSettings(x_axis, y_axis, zombie);
    }
    else
    {
        cout << endl;
        cout << " Settings Updated." << endl;
        sleep(1);
    }
}

// BOARD CREATION
void createBoard(int x_axis, int y_axis, int zombie)
{
    system("CLS");

    char characters[] = {' ', '^', 'v', '>', '<', 'h', 'p', 'r', ' '};

    cout << "################################" << endl;
    cout << " ...::: Alien vs Zombie :::... " << endl;
    cout << "################################" << endl;
    char board[x_axis][y_axis];

    int numofobject = 9;
    for (int i = 0; i < x_axis; i++)
    {
        for (int j = 0; j < y_axis; j++)
        {
            int no = rand() % numofobject;
            board[i][j] = characters[no];
        }
    }

    // Place the Alien at the center of the game board
    int centerRow = x_axis / 2;
    int centerCol = y_axis / 2;
    board[centerRow][centerCol] = 'A';

    if (x_axis >= 10 || y_axis >= 10)
    {
        cout << " ";
        for (int i = 1; i <= y_axis; i++) //+1
        {
            cout << i % 10 << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < x_axis; i++)
    {
        cout << " ";
        for (int j = 0; j < y_axis; ++j)
        {
            cout << "+-";
        }
        cout << "+" << endl;
        // display row number
        cout << setw(2) << (y_axis - i);
        // display the border
        for (int j = 0; j < y_axis; ++j)
        {
            cout << "|" << board[i][j];
        }
        cout << "|" << endl;
    }

    alienStats();
}

// DEFAULT SETTINGS

void displayMainMenu(int x_axis, int y_axis, int zombie)
{

    system("CLS");

    char answer;
    cout << " __________________________________________" << endl;
    cout << "|          Default Game Settings          |" << endl;
    cout << "|_________________________________________|" << endl;
    cout << "|                                         |" << endl;
    cout << "|   Number of Board Rows     =>  " << x_axis << "        |" << endl;
    cout << "|   Number of Board Columns  =>  " << y_axis << "        |" << endl;
    cout << "|   Number of Zombies        =>  " << zombie << "        |" << endl;
    cout << "|_________________________________________|" << endl;
    cout << endl;
    cout << " Do you want to change the settings? (y/n) or press h for help => ";
    cin >> answer;
    answer = toupper(answer);
    if (answer == 'Y')
    {
        changeSettings(x_axis, y_axis, zombie);
        displayMainMenu(x_axis, y_axis, zombie);
    }
    else if (answer == 'N')
    {
        cout << "Let's play" << endl;
        sleep(1);
    }
    else if (answer == 'H')
    {
        system("CLS");

        char back;
        cout << " ..::Command list prompt::.. " << endl;
        cout << "       up   = move up " << endl;
        cout << "      down  = move down" << endl;
        cout << "      left  = move left" << endl;
        cout << "      right = move down" << endl;
        cout << "      quit  = close program" << endl;
        cout << endl;
        cout << endl;
        cout << "Press R to return to main menu" << endl;
        cin >> back;
        if (char back = 'r')
        {
            displayMainMenu(x_axis, y_axis, zombie);
        }
    }
    else
    {
        cout << "Input Error!" << endl;
        cout << endl;
        displayMainMenu(x_axis, y_axis, zombie);
    }
}

// BOARD CREATION (for alien movement)
void createBoard(int x_axis, int y_axis, int zombie, int x, int y)
{
    system("CLS");

    char characters[] = {' ', '^', 'v', '>', '<', 'h', 'p', 'r', ' '};
    int xx = 0;
    int yy = 0;

    char board[x_axis][y_axis];

    int numofobject = 9;
    for (int i = 0; i < x_axis; i++)
    {
        for (int j = 0; j < y_axis; j++) // random object generator
        {
            int no = rand() % numofobject;
            board[i][j] = characters[no];
        }
    }

    // Place the Alien at the center of the game board
    int centerRow = x_axis / 2;
    int centerCol = y_axis / 2;

    while (true)
    {
        system("CLS");
        cout << "#==============================#" << endl;
        cout << " ...::: Alien vs Zombie :::... " << endl;
        cout << "#==============================#" << endl;

        if (centerRow + xx == -1 || centerRow + xx == x_axis || centerCol + yy == -1 || centerCol + yy == y_axis)
            break;
        board[centerRow + xx][centerCol + yy] = 'A';

        if (x_axis >= 10 || y_axis >= 10)
        {
            cout << " ";
            for (int i = 1; i <= y_axis; i++) //+1
            {
                cout << i % 10 << " ";
            }
            cout << endl;
        }
        for (int i = 0; i < x_axis; i++)
        {
            cout << " ";
            for (int j = 0; j < y_axis; ++j)
            {
                cout << "+-";
            }
            cout << "+" << endl;
            // display row number
            cout << setw(2) << (y_axis - i);
            // display the border
            for (int j = 0; j < y_axis; ++j)
            {
                cout << "|" << board[i][j];
            }
            cout << "|" << endl;
        }
        cout << endl
             << endl;
        system("pause");
        board[centerRow + xx][centerCol + yy] = '.'; // trailling for alien

        if (x == 1)
        {
            xx--;
        }
        else if (x == -1)
        {
            xx++;
        }
        else if (y == 1)
        {
            yy++;
        }
        else if (y == -1)
        {
            yy--;
        }
    }
}
// alternate alien moving solution
// void up()
//{
//	int x, y;
//	bool found = false;
//
//	for(int i = 0; i < x_axis; i++)
//	{
//		if(found)
//			break;
//		for(int j = 0; j < y_axis; j++)
//		{
//			if(board[i][j] == 'A')
//			{
//				x = i;
//				y = j;
//				found = true;
//				break;
//			}
//		}
//	}
//
//	board[x][y] = '.';
// }

int main()
{
    int x_axis; // board of rows
    cout << "Enter number of board rows(odd numbers only):";
    cin >> x_axis;
    int y_axis; // board of column
    cout << "Enter number of board columns(odd numbers only):";
    cin >> y_axis;
    int zombie; // the number of zombies
    cout << "Enter number zombie:";
    cin >> zombie;
    if (zombie > 5)
    {
        cout << "Maximum allowed is 5" << endl;
        changeSettings(x_axis, y_axis, zombie);
    }
    displayMainMenu(x_axis, y_axis, zombie);
    createBoard(x_axis, y_axis, zombie);

    cout << endl
         << endl
         << "Command > ";
    string cmd;
    cin >> cmd;

    if (cmd == "up")
    {
        createBoard(x_axis, y_axis, zombie, 1, 0);
    }
    else if (cmd == "down")
    {
        createBoard(x_axis, y_axis, zombie, -1, 0);
    }
    else if (cmd == "right")
    {
        createBoard(x_axis, y_axis, zombie, 0, 1);
    }
    else if (cmd == "left")
    {

        createBoard(x_axis, y_axis, zombie, 0, -1);
    }
    else if (cmd == "quit")
    {
        string state;
        cout << "Are you sure? y/n" << endl;
        cin >> state;
        if ((state == "Y") || (state == "y"))
        {
            exit(0);
        }
        else if ((state == "N") || (state == "n"))
        {
            createBoard(x_axis, y_axis, zombie, 0, 0);
            // returns to board with Alien in middle
            // but command prompt will be removed
        }
        /*
        else if (cmd == "save")
        {
            Save();
        }
        */
    }

    alienStats();

    system("pause");

    return 0;
}
