#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <sstream>

using namespace std;

vector<int> input_vector();
string input_user_data();
bool check_data(vector<int>& user_vector);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "ru");
    vector<int> socks = input_vector();
    if (!check_data(socks))
    {
        throw new exception("Данные некорректны.");
    }
    string max_number_socks;
    for (int i = 0; i < socks.size(); i++)
    {
        for (int j = i + 1; j < socks.size(); j++)
        {
            if (socks[j] == socks[i])
            {
                max_number_socks.push_back(socks[i]);
            }
        }
    }
    cout << "Количество носков, введенных пользователем = " << socks.size() << endl 
         <<"Максимальное количество носков, которое может лежать перед Андрюшей = " << max_number_socks.length() << endl;
    return 0;
}

vector<int> input_vector()
{
    vector<int> user_vector;
    string user_string = input_user_data();
    stringstream transmitting_string(user_string);
    int number;
    while (transmitting_string >> number)
    {
        user_vector.push_back(number);
    }
    return user_vector;
}

string input_user_data() 
{
    string user_data;
    cout << "Введите порядок, в котором нужно достать носки из мешка = ";
    getline(cin, user_data);
    cout << endl;
    if (user_data.find_first_not_of("0123456789 ") == -1)
    {
        throw new exception("Введённая строка содержит посторонние символы.\n");
    }
    if (user_data.size() <= 0)
    {
        throw new exception("Введённая строка пустая.\n");
    }
    return user_data;
}

bool check_data(vector<int>& user_vector)
{
    if (user_vector.size() < 0 || user_vector.size() > 210)
    {
        return false;
    }
    int counts = 0;
    for (int i = 0; i < user_vector.size(); i++)
    {
        counts = 0;
        for (int j = 0; j < user_vector.size(); j++)
        {
            if (user_vector[i] == user_vector[j])
            {
                counts++;
            }
        }
        if (counts == 0)
        {
            return false;
        }
    }
    return true;
}