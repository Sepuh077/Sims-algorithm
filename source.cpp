#include <iostream>
#include "tex.h"

using namespace std;

int main() {
    tex a,b, e;
    a.input();
    b.input();
    tex n[5][5];
    tex t[10];
    t[1] = a;
    t[2] = b;
    t[3] = a*a;
    t[4] = b*b;
    t[5] = a*b;
    t[6] = b*a;

    for(int i = 1;i < 7; ++i) {
        int k = 1;
        while(k < 4) {
            if(t[i].a[k] == k)
                k++;
            else if(n[k][t[i].a[k]] == e) {
                n[k][t[i].a[k]] = t[i];
                break;
            }
            else {
                t[i] = t[i] * n[k][t[i].a[k]].hakadardz();
                k++;
            }
        }
    }
    int count = 1;
    for(int i = 1;i < 4; ++i) {
        for(int j = i + 1; j <= 4; ++j) {
            if(n[i][j]!=e) {
                t[count++] = n[i][j];
            }
        }
    }
    if(count != 7) {
        bool newItem = true;
        while(newItem) {
            newItem = false;
            for(int i = 1;i < count; ++i) {
                for(int j = 1; j < count; ++j) {
                    tex t0 = t[i]*t[j];
                    int k = 1;
                    while(k < 4) {
                        if(t0.a[k] == k)
                            k++;
                        else if(n[k][t0.a[k]] == e) {
                            n[k][t0.a[k]] = t0;
                            newItem = true;
                            break;
                        }
                        else {
                            t0 = t0 * (n[k][t0.a[k]].hakadardz());
                            k++;
                        }
                    }
                }
            }
        }
    }
    for(int i = 1;i <= 4; ++i) {
        cout<<endl;
        for(int j = 1;j <= 4; ++j) {
            e.print();
        }
        cout<<endl;
        for(int j = 1;j <= 4; ++j) {
            n[i][j].print();
        }
        cout<<endl;
        for(int j = 1;j <= 43; ++j)
            cout<<'-';
    }
    cout<<endl;
    return 0;
}