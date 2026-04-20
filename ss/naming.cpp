#include <iostream>

#define PI 3.1416

int SPEED = 100;

using namespace std;

class UserInfo
{
public:
    int userId;
    string userName;

    UserInfo(int userId, string userName)
    {
        this->userId = userId;
        this->userName = userName;
    }

    void PrintUserInfo()
    {
        cout << "userId: " << userId << " user_name: " << userName << endl;
    }
};

void cal(int n, int b)
{
    try
    {
        if (b == 0)
        {
            throw runtime_error("Division by zero!");
        }
        cout << n / b << endl;
    }
    catch (exception &e)
    {
        cerr << "Error: " << e.what() << '\n';
    }
}

int main()
{
    int userId;
    // cin >> userId;

    string user_name;
    // cin >> user_name;

    UserInfo student(userId, user_name);

    student.PrintUserInfo();
    cal(1, 0);

    return 0;
}