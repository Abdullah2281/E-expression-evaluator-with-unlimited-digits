#include <iostream>
#include "ulimitedrational.h"
using namespace std;
// #define arr_inp(a,n) for(int i=0;i<n;i++) cin>>a[i]
#define p(arr)         \
    for (auto i : arr) \
        cout << i << ' ';
int main()
{
    UnlimitedInt *ap = new UnlimitedInt("567382439779342879134719703429680197324978");
    UnlimitedInt *aq = new UnlimitedInt("2473647324535345");
    cout << ap->get_size() << endl;

    UnlimitedRational *a = new UnlimitedRational(ap, aq);
    cout << a->get_frac_str() << "\n";

    UnlimitedInt *bp = new UnlimitedInt("61342789041983742358931872463578493124857859342483574589314825378910492533245676754345678");
    UnlimitedInt *bq = new UnlimitedInt("345678998765432345678987654345678765434567");
    UnlimitedRational *b = new UnlimitedRational(bp, bq);
    cout << b->get_frac_str() << "\n";

    UnlimitedRational *res = a->add(a, b);
    cout <<  "add: " << res->get_frac_str() << endl;

    delete res;

    res = a->sub(a, b);
    cout << "subtract: " << res->get_frac_str() << endl;

    delete res;

    res = res->mul(a, b);
    cout << "mul: " << res->get_frac_str() << endl;
    delete res;

    res = a->div(a, b);
    cout << "div: " << res->get_frac_str() << endl;
    delete res;

    
    delete ap;
    delete bp;
    delete aq;
    delete bq;
    delete a;
    delete b;

    return 0;
}

//*** check sub with 1