// To-Do-Console.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <chrono>
/*#include "Credential.h"
#include "UserName.h"
#include "UserPassword.h"*/
#include "HeaderFiles/Credential.h"
#include "HeaderFiles/UserData.h"
#include "HeaderFiles/Hide.h"

using namespace std;

class Task {
private:
    string Description;
    chrono::system_clock::time_point timestamp;
public:
    Task(const string& desc) : Description(desc), timestamp(chrono::system_clock::now()) {}
    string getDescription() const { return Description;}
    string getTimestamp() const;
    void setDescription(const string& desc) { Description = desc; }
};
string Task::getTimestamp() const {
    time_t time = chrono::system_clock::to_time_t(timestamp);
    char buffer[26];
    ctime_s(buffer, sizeof(buffer), &time);
    string timeStr(buffer);
    timeStr.pop_back();
    return timeStr;
}
class User {
private:
    int user_id;
    int tasks_cnt;
    list<Task> tasks;
public:
    User(int id);
    list<Task>& addTask(const string& taskDesc);
    list<Task>& finishTask(int taskNumber);
    const list<Task>& Display() const;
};

User::User(int id) : user_id(id), tasks_cnt(0) {}

list<Task>& User::addTask(const string& taskdesc)
{
    tasks.push_back(Task(taskdesc));
    tasks_cnt++;
    return tasks;
}
list<Task>& User::finishTask(int taskNumber)
{
    if (taskNumber <= 0 || taskNumber > tasks_cnt)
    {
        cerr << "Invalid Task Number" << endl;
    }
    else
    {
        auto it = tasks.begin();
        advance(it, taskNumber - 1);
        tasks.erase(it);
        tasks_cnt--;
    }
    return tasks;
}
const list<Task>& User::Display() const {
    if (tasks.empty())
    {
        cout << "No tasks to display." << endl;
    }
    else
    {
        int task_number = 1;
        cout << "+---------------+-------------------------------------------+--------------------------+" << endl;
        cout << "| Task No.      | Task Description                          | Timestamp                |" << endl;
        cout << "+---------------+-------------------------------------------+--------------------------+" << endl;
        for (const auto& task : tasks) {
            cout << "| " << setw(13) << task_number++ << " | " << setw(41) << task.getDescription() << " | " << setw(22) << task.getTimestamp() << " |" << endl;
        }
        cout << "+---------------+-------------------------------------------+--------------------------+" << endl;
    }
    return tasks;
}
class Menu {
private:
    User user;
    int choice;
public:
    Menu(int userId);
    int display_Choice();
};
Menu::Menu(int userId) : user(userId), choice(-1) {}
int Menu::display_Choice() {
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
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            string task;
            cout << "Enter the Task : ";
            cin.ignore();
            getline(cin, task);
            user.addTask(task);
            break;
        }
        case 2:
        {
            int task_number;
            cout << "Enter the task number to finish : ";
            cin >> task_number;
            user.finishTask(task_number);
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
        default: {
            cout << "Invalid Choice. Please try again. \n";
            break;
        }
    }
    } while (choice != 4);
    return choice;
}
int main()
{
    UserData userdata;
    userdata.setUserData();
    Hide hide;
    string encripted = hide.encript();
    string decripted = hide.decript();
    cout << encripted << endl;
    Menu menu(1);
    menu.display_Choice();
    return 0;
}
//hiii cheking.
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file