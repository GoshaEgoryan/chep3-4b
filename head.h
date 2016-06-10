/* 
 * File:   head.h
 * Author: ���� ������
 *
 * Created on 27 ��� 2016 �., 2:30
 */

#ifndef HEAD_H
#define	HEAD_H

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <fstream>
#include "link.h"

using namespace std;

Link* kruskal(Link *list);
Link* prim(Link *list, int p);
bool isAll(vector<int>& a, int p);

#endif	/* HEAD_H */
