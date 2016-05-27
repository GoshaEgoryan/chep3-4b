/* 
 * File:   link.cpp
 * Author: ���� ������
 *
 * Created on 27 ��� 2016 �., 3:22
 */

#include "head.h"

Link::Link(const int tx, const int ty, const int tw, const int tn, Link* tprev, Link* tnext) {
    x = tx;
    y = ty;
    w = tw;
    n = tn;
    prev = tprev;
    next = tnext;
}

Link::Link(const Link* link) {
    x = link->getX();
    y = link->getY();
    w = link->getW();
    n = link->getN();
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

int Link::getN() const {
    return n;
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

void Link::setN(const int t) {
    n = t;
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
    Link
            *a = prev,
            *b = this,
            *c = next,
            *d = next->getNext();
    if (a != NULL) {
        a->setNext(c);
    }
    if (d != NULL) {
        d->setPrev(b);
    }
    b->setPrev(c);
    b->setNext(d);
    c->setPrev(a);
    c->setNext(b);
}

Link* Link::sortBubble() {
    Link *list = this->getFirst(), *act;
    int length = list->getLength();
    for (int i = 0; i < length - 1; i++) {
        act = list;
        for (int j = 0; j < length - i - 1; j++, act = act->getNext()) {
            if (act->getW() > act->getNext()->getW()) {
                act->turnRight();
                act = act->getPrev();
            }
        }
    }
    return list->getFirst();
}

Link* Link::copyList() {
    Link* act = this->getFirst();
    Link* result = new Link(act);
    while (act->getNext() != NULL) {
        result->setNext(new Link(act->getNext()));
        result->getNext()->setPrev(result);
        result = result->getNext();
        act = act->getNext();
    }
    return result->getFirst();
}

long int Link::getSumWeight() {
    long int result = 0;
    Link *t = this->getFirst();
    while (t != NULL) {
        result += t->getW();
        t = t->getNext();
    }
    return result;
}

bool Link::hasNum(const int t) {
    Link *act = this->getFirst();
    while (act != NULL) {
        if (act->getN() == t) {
            return true;
        }
        act = act->getNext();
    }
    return false;
}

bool Link::addNewLink(Link* link) {
    if (next != NULL) {
        return false;
    }
    next = new Link(link);
    next->setPrev(this);
    next->setNext(NULL);
    return true;
}

int Link::maxW() {
    int i = 0;
    Link* t = this->getFirst();
    while (t != NULL) {
        if (i < t->getW()) {
            i = t->getW();
        }
        t = t->getNext();
    }
    return i;
}

Link* Link::findForNum(int i) {
    Link *t = this->getFirst();
    while (t != NULL) {
        if (t->getN() == i) {
            return t;
        }
        t = t->getNext();
    }
    return this;
}
