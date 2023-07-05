#pragma once

#include "TRAIN.h"
#include "funcs.h"

void show_menu()
{
    cout << "1. Ввод данных о поездах с клавиатуры.\n";
    cout << "2. Считывание данных о поездах из файла.\n";
    cout << "3. Упорядочить записи по номерам поезда и названию пункта назначения.\n";
    cout << "4. Вывести на экран информацию о всех поездах.\n";
    cout << "5. Вывести в файл информацию о всех поездах.\n";
    cout << "6. Вывод на экран информации о поездах, следующих в заданный пункт.\n";
    cout << "7. Вывод на экран информации о поездах, которые не имеют промежуточных станций.\n";
    cout << "8. Вывод в файл информации о поездах, следующих в заданный пункт.\n";
    cout << "9. Вывод в файл информации о поездах, которые не имеют промежуточных станций.\n";
    cout << "10. Удалить поезд из списка.\n";
    cout << "11. Добавить поезд в список с консоли.\n";
    cout << "12. Добавить поезд в список из файла.\n";
    cout << "13. Заменить поезд в списке с консоли.\n";
    cout << "14. Заменить поезд в списке из файла.\n";
    cout << "0. Закончить работу.\n";
}

void work_menu(int number, vector <TRAIN> &Trains)
{
    switch (number)
    {
        case 1:
        {
            Trains = input_from_console();
            break;
        }
        case 2:
        {
            Trains = input_from_file();
            break;
        }
        case 3:
        {
            sort_array_trains(Trains);
            break;
        }
        case 4:
        {
            for (int i = 0; i < Trains.size(); ++i) {
                Trains[i].output_console();
            }
            break;
        }
        case 5:
        {
            ofstream fout("output_trains.txt");
            for (int i = 0; i < Trains.size(); ++i) {
                fout << "Номер поезда: " << Trains[i].get_number_of_train() << '\n';
                fout << "Название пункта назначения: " << Trains[i].get_name_of_destination() << '\n';
                fout << "Время отправления: " << Trains[i].get_departure_time() << '\n';
                if (Trains[i].get_List_station_size() != 0) {
                    fout << "Список остановок: " << '\n';
                    for (int j = 0; j < Trains[i].get_List_station_size(); ++j) {
                        fout << j + 1 << ". " << Trains[i].get_List_station_i(j) << '\n';
                    }
                    fout << '\n';
                }
                else
                    fout << "Поезд двигается без остановок!" << '\n' << '\n';
            }
            fout.close();
            break;
        }
        case 6:
        {
            find_trains_with_cur_destination(Trains);
            break;
        }
        case 7:
        {
            find_trains_without_stops(Trains);
            break;
        }
        case 8:
        {
            find_trains_with_cur_destination_file(Trains);
            break;
        }
        case 9:
        {
            find_trains_without_stops_file(Trains);
            break;
        }
        case 10:
        {
            int pos;
            cout << "Элемент на какой позиции вы хотите удалить?" << '\n';
            cin >> pos;
            pos -= 1;
            bool flag = check_exist_elem(pos, Trains);
            if (flag) {
                remove_item(pos, Trains);
                sort_array_trains(Trains);
                break;
            }
            else {
                cout << "Этой позиции нет в списке!" << '\n';
                break;
            }
        }
        case 11:
        {
            Trains.push_back(input_one_from_console());
            break;
        }
        case 12:
        {
            Trains.push_back(input_one_from_file());
            break;
        }
        case 13:
        {
            int pos;
            cout << "Элемент на какой позиции вы хотите поменять?" << '\n';
            cin >> pos;
            pos -= 1;
            bool flag = check_exist_elem(pos, Trains);
            if (flag) {
                remove_item(pos, Trains);
                cout << "На какой элемент вы хотите его заменить?" << '\n' << '\n';
                Trains.push_back(input_one_from_console());
                sort_array_trains(Trains);
                break;
            }
            else {
                cout << "Этой позиции нет в списке!" << '\n';
                break;
            }
        }
        case 14:
        {
            int pos;
            cout << "Элемент на какой позиции вы хотите поменять?" << '\n';
            cin >> pos;
            pos -= 1;
            bool flag = check_exist_elem(pos, Trains);
            if (flag) {
                remove_item(pos, Trains);
                cout << "На какой элемент вы хотите его заменить?" << '\n' << '\n';
                Trains.push_back(input_one_from_file());
                sort_array_trains(Trains);
                break;
            }
            else {
                cout << "Этой позиции нет в списке!" << '\n';
                break;
            }
        }
        case 0:
        {
            exit(0);
            break;
        }
        default:
        {
            break;
        }
    }
}