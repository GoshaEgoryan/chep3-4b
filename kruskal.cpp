/* 
 * File:   kruskal.cpp
 * Author: Гоша Егорян
 *
 * Created on 27 мая 2016 г., 4:32
 */

#include "head.h"

Link* kruskal(Link* list) {
    Link
            *t = list->copyList()->sortBubble(),
            *result = new Link(t),
            *start = result,
            *act;
    bool q, e;
    start->setNext(NULL);
    while (t->getNext() != NULL) {
        t = t->getNext();
        q = false;
        e = false;
        act = start;
        while (act != NULL) {
            if ((t->getX() == act->getX())||(t->getX() == act->getY())) {
                q = true;
            }
            if ((t->getY() == act->getX())||(t->getY() == act->getY())) {
                e = true;
            }
            act = act->getNext();
        }
        if (q&&e) {
            continue;
        } else {
            result->setNext(new Link(t));
            result->getNext()->setPrev(result);
            result = result->getNext();
            result->setNext(NULL);
        }
    }
    result->setNext(NULL);
    return start;
}
