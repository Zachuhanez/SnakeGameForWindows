#include <Windows.h>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <conio.h>
#include <cstdlib>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

void Draw(int arr[][2], int L, int width = 0, int height = 0)
{
    for (int y2 = 0; y2 <= height; y2++)
    {
        if (y2 == 0 || y2 == height)
        {
            for (int i = 0; i <= width; i++)
            {
                cout << char(219);
            }
            cout << char(219) << endl;
        }
        else
        {
            cout << char(219);
            for (int x2 = 1; x2 <= width; x2++)
            {
                for (int i = 1; i < L; i++)
                {
                    if (arr[i][0] == x2 && arr[i][1] == y2)
                    {
                        if (i == 1)
                        {
                            if (arr[i + 1][0] != arr[i][0] && arr[i + 1][1] == arr[i][1])
                                cout << char(205);
                            else if (arr[i + 1][0] == arr[i][0] && arr[i + 1][1] != arr[i][1])
                                cout << char(186);
                            else
                                cout << " ";
                        }
                        else if (i == L - 1)
                        {
                            if (arr[i - 1][0] != arr[i][0] && arr[i - 1][1] == arr[i][1])
                                cout << char(205);
                            else if (arr[i + 1][0] == arr[i][0] && arr[i + 1][1] != arr[i][1])
                                cout << char(186);
                            else
                                cout << " ";
                        }
                        else if (arr[i - 1][0] - 1 == arr[i][0] && arr[i - 1][1] == arr[i][1])
                        {
                            if (arr[i + 1][0] + 1 == arr[i][0] && arr[i + 1][1] == arr[i][1])
                                cout << char(205);
                            else if (arr[i + 1][0] == arr[i][0] && arr[i + 1][1] + 1 == arr[i][1])
                                cout << char(200);
                            else if (arr[i + 1][0] == arr[i][0] && arr[i + 1][1] - 1 == arr[i][1])
                                cout << char(201);
                            else
                                cout << " ";
                        }
                        else if (arr[i - 1][0] + 1 == arr[i][0] && arr[i - 1][1] == arr[i][1])
                        {
                            if (arr[i + 1][0] - 1 == arr[i][0] && arr[i + 1][1] == arr[i][1])
                                cout << char(205);
                            else if (arr[i + 1][0] == arr[i][0] && arr[i + 1][1] + 1 == arr[i][1])
                                cout << char(188);
                            else if (arr[i + 1][0] == arr[i][0] && arr[i + 1][1] - 1 == arr[i][1])
                                cout << char(187);
                            else
                                cout << " ";
                        }
                        else if (arr[i - 1][0] == arr[i][0] && arr[i - 1][1] - 1 == arr[i][1])
                        {
                            if (arr[i + 1][0] == arr[i][0] && arr[i + 1][1] + 1 == arr[i][1])
                                cout << char(186);
                            else if (arr[i + 1][0] - 1 == arr[i][0] && arr[i + 1][1] == arr[i][1])
                                cout << char(201);
                            else if (arr[i + 1][0] + 1 == arr[i][0] && arr[i + 1][1] == arr[i][1])
                                cout << char(187);
                            else
                                cout << " ";
                        }
                        else if (arr[i - 1][0] == arr[i][0] && arr[i - 1][1] + 1 == arr[i][1])
                        {
                            if (arr[i + 1][0] == arr[i][0] && arr[i + 1][1] - 1 == arr[i][1])
                                cout << char(186);
                            else if (arr[i + 1][0] - 1 == arr[i][0] && arr[i + 1][1] == arr[i][1])
                                cout << char(200);
                            else if (arr[i + 1][0] + 1 == arr[i][0] && arr[i + 1][1] == arr[i][1])
                                cout << char(188);
                            else
                                cout << " ";
                        }
                        break;
                    }
                    else if (arr[0][0] == x2 && arr[0][1] == y2)
                    {
                        cout << "*";
                        break;
                    }
                    else if (i == L - 1)
                    {
                        cout << " ";
                    }
                }
            }
            cout << char(219) << endl;
        }
    }
}

void PlaySnake(int MaxX, int MaxY, int SnakeSpeed, string language)
{
    srand(time(0));
    bool FRoC = true;
    char v = ' ', v2 = v;
    bool GameOver = false;
    int TailL = 5;
    int NewELement[2];
    int PlayerX = 15, PlayerY = 15;
    int tail[1000][2]{ {rand() % MaxX, rand() % MaxY}, {15, 15}, {14, 15}, {13, 15}, {12, 15} };

    while (!GameOver)
    {
        system("cls");
        if (PlayerX == MaxX + 1 || PlayerY == MaxY || PlayerY == 0 || PlayerX == 0)
        {
            GameOver = true;
            break;
        }

        for (int i = 2; i < TailL; i++)
        {
            if (PlayerX == tail[i][0] && PlayerY == tail[i][1])
            {
                GameOver = true;
            }
        }

        setlocale(LC_ALL, "Rus");
        if (language == "Eng")
            cout << "Score: " << TailL - 5 << endl;
        else if (language == "Rus")
            cout << "Счёт: " << TailL - 5 << endl;
        
        setlocale(LC_ALL, ".OCP");
        Draw(tail, TailL, MaxX, MaxY);
        cout << "q - quit | w - Up | a - Left | s - Down | d - Right" << endl;

        if (tail[0][0] == 0 || tail[0][1] == 0)
        {
            if (tail[0][0] == 0)
            {
                while (tail[0][0] == 0)
                {
                    tail[0][0] = rand() % MaxX;
                }
            }
            if (tail[0][1] == 0)
            {
                while (tail[0][1] == 0)
                {
                    tail[0][1] = rand() % MaxY;
                }
            }
        }
        if (_kbhit())
        {
            v2 = _getch();
            if (v2 == 'w' && v != 's') { v = 'w'; }
            if (v2 == 's' && v != 'w') { v = 's'; }
            if (v2 == 'a' && v != 'd') { v = 'a'; }
            if (v2 == 'd' && v != 'a') { v = 'd'; }
            if (v2 == 'q') { break; }
            if (FRoC && v == 'a')
                v = ' ';
            FRoC = false;
        }

        this_thread::sleep_for(chrono::milliseconds(SnakeSpeed));

        if (v == 'w') { PlayerY--; }
        else if (v == 's') { PlayerY++; }
        else if (v == 'a') { PlayerX--; }
        else if (v == 'd') { PlayerX++; }

        v2 = v;

        if (v == 'w' || v == 's' || v == 'a' || v == 'd')
        {
            NewELement[0] = tail[TailL - 1][0];
            NewELement[1] = tail[TailL - 1][1];
            for (int i = TailL; i > 1; i--)
            {
                tail[i][0] = tail[i - 1][0];
                tail[i][1] = tail[i - 1][1];
            }
            tail[1][0] = PlayerX;
            tail[1][1] = PlayerY;
        }

        if (PlayerX == tail[0][0] && PlayerY == tail[0][1])
        {
            TailL++;
            tail[TailL - 1][0] = NewELement[0];
            tail[TailL - 1][1] = NewELement[1];

            tail[0][0] = rand() % MaxX;
            tail[0][1] = rand() % MaxY;
        }
    }
    if (GameOver)
    {
        system("cls");
        cout << "Score: " << TailL - 5 << endl;

        string GameOverStr = "bbbbb     b     bb   bb bbbbbnb        b b    b b b b bnb  bb   b   b   b  b  b bbbbbnb   b  bbbbbbb  b     b bnbbbbb b       b b     b bbbbbnnbbbbb b       b bbbbbb bbbbbnb   b  b     b  b      b   bnb   b   b   b   bbbbbb bbbbbnb   b    b b    b      b  bnbbbbb     b     bbbbbb b   bnn";
        for (int i = 0; i < GameOverStr.length(); i++)
        {
            if (GameOverStr[i] == 'b')
                cout << char(219);
            else if (GameOverStr[i] == ' ')
                cout << " ";
            else if (GameOverStr[i] == 'n')
                cout << endl;
        }
        cout << "q - quit | other - restart\n";
        char s = _getch();
        if (s == 'q') { cout << "Good luck!" << endl; }
        else { PlaySnake(MaxX, MaxY, SnakeSpeed, language); }
    }
}

void OptionList(string values[], int ValCount, int Choosed)
{
    for (int i = 0; i < ValCount; i++)
    {
        if (Choosed - 1 == i)
            cout << " | ";
        else
            cout << "   ";
        cout << values[i];
        if (Choosed - 1 == i)
            cout << " | ";
        else
            cout << "   ";
    }
}

int main()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);

    int MaxX = 25, MaxY = 25;
    int selector = 1;
    int OptionSelector = 1;
    const int options = 3;
    const int SOptionCount = 4;
    int SnakeSpeed;
    char moving = ' ';

    string optionArr[options]{ "Play", "Settings", "Quit"};
    string SettingsOptionsArr[SOptionCount]{"..","Field size", "Snake speed", "Language"};

    fstream settings("settings.txt", fstream::in);
    string str;
    string Val;
    string Lang;

    int ChoosedFieldSize = 2;
    string FieldSizeValues[3]{"20*20", "25*25", "30*30"};

    int ChoosedSnakeSpeed = 2;
    string SnakeSpeedValues[3]{"Slow", "Middle", "Fast"};

    int ChoosedLanguage = 1;
    string Languages[2]{"English", "Russian"};

    while (getline(settings, str))
    {
        Val = str[str.length()-1];
        str.erase(str.length() - 2);

        if (str == "field_size")
        {
            if (Val == "1")
                ChoosedFieldSize = 1;
            else if (Val == "2")
                ChoosedFieldSize = 2;
            else if (Val == "3")
                ChoosedFieldSize = 3;
        }
        else if (str == "snake_speed")
        {
            if (Val == "1")
                ChoosedSnakeSpeed = 1;
            else if (Val == "2")
                ChoosedSnakeSpeed = 2;
            else if (Val == "3")
                ChoosedSnakeSpeed = 3;
        }
        else if (str == "language")
        {
            if (Val == "1")
                ChoosedLanguage = 1;
            else if (Val == "2")
                ChoosedLanguage = 2;
        }
    }

    while (true)
    {
        system("cls");

        if (ChoosedFieldSize == 1)
            MaxX = 20, MaxY = 20;
        else if (ChoosedFieldSize == 2)
            MaxX = MaxY = 25;
        else if (ChoosedFieldSize == 3)
            MaxX = MaxY = 30;
        
        if (ChoosedSnakeSpeed == 1)
            SnakeSpeed = 325;
        else if (ChoosedSnakeSpeed == 2)
            SnakeSpeed = 250;
        else if (ChoosedSnakeSpeed == 3)
            SnakeSpeed = 150;

        if (ChoosedLanguage == 1)
        {
            Lang = "Eng";

            optionArr[0]          =       "Play", optionArr[1]          =    "Settings", optionArr[2]          =     "Quit";
            SettingsOptionsArr[1] = "Field size", SettingsOptionsArr[2] = "Snake speed", SettingsOptionsArr[3] = "Language";
            SnakeSpeedValues[0]   =       "Slow", SnakeSpeedValues[1]   =      "Middle", SnakeSpeedValues[2]   =     "Fast";
            Languages[0]          =    "English", Languages[1]          =     "Russian";
        }
        else if (ChoosedLanguage == 2)
        {
            Lang = "Rus";

            optionArr[0]          =      "Играть", optionArr[1]          =       "Настройки", optionArr[2]          =   "Выйти";
            SettingsOptionsArr[1] = "Размер поля", SettingsOptionsArr[2] = "Скорость змейки", SettingsOptionsArr[3] =    "Язык";
            SnakeSpeedValues[0]   =   "Медленная", SnakeSpeedValues[1]   =         "Средняя", SnakeSpeedValues[2]   = "Быстрая";
            Languages[0]          =  "Английский", Languages[1]          =         "Русский";
        }

        string SnakeStr = "bbbb b  b bbb  b  b bbbbnb    b  b b  b b b  bnbbbb b bb b  b bb   bbbbn   b bb b bbbb b b  bnbbbb b  b b  b b  b bbbbn";;
        setlocale(LC_ALL, ".OCP");
        for (int i = 0; i < SnakeStr.length(); i++)
        {
            if (SnakeStr[i] == 'b')
                cout << char(219);
            else if (SnakeStr[i] == ' ')
                cout << " ";
            else if (SnakeStr[i] == 'n')
                cout << endl;
        }
        setlocale(LC_ALL, "Rus");
        for (int i = 0; i < options; i++)
        {
            if (selector - 1 == i)
                cout << "*";
            cout << "\t" << optionArr[i] << endl;
        }
        cout << "_________________________\n" << "w - " << char(24) << " | s - " << char(25) << " | e - Enter";
        moving = _getch();
        if (moving == 'w')
        {
            if (selector == 1)
                selector = options;
            else
                selector--;
        }
        else if (moving == 's')
        {
            if (selector == options)
                selector = 1;
            else
                selector++;
        }
        else if (moving == 'e')
        {
            if (selector == 1)
            {
                PlaySnake(MaxX, MaxY, SnakeSpeed, Lang);
            }
            else if (selector == 2)
            {
                while (true)
                {
                    system("cls");

                    for (int i = 0; i < SOptionCount; i++)
                    {
                        if (OptionSelector - 1 == i)
                            cout << "*";
                        cout << "\t" << SettingsOptionsArr[i] << "\t";
                        if (SettingsOptionsArr[i] == "Field size" || SettingsOptionsArr[i] == "Размер поля")
                            OptionList(FieldSizeValues, 3, ChoosedFieldSize);
                        else if (SettingsOptionsArr[i] == "Snake speed" || SettingsOptionsArr[i] == "Скорость змейки")
                            OptionList(SnakeSpeedValues, 3, ChoosedSnakeSpeed);
                        else if (SettingsOptionsArr[i] == "Language" || SettingsOptionsArr[i] == "Язык")
                        {
                            if (SettingsOptionsArr[i] == "Язык")
                                cout << "\t";

                            OptionList(Languages, 2, ChoosedLanguage);
                        }
                        cout << endl;
                    }

                    cout << "_________________________\n" << "w - ↑ | s - ↓ | e - Enter\n" << "a - Save | d - Set to defualt";
                    
                    char SOption = _getch();
                    if (SOption == 's')
                    {
                        if (OptionSelector == SOptionCount)
                            OptionSelector = 1;
                        else
                            OptionSelector++;
                    }
                    else if (SOption == 'w')
                    {
                        if (OptionSelector == 1)
                            OptionSelector = SOptionCount;
                        else
                            OptionSelector--;
                    }
                    else if (SOption == 'd')
                    {
                        ChoosedSnakeSpeed = 2;
                        ChoosedFieldSize = 2;
                        ChoosedLanguage = 1;
                    }
                    else if (SOption == 'e')
                    {
                        if (OptionSelector == 1)
                        {
                            fstream SavedFile;
                            SavedFile.open("settings.txt", fstream::out | fstream::trunc);

                            SavedFile << "field_size=" << ChoosedFieldSize << "\nsnake_speed=" << ChoosedSnakeSpeed << "\nlanguage=" << ChoosedLanguage;
                            
                            SavedFile.close();
                            break;
                        }

                        else if (OptionSelector == 2)
                        {
                            if (ChoosedFieldSize == 3)
                                ChoosedFieldSize = 1;
                            else
                                ChoosedFieldSize++;
                        }
                        else if (OptionSelector == 3)
                        {
                            if (ChoosedSnakeSpeed == 3)
                                ChoosedSnakeSpeed = 1;
                            else
                                ChoosedSnakeSpeed++;
                        }
                        else if (OptionSelector == 4)
                        {
                            if (ChoosedLanguage == 2)
                                ChoosedLanguage = 1;
                            else
                                ChoosedLanguage++;
                        }
                    }
                }
            }
            else if (selector == 3)
            {
                settings.close();
                break;
            }
        }
    }
}
