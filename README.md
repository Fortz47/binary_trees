# Binary trees
This is a group project to test the understanding of the following:
- The binary trees
- The difference between a binary tree and a Binary Search Tree
- The possible benefit in terms of time complexity compared to linked lists
- The depth, the height, the size of a binary tree
- The different traversal methods to go through a binary tree
- The difference between a complete, a full, a perfect, a balanced binary tree

The understanding of the following forms of binary trees are also tested:
- Binary Search Tree
- AVL Tree
- Max Binary Heap

## Data Structures
The following data structures and types where used in this project

### Basic Binary Tree

```c
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
```
### Binary Search Tree

```c
typedef struct binary_tree_s bst_t;
```

### AVL Tree

```c
typedef struct binary_tree_s avl_t;
```

### Max Binary Heap

```c
typedef struct binary_tree_s heap_t;
```

### Print function
void binary_tree_print(const binary_tree_t *tree): Function to print binary trees in a pretty way
```c
                           .----------------------(006)-------.
                      .--(001)-------.                   .--(008)--.
                 .--(-02)       .--(003)-------.       (007)     (009)
       .-------(-06)          (002)       .--(005)
  .--(-08)--.                           (004)
(-09)     (-07)
```
[Original code](Original code from http://stackoverflow.com/a/13755911/5184480)
