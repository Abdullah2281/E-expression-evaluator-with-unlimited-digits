/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "exprtreenode.h"

ExprTreeNode::ExprTreeNode() {
    type = "";
    val = NULL;
    evaluated_value = NULL;
    id = "";
    left = NULL;
    right = NULL;
}

ExprTreeNode::ExprTreeNode(string t, UnlimitedInt* v) {
    type = "";
    val = NULL;
    evaluated_value = NULL;
    id = "";
    left = NULL;
    right = NULL;
}

ExprTreeNode::ExprTreeNode(string t, UnlimitedRational* v) {
    type = "";
    val = NULL;
    evaluated_value = NULL;
    id = "";
    left = NULL;
    right = NULL;
}

ExprTreeNode::~ExprTreeNode() {
    if (val != nullptr) {
        delete val;
    }
    if(evaluated_value!=NULL) {
        delete evaluated_value; 
    }
    
}


