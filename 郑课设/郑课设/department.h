#pragma once
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "operator.h"
#include "head.h"

//初始化顺序表
void initDep(Dep* pc);

//插入部门信息
void input_dep(Sta* spc, Dep* cpc);

//查询部门信息
void search_dep(Sta* spc, Dep* cpc);

//按照编号查找
void search_dep_id(Sta* spc, Dep* cpc);

//按照部门姓名查找
void search_dep_name(Sta* spc, Dep* cpc);

//显示部门信息
void show_dep(Sta* spc, Dep* cpc);

//修改部门信息
void edit_dep(Sta* spc, Dep* cpc);
//更新部门数据库
void renew_dep(Dep* pc);
//删除该部门
void delete_dep(Sta* spc, Dep* cpc);

//部门操作
void dep_operate(Sta* spc, Dep* cpc);

//加载部门数据库
void Lorddep(Dep* pc);