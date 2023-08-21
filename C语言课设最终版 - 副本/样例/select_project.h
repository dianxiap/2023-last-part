#pragma once
//选课记录
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "headdefine.h"
#include "project.h"
#include "student.h"

//开始菜单

//开始页面
void home(Stu* spc, Cou* cpc, Sel* lpc);

//初始化选课记录顺序表
void init_Sel(Sel* pc);

//选课记录
void statistic(Sel* lpc, Stu* spc, Cou* cpc);

//开始选课
void choose(Stu* spc, Cou* cpc, Sel* lpc);

//删除选课记录
void delete_sel(Cou* cpc, Sel* lpc, int q);
