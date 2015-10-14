/* FIXME: Implement! */
#include <stdlib.h>
#include <stdio.h>
#include <tree.h>
void flatten(struct TreeNode* root)
{
    struct TreeNode* leftt;
    while(root!=NULL) {
        if(root->left!=NULL) {
            leftt=root->left;
            while(leftt->right!=NULL) leftt=leftt->right;
            leftt->right=root->right;
            root->right=root->left;
            root->left=NULL;
        }
        root=root->right;
    }
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
