/* 
 * File:   link.cpp
 * Author: Гоша Егорян
 *
 * Created on 27 мая 2016 г., 3:22
 */

#include "head.h"

Link::Link(const int tx, const int ty, const int tw) {
    x = tx;
    y = ty;
    w = tw;
    prev = NULL;
    next = NULL;
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

Link* Link::getPrev() const {
    return prev;
}

Link* Link::getNext() const {
    return next;
}

Link* Link::getClone() const {
    return new Link(this);
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
