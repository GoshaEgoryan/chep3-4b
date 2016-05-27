/* 
 * File:   isAll.cpp
 * Author: Гоша Егорян
 *
 * Created on 27 мая 2016 г., 8:02
 */

#include "head.h"

bool isAll(vector<int>& points, int p) {
    for(int i = 1; i <= p; i++) {
        if(!count(points.begin(), points.end(), i)) {
            return false;
        }
    }
    return true;
}
