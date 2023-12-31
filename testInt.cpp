#include <iostream>
#include "ulimitedint.h"
using namespace std;
// #define arr_inp(a,n) for(int i=0;i<n;i++) cin>>a[i]
#define p(arr)         \
    for (auto i : arr) \
        cout << i << ' ';
int main()
{
    UnlimitedInt *l = new UnlimitedInt(0);
    UnlimitedInt *k = new UnlimitedInt("3");
    UnlimitedInt *a;
    UnlimitedInt *e;
    UnlimitedInt *p;
    UnlimitedInt *d;
    UnlimitedInt *q;


    cout << l->get_size() << "\n";
    cout << k->get_size() << endl;
    cout << l->get_sign() << endl;
    cout << k->get_sign() << endl;
    int *b;
    b = l->get_array();
    int *c;
    c = k->get_array();

    for(int i=0; i<l->get_size(); i++) {
        cout << b[i] << " " ;
    } cout << endl;

    for(int i=0; i<k->get_size(); i++) {
        cout << c[i] << " " ; 
    }cout << endl;

    string s = l-> to_string();
    cout << s << endl;

    string s1 = k->to_string();
    cout << s1 << endl;


    a = a->add(l, k);
    cout << "sum ka size : " << a->get_size() << endl;
    cout << "addition ka magnitude : " << a->to_string() << endl;
    cout << "sign of add : " << a->get_sign() << endl;
    cout << endl;

    e=e->sub(l, k);
    cout << "sub ka size : " << e->get_size() << endl;
    cout << "sub ka magnitude : " << e->to_string() << endl;
    cout << "sign of sub : " << e->get_sign() << endl;
    cout << endl;

    p=p->mul(l, k);
    cout << "mul ka size : " << p->get_size() << endl;
    cout << "mul ka magnitude : " << p->to_string() << endl;
    cout << "sign of mul : " << p->get_sign() << endl;
    cout << endl;

    d=d->div(l, k);
    cout << "div ka size : " << d->get_size() << endl;
    cout << "div ka magnitude : " << d->to_string() << endl;
    cout << "sign of div : " << d->get_sign() << endl;
    cout << endl;

    q=q->mod(l, k);
    cout << "mod ka size : " << q->get_size() << endl;
    cout << "mod ka magnitude : " << q->to_string() << endl;
    cout << "sign of mod : " << q->get_sign() << endl;
    cout << endl;



    // int *b;
    // b = a->get_array();

    // for (int i = 0; i < a->get_size(); i++)
    // {
    //     cout << b[i] << " ";
    // }
    // cout << "\n";
    // cout << a->get_sign() << "\n";
    // cout << a->to_string();
    return 0;
}