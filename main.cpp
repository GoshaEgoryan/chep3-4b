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
    
    cout << "Введите количество вершин и рёбер:" << endl;
    cin >> p >> l;
    
    for (int i = 0; i < l; i++) {
        cout << "Введите исходную и конечную вершины:" << endl;
        cin >> x >> y;
        if ( (x>p)||(y>p) ) {
            cout << "Неверные данные. Пожалуйста, проверьте их и повторите ввод." << endl;
            i--;
            continue;
        }
        cout << "Введите вес ребра:" << endl;
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
    cout << "Количество вершин в минимальном остовном дереве: " << p << ", рёбер: " << t->getLength() << endl << "Рёбра:" << endl;
    while (t != NULL) {
        t->print();
        t=t->getNext();
    }
    
    system("pause");
    return 0;
}
