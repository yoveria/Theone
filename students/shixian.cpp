#include "student.h"
using namespace std;
//-----------------------------�����ú���
bool cmp_xuhao(students a, students b)
{
    return a.get_xuhao() < b.get_xuhao();
}
bool cmp_pai(students a, students b)
{
    return a.get_pai() < b.get_pai();
}
bool cmp_score(students a, students b)
{
    return (a.get_score1() + a.get_score2()) > (b.get_score1() + b.get_score2());
}
//------------------------------ȡ���ݺ���
long long students::get_xuhao()
{
    return xuhao;
}
string students::get_name()
{
    return name;
}
int students::get_score1()
{
    return score1;
}
int students::get_score2()
{
    return score2;
}
int students::get_pai()
{
    return pai;
}
//-------------------------------��ʼ��
void ku::jiazai_s()
{
    int n = 0;

    fstream ifh(".\\the_ss.txt", ios::in);
    if (ifh)
    {
        string hang;
        while (getline(ifh, hang, '\n'))
        {
            n++;
        }
        ifh.close();
    }

    fstream ifs("the_ss.txt", ios::in);
    if (ifs)
    {
        if (n == 0)
        {
            cout << "����ѧ��\n";
        }
        for (int i = 0; i < n; i++)
        {
            students tmp;
            ifs >> tmp.pai >> tmp.name >> tmp.xuhao >> tmp.score1 >> tmp.score2;
            st.push_back(tmp);
        }
        s_num = n;
    }
}
//------------------------------��ѯѧ��
void ku::find_()
{
    int input = 0;
    do
    {
        cout << "=============================" << endl;
        cout << "      1.  ��ѧ��     " << endl;  //
        cout << "      2.  ������      " << endl; //
        cout << "      0.  ����        " << endl;
        cout << "=============================" << endl;
        cin >> input;
        if (input == 1)
        {
            find_w_xuhao();
        }
        else if (input == 2)
        {
            find_w_name();
        }
    } while (input);
}
void ku::find_w_name()
{
    cout << "������Ҫ��ѯѧ��������:>";
    string temp;
    cin >> temp;
    for (int i = 0; i < st.size(); i++)
    {
        if (temp == st[i].get_name())
        {
            cout << left << setw(8) << "����" << " " << left << setw(15)
                 << "ѧ��" << left << setw(10) << "��ѧ�ɼ�"
                 << left << setw(15) << "Ӣ��ɼ�" << "\n";
            cout << left << setw(8) << st[i].name << " " << left << setw(15)
                 << st[i].xuhao << left << setw(10) << st[i].score1
                 << left << setw(15) << st[i].score2 << "\n";
            break;
        }
    }
}
void ku::find_w_xuhao()
{
    cout << "������Ҫ��ѯѧ����ѧ��:>";
    long long temp;
    cin >> temp;
    for (int i = 0; i < st.size(); i++)
    {
        if (temp == st[i].get_xuhao())
        {
            cout << left << setw(8) << "����" << " " << left << setw(15)
                 << "ѧ��" << left << setw(10) << "��ѧ�ɼ�"
                 << left << setw(15) << "Ӣ��ɼ�" << "\n";
            cout << right << setw(8) << st[i].name << " " << left << setw(15)
                 << st[i].xuhao << left << setw(8) << st[i].score1
                 << left << setw(8) << st[i].score2 << "\n";
            break;
        }
    }
}
//------------------------------���ѧ��
void ku::tianjia()
{
    ofstream ifo(".\\the_ss.txt", ios::app);
    if (ifo)
    {
        students tmp;
        cout << "������ѧ��������";
        cin >> tmp.name;
        cout << "������ѧ�ţ�";
        cin >> tmp.xuhao;
        cout << "��������ѧ�ɼ���";
        cin >> tmp.score1;
        cout << "������Ӣ��ɼ���";
        cin >> tmp.score2;
        s_num++;
        tmp.pai = s_num;
        cout << "����ӳɹ���\n";
        st.push_back(tmp);
        ifo << s_num << " " << tmp.name << " " << tmp.xuhao << " " << tmp.score1 << " " << tmp.score2 << "\n";
    }
    else
    {
        cerr << "��Ǹ������ʧ�ܡ���";
    }
    Sleep(500);
    system("cls");
}
//------------------------------------ɾ��ѧ��
void ku::del_inf()
{
    cout << "������Ҫɾ����Ϣ��ѧ����ѧ��:>";
    long long temp;
    cin >> temp;
    for (int i = 0; i < st.size(); i++)
    {
        if (temp == st[i].get_xuhao())
        {
            st.erase(st.begin() + i);
            s_num--;
            ss_wenben();

            cout << "��ɾ���ɹ���\n";
            Sleep(500);
            system("cls");
        }
    }
}

void ku::change_inf()
{
    cout << "=============================\n";
    cout << "������Ҫ�޸�ѧ����ѧ��:>";
    long long tmp;
    cin >> tmp;
    int snum = st.size();
    for (int i = 0; i < snum; i++)
    {
        if (st[i].xuhao == tmp)
        {
            cout << "=============================\n";
            cout << "       1.����       \n";
            cout << "       2.��ѧ�ɼ�       \n";
            cout << "       3.Ӣ��ɼ�       \n";
            cout << "       0.����       \n";
            cout << "��ѡ��Ҫ�޸ĵ�����:>";
            int shu;
            cin >> shu;
            switch (shu)
            {
            case 1:
                cout << "����������:>";
                cin >> st[i].name;
                break;
            case 2:
                cout << "��������ѧ�ɼ�:>";
                cin >> st[i].score1;
                break;
            case 3:
                cout << "������Ӣ��ɼ�:>";
                cin >> st[i].score2;
                break;
            case 0:
                Sleep(500);
                cout << "�����سɹ���" << endl
                     << endl;
                break;
            default:
                cout << "��������ѷ���" << endl;
                break;
            }
            if (1 <= shu && shu <= 3)
            {
                ss_wenben();
                cout << "�޸ĳɹ���\n";
            }
        }
    }
}

void ku::show_()
{
    int input = 0;
    do
    {
        cout << "=============================" << endl;
        cout << "      1.  ��ѧ��     " << endl;    //
        cout << "      2.  ���ܳɼ�      " << endl; //
        cout << "      0.  ����        " << endl;
        cout << "=============================" << endl;
        cin >> input;
        if (input == 1)
        {
            zhanshi_w_xuhao();
        }
        else if (input == 2)
        {
            zhanshi_w_score();
        }
    } while (input);
}

void ku::zhanshi_w_xuhao()
{
    sort(st.begin(), st.end(), cmp_xuhao);
    cout << left << setw(8) << "����" << " " << left << setw(15)
         << "ѧ��" << left << setw(10) << "��ѧ�ɼ�"
         << left << setw(15) << "Ӣ��ɼ�" << "\n";
    for (int i = 0; i < (int)st.size(); i++)
    {
        cout << left << setw(8) << st[i].name << " " << left << setw(15)
             << st[i].xuhao << left << setw(10) << st[i].score1
             << left << setw(15) << st[i].score2 << "\n";
    }
    sort(st.begin(), st.end(), cmp_pai);
    return;
}
void ku::zhanshi_w_score()
{
    sort(st.begin(), st.end(), cmp_score);
    cout << left << setw(8) << "����" << " " << left << setw(15)
         << "ѧ��" << left << setw(10) << "��ѧ�ɼ�"
         << left << setw(15) << "Ӣ��ɼ�" << "\n";
    for (int i = 0; i < (int)st.size(); i++)
    {
        cout << left << setw(8) << st[i].name << " " << left << setw(15)
             << st[i].xuhao << left << setw(10) << st[i].score1
             << left << setw(15) << st[i].score2 << "\n";
    }
    sort(st.begin(), st.end(), cmp_pai);
    return;
}