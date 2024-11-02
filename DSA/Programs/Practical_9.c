#include <stdio.h>
#include <stdlib.h>

struct BST
{
    int data;
    struct BST *left, *right;
};

/**
 * @brief Prints the values in the binary search tree in pre-order traversal.
 *
 * This function prints the values in the binary search tree in pre-order
 * traversal. The root value is printed first, followed by the left subtree and
 * then the right subtree. If the tree is empty, it simply returns.
 *
 * @param[in] root The root of the binary search tree to be printed.
 */
void preOrder(struct BST *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

/**
 * @brief Prints the values in the binary search tree in in-order traversal.
 *
 * This function prints the values in the binary search tree in in-order
 * traversal. It first recursively traverses the left subtree, then prints
 * the root value, followed by the right subtree. If the tree is empty,
 * it simply returns.
 *
 * @param[in] root The root of the binary search tree to be printed.
 */
void inOrder(struct BST *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data); // Print in between left and right traversal
        inOrder(root->right);
    }
}

/**
 * @brief Prints the values in the binary search tree in post-order traversal.
 *
 * This function prints the values in the binary search tree in post-order
 * traversal. It first recursively traverses the left subtree, then the
 * right subtree, and finally prints the root value. If the tree is empty,
 * it simply returns.
 *
 * @param[in] root The root of the binary search tree to be printed.
 */
void postOrder(struct BST *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

/**
 * @brief Creates a new node for the binary search tree with the given key.
 *
 * This function allocates memory for a new BST node, initializes it with
 * the provided key, and sets its left and right child pointers to NULL.
 * If memory allocation fails, the function prints an error message and
 * terminates the program.
 *
 * @param key The value to be stored in the new node.
 * @return A pointer to the newly created BST node.
 */
struct BST *createNode(int key)
{
    struct BST *newNode = (struct BST *)malloc(sizeof(struct BST));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/**
 * @brief Inserts a new node with the given key into the binary search tree.
 *
 * This function will insert a new node with the given key into the binary
 * search tree rooted at the given root. If the tree is empty, a new node with
 * the given key is created and returned. If the key is less than the root's key,
 * the key is inserted into the left subtree, and if it is greater, it is
 * inserted into the right subtree. If the key equals the root's key, the
 * duplicate value is ignored. The modified root of the tree is returned.
 *
 * @param[in] root The root of the binary search tree to be modified.
 * @param[in] key The value to be stored in the new node.
 * @return The modified root of the binary search tree.
 */
struct BST *insert(struct BST *root, int key)
{
    if (root == NULL)
    {
        return createNode(key);
    }

    if (key < root->data)
    {
        root->left = insert(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = insert(root->right, key);
    }
    // If key equals root->data, ignore the duplicate value

    return root;
}

/**
 * @brief Builds a binary search tree from user input.
 *
 * This function will repeatedly prompt the user for the number of nodes to
 * insert and the values to be stored in those nodes. The function will return
 * the root of the modified binary search tree.
 *
 * @return The root of the modified binary search tree.
 */
struct BST *buildBST()
{
    struct BST *root = NULL;
    int n, value;
    char buffer[100];

    printf("Enter the number of nodes to insert: ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid input for number of nodes!\n");
        return NULL;
    }

    while (getchar() != '\n')
        ;

    for (int i = 0; i < n; i++)
    {
        printf("Enter value for node %d: ", i + 1);
        if (scanf("%d", &value) != 1)
        {
            printf("Invalid input!\n");
            return NULL;
        }
        root = insert(root, value);
        while (getchar() != '\n')
            ; // Clear input buffer
    }

    return root;
}

int main()
{
    struct BST *root = buildBST();

    printf("Preorder traversal: ");
    preOrder(root);
    printf("\n");

    printf("Inorder traversal: ");
    inOrder(root);
    printf("\n");

    printf("Postorder traversal: ");
    postOrder(root);
    return 0;
}