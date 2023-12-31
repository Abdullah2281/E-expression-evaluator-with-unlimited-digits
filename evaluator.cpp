/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "evaluator.h"

Evaluator::Evaluator() {
    symtable = new SymbolTable();

}
Evaluator::~Evaluator() {
   for (ExprTreeNode* node : expr_trees) {
        delete node;
    }
    expr_trees.clear(); // Clear the vector
    delete symtable;
}

bool isDig(const std::string s) {
    if (!s.empty()) {
        char firstChar = s[0];
        if ((firstChar >= '0' && firstChar <= '9') || firstChar == '-') {
            return true;
        }
    }
    return false;
}

ExprTreeNode *parsehelper(vector<string>& code, int& idx) {
    if (idx >= code.size()) {
        return nullptr;
    }

    string str = code[idx];
    idx++;

    ExprTreeNode* node = new ExprTreeNode();

    if (str == "(") {
        node->left = parsehelper(code, idx); // Parse left subtree
        if (idx < code.size()) {
            if(code[idx]=="+") {
            node->type = "ADD";
            idx++;
            node->right = parsehelper(code, idx);
            }
            if(code[idx]=="-") {
            node->type = "SUB";
            idx++;
            node->right = parsehelper(code, idx);
            }
            if(code[idx]=="*") {
            node->type = "MUL";
            idx++;
            node->right = parsehelper(code, idx);
            }
            if(code[idx]=="/") {
            node->type = "DIV";
            idx++;
            node->right = parsehelper(code, idx);
            }
        } 
        idx++; // Skip the closing ")"
    } 
    else if (isDig(str)) {
        node->type = "VAL";
        node->val = new UnlimitedRational(new UnlimitedInt(str),new UnlimitedInt("1"));
        node->evaluated_value = node->val;
    }
    else {
        node->type = "VAR";
        node->id = str;
    }

    return node;
}

void Evaluator::parse(vector<string> code) {
    ExprTreeNode* node = new ExprTreeNode();
    node->type = "EQ";
    node->id = code[1];
    node->left = new ExprTreeNode();
    node->left->type = "VAR";
    node->left->id = code[0];
    code.erase(code.begin());
    code.erase(code.begin());

    int idx = 0;
    node->right = parsehelper(code,idx);
    expr_trees.push_back(node);
}

UnlimitedRational* evaluateNode(ExprTreeNode* node, SymbolTable* stable) {
    if (node == NULL) {
        return NULL;
    }

    if (node->type == "VAR") {
        node->val= stable->search(node->id);
        return node->val;
    } 
    else if (node->type == "VAL") {
        node->evaluated_value = node->val;
        return node->val;
    }

    else if (node->type == "ADD") {
        UnlimitedRational* l = evaluateNode(node->left,stable);
        UnlimitedRational* r = evaluateNode(node->right,stable);
        node->evaluated_value = UnlimitedRational::add(l,r);
        return node->evaluated_value;
    } 
    else if (node->type == "SUB") {
        UnlimitedRational* l = evaluateNode(node->left,stable);
        UnlimitedRational* r = evaluateNode(node->right,stable);
        node->evaluated_value = UnlimitedRational::sub(l,r);
        return node->evaluated_value;
    } 
    else if (node->type == "MUL") {
        UnlimitedRational* l = evaluateNode(node->left,stable);
        UnlimitedRational* r = evaluateNode(node->right,stable);
        node->evaluated_value = UnlimitedRational::mul(l,r);
        return node->evaluated_value;
    } 
        UnlimitedRational* l = evaluateNode(node->left,stable);
        UnlimitedRational* r = evaluateNode(node->right,stable);
        node->evaluated_value = UnlimitedRational::div(l,r);
        return node->evaluated_value;
}

void Evaluator::eval() {
    for(int i=0; i<expr_trees.size(); i++) {
    ExprTreeNode* root = expr_trees[i];
    string k = root->left->id;
    UnlimitedRational* push = evaluateNode(root->right, symtable);
    symtable->insert(k,push);
    }
}
