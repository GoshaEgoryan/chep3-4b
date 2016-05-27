/* 
 * File:   link.cpp
 * Author: ���� ������
 *
 * Created on 27 ��� 2016 �., 3:22
 */

#include "head.h"

Link::Link(const int tx, const int ty, const int tw, Link* tprev, Link* tnext) {
    x = tx;
    y = ty;
    w = tw;
    prev = tprev;
    next = tnext;
}

Link::Link(const Link* link) {
    x = link->getX();
    y = link->getY();
    w = link->getW();
    prev = link->getPrev();
    next = link->getNext();
}

int Link::getX() const {
    return x;
}

int Link::getY() const {
    return y;
}

int Link::getW() const {
    return w;
}

int Link::getLength() {
    return getLinksToEnd() + 1;
}

int Link::getLinksToEnd() {
    int result = 0;
    Link *t = this;
    while (t->getNext() != NULL) {
        t = t->getNext();
        result++;
    }
    return result;
}

Link* Link::getPrev() const {
    return prev;
}

Link* Link::getNext() const {
    return next;
}

Link* Link::getClone() const {
    return new Link(this);
}

Link* Link::getLast() {
    Link *t = this;
    while (t->getNext() != NULL) {
        t = t->getNext();
    }
    return t;
}

Link* Link::getFirst() {
    Link *t = this;
    while (t->getPrev() != NULL) {
        t = t->getPrev();
    }
    return t;
}

void Link::setX(const int t) {
    x = t;
}

void Link::setY(const int t) {
    y = t;
}

void Link::setW(const int t) {
    w = t;
}

void Link::setPrev(Link* t) {
    prev = t;
}

void Link::setNext(Link* t) {
    next = t;
}

void Link::print() const {
    cout << x << " " << y << " " << w << endl;
}

void Link::turnRight() {
    if (next == NULL) {
        return;
    }
    Link *t = next;
    t->setPrev(prev);
    next = t->getNext();
    t->setNext(this);
    prev = t;
}

Link* Link::bubbleSort() {
    Link *list = this->getFirst(), *act;
    bool swapped;
    int length = list->getLength();
    for (int i = 0; i < length - 1; i++) {
        swapped = false;
        act = list;
        for (int j = 0; j < length - i - 1; j++, act = act->getNext()) {
            if (act->getW() > act->getNext()->getW()) {
                act->turnRight();
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
    return list->getFirst();
}