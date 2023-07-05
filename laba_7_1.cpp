#include "funcs.h"
#include "menu.h"
#include "TRAIN.h"

int main(){
    vector <TRAIN> Trains;
    int number = -1;
    int end_number = 15;
    while (number != end_number)
    {
        show_menu();
        cin >> number;
        if (!(number >= 0 && number <= end_number))
        {
            cout << "Все плохо!\n";
        }
        else
        {
            work_menu(number, Trains);
        }
    }
    clear_vector_train(Trains);
    return 0;
}