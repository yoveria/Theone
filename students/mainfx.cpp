#include "student.h"
using namespace std;

void menu()
{
    cout << "       *��ӭ����ѧ����Ϣ����ϵͳ*       " << endl;
    cout << "=============================" << endl;
    cout << "      1.  ��ѯ       " << endl;
    cout << "      2.  ���       " << endl;
    cout << "      3.  �޸�       " << endl;
    cout << "      4.  ɾ��       " << endl;
    cout << "      5.  ��ʾ       " << endl;
    cout << "      0.  �˳�ϵͳ         " << endl;
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