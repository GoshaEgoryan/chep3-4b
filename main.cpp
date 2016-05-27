/* 
 * File:   main.cpp
 * Author: ���� ������
 *
 * Created on 27 ��� 2016 �., 2:23
 */

#include "head.h"

int main() {
    setlocale(LC_ALL, "Russian");
    
    bool first = true;
    int p, l, x, y, w;
    Link *list, *t;
    
    cout << "������� ���������� ������ � ����:" << endl;
    cin >> p >> l;
    
    for (int i = 0; i < l; i++) {
        cout << "������� �������� � �������� �������:" << endl;
        cin >> x >> y;
        if ( (x>p)||(y>p) ) {
            cout << "�������� ������. ����������, ��������� �� � ��������� ����." << endl;
            i--;
            continue;
        }
        cout << "������� ��� �����:" << endl;
        cin >> w;
        if (first) {
            t = new Link(x, y, w);
            list = t;
            first = false;
        } else {
            t = new Link(x, y, w, t);
            t->getPrev()->setNext(t);
        }
    }
    
    list = kruskal(list);
    
    t = list;
    cout << "���������� ������ � ����������� �������� ������: " << p << ", ����: " << t->getLength() << endl << "и���:" << endl;
    while (t != NULL) {
        t->print();
        t=t->getNext();
    }
    
    system("pause");
    return 0;
}
