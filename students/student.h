#ifndef _WINTER_H_
#define _WINTER_H_
#include <iostream>
#include <string.h>
#include <vector>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <algorithm>
using namespace std;
class students;
class ku
{
public:
    void find_();
    void find_w_xuhao();
    void find_w_name();

    void change_inf(); // 修改信息

    void del_inf();

    void show_();
    void zhanshi_w_xuhao(); //
    void zhanshi_w_score(); //

    void tongji();
    int the_ave();  //
    int the_high(); //
    int the_low();  //

    void jiazai_s(); // 初始化
    void tianjia();
    void ss_wenben(); // 刷新文本

protected:
    vector<students> st;
    int s_num;
};

class students
{
public:
    friend class ku;
    long long get_xuhao();
    string get_name();
    int get_pai();
    int get_score1();
    int get_score2();

protected:
    int pai;
    string name;
    long long xuhao;
    int score1;
    int score2;
};

void menu();
#endif