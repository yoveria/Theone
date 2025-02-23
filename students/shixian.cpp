#include "student.h"
using namespace std;
//-----------------------------排序用函数
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
//------------------------------取内容函数
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
//-------------------------------初始化
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
            cout << "暂无学生\n";
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
//------------------------------查询学生
void ku::find_()
{
    int input = 0;
    do
    {
        cout << "=============================" << endl;
        cout << "      1.  按学号     " << endl;  //
        cout << "      2.  按姓名      " << endl; //
        cout << "      0.  返回        " << endl;
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
    cout << "请输入要查询学生的姓名:>";
    string temp;
    cin >> temp;
    for (int i = 0; i < st.size(); i++)
    {
        if (temp == st[i].get_name())
        {
            cout << left << setw(8) << "姓名" << " " << left << setw(15)
                 << "学号" << left << setw(10) << "数学成绩"
                 << left << setw(15) << "英语成绩" << "\n";
            cout << left << setw(8) << st[i].name << " " << left << setw(15)
                 << st[i].xuhao << left << setw(10) << st[i].score1
                 << left << setw(15) << st[i].score2 << "\n";
            break;
        }
    }
}
void ku::find_w_xuhao()
{
    cout << "请输入要查询学生的学号:>";
    long long temp;
    cin >> temp;
    for (int i = 0; i < st.size(); i++)
    {
        if (temp == st[i].get_xuhao())
        {
            cout << left << setw(8) << "姓名" << " " << left << setw(15)
                 << "学号" << left << setw(10) << "数学成绩"
                 << left << setw(15) << "英语成绩" << "\n";
            cout << right << setw(8) << st[i].name << " " << left << setw(15)
                 << st[i].xuhao << left << setw(8) << st[i].score1
                 << left << setw(8) << st[i].score2 << "\n";
            break;
        }
    }
}
//------------------------------添加学生
void ku::tianjia()
{
    ofstream ifo(".\\the_ss.txt", ios::app);
    if (ifo)
    {
        students tmp;
        cout << "请输入学生姓名：";
        cin >> tmp.name;
        cout << "请输入学号：";
        cin >> tmp.xuhao;
        cout << "请输入数学成绩：";
        cin >> tmp.score1;
        cout << "请输入英语成绩：";
        cin >> tmp.score2;
        s_num++;
        tmp.pai = s_num;
        cout << "【添加成功】\n";
        st.push_back(tmp);
        ifo << s_num << " " << tmp.name << " " << tmp.xuhao << " " << tmp.score1 << " " << tmp.score2 << "\n";
    }
    else
    {
        cerr << "抱歉，加载失败……";
    }
    Sleep(500);
    system("cls");
}
//------------------------------------删除学生
void ku::del_inf()
{
    cout << "请输入要删除信息的学生的学号:>";
    long long temp;
    cin >> temp;
    for (int i = 0; i < st.size(); i++)
    {
        if (temp == st[i].get_xuhao())
        {
            st.erase(st.begin() + i);
            s_num--;
            ss_wenben();

            cout << "【删除成功】\n";
            Sleep(500);
            system("cls");
        }
    }
}

void ku::change_inf()
{
    cout << "=============================\n";
    cout << "请输入要修改学生的学号:>";
    long long tmp;
    cin >> tmp;
    int snum = st.size();
    for (int i = 0; i < snum; i++)
    {
        if (st[i].xuhao == tmp)
        {
            cout << "=============================\n";
            cout << "       1.姓名       \n";
            cout << "       2.数学成绩       \n";
            cout << "       3.英语成绩       \n";
            cout << "       0.返回       \n";
            cout << "请选择要修改的内容:>";
            int shu;
            cin >> shu;
            switch (shu)
            {
            case 1:
                cout << "请输入姓名:>";
                cin >> st[i].name;
                break;
            case 2:
                cout << "请输入数学成绩:>";
                cin >> st[i].score1;
                break;
            case 3:
                cout << "请输入英语成绩:>";
                cin >> st[i].score2;
                break;
            case 0:
                Sleep(500);
                cout << "【返回成功】" << endl
                     << endl;
                break;
            default:
                cout << "输入错误，已返回" << endl;
                break;
            }
            if (1 <= shu && shu <= 3)
            {
                ss_wenben();
                cout << "修改成功！\n";
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
        cout << "      1.  按学号     " << endl;    //
        cout << "      2.  按总成绩      " << endl; //
        cout << "      0.  返回        " << endl;
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
    cout << left << setw(8) << "姓名" << " " << left << setw(15)
         << "学号" << left << setw(10) << "数学成绩"
         << left << setw(15) << "英语成绩" << "\n";
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
    cout << left << setw(8) << "姓名" << " " << left << setw(15)
         << "学号" << left << setw(10) << "数学成绩"
         << left << setw(15) << "英语成绩" << "\n";
    for (int i = 0; i < (int)st.size(); i++)
    {
        cout << left << setw(8) << st[i].name << " " << left << setw(15)
             << st[i].xuhao << left << setw(10) << st[i].score1
             << left << setw(15) << st[i].score2 << "\n";
    }
    sort(st.begin(), st.end(), cmp_pai);
    return;
}