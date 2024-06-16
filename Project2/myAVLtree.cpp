#include "myAVLtree.hpp"

/**
 * Return the height of node or -1 if nullptr.
*/
int height(AVLnode *t) {
    return t == nullptr ? -1 : t->height;
}

/**
 * Internal method to insert into subtree.
 * x is the item to insert
 * t is the node that roots the subtree.
 * set the new root of the subtree.
*/
void insert(const int &x, AVLnode *&t) {
    if (t == nullptr) {
        t = new AVLnode(x, nullptr, nullptr);
    } else if (x <= t->element) {
        insert(x, t->left);
    } else if (t->element < x) {
        insert(x, t->right);
    }

    balance(t);
}

static const int ALLOWED_IMBALANCE = 1;

//Assume t is balanced or within one of being balanced
void balance(AVLnode *&t){
    if (t == nullptr) {
        return;
    }

    if (height(t->left) - height(t->right) > ALLOWED_IMBALANCE) {
        if (height(t->left->left) >= height(t->left->right)) {
            rotateWithLeftChild(t);
        } else {
            doubleWithLeftChild(t);
        }
    } else if (height(t->right) - height(t->left) > ALLOWED_IMBALANCE) {
        if (height(t->right->right) >= height(t->right->left)) {
            rotateWithRightChild(t);
        } else {
            doubleWithRightChild(t);
        }
    }

    t->height = std::max(height(t->left), height(t->right)) + 1; 
}

/**
 * rotate binary tree node with left child.
 * for AVL trees this is a single rotation for case 1
 * update heights, then set new root.
*/
void rotateWithLeftChild(AVLnode *&k2){
    AVLnode *k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = std::max(height(k2->left), height(k2->right)) + 1;
    k1->height = std::max(height(k1->left), k2->height) + 1;
    k2 = k1;
}

/**
 * rotate binary tree node with right child.
 * for AVL trees this is a single rotation for case 4
 * update heights, then set new root.
*/
void rotateWithRightChild(AVLnode *&k2){
    AVLnode *k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;
    k2->height = std::max(height(k2->right), height(k2->left)) + 1;
    k1->height = std::max(height(k1->right), k2->height) + 1;
    k2 = k1;
}

/**
 * double rotate binary tree node: first left child
 * with its right child; then node k3 with new left child.
 * for AVL trees, this is a double rotation for case 2
 * Update hrights, then set new root.
*/
void doubleWithLeftChild(AVLnode *&k3){
    rotateWithRightChild(k3->left);
    rotateWithLeftChild(k3);
}

/**
 * Double rotate binary tree node: first right child.
 * with its left child; then node k1 with new right child.
 * For AVL trees, this is a double rotation for case 3.
 * Update heights, then set new root.
*/
void doubleWithRightChild(AVLnode *&k3) {
    rotateWithLeftChild(k3->right); 
    rotateWithRightChild(k3); 
}

/**
 * internal method to remove from a subtree
 * x is the item to remove
 * t is the node that roots the subtree
 * set the new root of the sub tree
*/
void remove(const int &x, AVLnode *&t){
    if (t == nullptr) {
        return;
    }

    if (x < t->element) {
        remove(x, t->left);
    } else if (t->element < x) {
        remove(x, t->right); 
    } else if (t->left != nullptr && t->right != nullptr) {
        t->element = findMinimum(t->right)->element;
        remove(t->element, t->right);
    } else {
        AVLnode *oldNode = t; 
        t = (t->left != nullptr) ? t->left : t->right; 
        delete oldNode;
        oldNode = nullptr;
    }

    balance(t);
}

/**
 * internal method to find the smallest item in subtree t.
 * return node containing the smallest item
*/
AVLnode *findMinimum(AVLnode *t){
    if (t == nullptr){
        return nullptr;
    }
    if(t->left == nullptr){
        return t;
    }
    return findMinimum(t->left);
}

/**
 * internal method to find the largest item in a subtree t
 * return node containing the largest item
*/
AVLnode *findMaximum(AVLnode *t){
    if (t != nullptr) {
        while(t->right != nullptr) {
            t = t->right;
        }
    }
    return t;
}

void treeMedian(const std::vector<int> *instructions){
    std::vector<int> median;  // vector to keep track of medians
    AVLnode *max = nullptr;
    AVLnode *min = nullptr; 

    // counters
    int max_counter = 0;
    int min_counter = 0;

    const auto time_begin = std::chrono::steady_clock::now();

    for (auto it = instructions->begin(); it != instructions->end(); ++it){  // loops through the vector "instructions"
        if (max == nullptr && *it != -1) {  // checks to see if max = nullptr AND if the value is not equal to -1
            insert(*it, max);  // insert the value
            max_counter += 1; 

        } else if (*it == -1) {  // if the value is equal to -1
            AVLnode *rightMost = findMaximum(max);  // find the maximum value 
            median.push_back(rightMost->element);  // pushes the right most value into the median's vector
            remove(rightMost->element, max);  // remove/pop the value
            max_counter -= 1; 

            if (min_counter > max_counter) {  // if the min counter is greater than the max counter
                AVLnode *leftMost = findMinimum(min);  // find the minimum value 
                auto copy = leftMost->element;
                remove(copy, min);
                insert(copy, max);
                min_counter -= 1;  // decrement 1 to min_counter and assign it's current value to min_counter
                max_counter += 1;  // increment 1 to max_counter and assign it's current value to max_counter
            }
        } else {
            if (*it <= findMaximum(max)->element) {  // if the current value is less than or equal to the value stored in the max node
                insert(*it, max);
                max_counter += 1;

                // balancing the AVL tree
                if (max_counter > min_counter + 1) {
                    AVLnode *rightMost = findMaximum(max);
                    int copy2 = rightMost->element;
                    remove(copy2, max);
                    insert(copy2, min); 
                    max_counter -= 1;  // decrement + assign
                    min_counter += 1;  // increment + assign
                }
            } else if (*it > findMaximum(max)->element) {
                insert(*it, min);
                min_counter += 1; 

                if (min_counter > max_counter){
                    AVLnode *leftMost = findMinimum(min);
                    auto copy3 = leftMost->element;
                    remove(copy3, min);
                    insert(copy3, max);
                    min_counter -= 1;  // decrement + assign
                    max_counter += 1;  // increment + assign
                }
            }
        }
    }
    const auto time_end = std::chrono::steady_clock::now();
    int duration_ = std::chrono::duration<double, std::micro>(time_end - time_begin).count();

    // std::cout << "Time to insert and pop medians for AVLtree: " << duration_ << " microseconds" << std::endl;

    for (int i = 0; i < median.size(); i++){
        std::cout << median[i] << " ";
    }
}