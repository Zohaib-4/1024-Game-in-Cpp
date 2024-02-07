#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <conio.h>

using namespace std;
void display(int a[4][4]);
void up(int grid[][4], int, bool&);
void down(int grid[][4], int, bool&);
void left(int grid[][4], int, bool&);
void right(int grid[][4], int, bool&);
void spawnblock(int[][4]);
int continueorlose(int[][4], int);
bool fullOrNot(int[][4]);
int win(int grid[][4], int);

int main()
{
    srand(time(0));
    cout << "\n\n\t\t\tPress any key to Start" << endl;
    char input = _getch();
    int c, r = 0, i = 0, j = 0, count = 0, count1 = 0, count2 = 0;
    int num = 0;
    int position = 0;
    int grid[4][4] = { 0 }, check[4][4] = { 0 };
    bool shift = true;
    for (c = 0, count = 0; count < 2; count++)
    {
        do
        {
            r = rand() % 4;
            c = rand() % 4;
        } while (grid[r][c] != 0);
        num = rand() % 2 + 1;
        grid[r][c] = num;
    }
    display(grid);
    while (1)
    {
        cout << "\n\n ENTER 'l' TO SWIPE LEFT | 'r' TO SWIPE RIGHT | 'u' TO SWIPE UP | 'd' TO SWIPE DOWN:";
        input = _getch();

        system("cls");
        if (input == 'u') up(grid, r, shift);
        if (input == 'd') down(grid, r, shift);
        if (input == 'l') left(grid, r, shift);
        if (input == 'r') right(grid, r, shift);
        if (input == 27) break;

        if (fullOrNot(grid))
        {
            if ((input == 'r' || input == 'u' || input == 'd' || input == 'l') && shift)
            {
                spawnblock(grid);
            }
        }


        display(grid);



        count1 = continueorlose(grid, 4);
        if (count1 == 1)
        {

            cout << "\n\n\t\t\tYou Lose\n\n\n";
            break;
        }
        count2 = win(grid, 4);
        if (count2 == 1)
        {
            cout << "\n\n\nYou Won";
            break;
        }

    }
}

void display(int a[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        cout << "_____________________________________________";
        cout << endl;
        cout << "|          |          |          |          |";
        cout << endl;

        for (int j = 0; j < 4; j++)
        {
            if (a[i][j] == 0)
            {
                cout << "|          ";
            }
            else if (a[i][j] < 10)
            {
                cout << "|     " << a[i][j] << "    ";
            }
            else if (a[i][j] < 100)
            {
                cout << "|    " << a[i][j] << "    ";
            }
            else if (a[i][j] < 1000)
            {
                cout << "|   " << a[i][j] << "    ";
            }
            else
                cout << "| " << a[i][j] << "   ";
        }
        cout << "|";
        cout << endl;
        cout << "|          |          |          |          |";
        cout << endl;

    }
    cout << "_____________________________________________";
}


void right(int grid[][4], int row, bool& shift)
{
    shift = false;

    for (int count = 0; count < 4; count++)
    {
        for (int r = 0; r < 4; r++)
        {
            for (int c = 3; c > 0; c--)
            {
                if (grid[r][c - 1] == grid[r][c] && grid[r][c] != 0)
                {
                    grid[r][c] = grid[r][c] + grid[r][c - 1];
                    grid[r][c - 1] = 0;
                    shift = true;
                }
                else if (grid[r][c] == 0 && grid[r][c - 1] != 0)
                {
                    grid[r][c] = grid[r][c - 1];
                    grid[r][c - 1] = 0;
                    shift = true;
                }
                else if (grid[r][c] != grid[r][c - 1])
                {
                    continue;
                }
            }
        }
    }
}

void left(int grid[][4], int row, bool& shift)
{
    shift = false;
    for (int count = 0; count < 4; count++)
    {
        for (int r = 0; r < 4; r++)
        {
            for (int c = 0; c < 3; c++)
            {
                if (grid[r][c + 1] == grid[r][c] && grid[r][c] != 0)
                {
                    grid[r][c] = grid[r][c] + grid[r][c + 1];
                    grid[r][c + 1] = 0;
                    shift = true;
                }
                else if (grid[r][c] == 0 && grid[r][c + 1] != 0)
                {
                    grid[r][c] = grid[r][c + 1];
                    grid[r][c + 1] = 0;
                    shift = true;
                }
                else if (grid[r][c] != grid[r][c + 1])
                {
                    continue;
                }
            }
        }
    }
}

void down(int grid[][4], int row, bool& shift)
{
    shift = false;
    for (int count = 0; count < 4; count++)
    {
        for (int c = 0; c < 4; c++)
        {
            for (int r = 3; r > 0; r--)
            {
                if (grid[r][c] == grid[r - 1][c] && grid[r][c] != 0)
                {
                    grid[r][c] = grid[r - 1][c] + grid[r][c];
                    grid[r - 1][c] = 0;
                    shift = true;
                }
                else if (grid[r][c] == 0 && grid[r - 1][c] != 0)
                {
                    grid[r][c] = grid[r - 1][c];
                    grid[r - 1][c] = 0;
                    shift = true;
                }
                else if (grid[r][c] != grid[r - 1][c])
                {
                    continue;
                }
            }
        }
    }
}

void up(int grid[][4], int row, bool& shift)
{
    shift = false;
    for (int count = 0; count < 4; count++)
    {
        for (int c = 0; c < 4; c++)
        {
            for (int r = 0; r < 3; r++)
            {
                if (grid[r][c] == grid[r + 1][c] && grid[r][c] != 0)
                {
                    grid[r][c] = grid[r][c] + grid[r + 1][c];
                    grid[r + 1][c] = 0;
                    shift = true;
                }
                else if (grid[r][c] == 0 && grid[r + 1][c] != 0)
                {
                    grid[r][c] = grid[r + 1][c];
                    grid[r + 1][c] = 0;
                    shift = true;
                }
                else if (grid[r][c] != grid[r + 1][c])
                {
                    continue;
                }
            }
        }
    }
}

void spawnblock(int grid[][4])
{
    int r, c;
    srand(time(0));
    int flag = 1;
    r = rand() % 4;
    c = rand() % 4;
    while (flag)
    {
        if (grid[r][c] == 0)
        {
            grid[r][c] = 1 + rand() % 2;
            flag = 0;
        }
        else
        {
            r = rand() % 4;
            c = rand() % 4;
        }
    }
}

int continueorlose(int grid[][4], int size)
{
    int a = 1, b = 1, i, j;

    if (fullOrNot(grid))
    {
        a = 0;
    }


    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (grid[i + 1][j] == grid[i][j] || grid[i][j + 1] == grid[i][j])
            {
                b = 0;
                break;
            }
        }
    }

    if (a == 1 && b == 0)
    {
        return 0;
    }
    else if (a == 0 && b == 1)
    {
        return 0;
    }
    else if (a == 0 && b == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int win(int grid[][4], int size)
{
    for (int i = 0; i < 4; i++)
    {


        for (int j = 0; j < 4; j++)
        {
            if (grid[i][j] == 1024)
            {
                return 1;
            }
        }
    }
    return 0;
}
bool fullOrNot(int arr[][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (arr[i][j] == 0)
            {
                return true;
            }
        }
    }
    return false;
}