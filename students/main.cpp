#include "student.h"
// #include "shixian.cpp"
// #include "mainfx.cpp"
using namespace std;
int main()
{
    ku lib;
    lib.jiazai_s();
    int input = 0;
    do
    {
        menu();
        printf("����������ѡ��:>");
        cin >> input;
        system("cls");
        switch (input)
        {
        case 1:
            lib.find_();
            break;
        case 2:
            lib.tianjia();
            break;
        case 3:
            lib.change_inf();
            break;
        case 4:
            lib.del_inf();
        case 5:
            lib.show_();
        case 0:
            Sleep(600);
            cout << "���˳��ɹ���" << "\n";
            break;
        default:
            cout << "�����������������" << endl;
            break;
        }
    } while (input);
    return 0;
}