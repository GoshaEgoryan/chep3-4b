/* 
 * File:   link.h
 * Author: ���� ������
 *
 * Created on 27 ��� 2016 �., 3:16
 */

#ifndef LINK_H
#define	LINK_H

class Link {
public:
    Link(int tx, int ty, int tw, int tn = 0, Link* tprev = NULL, Link* tnext = NULL);
    Link(const Link* link);
    int getX() const;
    int getY() const;
    int getW() const;
    int getN() const;
    int getLength();
    int getLinksToEnd();
    Link* getPrev() const;
    Link* getNext() const;
    Link* getClone() const;
    Link* getLast();
    Link* getFirst();
    void setX(int t);
    void setY(int t);
    void setW(int t);
    void setN(int t);
    void setPrev(Link* t);
    void setNext(Link* t);
    void print() const;
    void turnRight();
    Link* sortBubble();
    Link* copyList();
    long int getSumWeight();
private:
    int x, y, w, n;
    Link *prev, *next;
};

#endif	/* LINK_H */

