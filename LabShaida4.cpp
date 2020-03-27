// LabShaida4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <array>
#include <set>
#include <ctime>
#include <map>
#include <iomanip>
#include "windows.h"
#include <conio.h>

using namespace std;

template<typename type >type getValue(string s);
enum Colors
{
    Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray,
    DarkGray, LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};

template<Colors txt = LightGray, Colors bg = Black> ostream& color(ostream& text) {
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | txt));
    return text;
}



template<class T>
void Print(T container)
{
    for (auto it : container)
    {
        cout << fixed << setprecision(2) << it.first << ":\t" << it.second << endl;;
    }
}
template<class T>
void Print(T container, int key)
{
    for (auto it : container)
    {
        if(it.first == key)cout << color<Green, Black> << fixed << setprecision(2) << it.first << ":\t" << it.second << color<LightGray, Black> << color << endl;
        else cout << color<LightGray, Black> << fixed << setprecision(2) << it.first << ":\t" << it.second << color<LightGray, Black> << color << endl;
        
    }
}
template<class T>
void init_set(T &container, int counter)
{
 
    for (int i = 0; i < counter; i++)
    {
        container[i] = ((float)(rand()%100-50))/10;

    }
}
template<class T>
void finder(T &container)
{
    int key = (*(container.begin())).first;
    float max = (*(container.begin())).second;
    
    for (auto &it : container)
    {
        if (it.second > max) 
        {
            key = it.first;
            max = it.second; 
            
        }
    }
    Print(container, key);
    system("pause");
    system("cls");
    container.insert({ ((*(--container.end())).first)+1,max});
    Print(container, key);
    system("pause");
    system("cls");
    
}

template<class T>
void remover(T& container, int key)
{
    container.erase(key);

}

template<class T>
void finderAdder(T& container)
{
    float aver = 0;
    float sum = 0;
    int iter = 0;
    for (auto& it : container)
    {
            sum += it.second;
            iter++;
    }
    aver = sum / iter;
    
    for (auto it : container)
    {
        container[it.first] = it.second + aver;
    }
    Print(container);
    cout << "Среднее: " << aver << endl;
    system("pause");
}

int getValue(string msg)
{
    while (true) // Цикл продолжается до тех пор, пока пользователь не введёт корректное значение
    {
        cout << msg << ":";
        int a;
        std::cin >> a;

        if (std::cin.fail()) // Если предыдущее извлечение оказалось неудачным,
        {
            std::cin.clear(); // То возвращаем cin в 'обычный' режим работы
            std::cin.ignore(32767, '\n'); // Удаляем значения предыдущего ввода из входного буфера
        }
        else // Eсли всё хорошо, то возвращаем a
            return a;
    }
}


int main()
{
    setlocale(LC_ALL, "");
    srand(time(0));
    map<int , float> mapa;
    init_set(mapa, 10);
    Print(mapa);
    system("pause");
    system("cls");
    finder(mapa);
    finderAdder(mapa);
    remover(mapa,getValue("Введите ключ элемента для удаления:"));
    system("cls");
    Print(mapa);
    system("pause");
}

