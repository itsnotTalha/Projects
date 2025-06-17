#include <iostream>
#include <sstream>
#include <thread>
#include <chrono>
#include <iomanip>
#include <cstdlib>
#include <regex>
#include <windows.h>

using namespace std;

void hideCursor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void setConsoleSize(int columns, int rows) {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD bufferSize = { (SHORT)columns, (SHORT)rows };
    SetConsoleScreenBufferSize(hOut, bufferSize);
    SMALL_RECT windowSize = { 0, 0, (SHORT)(columns - 1), (SHORT)(rows - 1) };
    SetConsoleWindowInfo(hOut, TRUE, &windowSize);
}

void setFontSize(int width, int height) {
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = width;
    cfi.dwFontSize.Y = height;
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    lstrcpyW(cfi.FaceName, L"Consolas");
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

int parseTimeToSeconds(string timeStr) {
    replace(timeStr.begin(), timeStr.end(), ':', ' ');
    int h = 0, m = 0, s = 0;
    stringstream ss(timeStr);
    ss >> h >> m >> s;
    if (ss.fail()) return -1;
    return h * 3600 + m * 60 + s;
}

string formatTime(int totalSeconds) {
    int h = totalSeconds / 3600;
    int m = (totalSeconds % 3600) / 60;
    int s = totalSeconds % 60;
    stringstream ss;
    ss << setfill('0') << setw(2) << h << ":"
       << setw(2) << m << ":"
       << setw(2) << s;
    return ss.str();
}

int main() {
    setConsoleSize(80, 25);
    setFontSize(0, 24);

    string title;
    getline(cin, title);

    string userInput;
    cout << "Target time (HH:MM:SS or H M S): ";
    getline(cin, userInput);

    int targetSeconds = parseTimeToSeconds(userInput);
    if (targetSeconds < 0) {
        cout << "Invalid time format!" << endl;
        return 1;
    }

    setConsoleSize(26, 12);
    hideCursor();
    auto startTime = chrono::system_clock::now();

    for (int i = 0; i <= targetSeconds; ++i) {
        system("cls");
        cout << endl;
        cout << title << endl;
        cout << endl << endl;
        cout << "----------Timer----------\n\t" << formatTime(i) << endl;
        cout << "-------Remaining---------\n\t" << formatTime(targetSeconds - i) << endl << endl << endl;
        chrono::system_clock::time_point nextTick = startTime + chrono::seconds(i + 1);
        this_thread::sleep_until(nextTick);
    }

    system("cls");
    Beep(523, 1000);
    for (int i = 0; i < 11; i++)
        cout << "Time reached!" << endl;

    cin.ignore();
    cin.get();
    return 0;
}
