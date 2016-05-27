/* 
 * File:   main.cpp
 * Author: Гоша Егорян
 *
 * Created on 27 мая 2016 г., 2:23
 */

#include "head.h"

int main() {
    setlocale(LC_ALL, "Russian");

    bool first = true;
    int p, l, x, y, w;
    Link *list, *t;

    cin >> p >> l;

    for (int i = 0; i < l; i++) {
        cin >> x >> y >> w;
        if ((x > p) || (y > p)) {
            cout << "Неверные данные. Пожалуйста, проверьте их и повторите ввод." << endl;
            i--;
            continue;
        }
        if (first) {
            t = new Link(x, y, w, i + 1);
            list = t;
            first = false;
        } else {
            t = new Link(x, y, w, i + 1, t);
            t->getPrev()->setNext(t);
        }
    }
    
    cout << endl << "---------------------------" << endl << endl << "Прима:" << endl;
    t = prim(list, p);
    cout << t->getSumWeight() << endl;
//    while (t != NULL) {
//        cout << t->getN() << " ";
//        t = t->getNext();
//    }
//    
//    cout << endl << endl;

    cout << endl << "---------------------------" << endl << endl << "Крускала:" << endl;
    t = kruskal(list);
    cout << t->getSumWeight() << endl;
    while (t != NULL) {
        cout << t->getN() << " ";
        t = t->getNext();
    }
    
    cout << endl << endl;

    system("pause");
    return 0;
}
