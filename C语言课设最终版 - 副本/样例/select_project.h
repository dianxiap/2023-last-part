#pragma once
//ѡ�μ�¼
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "headdefine.h"
#include "project.h"
#include "student.h"

//��ʼ�˵�

//��ʼҳ��
void home(Stu* spc, Cou* cpc, Sel* lpc);

//��ʼ��ѡ�μ�¼˳���
void init_Sel(Sel* pc);

//ѡ�μ�¼
void statistic(Sel* lpc, Stu* spc, Cou* cpc);

//��ʼѡ��
void choose(Stu* spc, Cou* cpc, Sel* lpc);

//ɾ��ѡ�μ�¼
void delete_sel(Cou* cpc, Sel* lpc, int q);
