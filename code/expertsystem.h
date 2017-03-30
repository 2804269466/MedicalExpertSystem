#pragma once
#include<iostream>
#include<cstdio>
#include<map>
#include<fstream>
#include<string>
#include<queue>
#include<set>
#include <boost/regex.hpp>
#include<cmath>
#include<QDebug>
#include<Windows.h>


#define MAX_DISEASE_TYPE 10000
#define MAX_SYMPTOM_TYPE 10000
#define SYMPTOM_ABSTRACT 0
#define SYMPTOM_SPECIFIC 1

#define ROOT 0
#define FIRST_LEVEL 1
#define SECOND_LEVEL 2

#define VERY 0.14
#define PROBABLY 0.08
#define NOTLIKELY 0.03

#define TYPE_VERY 0
#define TYPE_PROBABLY 1
#define TYPE_NOTLIKELY 2

using namespace std;

//功能函数 类型转换
string wstr2str(const wstring &wstr);//wstr to str
wstring str2wstr(const string& s);//str to wstr

//前端接口
void ui_map_change(string symptom, double cf, double degree);//前端症状输入监听
void ui_map_output();//查看所有输入症状

//专家系统准备，读取各规则库和编码库
bool read_symptomID(string filepath, string filename);
bool read_diseaseID(string filepath, string filename);
bool read_diseaseType(string filepath, string filename);
bool read_rule_A(string filepath, string filename);
bool read_rule_S(string filepath, string filename);
int system_prepare();

//结果推断
void user_interface();
void view_result();

//变量重置
void reset_environment();

struct UIRes{
    string sdiseasename;
    int possibility;

    friend bool operator < (UIRes a, UIRes b){
        return a.possibility < b.possibility;
    }
};
priority_queue<UIRes> ui_res_map();


