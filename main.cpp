#include<iostream>
using namespace std;
class node
{

public:
    char data;
    node* lchild;
    node* rchild;
    friend class bitree;
    node() { lchild = NULL; rchild = NULL; }
};
class bitree
{
    node* root;
public:
    bitree() {  }
    node*& get_root() { return root; }
    node* creat_tree(node*&bt)
    {
        char ch;
        cin >> ch;
        if (ch == '#') bt = NULL;
        else
        {
            bt = new node;
            bt->data = ch;
            bt->lchild=creat_tree(bt->lchild);
            bt->rchild=creat_tree(bt->rchild);
        }
        return bt;
    }
    void pre(node*bt)
    {
        if (bt != NULL)
        {
            cout << bt->data << endl;
            pre(bt->lchild);
            pre(bt->rchild);
        }
    }
    void in(node*bt)
    {
        int top = -1;
        node* s[1000];
        while (bt != NULL || top != -1)
        {
            while (bt != NULL)
            {
                s[++top] = bt;
                bt = bt->lchild;
            }
            if (top != -1)
            {
                bt = s[top--];
                cout << bt->data << endl;
                bt = bt->rchild;
            }
        }
    }
};
int main()
{
    bitree a;
    a.creat_tree(a.get_root());
    cout << "前序递归:" << endl;
    a.pre(a.get_root());
    cout << endl;
    cout << "中序非递归：" << endl;
    a.in(a.get_root());
}