/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "ulimitedint.h"

//constructors
UnlimitedInt::UnlimitedInt() {
    sign = 1;
    capacity = 1;
    size = 0;
    unlimited_int = new int[capacity]();
}

UnlimitedInt::UnlimitedInt(string s) {
    if (s[0] == '-') {
        sign = -1;
        size = s.length() - 1;
        capacity = size;
        unlimited_int = new int[capacity]();

        for (int i = 1; i < s.length(); i++) {
            unlimited_int[i - 1] = s[i] - '0';
        }
    } else {
        sign = 1;
        size = s.length();
        capacity = size;
        unlimited_int = new int[capacity]();

        for (int i = 0; i < s.length(); i++) {
            unlimited_int[i] = s[i] - '0';
        }
    }
}

UnlimitedInt::UnlimitedInt(int i) {
    if(i == 0) {
        size = 1;
        capacity = 1;
        sign = 1;
        unlimited_int = new int[capacity]();
        return;
    }

    if(i<0) {
        sign = -1;
        i=-i;
    }
    else {
        sign = 1;
    }
    int temp = i;
    int s = 0;
    while(temp != 0) {
        temp = temp/10;
        s++;
    }

    size = s;
    capacity = s;
    unlimited_int = new int[capacity]();
    temp = i;
    for(int j = size - 1; j >= 0; j--) {
        unlimited_int[j] = temp%10;
        temp = temp/10;
    }

}

UnlimitedInt::UnlimitedInt(int* ulimited_int, int cap, int sgn, int sz) {
    capacity = cap;
    sign = sgn;
    size = sz;
    capacity = size;
    ulimited_int = new int[capacity]();
}

//destructor
UnlimitedInt::~UnlimitedInt() {
        delete[] unlimited_int;
}

//functions
int UnlimitedInt::get_size() {
    return size;
}

int* UnlimitedInt::get_array() {
    return unlimited_int;
}

int UnlimitedInt::get_sign() {
    return sign;
}

int UnlimitedInt::get_capacity() {
    return capacity;
}

bool bigger(string s1, string s2) {
    int len1 = s1.length();
    int len2 = s2.length();

    if (len1 < len2) {
        return false; // s1 is smaller
    } else if (len1 > len2) {
        return true; // s1 is larger
    } else {
        for (int i = 0; i < len1; i++) {
            if (s1[i] < s2[i]) {
                return false; // s1 is smaller
            } else if (s1[i] > s2[i]) {
                return true; // s1 is larger
            }
        }
    }
    return true;  // yaha galti ho sakta hai
}

string to_str(string s) {
     string result = "";
     int size = s.size();
    if (!s.empty() && s[0]=='-') {
        s = s.substr(1); 
    }
    return s;
}

string UnlimitedInt::to_string() {
     string result = "";
     if(sign == -1) {
        result+="-";
     }
    int size = get_size();
    for (int i = 0; i < size; i++) {
        result += std::to_string(unlimited_int[i]);
    }
    return result;
}


UnlimitedInt *UnlimitedInt::add(UnlimitedInt* i1, UnlimitedInt* i2) {

    string s1a = i1->to_string();
    string s2a = i2->to_string();
    string s1 = to_str(s1a);
    string s2 = to_str(s2a);

    int sign1 = i1->get_sign();
    int sign2 = i2->get_sign();

    //agar dono +ve ho to normal add
    if(sign1 == 1 && sign2 == 1) {
    string result = "";
    int carry = 0;
    int i = s1.size() - 1;
    int j = s2.size() - 1;
    while (i >= 0 || j >= 0 || carry) {
        int digit1, digit2;

if (i >= 0) {
    digit1 = s1[i] - '0';
} else {
    digit1 = 0;
}

if (j >= 0) {
    digit2 = s2[j] - '0';
} else {
    digit2 = 0;
}

        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result = std::to_string(sum % 10) + result;
        i--;
        j--;
    }
    UnlimitedInt* ans = new UnlimitedInt(result);
    ans->sign = 1;
    return ans;
    }  


    //agar ek +ve aur ek -ve
    // pahla +ve dusra -ve and pahla bada aur pahla -ve dusra +ve and pahla bada then ans mag same but sign diff
    if((sign1 == 1 && sign2 == -1 && bigger(s1,s2)) || (sign1 == -1 && sign2 == 1 && bigger(s1,s2))) {
    string result = "";
    int borrow = 0;
    int i = s1.size() - 1;
    int j = s2.size() - 1;
    while (i >= 0) {
        int digit1 = s1[i] - '0';
        int digit2 = (j >= 0) ? (s2[j] - '0') : 0;
        int diff = digit1 - digit2 - borrow;

        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result = std::to_string(diff) + result;
        i--;
        j--;
    }
    // Remove leading zeros
    result.erase(0, min(result.find_first_not_of('0'), result.size() - 1));
    UnlimitedInt* ans = new UnlimitedInt(result);
    if(sign1 == 1 && sign2 == -1 && bigger(s1,s2)) {
        ans -> sign = 1;
    }
    else {
        ans -> sign = -1;
    }
    return ans;
    }


    // pahla +ve dusra -ve and pahla wala chota ya pahla -ve dusra +ve and pahla chota then ans magnitude same but sign diff
    if((sign1==1 && sign2 ==-1 && !bigger(s1,s2)) || (sign1==-1 && sign2==1 && !bigger(s1,s2))) {
    string result = "";
    int borrow = 0;
    int i = s2.size() - 1;
    int j = s1.size() - 1;

    while (i >= 0) {
        int digit1 = s2[i] - '0';
        int digit2 = (j >= 0) ? (s1[j] - '0') : 0;
        int diff = digit1 - digit2 - borrow;

        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        result = std::to_string(diff) + result;
        i--;
        j--;
    }

    // Remove leading zeros
    result.erase(0, result.find_first_not_of('0'));
    UnlimitedInt* ans = new UnlimitedInt(result);
    if(sign1 == 1 && sign2 == -1 && !bigger(s1,s2)) {
        ans->sign = -1;
    }
    else {
        ans -> sign = 1;
    }
    return ans;
    }


    //agar pahla and dusra dono negative 
    if(sign1 == -1 && sign2 == -1) {
    string result = "";
    int carry = 0;
    int i = s1.size() - 1;
    int j = s2.size() - 1;
    while (i >= 0 || j >= 0 || carry) {
        int digit1, digit2;

        if (i >= 0) {
        digit1 = s1[i] - '0';
        } 
        else {
        digit1 = 0;
    }

if (j >= 0) {
    digit2 = s2[j] - '0';
} 
else {
    digit2 = 0;
}
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result = std::to_string(sum % 10) + result;
        i--;
        j--;
    }
    UnlimitedInt* ans = new UnlimitedInt(result);
    ans->sign = -1;
    return ans;
    } 
    return new UnlimitedInt("0");
}



UnlimitedInt *UnlimitedInt::sub(UnlimitedInt* i1, UnlimitedInt* i2) {
    string s1a = i1->to_string();
    string s2a = i2->to_string();
    string s1 = to_str(s1a);
    string s2 = to_str(s2a);
    
    int sign1 = i1->get_sign();
    int sign2 = i2->get_sign();

    //dono +ve and pahla wala jyada bada to normal subtract
    if(sign1 == 1 && sign2==1 && bigger(s1,s2) || (sign1==-1 && sign2==-1 && bigger(s1,s2))) {
        string result = "";
    int borrow = 0;
    int i = s1.size() - 1;
    int j = s2.size() - 1;
    while (i >= 0) {
        int digit1 = s1[i] - '0';
        int digit2 = (j >= 0) ? (s2[j] - '0') : 0;
        int diff = digit1 - digit2 - borrow;

        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result = std::to_string(diff) + result;
        i--;
        j--;
    }
    result.erase(0, min(result.find_first_not_of('0'), result.size() - 1));
    UnlimitedInt* ans = new UnlimitedInt(result);
    if(sign1 == 1 && sign2==1 && bigger(s1,s2)) {
        ans ->sign = 1;
    }
    else {
        ans ->sign = -1;
    }
    return ans;
    }

    if((sign1==1 && sign2==-1) || (sign1==-1 && sign2==1)) {
    string result = "";
    int carry = 0;
    int i = s1.size() - 1;
    int j = s2.size() - 1;
    while (i >= 0 || j >= 0 || carry) {
        int digit1, digit2;

if (i >= 0) {
    digit1 = s1[i] - '0';
} else {
    digit1 = 0;
}

if (j >= 0) {
    digit2 = s2[j] - '0';
} else {
    digit2 = 0;
}

        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result = std::to_string(sum % 10) + result;
        i--;
        j--;
    }
    UnlimitedInt* ans = new UnlimitedInt(result);
    if(sign1==1 && sign2==-1) {
        ans->sign = 1;
    }
    else {
        ans->sign = -1;
    }
    return ans;
    }

    if((sign1==-1 && sign2==-1 && !bigger(s1,s2)) || (sign1==1 && sign2==1 && !bigger(s1,s2))) {
    string result = "";
    int borrow = 0;
    int i = s2.size() - 1;
    int j = s1.size() - 1;

    while (i >= 0) {
        int digit1 = s2[i] - '0';
        int digit2 = (j >= 0) ? (s1[j] - '0') : 0;
        int diff = digit1 - digit2 - borrow;

        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        result = std::to_string(diff) + result;
        i--;
        j--;
    }
    result.erase(0, result.find_first_not_of('0'));
    UnlimitedInt* ans = new UnlimitedInt(result);
    if(sign1 == -1 && sign2 == -1 && !bigger(s1,s2)) {
        ans->sign = 1;
    }
    else {
        ans -> sign = -1;
    }
    return ans;
    }
    return new UnlimitedInt("0");
}


string addStrings(string s1, string s2) {
    string result = "";
    int carry = 0;
    int i = s1.size() - 1;
    int j = s2.size() - 1;

    while (i >= 0 || j >= 0 || carry > 0) {
        int digit1, digit2;

if (i >= 0) {
    digit1 = s1[i] - '0';
} else {
    digit1 = 0;
}

if (j >= 0) {
    digit2 = s2[j] - '0';
} else {
    digit2 = 0;
}

        int sum = digit1 + digit2 + carry;

        carry = sum / 10;
        sum = sum % 10;

        result = std::to_string(sum) + result;

        i--;
        j--;
    }
    return result;
}


string multiplyByDigit(string s, int d) { //d belongs to [0,9]
    if (d == 0) {
        return "0";
    }
    string result = "";
    int carry = 0;

    for (int i = s.size() - 1; i >= 0; i--) {
        int product = (s[i] - '0') * d + carry;
        carry = product / 10;
        product = product % 10;
        result = std::to_string(product) + result;
    }

    if (carry > 0) {
        result = std::to_string(carry) + result;
    }

    return result;
}


UnlimitedInt *UnlimitedInt::mul(UnlimitedInt* i1, UnlimitedInt* i2) {
    string s1a = i1->to_string();
    string s2a = i2->to_string();
    string s1 = to_str(s1a);
    string s2 = to_str(s2a);
    
    int sign1 = i1->get_sign();
    int sign2 = i2->get_sign();

    string result = "0";

    for (int i = s2.size() - 1; i >= 0; i--) {
        int digit = s2[i] - '0';
        std::string product = multiplyByDigit(s1, digit);
        int zeros = s2.size() - 1 - i;
        for (int j = 0; j < zeros; j++) {
            product += "0";
        }
        result = addStrings(result, product);
    }
    result.erase(0, min(result.find_first_not_of('0'), result.size() - 1));
    UnlimitedInt* ans = new UnlimitedInt(result);
    if((sign1==1 && sign2==1) || (sign1==-1 && sign2==-1)) {
        ans->sign = 1;
    }
    else {
        ans -> sign = -1;
    }
    return ans;
}


string subtract(string s1, string s2) {
    string result = "";
    int borrow = 0;
    int i = s1.size() - 1;
    int j = s2.size() - 1;

    while (i >= 0) {
        int digit1, digit2;

if (i >= 0) {
    digit1 = s1[i] - '0';
} else {
    digit1 = 0;
}

if (j >= 0) {
    digit2 = s2[j] - '0';
} else {
    digit2 = 0;
}

        int diff = digit1 - digit2 - borrow;

        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result = std::to_string(diff) + result;
        i--;
        j--;
    }
    result.erase(0, min(result.find_first_not_of('0'), result.size() - 1));
    return result;
}

string multiply(string s1, string s2) {
    string result = "0";

    for (int i = s2.size() - 1; i >= 0; i--) {
        int digit = s2[i] - '0';
        std::string product = multiplyByDigit(s1, digit);
        int zeros = s2.size() - 1 - i;
        for (int j = 0; j < zeros; j++) {
            product += "0";
        }
        result = addStrings(result, product);
    }
    result.erase(0, min(result.find_first_not_of('0'), result.size() - 1));
    return result;
}

bool isLess(string a, string b) {
    if (a.length() < b.length()) return true;
    if (a.length() > b.length()) return false;
    return a <= b;
}

string divide(string s1, string s2) {
    string quotient = "0";
    string rem = s1;

    while(bigger(rem,s2)) {
        rem = subtract(rem, s2);
        quotient = addStrings(quotient, "1");
    }
    return quotient;
}

string remainder(string s1, string s2) {
    if(bigger(s2,s1)) {
        return "0";
    }
    string quotient = "0";
    string rem = s1;

    while(bigger(rem,s2)) {
        rem = subtract(rem, s2);
        quotient = addStrings(quotient, "1");
    }
    return rem;
}


UnlimitedInt *UnlimitedInt::div(UnlimitedInt* i1, UnlimitedInt* i2) {
    string s1a = i1->to_string();
    string s2a = i2->to_string();
    string s1 = to_str(s1a);
    string s2 = to_str(s2a);
    
    int sign1 = i1->get_sign();
    int sign2 = i2->get_sign();


    string temps2 = s2; 
    string rem = s1;
    string quotient = "0";
    while(bigger(rem, temps2)) {
        int size1 = rem.size();
        int size2 = temps2.size();
        if(size1-size2-1 >= 0) {
            temps2.append(size1-size2-1, '0');
        } 
        string addquotient = divide(rem,temps2);
        quotient = addStrings(quotient,addquotient.append(size1-size2, '0'));
        rem = remainder(rem,temps2);
        temps2 = s2;
    }
    int toadd = quotient.back()-'0';
    quotient.erase(quotient.end()-1);
    quotient = addStrings(quotient, std::to_string(toadd));

    if((sign1==1 && sign2==1) || (sign1==-1 && sign2==-1)) {
        UnlimitedInt *ans = new UnlimitedInt(quotient);
        ans -> sign = 1;
        return ans;
    }
    else if(((sign1==1 && sign2==-1) || (sign1==-1 && sign2==1)) && (rem=="0" || rem == "-0")) {
        UnlimitedInt *ans = new UnlimitedInt(quotient);
        ans -> sign = -1;
        return ans;
    }
    else {
        UnlimitedInt *ans = new UnlimitedInt(addStrings(quotient, "1"));
        ans -> sign = -1;
        return ans;
    }
}



UnlimitedInt *UnlimitedInt::mod(UnlimitedInt* i1, UnlimitedInt* i2) {
    UnlimitedInt *a;
    a = a->div(i1, i2);
    UnlimitedInt *c;
    c = c->mul(i2, a);
    UnlimitedInt *ans;
    ans = ans->sub(i1,c);
    delete a;
    delete c;

    return ans;
    
}

