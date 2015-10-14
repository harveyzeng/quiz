/* FIXME: Implement! */
#include <stdlib.h>
#include <stdio.h>
#include <tree.h>
struct TreeNode *_flatten(struct TreeNode * node)
{
    if (node == NULL) {
        return NULL;
    }
    if (node->right) {
        node->right = _flatten(node->right);
    }
    if (node->left) {
        struct TreeNode *tmp = node->right;
        node->right = _flatten(node->left);
        struct TreeNode *t = node->right;
        while (t->right) {
            t = t->right;
        }
        t->right = tmp;
        node->left = NULL;
    }
    return node;
}

void flatten(struct TreeNode* node)
{
    _flatten(node);
}

int main()
{
    Node *root = NULL;
    insert(&root, 1);
    insert(&(root->left), 2);
    insert(&(root->left->left), 3);
    insert(&(root->left), 4);
    insert(&root, 5);
    insert(&root, 6);
    
    print_preorder(root);
    printf("\n");
    print_inorder(root);
    printf("\n");
    print_postorder(root);
    printf("\n");

    flatten(root);
    
    print_preorder(root);
    printf("\n");
    print_inorder(root);
    printf("\n");
    print_postorder(root);
    printf("\n");
    return 0;
}
