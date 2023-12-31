/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "ulimitedrational.h"
#include<iostream>
using namespace std;

string gcd(string a, string b) {
    UnlimitedInt *a1 = new UnlimitedInt(a);
    UnlimitedInt *a2 = new UnlimitedInt(b);
    if(b == "0") {
        return a;
    }
    UnlimitedInt *a3;
    a3 = a3->mod(a1,a2);
    delete a1;
    delete a2;
    return gcd(b, a3->to_string());
}

string str(string s) {
     string result = "";
     int size = s.size();
    if (!s.empty() && s[0]=='-') {
        s = s.substr(1); 
    }
    return s;
}

UnlimitedRational::UnlimitedRational() {

}

UnlimitedRational::UnlimitedRational(UnlimitedInt* num, UnlimitedInt* den) {
    string s1a = num->to_string();
    string s2a = den->to_string();
    string a = str(s1a);
    string b = str(s2a);

    if(b == "0") {
        p = new UnlimitedInt("0");
        q = new UnlimitedInt("0");
        return;
    }

    else {
    string c = gcd(a,b);
    // printf("%s GCD\n",c.c_str());
    
    UnlimitedInt *a3=new UnlimitedInt(c);
    p = a3->div(num,a3);
    num = a3;

   q=a3->div(den,a3);
   delete a3;
    }
}

UnlimitedRational::~UnlimitedRational() {
    delete p;
    delete q;
}

UnlimitedInt *UnlimitedRational::get_p() {
    return p;
}

UnlimitedInt *UnlimitedRational::get_q() {
    return q;
}

string UnlimitedRational::get_p_str() {
    return p->to_string();
}

string UnlimitedRational::get_q_str() {
    return q->to_string();
}

string UnlimitedRational::get_frac_str() {
    string ans = "";
    ans+=get_p_str();
    ans+="/";
    ans+=get_q_str();
    return ans;
}


UnlimitedRational *UnlimitedRational::add(UnlimitedRational* i1, UnlimitedRational* i2) {
    if (str(i1->q->to_string()) == "0" || str(i2->q->to_string()) == "0") {
        return new UnlimitedRational(new UnlimitedInt("0"), new UnlimitedInt("0"));
    }

    UnlimitedInt *n1 = i1->get_p();
    UnlimitedInt *d1 = i1->get_q();
    UnlimitedInt *n2 = i2->get_p();
    UnlimitedInt *d2 = i2->get_q();

    UnlimitedInt *n = new UnlimitedInt(); 
    UnlimitedInt *p1 = new UnlimitedInt(); 
    UnlimitedInt *p2 = new UnlimitedInt();

    p1 = p1->mul(n1, d2);
    p2 = p2->mul(n2,d1);
    n = n->add(p1,p2);

    UnlimitedInt *d = new UnlimitedInt();
    d = d->mul(d1,d2);

    UnlimitedRational *ans = new UnlimitedRational(n, d);
    delete n;
    delete p1;
    delete p2;
    delete d;
    return ans;
}

UnlimitedRational *UnlimitedRational::sub(UnlimitedRational* i1, UnlimitedRational* i2) {
    if (str(i1->q->to_string()) == "0" || str(i2->q->to_string()) == "0") {
        return new UnlimitedRational(new UnlimitedInt("0"), new UnlimitedInt("0"));
    }

    UnlimitedInt *n1 = i1->get_p();
    UnlimitedInt *d1 = i1->get_q();
    UnlimitedInt *n2 = i2->get_p();
    UnlimitedInt *d2 = i2->get_q();

    UnlimitedInt *n = new UnlimitedInt(); 
    UnlimitedInt *p1 = new UnlimitedInt(); 
    UnlimitedInt *p2 = new UnlimitedInt();

    p1 = p1->mul(n1, d2);
    p2 = p2->mul(n2,d1);
    n = n->sub(p1,p2);

    UnlimitedInt *d = new UnlimitedInt();
    d = d->mul(d1,d2);

    UnlimitedRational *ans = new UnlimitedRational(n, d);
    delete n;
    delete p1;
    delete p2;
    delete d;
    return ans;
}

UnlimitedRational *UnlimitedRational::mul(UnlimitedRational* i1, UnlimitedRational* i2) {
    if (str(i1->q->to_string()) == "0" || str(i2->q->to_string()) == "0") {
        return new UnlimitedRational(new UnlimitedInt("0"), new UnlimitedInt("0"));
    }

    UnlimitedInt *n1 = i1->get_p();
    UnlimitedInt *d1 = i1->get_q();
    UnlimitedInt *n2 = i2->get_p();
    UnlimitedInt *d2 = i2->get_q();

    UnlimitedInt *n = new UnlimitedInt();
    n = n->mul(n1, n2);

    UnlimitedInt *d = new UnlimitedInt();
    d = d->mul(d1, d2);

    UnlimitedRational *ans = new UnlimitedRational(n, d);
    delete n;
    delete d;
    return ans;
}

UnlimitedRational *UnlimitedRational::div(UnlimitedRational* i1, UnlimitedRational* i2) {
    if (str(i1->q->to_string()) == "0" || str(i2->q->to_string()) == "0") {
        return new UnlimitedRational(new UnlimitedInt("0"), new UnlimitedInt("0"));
    }

    UnlimitedInt *n1 = i1->get_p();
    UnlimitedInt *d1 = i1->get_q();
    UnlimitedInt *n2 = i2->get_p();
    UnlimitedInt *d2 = i2->get_q();

    UnlimitedInt *n = new UnlimitedInt();
    n = n->mul(n1, d2);

    UnlimitedInt *d = new UnlimitedInt();
    d = d->mul(d1, n2);

    UnlimitedRational *ans = new UnlimitedRational(n, d);
    delete n;
    delete d;
    return ans;
}
// int main()
// {
//     UnlimitedInt *ap = new UnlimitedInt(-1);
//     UnlimitedInt *aq = new UnlimitedInt("5");
//     cout << ap->get_size() << endl;

//     UnlimitedRational *a = new UnlimitedRational(ap, aq);
//     cout << a->get_frac_str() << "\n";

//     UnlimitedInt *bp = new UnlimitedInt(0);
//     UnlimitedInt *bq = new UnlimitedInt(-0);
//     UnlimitedRational *b = new UnlimitedRational(bp, bq);
//     cout << b->get_frac_str() << "\n";

//     UnlimitedRational *res = a->add(a, b);
//     cout << res->get_frac_str() << endl;

//     delete res;

//     res = a->sub(a, b);
//     cout << res->get_frac_str() << endl;

//     delete res;

//     res = res->mul(a, b);
//     cout << res->get_frac_str() << endl;
//     delete res;

//     res = a->div(a, b);
//     cout << res->get_frac_str() << endl;
//     delete res;

    
//     delete ap;
//     delete bp;
//     delete aq;
//     delete bq;
//     delete a;
//     delete b;

//     return 0;
// }
