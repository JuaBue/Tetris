#include <iostream>
#include <vector>
#include <string>
#define UNICODE
#include <Windows.h>

using namespace std;

wstring tetromino[7];
int nFieldWidth = 12;
int nFieldHeight = 18;
unsigned char *pField = nullptr;

int nScreenWidth = 80;      // Console Screen Size X (columns)
int nScreenHeight = 30;     // Console Screen Size Y (rows)

int Rotate(int px, int py, int r)
{
    int retorno = 0;
    switch (r % 4)
    {
    case 0:
        retorno = py * 4 + px;          // 0 degrees
        break;
    case 1:
        retorno = 12 + py - (px * 4);   // 90 degress
        break;
    case 2:
        retorno = 15 - (py * 4) - px;   // 180 degress
        break;
    case 3:
        retorno = 3 - py + (py * 4);    // 270 degress
        break;
    default:
        retorno = 0;                    // Error. 
        break;
    }

    return retorno;
}

int main()
{
    // Create assets
    tetromino[0].append(L"..X.");
    tetromino[0].append(L"..X.");
    tetromino[0].append(L"..X.");
    tetromino[0].append(L"..X.");

    tetromino[1].append(L"..X.");
    tetromino[1].append(L".XX.");
    tetromino[1].append(L".X..");
    tetromino[1].append(L"....");

    tetromino[2].append(L".X..");
    tetromino[2].append(L".XX.");
    tetromino[2].append(L"..X.");
    tetromino[2].append(L"....");

    tetromino[3].append(L"....");
    tetromino[3].append(L".XX.");
    tetromino[3].append(L".XX.");
    tetromino[3].append(L"....");

    tetromino[4].append(L"..X.");
    tetromino[4].append(L".XX.");
    tetromino[4].append(L"..X.");
    tetromino[4].append(L"....");

    tetromino[5].append(L".XX.");
    tetromino[5].append(L"..X.");
    tetromino[5].append(L"..X.");
    tetromino[5].append(L"....");

    tetromino[6].append(L"....");
    tetromino[6].append(L".XX.");
    tetromino[6].append(L".X..");
    tetromino[6].append(L".X..");

    pField = new unsigned char[nFieldWidth*nFieldHeight];   // Create play field buffer
    for (int nIndex = 0; nIndex < nFieldWidth; nIndex++)    // Board Boundary
    {
        for (int nIndey = 0; nIndey < nFieldHeight; nIndey++)
        {
            pField[nIndey*nFieldWidth + nIndex] = (nIndex == 0 || nIndex == nFieldWidth - 1 || nIndey == nFieldHeight - 1) ? 9 : 0;
        }
    }

    wchar_t *screen = new wchar_t[nScreenWidth*nScreenHeight];
    for (int nIndex = 0; nIndex < nScreenWidth * nScreenHeight; nIndex++)
    {
        screen[nIndex] = L' ';
    }

    HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(hConsole);
    DWORD dwBytesWritten = 0;

    // Display Frame
    WriteConsoleOutputCharacter(hConsole, screen, nScreenHeight * nScreenWidth, { 0,0 }, &dwBytesWritten);
    Sleep(1000 / 30);
    return 0;
}

