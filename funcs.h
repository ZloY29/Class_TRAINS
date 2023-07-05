#pragma once

#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include "TRAIN.h"

using namespace std;

// Проверка корректности ввода количества поездов.
void input_cnt_trains(int &num)
{
    cin >> num;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "Некорректно введена информация о количестве поездов, введите повторно!\n";
        cin >> num;
    }
}

// Проверка корректности ввода номера поезда.
void input_number_of_trains(int &num)
{
    cin >> num;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "Некорректно введена информация о номере поезда, введите повторно!\n";
        cin >> num;
    }
}

// Проверка корректности ввода количества остановок.
void input_cnt_stops(int &num)
{
    cin >> num;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "Некорректно введена информация о количестве остановок, введите повторно!\n";
        cin >> num;
    }
}

// Проверка существования данной позиции в списке.
bool check_exist_elem(int pos, vector <TRAIN>& Trains) {
    if (pos >= Trains.size() || pos < 0) {
        cout << "Данного поезда нет в списке!" << '\n';
        return false;
    }
    return true;
}

// Удаление элемента из списка.
void remove_item(int pos, vector <TRAIN>& Trains) {
    Trains.erase(Trains.begin() + pos);
}

// Оператор сравнения равно.
bool operator== (const TRAIN &t1, const TRAIN &t2)
{
    bool flag = true;
    for (int i = 0; i < t1.List_station.size(); ++i) {
        if (t1.List_station[i] != t2.List_station[i])
            flag = false;
    }
    if (flag)
        return (t1.number_of_train == t2.number_of_train &&
                t1.name_of_destination == t2.name_of_destination &&
                t1.departure_time == t2.departure_time);
    else return 0;
}

// Оператор сравнения не равно.
bool operator!= (const TRAIN &t1, const TRAIN &t2)
{
    return !(t1 == t2);
}

// Ввод информации о поездах через консоль.
vector <TRAIN> input_from_console() {
    int cnt_trains;
    int number_of_train;
    int cnt_stops;
    string name_of_destination;
    string departure_time;
    vector <string> List_station;
    cout << "Введите количество поездов:" << '\n';
    input_cnt_trains(cnt_trains);
    vector <TRAIN> Trains;
    for (int i = 0; i < cnt_trains; i++) {
        string shavat;
        cout << "Введите номер поезда:" << '\n';
        input_number_of_trains(number_of_train);
        cout << "Введите название пункта назначения:" << '\n';
        getline(cin, shavat);
        getline(cin, name_of_destination, '\n');
        cout << "Введите время отправления:" << '\n';
        getline(cin, departure_time, '\n');
        cout << "Введите количество остановок:" << '\n';
        input_cnt_stops(cnt_stops);
        if (cnt_stops != 0) {
            List_station.resize(cnt_stops);
            cout << "Введите названия остановок:" << '\n';
            getline(cin, shavat);
            for (int j = 0; j < cnt_stops; j++)
            {
                string term;
                getline(cin, term, '\n');
                List_station[j] = term;
            }
        }
        TRAIN t(number_of_train, name_of_destination, departure_time, List_station);
        Trains.push_back(t);
        List_station.clear();
    }
    return Trains;
}

// Считывание информации о поездах из файла.
vector <TRAIN> input_from_file() {
    ifstream fin("input_trains.txt");
    int cnt_trains;
    int number_of_train;
    int cnt_stops;
    string name_of_destination;
    string departure_time;
    vector <string> List_station;
    fin >> cnt_trains;
    vector <TRAIN> Trains;
    for (int i = 0; i < cnt_trains; i++) {
        string shavat;
        fin >> number_of_train;
        getline(fin, shavat);
        getline(fin, name_of_destination, '\n');
        getline(fin, departure_time, '\n');
        fin >> cnt_stops;
        if (cnt_stops != 0) {
            List_station.resize(cnt_stops);
            getline(fin, shavat);
            for (int j = 0; j < cnt_stops; j++)
            {
                string term;
                getline(fin, term, '\n');
                List_station[j] = term;
            }
        }
        TRAIN t(number_of_train, name_of_destination, departure_time, List_station);
        Trains.push_back(t);
        List_station.clear();
    }
    fin.close();
    return Trains;
}

// Сортировка списка поездов.
void sort_array_trains(vector <TRAIN> &Trains) {
    for (int i = 0; i < Trains.size(); i++) {
        for (int j = 0; j < Trains.size() - 1; j++) {
            if (Trains[j] > Trains[j + 1]) {
                TRAIN t = Trains[j];
                Trains[j] = Trains[j + 1];
                Trains[j + 1] = t;
            }
        }
    }
}

// Ввод данных об одном поезде через консоль.
TRAIN input_one_from_console() {
    int number_of_train;
    int cnt_stops;
    string name_of_destination;
    string departure_time;
    vector <string> List_station;
    vector <TRAIN> Trains;
    string shavat;
    cout << "Введите номер поезда:" << '\n';
    input_number_of_trains(number_of_train);
    cout << "Введите название пункта назначения:" << '\n';
    getline(cin, shavat);
    getline(cin, name_of_destination, '\n');
    cout << "Введите время отправления:" << '\n';
    getline(cin, departure_time, '\n');
    cout << "Введите количество остановок:" << '\n';
    input_cnt_stops(cnt_stops);
    if (cnt_stops != 0) {
        List_station.resize(cnt_stops);
        cout << "Введите названия остановок:" << '\n';
        getline(cin, shavat);
        for (int j = 0; j < cnt_stops; j++)
        {
            string term;
            getline(cin, term, '\n');
            List_station[j] = term;
        }
    }
    TRAIN t(number_of_train, name_of_destination, departure_time, List_station);
    return t;
}

// Считывание данных об одном поезде из файла.
TRAIN input_one_from_file() {
    ifstream fin("input_one_train.txt");
    int number_of_train;
    int cnt_stops;
    string name_of_destination;
    string departure_time;
    vector <string> List_station;
    vector <TRAIN> Trains;
    cin >> number_of_train;
    getline(cin, name_of_destination, '\n');
    getline(cin, departure_time, '\n');
    cin >> cnt_stops;
    if (cnt_stops != 0) {
        List_station.resize(cnt_stops);
        for (int j = 0; j < cnt_stops; j++)
        {
            string term;
            getline(cin, term, '\n');
            List_station[j] = term;
        }
    }
    TRAIN t(number_of_train, name_of_destination, departure_time, List_station);
    fin.close();
    return t;
}

// Нахождение поезда из списка следующего в данный пункт.
vector <TRAIN> find_cur_destination(string term, vector <TRAIN> &Trains) {
    vector <TRAIN> Cur_Trains;
    for (int i = 0; i < Trains.size(); ++i) {
        if (Trains[i].get_name_of_destination() == term) {
            Cur_Trains.push_back(Trains[i]);
        }
    }
    return Cur_Trains;
}

// Нахождение поездов из списка следующих в данный пункт.
void find_trains_with_cur_destination(vector <TRAIN> &Trains) {
    string find_cur;
    string shavat;
    vector <TRAIN> Cur_Trains;
    cout << "Введите название пункта назначения, поезда в который вы хотите найти:" << '\n';
    getline(cin, shavat);
    getline(cin, find_cur, '\n');
    Cur_Trains = find_cur_destination(find_cur, Trains);
    if (Cur_Trains.size() != 0) {
        cout << "По вашему запросу найдены следующие поезда:" << '\n' << '\n';
        for (int i = 0; i < Cur_Trains.size(); ++i) {
            Cur_Trains[i].output_console();
        }
    }
    else
        cout << "По вашему запросу ничего не найдено!" << '\n';
}

void output_file(vector <TRAIN> &Trains) {
    ofstream fout("output_trains.txt");
    for (int i = 0; i < Trains.size(); ++i) {
        fout << "Номер поезда: " << Trains[i].get_number_of_train() << '\n';
        fout << "Название пункта назначения: " << Trains[i].get_name_of_destination() << '\n';
        fout << "Время отправления: " << Trains[i].get_departure_time() << '\n';
        if (Trains[i].get_List_station_size() != 0) {
            fout << "Список остановок: " << '\n';
            for (int j = 0; j < Trains[i].get_List_station_size(); ++j) {
                fout << i + 1 << ". " << Trains[i].get_List_station_i(j) << '\n';
            }
            fout << '\n';
        }
        else
            fout << "Поезд двигается без остановок!" << '\n' << '\n';
    }
    fout.close();
}

// Нахождение поездов из списка следующих в данный пункт, вывод в файл.
void find_trains_with_cur_destination_file(vector <TRAIN> &Trains) {
    string find_cur;
    string shavat;
    vector <TRAIN> Cur_Trains;
    cout << "Введите название пункта назначения, поезда в который вы хотите найти:" << '\n';
    getline(cin, shavat);
    getline(cin, find_cur, '\n');
    Cur_Trains = find_cur_destination(find_cur, Trains);
    if (Cur_Trains.size() != 0) {
        cout << "По вашему запросу найдены следующие поезда:" << '\n' << '\n';
        output_file(Cur_Trains);
    }
    else{
        ofstream fout("output_trains.txt");
        fout << "По вашему запросу ничего не найдено!" << '\n';
        fout.close();
    }
}

// Нахождение поезда из списка без промежуточных станций.
vector <TRAIN> find_train_without_stops(vector <TRAIN> &Trains) {
    vector <TRAIN> Cur_Trains;
    for (int i = 0; i < Trains.size(); ++i) {
        if (Trains[i].get_List_station_size() == 0)
            Cur_Trains.push_back(Trains[i]);
    }
    return Cur_Trains;
}

// Нахождение поездов из списка без промежуточных станций.
void find_trains_without_stops(vector <TRAIN> &Trains) {
    vector <TRAIN> Cur_Trains;
    Cur_Trains = find_train_without_stops(Trains);
    if (Cur_Trains.size() != 0) {
        cout << "По вашему запросу найдены следующие поезда:" << '\n' << '\n';
        for (int i = 0; i < Cur_Trains.size(); ++i) {
            Cur_Trains[i].output_console();
        }
    }
    else
        cout << "По вашему запросу ничего не найдено!" << '\n';
}

// Нахождение поездов из списка без промежуточных станций, вывод в файл.
void find_trains_without_stops_file(vector <TRAIN> &Trains) {
    vector <TRAIN> Cur_Trains;
    Cur_Trains = find_train_without_stops(Trains);
    if (Cur_Trains.size() != 0) {
        cout << "По вашему запросу найдены следующие поезда:" << '\n' << '\n';
        output_file(Cur_Trains);
    }
    else{
        ofstream fout("output_trains.txt");
        fout << "По вашему запросу ничего не найдено!" << '\n';
        fout.close();
    }
}

// Очистка вектора.
void clear_vector_train(vector <TRAIN> &Trains) {
    for (int i = 0; i < Trains.size(); ++i) {
        Trains[i].~TRAIN();
    }
    Trains.clear();
}