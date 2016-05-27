/* 
 * File:   prim.cpp
 * Author: ���� ������
 *
 * Created on 27 ��� 2016 �., 7:24
 */

#include "head.h"

Link* prim(Link *input, int p) {
    bool first = true;
    int minW, num;
    vector<int> points;
    Link
            *start = input->copyList()->getFirst(),
            *start_t,
            *end,
            *end_t;
    points.push_back(start->getX());
    while (!isAll(points, p)) {
        minW = start->maxW();
        start_t = start;
        while (start_t != NULL) {
            if
                (
                    (
                        (
                            count(points.begin(), points.end(), start_t->getX())
                            +
                            count(points.begin(), points.end(), start_t->getY())
                        )
                        == 1
                    )
                    &&
                    (
                        minW > start_t->getW()
                    )
                ) {
                minW = start_t->getW();
                num = start_t->getN();
            }
            start_t = start_t->getNext();
        }
        if (first) {
            end = new Link(start->findForNum(num));
            end_t = end;
            end_t->setNext(NULL);
            end_t->setPrev(NULL);
            first = false;
        } else {
            end_t->addNewLink(start->findForNum(num));
            end_t = end_t->getNext();
        }
        if (!count(points.begin(), points.end(), end_t->getX())) {
            points.push_back(end_t->getX());
        }
        if (!count(points.begin(), points.end(), end_t->getY())) {
            points.push_back(end_t->getY());
        }
    }
    return end;
}
