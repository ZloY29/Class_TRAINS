#pragma once
#include "funcs.h"

using namespace std;

class TRAIN{
private:
    int number_of_train;
    string name_of_destination;
    string departure_time;
    vector <string> List_station;
public:
    // Конструктор по заданным значениям.
    TRAIN(int number_of_train, string name_of_destination, string departure_time, vector <string> List_station)
    {
        this->number_of_train = number_of_train;
        this->name_of_destination = name_of_destination;
        this->departure_time = departure_time;
        this->List_station = List_station;
    };

    // Конструктор.
    TRAIN () {
        number_of_train = 0;
        name_of_destination = "";
        departure_time = "";
        List_station = {""};
    }

    // Деструктор.
    ~TRAIN() {
        for (int i = 0; i < List_station.size(); ++i) {
            this -> List_station[i].clear();
        }
        this -> List_station.clear();
        this -> name_of_destination.clear();
        this -> departure_time.clear();
    }

    // Конструктор присваивания.
    TRAIN(const TRAIN &t) {
        this -> number_of_train = t.number_of_train;
        this -> name_of_destination = t.name_of_destination;
        this -> departure_time = t.departure_time;
        for (int i = 0; i < t.List_station.size(); ++i) {
            this -> List_station.push_back(t.List_station[i]);
        }
    }

    // Функция вывода информации о поездах в консоль.
    void output_console() {
        cout << "Номер поезда: " << number_of_train << '\n';
        cout << "Название пункта назначения: " << name_of_destination << '\n';
        cout << "Время отправления: " << departure_time << '\n';
        if (List_station.size() != 0) {
            cout << "Список остановок: " << '\n';
            for (int i = 0; i < List_station.size(); ++i) {
                cout << i + 1 << ". " << List_station[i] << '\n';
            }
            cout << '\n';
        }
        else
            cout << "Поезд двигается без остановок!" << '\n' << '\n';
    }

    void set_number_of_train(int m) {
        number_of_train = m;
    }

    void set_name_of_destination (string s) {
        name_of_destination = s;
    }

    void set_departure_time(string s) {
        departure_time = s;
    }

    int get_number_of_train() {
        return number_of_train;
    }

    int get_List_station_size() {
        return List_station.size();
    }

    string get_List_station_i(int i) {
        return List_station[i];
    }

    string get_name_of_destination(){
        return name_of_destination;
    }

    string get_departure_time() {
        return departure_time;
    }

    friend bool operator== (const TRAIN &t1, const TRAIN &t2);

    friend bool operator!= (const TRAIN &t1, const TRAIN &t2);

    // Оператор сравнения меньше.
    bool operator< (TRAIN& t1) {
        if (t1.get_number_of_train() != this->get_number_of_train())
            return t1.get_number_of_train() > this->get_number_of_train() ||
                   t1.get_number_of_train() > this->get_number_of_train();
        else
            return t1.get_name_of_destination() > this->get_name_of_destination();
    }

    // Оператор сравнения больше.
    bool operator> (TRAIN& t1) {
        if (t1.get_number_of_train() != this->get_number_of_train())
            return t1.get_number_of_train() < this->get_number_of_train() ||
                   t1.get_number_of_train() < this->get_number_of_train();
        else
            return t1.get_name_of_destination() < this->get_name_of_destination();
    }

    // Оператор присваивания.
    TRAIN& operator =(const TRAIN& t) {
        this-> number_of_train = t.number_of_train;
        this-> name_of_destination = t.name_of_destination;
        this-> departure_time = t.departure_time;
        this-> List_station.clear();
        this-> List_station.resize(t.List_station.size());
        for (int i = 0; i < t.List_station.size(); i++) {
            this-> List_station[i] = t.List_station[i];
        }
        return *this;
    }
};