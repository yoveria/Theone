#include "student.h"
using namespace std;

void menu()
{
    cout << "       *欢迎进入学生信息管理系统*       " << endl;
    cout << "=============================" << endl;
    cout << "      1.  查询       " << endl;
    cout << "      2.  添加       " << endl;
    cout << "      3.  修改       " << endl;
    cout << "      4.  删除       " << endl;
    cout << "      5.  显示       " << endl;
    cout << "      0.  退出系统         " << endl;
    cout << "=============================" << endl;
}

void ku::ss_wenben()
{
    fstream ifb(".\\the_ss.txt", ios::out);

    for (int i = 0; i < st.size(); i++)
    {
        ifb << st[i].pai << " " << st[i].name << " " << st[i].xuhao << " " << st[i].score1 << " " << st[i].score2 << "\n";
    }
}