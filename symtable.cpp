/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "symtable.h"

SymbolTable::SymbolTable() {
    size = 0;
    root = NULL;
}

void baldevDestroyer(SymEntry* node) {
    if (node == NULL) {
        return;
    }
    baldevDestroyer(node->left);
    baldevDestroyer(node->right);
    delete node->val;
    delete node;
}

SymbolTable::~SymbolTable() {
    baldevDestroyer(root);
    size = 0;
    root = NULL;
}

SymEntry* insertHelper(SymEntry*& node, string k, UnlimitedRational* v) {
    if (node == NULL) {
        return new SymEntry(k, v);
    } 
        if (k < node->key) {
            node->left = insertHelper(node->left, k, v);
        } 
        else {
            node->right = insertHelper(node->right, k, v);
        } 
        return node;
    }


void SymbolTable::insert(string k, UnlimitedRational* v) {
    root = insertHelper(root, k, v);
    size++;
    return;
}

SymEntry* findMin(SymEntry* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

SymEntry* removeHelper(SymEntry*& node, string k) {
    if(node == NULL) {
        return node;
    }

    if(node->key == k) {
        if(node->left == NULL && node->right == NULL) {
            delete node;
            return NULL;
        }
        if(node->left!=NULL && node->right==NULL) {
            SymEntry* temp = node->left;
            delete node;
            return temp;
        }
        if(node->right!=NULL && node->left==NULL) {
            SymEntry* temp = node->right;
            delete node;
            return temp;
        }
        if(node->right!=NULL && node->left!=NULL) {
            SymEntry* temp = findMin(node->right);
            node->key = temp->key;
            UnlimitedRational *k = node->val;
            node->val = temp->val;
            temp->val = k;
            node->right = removeHelper(node->right, temp->key);
            return node;
        }
    }

    else if(node->key > k) {
        node->left = removeHelper(node->left, k);
        return node;
    }
        node->right = removeHelper(node->right, k);
        return node;

}

void SymbolTable::remove(string k) {
    root = removeHelper(root, k);
    size--;
}

SymEntry* searchHelper(SymEntry* node, string k) {
    if (k == node->key) {
        return node;
    } 
    else if (k < node->key) {
        return searchHelper(node->left, k);
    } 
        return searchHelper(node->right, k);
}

UnlimitedRational* SymbolTable::search(string k) {
    SymEntry* ans = searchHelper(root, k);
    return ans->val;
}

int SymbolTable::get_size() {
    return size;
}

SymEntry* SymbolTable::get_root() {
    return root;
}