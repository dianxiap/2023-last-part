#pragma once
#pragma once
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "operator.h"
#include "head.h"

//初始化顺序表
void init_sta(Sta* pc);
//插入员工信息
void input_sta(Sta* spc, Dep* cpc);

//查找员工信息
void search_sta(Sta* spc, Dep* cpc);
//根据下标查找员工信息
void search_sta_id(Sta* spc, Dep* cpc);
//根据姓名查找员工信息
void search_sta_name(Sta* spc, Dep* cpc);

//显示员工信息
void show_sta(Sta* spc, Dep* cpc);
//编辑员工信息
void edit_sta(Sta* spc, Dep* cpc);
//更新员工信息
void renew_sta(Sta* spc);
//删除员工信息
void delete_sta(Sta* spc, Dep* cpc);
//加载员工信息
void LordSta(Sta* pc);
//管理员工信息
void sta_operate(Sta* spc, Dep* cpc);