/* 
 * File:   main.cpp
 * Author: Гоша Егорян
 *
 * Created on 27 мая 2016 г., 2:23
 */

#include "head.h"

int main() {
    setlocale(LC_ALL, "Russian");
    ifstream fin;
    ofstream fout;
    
    fin.open("test.txt");
    fout.open("results.txt");

    bool first = true;
    int p, l, x, y, w;
    Link *list, *t;

    fin >> p >> l;

    for (int i = 0; i < l; i++) {
        fin >> x >> y >> w;
        if ((x > p) || (y > p)) {
            fout << "Неверные данные. Пожалуйста, проверьте их и повторите ввод. (" << x << " " << y << " " << w << ")" << endl;
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
    
    fout << endl << "---------------------------" << endl << endl << "Прима:" << endl;
    t = prim(list, p);
    fout << t->getSumWeight() << endl;
//    while (t != NULL) {
//        cout << t->getN() << " ";
//        t = t->getNext();
//    }
//    
//    cout << endl << endl;

    fout << endl << "---------------------------" << endl << endl << "Крускала:" << endl;
    t = kruskal(list);
    fout << t->getSumWeight() << endl;
    while (t != NULL) {
        fout << t->getN() << " ";
        t = t->getNext();
    }
    
    fout << endl << endl;

    system("pause");
    return 0;
}
