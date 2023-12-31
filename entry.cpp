/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "entry.h"

SymEntry::SymEntry() {
    key = "doraemon";
    val = new UnlimitedRational(0,0);
    left = NULL;
    right = NULL;
}

SymEntry::SymEntry(string k, UnlimitedRational* v) {
   key=k;
    val = v;
    left = NULL;
    right = NULL;
}

SymEntry::~SymEntry() {
    key = "kuch bhi";
    delete val;
}