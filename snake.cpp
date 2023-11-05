#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

bool gameOver;
const int width = 40;
const int height = 20;
int x, y, fruitX, fruitY, score,enemyX,enemyY;
int nTail;
int tailX[100], tailY[100];
enum eDirection
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};
eDirection dir;

void Setup1()
{
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}
void Setup2()
{
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    enemyX = rand() % width;
    enemyY = rand() % height;
    score = 0;
}

void Draw()
{
    system("cls");
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                cout << "#";
            if (i == y && j == x)
                cout << "O";
            else if (i == fruitY && j == fruitX)
                cout << "F";
            else if (i == enemyY && j == enemyX)
                cout << "X";
            else
            {
                bool print = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        cout << "o";
                        print = true;
                    }
                }
                if (!print)
                    cout << " ";
            }

            if (j == width - 1)
                cout << "#";
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;
    cout << "Score:" << score << endl;
}

void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}
void anot1(int *x, int *y)
{
    if (*x >= width)
        *x = 0;
    else if (*x < 0)
        *x = width - 1;
    if (*y >= height)
        *y = 0;
    else if (*y < 0)
        *y = height - 1;

    for (int i = 0; i < nTail; i++)
        if (tailX[i] == *x && tailY[i] == *y)
            gameOver = true;

    if (*x == fruitX && *y == fruitY)
    {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }
}
void anot2(int *x, int *y)
{
    if (*x >= width)
        gameOver = true;
    else if (*x < 0)
        gameOver = true;
    if (*y >= height)
        gameOver = true;
    else if (*y < 0)
        gameOver = true;

    for (int i = 0; i < nTail; i++)
        if (tailX[i] == *x && tailY[i] == *y)
            gameOver = true;

    if (*x == fruitX && *y == fruitY)
    {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }
}
void anot3(int *x, int *y)
{
    if (*x >= width)
        *x = 0;
    else if (*x < 0)
        *x = width - 1;
    if (*y >= height)
        *y = 0;
    else if (*y < 0)
        *y = height - 1;

    for (int i = 0; i < nTail; i++)
        if (tailX[i] == *x && tailY[i] == *y)
            gameOver = true;

    if (*x == fruitX && *y == fruitY)
    {
        score += 10;
        *x = rand() % width;
        *y = rand() % height;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }
    else if (*x == enemyX && *y == enemyY)
    {
        score -= 10;
        enemyX = 1+rand() % width;
        enemyY = 1+rand() % height;
        nTail--;
        if(score<0) gameOver=true;
    }
}
void anot4(int *x, int *y)
{
    if (*x >= width)
        *x = 0;
    else if (*x < 0)
        *x = width - 1;
    if (*y >= height)
        *y = 0;
    else if (*y < 0)
        *y = height - 1;

    for (int i = 0; i < nTail; i++)
        if (tailX[i] == *x && tailY[i] == *y)
            gameOver = true;

    if (*x == fruitX && *y == fruitY)
    {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        *x = rand() % width;
        *y = rand() % height;
        nTail++;
    }
    else if (*x == enemyX && *y == enemyY)
    {
        gameOver=true;
    }
}
void anot5(int *x, int *y)
{
    if (*x >= width)
        gameOver = true;
    else if (*x < 0)
        gameOver = true;
    if (*y >= height)
        gameOver = true;
    else if (*y < 0)
        gameOver = true;

    for (int i = 0; i < nTail; i++)
        if (tailX[i] == *x && tailY[i] == *y)
            gameOver = true;

    if (*x == fruitX && *y == fruitY)
    {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        *x = rand() % width;
        *y = rand() % height;
        nTail++;
    }
    else if (*x == enemyX && *y == enemyY)
    {
        gameOver=true;
    }
}
void Logic(int a)
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int tempX, tempY;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++)
    {
        tempX = tailX[i];
        tempY = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = tempX;
        prevY = tempY;
    }

    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }

    if (a == 1)
    {
        anot1(&x, &y);
    }
    else if (a == 2)
    {
        anot2(&x, &y);
    }
    else if (a == 3)
    {
        anot3(&x, &y);
    }
    else if (a == 4)
    {
        anot4(&x, &y);
    }
    else
    {
        anot5(&x, &y);
    }
}

int main()
{
    int x;
    cout << "(1-5) difficulty level" << endl;
    cin >> x;
    if(x>=3){
        Setup2();
    }
    else if(x<3){
        Setup1();
    }
    while (!gameOver)
    {
        Draw();
        Input();
        Logic(x);
        if(x==4){
            Sleep(65);
        }
        else if(x==3){
            Sleep(60);
        }
        else if(x==5){
            Sleep(90);
        }
        else{
            Sleep(100);
        }
    }
    return 0;
}
