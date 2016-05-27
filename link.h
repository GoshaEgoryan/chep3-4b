/* 
 * File:   link.h
 * Author: Гоша Егорян
 *
 * Created on 27 мая 2016 г., 3:16
 */

#ifndef LINK_H
#define	LINK_H

class Link {
public:
    Link(int tx, int ty, int tw);
    Link(const Link* link);
    int getX() const;
    int getY() const;
    int getW() const;
    Link* getPrev() const;
    Link* getNext() const;
    Link* getClone() const;
    void setX(int t);
    void setY(int t);
    void setW(int t);
    void setPrev(Link* t);
    void setNext(Link* t);
    void print() const;
private:
    int x, y, w;
    Link *prev, *next;
};

#endif	/* LINK_H */

