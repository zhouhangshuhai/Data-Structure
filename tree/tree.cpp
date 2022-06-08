//
// Created by 周舟 on 2022/5/25.
//
#include "iostream"

using namespace std;

//二叉树的结构体
struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

//插入节点
void insertNode(TreeNode* &root, int data){
    if(root == NULL){
        root = new TreeNode(data);
        return;
    }
    if(data < root->data){
        insertNode(root->left, data);
    }else{
        insertNode(root->right, data);
    }
}

//删除节点
void deleteNode(TreeNode* &root, int data){
    if(root == NULL){
        return;
    }
    if(data < root->data){
        deleteNode(root->left, data);
    }else if(data > root->data){
        deleteNode(root->right, data);
    }else{
        if(root->left == NULL && root->right == NULL){
            delete root;
            root = NULL;
        }else if(root->left == NULL){
            TreeNode* temp = root;
            root = root->right;
            delete temp;
        }else if(root->right == NULL){
            TreeNode* temp = root;
            root = root->left;
            delete temp;
        }else{
            TreeNode* temp = root->right;
            while(temp->left != NULL){
                temp = temp->left;
            }
            root->data = temp->data;
            deleteNode(root->right, temp->data);
        }
    }
}

//先序遍历
void preOrder(TreeNode* root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
//中序遍历
void inOrder(TreeNode* root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
//后序遍历
void postOrder(TreeNode* root){
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main() {
    TreeNode* root = NULL;
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 7);
    insertNode(root, 2);
    insertNode(root, 4);
    insertNode(root, 6);
    insertNode(root, 8);
    insertNode(root, 1);
    cout << "先序遍历：";
    preOrder(root);
    cout << endl;
    cout << "中序遍历：";
    inOrder(root);
    cout << endl;
    cout << "后序遍历：";
    postOrder(root);
}
