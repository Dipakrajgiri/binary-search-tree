#include <iostream>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};
node *tree = NULL;
node *insertelement(node *tree, int val)
{
    struct node *ptr, *nodeptr, *parentptr;
    ptr = new node;
    ptr->data = val;
    ptr->left = NULL;
    ptr->right = NULL;
    if (tree == NULL)
    {
        tree = ptr;
    }
    else
    {
        parentptr = NULL;
        nodeptr = tree;
        while (nodeptr != NULL)
        {
            parentptr = nodeptr;
            if (val < nodeptr->data)
                nodeptr = nodeptr->left;
            else
                nodeptr = nodeptr->right;
        }
        if (val < parentptr->data)
            parentptr->left = ptr;
        else
            parentptr->right = ptr;
    }
    return tree;
}
void search(node *tree, int val)
{

    if (tree == NULL)
    {
        cout << "the element is not in tree";
        return;
    }
    if (tree->data == val)
    {
        cout << "the element is in tree";
        return;
    }
    else
    {
        if (tree->data > val)
        {
            search(tree->left, val);
        }
        else
        {
            search(tree->right, val);
        }
    }
}
void inorderdisplay(node *tree)
{
    if (tree != NULL)
    {
        inorderdisplay(tree->left);
        cout << endl
             << tree->data;
        inorderdisplay(tree->right);
    }
}
node *largest(node *tree)
{
    if ((tree == NULL) || (tree->right == NULL))
        return tree;
    else
        return largest(tree->right);
}
node *minValueNode(node *node)
{
    struct node *current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}
node *deletenode(node *root, int val)
{

    if (root == NULL)
        return root;

    if (val < root->data)
        root->left = deletenode(root->left, val);

    else if (val > root->data)
        root->right = deletenode(root->right, val);

    else
    {
        if (root->left == NULL && root->right == NULL)
            return NULL;

        else if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        struct node *temp = minValueNode(root->right);

        root->data = temp->data;

        root->right = deletenode(root->right, temp->data);
    }
    return root;
}

int main()
{
    int x, val;
    struct node *ptr;
    do
    {
        cout << endl
             << "enter 1 to insert an element" << endl
             << "enter 2 to search a element" << endl
             << "enter 3 to delete element" << endl
             << "enter 4 to display in inorder" << endl
             << "enter 5 to exit" << endl;

        cin >> x;
        switch (x)
        {
        case 1:
            cout << "\n Enter the value of the new node : ";
            cin >> val;
            tree = insertelement(tree, val);
            break;

        case 2:
            cout << "\n Enter the element to search: \n";
            cin >> val;
            search(tree, val);
            break;

        case 3:
            cout << "\n Enter the element to delete : \n";
            cin >> val;
            tree = deletenode(tree, val);
            break;
        case 4:
            cout << "\n The elements of the tree are : \n";
            inorderdisplay(tree);
            break;
        }
    } while (x != 5);
    return 0;
}
