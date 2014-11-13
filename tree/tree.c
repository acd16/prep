#include "tree.h"

leaf * insert(int val){
    leaf * node = malloc(sizeof(leaf));
    //printf("insert %p %d\n", node, val);
    node -> value = val;
    node -> left = NULL;
    node -> right = NULL;
    return node;
}

void inorder(leaf * root){
    //printf("inorder %p\n", root);
    if(root){
        inorder(root->left);
        printf("%d ", root->value);
        inorder(root->right);
    }
}

void preorder(leaf * root){
    //printf("inorder %p\n", root);
    if(root){
        printf("%d ", root->value);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(leaf * root){
    //printf("inorder %p\n", root);
    if(root){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->value);
    }
}

void push(node** ele, leaf * val){
    node * new = malloc(sizeof(node));
    //printf("new is %p\n", new);
    new -> point = val;
    new -> next = NULL;
    if(*ele == NULL)
        *ele = new;
    else{
        new->next = *ele;
        *ele = new;
    }
}

leaf * pop(node** ele){
    if(*ele == NULL){
        return NULL;
    }
    leaf * val;
    node * temp = NULL;
    val = (*ele)->point;
    //printf("%d value is\n", (*ele)->value);
    if ((*ele)->next == NULL){
        free(*ele);
        *ele = NULL;
    }
    else{
        temp = *ele;
        *ele = (*ele)->next;
        free(temp);
    }
    return val;
}

void iterpreorder(leaf * root){
    node * stack = NULL;
    while(1){
        while(root){
            printf("%d ", root->value);
            //printf("pushed %d\n", root->value);
            push(&stack, root);
            root = root->left;
        }
        if(stack == NULL)
            break;
        //printf("stack bef %p\n", stack);
        root = pop(&stack);
        //printf("stack aft %p\n", stack);
        //printf("popped %d\n", root->value);
        root = root->right;
    }
}

void iterinorder(leaf * root){
    node * stack = NULL;
    while(1){
        while(root){
            //printf("pushed %d\n", root->value);
            push(&stack, root);
            root = root->left;
        }
        if(stack == NULL)
            break;
        //printf("stack bef %p\n", stack);
        root = pop(&stack);
        printf("%d ", root->value);
        //printf("stack aft %p\n", stack);
        //printf("popped %d\n", root->value);
        root = root->right;
    }
}

int height(leaf * root){
    if(root == NULL)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh, rh) + 1;
}

int findPath(leaf * root, int data, int * sum){
    if(root == NULL)
        return 0;
    if((root->value == data) || findPath(root->left, data, sum) ||
            findPath(root->right, data, sum)){
        printf("%d->", root->value);
        *sum += root->value;
    }
    else{
        return 0;
    }
}

void findMaxPathSum(leaf* root, int sum, int* maxSum, leaf** node){
    if(root == NULL)
        return;
    sum = sum + root->value;
    if(*maxSum < sum){
        *maxSum = sum;
        *node = root;
    }
    findMaxPathSum(root->left, sum, maxSum, node);
    findMaxPathSum(root->right, sum, maxSum, node);
}

void findMaxLeafSum(leaf* root, int sum, int* maxSum, leaf** node){
    if(root == NULL)
        return;
    sum = sum + root->value;
    if((root->left == NULL) && (root->right == NULL)){
        if(*maxSum < sum){
        *maxSum = sum;
        *node = root;
        }
        printf("sum to leaf %d is %d\n", root->value, sum);
    }
    findMaxLeafSum(root->left, sum, maxSum, node);
    findMaxLeafSum(root->right, sum, maxSum, node);
}

int hasLeafSum(leaf* root, int sum){
    if(root == NULL)
        return 0;
    sum -= root->value;
    if(sum == 0 && (root->left == NULL) && (root->right == NULL))
        return 1;
    else {
        return (hasLeafSum(root->left, sum) || hasLeafSum(root->right, sum));
    }
}

int isBstUtil(leaf * root, int min, int max){
    if (root == NULL)
        return 1;
    if(root->value < min || root->value > max)
        return 0;
    return isBstUtil(root->left, min, root->value) & isBstUtil(root->right, root->value, max);
}

int isBst(leaf * root){
    return isBstUtil(root, INT_MIN, INT_MAX);
}
int main(){
    int sum = 0, pathMax = INT_MIN;
    leaf * root = NULL;
    root = insert(50);
    root->left = insert(30);
    root->left->right  = insert(32);
    root->left->left = insert(25);
    root->left->left->left = insert(22);
    root->left->left->right = insert(27);
    root->left->right->right  = insert(34);
    root->right = insert(72);
    root->right->left = insert(70);
    root->right->right = insert(77);
    printf("%d\n", isBst(root));
    //printf("%d\n", hasLeafSum(root, 175));
    /*leaf * gg = malloc(sizeof(leaf));
    findMaxLeafSum(root, 0, &pathMax, &gg);
    printf("\nmaxsum = %d\n", pathMax);
    findPath(root, gg->value, &sum);
    printf("\nsum = %d\n", sum);
    free(gg);*/
    //printf("%d\n", height(root));
    /*inorder(root);
    printf("\n");
    iterinorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");*/
    /*node * test = NULL;
    push(&test,1);
    push(&test,2);
    push(&test,3);
    push(&test,4);
    printf("%d\n", pop(&test));
    printf("%d\n", pop(&test));
    printf("%d\n", pop(&test));
    printf("%d\n", pop(&test));
    printf("%d\n", pop(&test));*/
}
