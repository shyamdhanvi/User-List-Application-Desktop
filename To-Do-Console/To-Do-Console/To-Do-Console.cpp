// To-Do-Console.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <string>
#include <iomanip>
using namespace std;
class User{
private: 
    int user_id;
public:
    int Tasks_n_o;
    list<string> Tasks;
    User(int id);
    list<string>& add_Task(const string &task);
    list<string>& finish(int Task_n_o);
    const list<string>& Display() const;
};
User::User(int id) : user_id(id), Tasks_n_o(0) {}
list<string>& User::add_Task(const string &task)
{
    Tasks.push_back(task);
    Tasks_n_o++;
    return Tasks;
}
list<string>& User :: finish(int Task_n_o)
{
    if (Task_n_o <= 0 || Task_n_o > Tasks_n_o)
    {
        std::cerr << "Invalid Task Number" << endl;
        return Tasks;
    }
    else
    {
        auto it = Tasks.begin();
        advance(it, Task_n_o - 1);
        Tasks.erase(it);
        Tasks_n_o--;
    }
    return Tasks;
}
const list<string>& User :: Display() const {
    if (Tasks.empty())
    {
        cout << "No task to display." << endl;
        return Tasks;
    }
    int task_number = 1;
    cout << "+---------------+-------------------------------------------+" << endl;
    cout << "| Task No.      | Task Description                          |" << endl;
    cout << "+---------------+-------------------------------------------+" << endl;
    for (const auto& taski : Tasks)
    {
    cout << "| "<< setw(13) << task_number++ << " | " << setw(41) << taski << " |" << endl;
    }
    cout << "+---------------+-------------------------------------------+" << endl;
    return Tasks;
}
int main()
{
    User user(1);
    int choice;
    do {
        cout << "+--------------+----------------------------+" << endl;
        cout << "| Option No.   | Option Description         |" << endl;
        cout << "+--------------+----------------------------+" << endl;
        cout << "| 1            | Add Task                   |" << endl;
        cout << "| 2            | Finish Task                |" << endl;
        cout << "| 3            | Display Tasks              |" << endl;
        cout << "| 4            | Exit                       |" << endl;
        cout << "+--------------+----------------------------+" << endl;
        cout << "Enter Your Choice : ";
        cin>>choice;
        switch (choice) {
        case 1:
        {
            string task;
            cout << "Enter the Task : ";
            cin.ignore();
            getline(cin, task);
            user.add_Task(task);
            break;
        }
        case 2:
        {
            int task_number;
            cout << "Enter the task number to finish : ";
            cin >> task_number;
            user.finish(task_number);
            break;
        }
        case 3:
        {
            user.Display();
            break;
        }
        case 4:
        {
            cout << "Exiting.....\n";
        }
        default:
            cout << "Invalid Choice. Please try again. \n";
            break;
        }
    } while (choice != 4);
    return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file