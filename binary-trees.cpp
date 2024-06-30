#include <bits/stdc++.h>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <limits>
#include <vector>
using namespace std;
// Short function start-->>
void printArray(long long arr[], int length)
{
    for (int i = 0; i < length; ++i)
    {
        cout << arr[i] << " ";
    }
}
void printVector(vector<int> &arr)
{
    for (auto it : arr)
    {
        cout << it << " ";
    }
}
void printVectorString(vector<string> &arr)
{
    for (auto it : arr)
    {
        cout << it << endl;
    }
}
void printVectorVector(vector<vector<int>> x)
{
    for (const auto &row : x)
    {
        cout << "[";
        for (const auto &element : row)
        {
            cout << element << " ";
        }
        cout << "]";
        cout << std::endl;
    }
}
void printVectorVectorString(vector<vector<string>> x)
{
    for (const auto &row : x)
    {
        cout << "[";
        for (const auto &element : row)
        {
            cout << element << " ";
        }
        cout << "]";
        cout << std::endl;
    }
}
void printString(string s, int length)
{
    for (int i = 0; i < length; ++i)
    {
        cout << s[i] << " ";
    }
}

// =====================================BINARY TREE===============================================>>
// Short function end-->>
/*
What is Binary Tree?
-->>A binary tree is a hierarchical data structure composed of nodes, where each node has at most two children, referred to as the left child and the right child. The topmost node in a binary tree is called the root node. Each node in a binary tree can have zero, one, or two children nodes.

(*)Here are some key terms related to binary trees:
1.Root: The topmost node in a binary tree. It is the starting point of the tree traversal and the only node without a parent.

2.Children: Each node in a binary tree can have at most two children nodes. These are the nodes directly connected to a particular node.

3.Subtree: A subtree is a portion of a binary tree that consists of a node (called the root of the subtree) and all of its descendants (children, grandchildren, and so on). Every node in a binary tree is itself the root of a subtree.

4.Leaf Node (or Terminal Node): A leaf node is a node in a binary tree that does not have any children. In other words, it is a node without any further branches or nodes stemming from it.

5.Ancestor: An ancestor of a node in a binary tree is any node that lies on the path from the root node to that particular node. In other words, an ancestor is any node that is higher in the tree hierarchy than the given node, including the root node itself.

When does a Binary Tree called Complete Binary Tree?
-->If all levels are completely filled except the last one. The last level has all nodes or left as possible

what is perfect Binary tree?
-->All leaf nodes are at same level

What is Balanced Bonary tree?
-->>The height of the tree at max log(N).N= no of nodes. If n=8 log8=3 then height should be 3
Means for every node height(left)-height(right)<=1

what is Degenerate tree?
-->>when every node has a single children like linked list.



*/

/*
1. Binary Tree Representation.
ANS :
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :
// SC :
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node *prev;
    Node *next;

    Node(int val)
    {
        data = val;
        left = right = NULL;
        next = prev = NULL;
    }
};

struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}
void printTree(Node *root, int space = 0, int level = 0)
{
    if (root == nullptr)
        return;

    const int spacing = 4;
    space += spacing;

    printTree(root->right, space, level + 1);
    std::cout << std::endl;
    for (int i = spacing; i < space; ++i)
    {
        std::cout << " ";
    }
    std::cout << root->data << std::endl;

    printTree(root->left, space, level + 1);
}
/*
2. Binary Tree Trevarsal
ANS :  Here we got 2 types of search
    A) DFS : Depth first search : Its goes depthwise like deep into sub trees
        DFS comes to 3 types :
            i) Inorder Traversal(left root right) :
            ii) Pre-order Traversal(root left right) :
            iii) Post-order Traversal(left right root) :

    B)BFS : Breadth first search : Its Goes levelwise

Input :   || Output :
*/
// In-order Traversal-->>
// TC :O(N)
// SC :O(N) || For complete binary tree this will be O(logN)
void inorderTraversal(Node *root)
{
    if (root == nullptr)
        return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}
// Pre-order Traversal-->>
// TC :O(N)
// SC :O(N)
void preorderTraversal(Node *root)
{
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Post-order Traversal-->>
// TC :O(N)
// SC :O(N)
void postorderTraversal(Node *root)
{
    if (root == nullptr)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}
// Level-order(BFS) Traversal-->>
// TC :O(N)
// SC :O(N)
vector<vector<int>> levelorderTraversal(Node *root)
{
    vector<vector<int>> ans;
    if (root == nullptr)
        return ans;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size; i++)
        {
            Node *node = q.front();
            q.pop();
            if (node->left != nullptr)
                q.push(node->left);
            if (node->right != nullptr)
                q.push(node->right);
            level.push_back(node->data);
        }
        ans.push_back(level);
    }
    return ans;
}

/*
3. Iterative Pre-order Traversal
ANS :
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC : O(N)
// SC :O(N)
vector<int> iterativePreorderTraversal(Node *root)
{
    vector<int> preorder;
    if (root == nullptr)
        return preorder;
    stack<Node *> st;
    st.push(root);
    while (!st.empty())
    {
        root = st.top();
        st.pop();
        preorder.push_back(root->data);
        // Its a LIFO so we have to push first right then left
        if (root->right != nullptr)
            st.push(root->right);
        if (root->left != nullptr)
            st.push(root->left);
    }
    return preorder;
}

/*
4. Iterative In-order Traversal
ANS :
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC : O(N)
// SC :O(N)
vector<int> iterativeInorderTraversal(Node *root)
{
    stack<Node *> st;
    Node *node = root;
    vector<int> inorder;
    while (true)
    {
        if (node != nullptr)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            if (st.empty() == true)
                break;
            node = st.top();
            st.pop();
            inorder.push_back(node->data);
            node = node->right;
        }
    }
    return inorder;
}
/*

5. Iterative Post-order Traversal
ANS :
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ------using 2 stack----->
// TC :O(N)
// SC :O(N+N)
vector<int> iterativePostorderTaversal2(Node *root)
{
    vector<int> postorder;
    if (root == nullptr)
        return postorder;
    stack<Node *> s1, s2;
    s1.push(root);
    while (!s1.empty())
    {
        root = s1.top();
        s1.pop();
        s2.push(root);
        if (root->left != NULL)
            s1.push(root->left);
        if (root->right != NULL)
            s1.push(root->right);
    }
    while (!s2.empty())
    {
        postorder.push_back(s2.top()->data);
        s2.pop();
    }
    return postorder;
}
// Optimal -----using 1 stack----->
// TC :O(N)
// SC :O(N)
vector<int> iterativePostorderTaversal(Node *root)
{

    vector<int> postOrder;
    if (root == NULL)
        return postOrder;

    stack<Node *> st;
    while (root != NULL || !st.empty())
    {

        if (root != NULL)
        {
            st.push(root);
            root = root->left;
        }
        else
        {
            Node *temp = st.top()->right;
            if (temp == NULL)
            {
                temp = st.top();
                st.pop();
                postOrder.push_back(temp->data);
                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    postOrder.push_back(temp->data);
                }
            }
            else
                root = temp;
        }
    }
    return postOrder;
}

/*
6. Pre-order,In-order,Post-order Traversal in One Traverse
ANS :
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC : O(N) , We are visiting every node thrice therefore time complexity will be O(3*N), which can be assumed as linear time complexity.
// SC : O(N), We are using three lists and a stack to store the nodes. The time complexity will be about O(4*N), which can be assumed as linear time complexity.
void allTraversal(Node *root, vector<int> &pre, vector<int> &in, vector<int> &post)
{
    stack<pair<Node *, int>> st;
    st.push({root,
             1});
    if (root == NULL)
        return;

    while (!st.empty())
    {
        auto it = st.top();
        st.pop();

        // this is part of pre
        // increment 1 to 2
        // push the left side of the tree
        if (it.second == 1)
        {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->left != NULL)
            {
                st.push({it.first->left,
                         1});
            }
        }

        // this is a part of in
        // increment 2 to 3
        // push right
        else if (it.second == 2)
        {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->right != NULL)
            {
                st.push({it.first->right,
                         1});
            }
        }
        // don't push it back again
        else
        {
            post.push_back(it.first->data);
        }
    }
}
/*
7. Maximum depth of a Binary Tree
ANS : Find the Maximum Depth of Binary Tree. Maximum Depth is the count of nodes of the longest path from the root node to the leaf node.
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ------Using LEVEL ORDER TRAVERSAL----->
// TC :O(N)
// SC :O(N)
int maxDepthLevelOrder(Node *root)
{
    if (root == nullptr)
        return 0;

    queue<Node *> q;
    q.push(root);

    int height = 0;

    while (!q.empty())
    {
        int size = q.size();

        // Process all nodes at the current level
        while (size-- > 0)
        {
            Node *remNode = q.front();
            q.pop();

            // Enqueue left child if exists
            if (remNode->left != nullptr)
                q.push(remNode->left);
            // Enqueue right child if exists
            if (remNode->right != nullptr)
                q.push(remNode->right);
        }

        // Increment the height for each level
        height++;
    }

    return height;
}
// Optimal -----Recursively ( Post Order Traversal )----->
// TC : O(N)
// SC :O(1) Extra Space + O(H) Recursion Stack space, where “H”  is the height of the binary tree.
int maxDepthLevelOrderOptimal(Node *root)
{
    if (root == NULL)
        return 0;

    int lh = maxDepthLevelOrderOptimal(root->left);
    int rh = maxDepthLevelOrderOptimal(root->right);

    return 1 + max(lh, rh);
}
/*
8. Check if the Binary Tree is Balanced Binary Tree
ANS :  Check whether the given Binary Tree is a Balanced Binary Tree or not. A binary tree is balanced if, for all nodes in the tree, the difference between left and right subtree height is not more than 1.
Input :   || Output :
*/
// Bruteforce ----------->
// TC : O(N^2)
// SC :O(1) ( Extra Space ) + O(H) ( Recursive Stack Space where “H” is the height of tree )
bool isBalancedBruteforce(Node *root)
{
    if (root == nullptr)
        return true;
    int lh = maxDepthLevelOrderOptimal(root->left);
    int rh = maxDepthLevelOrderOptimal(root->right);
    if (abs(rh - lh) > 1)
        return false;
    bool left = isBalancedBruteforce(root->left);
    bool right = isBalancedBruteforce(root->right);
    if (!left || !right)
        return false;
    return true;
}
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC : O(N)
// SC :O(1) ( Extra Space ) + O(H) ( Recursive Stack Space where “H” is the height of tree )
int dfsHeight(Node *root)
{

    if (root == NULL)
        return 0;

    int leftHeight = dfsHeight(root->left);

    if (leftHeight == -1)
        return -1;

    int rightHeight = dfsHeight(root->right);

    if (rightHeight == -1)
        return -1;

    if (abs(leftHeight - rightHeight) > 1)
        return -1;

    return max(leftHeight, rightHeight) + 1;
}
bool isBalancedOptimal(Node *root)
{
    return dfsHeight(root) != -1;
}
/*
9. Calculate the Diameter of a Binary Tree
ANS :  Find the Diameter of a Binary Tree. Diameter is the length of the longest path between any 2 nodes in the tree and this path may or may not pass from the root.
Input :   || Output :
*/
// Bruteforce ----------->
// TC : O(N^2)
// SC :O(N) for recursive call stack
int diameterOfBinaryTreeBruteforce(Node *root)
{
    if (root == nullptr)
        return 0;

    // Calculate the height of left and right subtrees
    int lh = maxDepthLevelOrderOptimal(root->left);
    int rh = maxDepthLevelOrderOptimal(root->right);

    // Calculate the current diameter (path length through the current node)
    int currentDiameter = lh + rh;

    // Recursively calculate diameters in left and right subtrees
    int leftDiameter = diameterOfBinaryTreeBruteforce(root->left);
    int rightDiameter = diameterOfBinaryTreeBruteforce(root->right);

    // Return the maximum of the current diameter and diameters from
    // subtrees
    return max(currentDiameter, max(leftDiameter, rightDiameter));
}
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC : O(N)
// SC :O(1) Extra Space + O(H) Recursion Stack space (Where “H”  is the height of binary tree )
int fndMax(Node *node, int &diameter)
{

    if (!node)
    {
        return 0;
    }

    int lh = fndMax(node->left, diameter);
    int rh = fndMax(node->right, diameter);

    diameter = max(diameter, lh + rh);

    return 1 + max(lh, rh);
}
int diameterOfBinaryTreeOptimal(Node *root)
{
    int diameter = 0;
    fndMax(root, diameter);
    return diameter;
}

/*
10. Maximum Sum Path in Binary Tree
ANS : Write a program to find the maximum sum path in a binary tree. A path in a binary tree is a sequence of nodes where every adjacent pair of nodes are connected by an edge. A node can only appear in the sequence at most once. A path need not pass from the root. We need to find the path with the maximum sum in the binary tree.
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :O(N)
// SC :O(N)
int findMaxPathSum(Node *root, int &maxi)
{
    if (root == NULL)
        return 0;

    int leftMaxPath = max(0, findMaxPathSum(root->left, maxi));
    int rightMaxPath = max(0, findMaxPathSum(root->right, maxi));
    int val = root->data;
    maxi = max(maxi, (leftMaxPath + rightMaxPath) + val);
    return max(leftMaxPath, rightMaxPath) + val;
}

int maxPathSum(Node *root)
{
    int maxi = INT_MIN;
    findMaxPathSum(root, maxi);
    return maxi;
}
/*
11. Check if two trees are identical
ANS : Given two Binary Tree. Write a program to check if two trees are identical or not.
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :O(N)
// SC :O(N)
bool isIdentical(Node *node1, Node *node2)
{
    if (node1 == NULL && node2 == NULL)
        return true;
    else if (node1 == NULL || node2 == NULL)
        return false;

    return ((node1->data == node2->data) && isIdentical(node1->left, node2->left) && isIdentical(node1->right, node2->right));
}
/*
12. Zig Zag Traversal Of Binary Tree
ANS : Given the root of a binary tree, return the zigzag level order traversal of Binary Tree. (i.e., from left to right, then right to left for the next level and alternate between).
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :O(N)
// SC :O(N)
vector<vector<int>> zigzagLevelOrder(Node *root)
{
    vector<vector<int>> result;
    if (root == NULL)
    {
        return result;
    }

    queue<Node *> nodesQueue;
    nodesQueue.push(root);
    bool leftToRight = true;

    while (!nodesQueue.empty())
    {
        int size = nodesQueue.size();
        vector<int> row(size);
        for (int i = 0; i < size; i++)
        {
            Node *node = nodesQueue.front();
            nodesQueue.pop();

            // find position to fill node's value
            int index = (leftToRight) ? i : (size - 1 - i);

            row[index] = node->data;
            if (node->left)
            {
                nodesQueue.push(node->left);
            }
            if (node->right)
            {
                nodesQueue.push(node->right);
            }
        }
        // after this level
        leftToRight = !leftToRight;
        result.push_back(row);
    }
    return result;
}
/*
13. Boundary Traversal of a Binary Tree
ANS : BoundaryTraversal of a binary tree. Write a program for the Anti-Clockwise Boundary traversal of a binary tree.
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC : The time complexity will be O(H) + O(H) + O(N) which is ≈ O(N)
// SC :O(N)
// Approach: Boundary traversal in an anti-clockwise direction can be described as a traversal consisting of three parts:

// Part 1: Left Boundary of the tree (excluding the leaf nodes).
// Part 2: All the leaf nodes travelled in the left to right direction.
// Part 3: Right Boundary of the tree (excluding the leaf nodes), traversed in the reverse direction.
bool isLeaf(Node *root)
{
    return !root->left && !root->right;
}

void addLeftBoundary(Node *root, vector<int> &res)
{
    Node *cur = root->left;
    while (cur)
    {
        if (!isLeaf(cur))
            res.push_back(cur->data);
        if (cur->left)
            cur = cur->left;
        else
            cur = cur->right;
    }
}
void addRightBoundary(Node *root, vector<int> &res)
{
    Node *cur = root->right;
    vector<int> tmp;
    while (cur)
    {
        if (!isLeaf(cur))
            tmp.push_back(cur->data);
        if (cur->right)
            cur = cur->right;
        else
            cur = cur->left;
    }
    for (int i = tmp.size() - 1; i >= 0; --i)
    {
        res.push_back(tmp[i]);
    }
}

void addLeaves(Node *root, vector<int> &res)
{
    if (isLeaf(root))
    {
        res.push_back(root->data);
        return;
    }
    if (root->left)
        addLeaves(root->left, res);
    if (root->right)
        addLeaves(root->right, res);
}

vector<int> printBoundary(Node *root)
{
    vector<int> res;
    if (!root)
        return res;

    if (!isLeaf(root))
        res.push_back(root->data);

    addLeftBoundary(root, res);

    // add leaf nodes
    addLeaves(root, res);

    addRightBoundary(root, res);
    return res;
}

/*
14. Vertical Order Traversal of Binary Tree
ANS : Vertical Order Traversal Of A Binary Tree. Write a program for Vertical Order Traversal order of a Binary Tree.
There can be duplicate values among the nodes (here 10 is repeated twice).
If two or more nodes are overlapping at the same position(here 10 and 9), then they will be printed in ascending order.
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC : O(N*logN*logN*logN)
// SC : O(N)
vector<vector<int>> findVertical(Node *root)
{
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<Node *, pair<int, int>>> todo;
    todo.push({root,
               {0,
                0}}); // initial vertical and level
    while (!todo.empty())
    {
        auto p = todo.front();
        todo.pop();
        Node *temp = p.first;

        // x -> vertical , y->level
        int x = p.second.first, y = p.second.second;
        nodes[x][y].insert(temp->data); // inserting to multiset

        if (temp->left)
        {
            todo.push({temp->left,
                       {x - 1,
                        y + 1}});
        }
        if (temp->right)
        {
            todo.push({temp->right,
                       {x + 1,
                        y + 1}});
        }
    }
    vector<vector<int>> ans;
    for (auto p : nodes)
    {
        vector<int> col;
        for (auto q : p.second)
        {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}
/*
15. Top view of a Binary Tree
ANS :  Given below is a binary tree. The task is to print the top view of the binary tree. The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :O(N)
// SC :O(N)
vector<int> topView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    map<int, int> mpp;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        Node *node = it.first;
        int line = it.second;
        if (mpp.find(line) == mpp.end())
            mpp[line] = node->data;

        if (node->left != NULL)
        {
            q.push({node->left, line - 1});
        }
        if (node->right != NULL)
        {
            q.push({node->right, line + 1});
        }
    }

    for (auto it : mpp)
    {
        ans.push_back(it.second);
    }
    return ans;
}

/*
16. Bottom view of a Binary Tree
ANS :  Given a binary tree, print the bottom view from left to right. A node is included in the bottom view if it can be seen when we look at the tree from the bottom.
For middle always prefer right one if overlapping
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :O(N)
// SC :O(N)
vector<int> bottomView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    map<int, int> mpp;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        Node *node = it.first;
        int line = it.second;
        mpp[line] = node->data;

        if (node->left != NULL)
        {
            q.push({node->left, line - 1});
        }
        if (node->right != NULL)
        {
            q.push({node->right, line + 1});
        }
    }

    for (auto it : mpp)
    {
        ans.push_back(it.second);
    }
    return ans;
}

/*
17. Right/Left view of binary tree
ANS : Given a Binary Tree, find the Right/Left view of it. The right view of a Binary Tree is a set of nodes visible when the tree is viewed from the right side. The left view of a Binary Tree is a set of nodes visible when the tree is viewed from the left side.
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC : O(N)
// SC :O(H)       (H -> Height of the Tree)
// We play root right left=Right side view
// for Left side view= Eoot left right
// only change in recursion call
void rightRecursion(Node *root, int level, vector<int> &res)
{
    if (root == NULL)
        return;
    if (res.size() == level)
        res.push_back(root->data);
    rightRecursion(root->right, level + 1, res);
    rightRecursion(root->left, level + 1, res);
}

vector<int> rightSideView(Node *root)
{
    vector<int> res;
    rightRecursion(root, 0, res);
    return res;
}

/*
18. Check for Symmetrical Binary Tree
ANS : A symmetrical binary tree is a tree that forms a mirror of itself around the center. In other words, every node in the left subtree will have a mirror image in the right subtree.
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :O(N)
// SC :O(N)
/*
Right portion is Mirror version
root->left=Root Left Right |Then| root->right=Root Right Left
*/
bool isSymmetricUtil(Node *left, Node *right)
{
    if (left == NULL || right == NULL)
        return left == right;
    return (left->data == right->data) && isSymmetricUtil(left->left, right->right) && isSymmetricUtil(left->right, right->left);
}
bool isSymmetric(Node *root)
{
    if (!root)
        return true;
    return isSymmetricUtil(root->left, root->right);
}

/*
19. Print Root to Node Path in a Binary Tree
ANS : We are given a binary tree T and a node V. We need to print a path from the root of the tree to the node.
Note:
No two nodes in the tree have the same data value.
It is assured that the node V is present and a path always exists.
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC : O(N)
// SC :O(N)
bool getPath(Node *root, vector<int> &arr, int x)
{
    // if root is NULL
    // there is no path
    if (!root)
        return false;

    // push the node's value in 'arr'
    arr.push_back(root->data);

    // if it is the required node
    // return true
    if (root->data == x)
        return true;

    // else check whether the required node lies
    // in the left subtree or right subtree of
    // the current node
    if (getPath(root->left, arr, x) ||
        getPath(root->right, arr, x))
        return true;

    // required node does not lie either in the
    // left or right subtree of the current node
    // Thus, remove current node's value from
    // 'arr'and then return false
    arr.pop_back();
    return false;
}

/*
20. Lowest Common Ancestor for two given Nodes
ANS : The lowest common ancestor is defined between two nodes x and y as the lowest node in T that has both x and y as descendants (where we allow a node to be a descendant of itself.
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :O(N)
// SC :O(N)
Node *lowestCommonAncestor(Node *root, Node *p, Node *q)
{
    // base case
    if (root == NULL || root == p || root == q)
    {
        return root;
    }
    Node *left = lowestCommonAncestor(root->left, p, q);
    Node *right = lowestCommonAncestor(root->right, p, q);

    // result
    if (left == NULL)
    {
        return right;
    }
    else if (right == NULL)
    {
        return left;
    }
    else
    { // both left and right are not null, we found our result
        return root;
    }
}
/*
21. Maximum Width of a Binary Tree
ANS : Write a program to find the Maximum Width of A Binary Tree.
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC : O(N)
// SC :O(N)
int widthOfBinaryTree(Node *root)
{
    if (!root)
    {
        return 0;
    }

    unsigned long long ans = 0;
    queue<pair<Node *, unsigned long long>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        unsigned long long n = q.size();
        unsigned long long maxi = INT_MIN;
        unsigned long long mini = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            auto it = q.front();
            q.pop();
            Node *node = it.first;
            unsigned long long id = it.second;

            if (i == 0)
            {
                mini = id;
            }
            if (i == n - 1)
            {
                maxi = id;
            }

            if (node->left)
            {
                q.push({node->left, 2 * id + 1});
            }
            if (node->right)
            {
                q.push({node->right, 2 * id + 2});
            }
        }

        ans = max(ans, maxi - mini + 1);
    }
    return ans;
}

/*
22. Check for Children Sum Property in a Binary Tree
ANS : Children Sum Property in a Binary Tree. Write a program that converts any binary tree to one that follows the children sum property.
The children sum property is defined as, For every node of the tree, the value of a node is equal to the sum of values of its children(left child and right child).
Note:
The node values can be increased by 1 any number of times but decrement of any node value is not allowed.
A value for a NULL node can be assumed as 0.
You are not allowed to change the structure of the given binary tree.
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC : O(N)
// SC :O(N)
void reorder(Node *root)
{
    if (root == NULL)
        return;
    int child = 0;
    if (root->left)
    {
        child += root->left->data;
    }
    if (root->right)
    {
        child += root->right->data;
    }

    if (child < root->data)
    {
        if (root->left)
            root->left->data = root->data;
        else if (root->right)
            root->right->data = root->data;
    }

    reorder(root->left);
    reorder(root->right);

    int tot = 0;
    if (root->left)
        tot += root->left->data;
    if (root->right)
        tot += root->right->data;
    if (root->left || root->right)
        root->data = tot;
}
void changeTree(Node *root)
{
    reorder(root);
}

/*
23. Print Nodes at Distance K in a Binary Tree
ANS : Given a binary tree, a node from the tree, and an integer ‘K’, find all nodes that are at a distance ‘K’ from the given node and return the list of these nodes.
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC : O(N)
// SC :O(N)
void markParen(Node *root, map<Node *, Node *> &mp)
{
    queue<Node *> que;
    que.push(root);
    while (!que.empty())
    {
        Node *node = que.front();
        que.pop();
        if (node->left)
        {
            que.push(node->left);
            mp[node->left] = node;
        }
        if (node->right)
        {
            que.push(node->right);
            mp[node->right] = node;
        }
    }
}

vector<int> distanceK(Node *root, Node *target, int k)
{
    vector<int> ans;
    if (!root || !target)
        return ans;
    map<Node *, Node *> markParent;
    markParen(root, markParent);
    map<Node *, bool> visited;
    queue<Node *> que;
    que.push(target);
    visited[target] = true;
    int count = 0;
    while (!que.empty())
    {
        int size = que.size();
        if (count++ == k)
            break;
        for (int i = 0; i < size; i++)
        {
            Node *node = que.front();
            que.pop();
            if (node->left && !visited[node->left])
            {
                que.push(node->left);
                visited[node->left] = true;
            }
            if (node->right && !visited[node->right])
            {
                que.push(node->right);
                visited[node->right] = true;
            }
            if (markParent[node] && !visited[markParent[node]])
            {
                que.push(markParent[node]);
                visited[markParent[node]] = true;
            }
        }
    }
    while (!que.empty())
    {
        Node *node = que.front();
        que.pop();
        ans.push_back(node->data);
    }
    return ans;
}

/*
24. Minimum Time Taken To Burn Tree
ANS : You have a binary tree of 'N' unique nodes and a Start node from where the tree will start to burn. Given that the Start node will always exist in the tree, your task is to print the time (in minutes) that it will take to burn the whole tree.
It is given that it takes 1 minute for the fire to travel from the burning node to its adjacent node and burn down the adjacent node.
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC : O(N)+O(N)
// SC :O(N)
int findMaxDistance(map<Node *, Node *> &mpp, Node *target)
{
    queue<Node *> q;
    q.push(target);
    map<Node *, int> vis;
    vis[target] = 1;
    int maxi = 0;
    while (!q.empty())
    {
        int sz = q.size();
        int fl = 0;
        for (int i = 0; i < sz; i++)
        {
            auto node = q.front();
            q.pop();
            if (node->left && !vis[node->left])
            {
                fl = 1;
                vis[node->left] = 1;
                q.push(node->left);
            }
            if (node->right && !vis[node->right])
            {
                fl = 1;
                vis[node->right] = 1;
                q.push(node->right);
            }
            if (mpp[node] && !vis[mpp[node]])
            {
                fl = 1;
                vis[mpp[node]] = 1;
                q.push(mpp[node]);
            }
        }
        if (fl)
            maxi++;
    }
    return maxi;
}
Node *bfsToMakeParents(Node *root, map<Node *, Node *> &mpp, int start)
{
    queue<Node *> q;
    q.push(root);
    Node *res;
    while (!q.empty())
    {
        Node *node = q.front();
        if (node->data == start)
            res = node;
        q.pop();
        if (node->left)
        {
            mpp[node->left] = node;
            q.push(node->left);
        }
        if (node->right)
        {
            mpp[node->right] = node;
            q.push(node->right);
        }
    }
    return res;
}

int timeToBurTree(Node *root, int start)
{
    map<Node *, Node *> mpp;
    Node *target = bfsToMakeParents(root, mpp, start);
    int maxi = findMaxDistance(mpp, target);
    return maxi;
}

/*
25. Count Number of Nodes in a Binary Tree
ANS : All levels except the last one are completely filled. The last level may or may not be completely filled.
Nodes in the last level are as left as possible.
Input :   || Output :
*/
// Bruteforce ----------->
// TC : O(N)
// SC :O(logN)
// Using any tree traversal – O(N) Approach
void inOrderTravCntNodes(Node *curr, int &count)
{
    if (curr == NULL)
        return;

    count++;
    inOrderTravCntNodes(curr->left, count);
    inOrderTravCntNodes(curr->right, count);
}
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC : O(log^2 N).
// SC : O(logN)
// we can find out the maximum number of nodes, formula: 2h – 1. (h=height)
// If leftHeight == rightHeight, then the last level nodes are completely filled
// If leftHeight != rightHeight, then the last level nodes are not completely filled
// In the second case, when leftHeight != rightHeight, we can take the help of recursion and say to recursively find the number of nodes in the left subtree (say leftNodes) and in the right subtree(say rightNodes) and then return 1 + leftNodes + rightNodes.
int findHeightLeft(Node *cur)
{
    int hght = 0;
    while (cur)
    {
        hght++;
        cur = cur->left;
    }
    return hght;
}
int findHeightRight(Node *cur)
{
    int hght = 0;
    while (cur)
    {
        hght++;
        cur = cur->right;
    }
    return hght;
}
int countNodes(Node *root)
{
    if (root == NULL)
        return 0;

    int lh = findHeightLeft(root);
    int rh = findHeightRight(root);

    if (lh == rh)
        return (1 << lh) - 1;

    int leftNodes = countNodes(root->left);
    int rightNodes = countNodes(root->right);

    return 1 + leftNodes + rightNodes;
}
/*
26. Requirements needed to construct a Unique Binary Tree
ANS : Given a pair of tree traversal, return 'true' if a unique binary tree can be constructed otherwise 'false'.
Note:
Each traversal is represented with an integer: preorder - 1, inorder - 2, postorder - 3.
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :
// SC :
int uniqueBinaryTree(int a, int b)
{
    if ((a == 2 && b != 2) || (a != 2 && b == 2))
    {
        return true;
    }
    return false;
}

/*
27. Construct A Binary Tree from Inorder and Preorder Traversal
ANS :
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :O(N)
// SC :O(N)
Node *constructTree(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, map<int, int> &mp)
{
    if (preStart > preEnd || inStart > inEnd)
        return NULL;

    Node *root = newNode(preorder[preStart]);
    int elem = mp[root->data];
    int nElem = elem - inStart;

    root->left = constructTree(preorder, preStart + 1, preStart + nElem, inorder,
                               inStart, elem - 1, mp);
    root->right = constructTree(preorder, preStart + nElem + 1, preEnd, inorder,
                                elem + 1, inEnd, mp);

    return root;
}

Node *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int preStart = 0, preEnd = preorder.size() - 1;
    int inStart = 0, inEnd = inorder.size() - 1;

    map<int, int> mp;
    for (int i = inStart; i <= inEnd; i++)
    {
        mp[inorder[i]] = i;
    }

    return constructTree(preorder, preStart, preEnd, inorder, inStart, inEnd, mp);
}

/*
28. Construct Binary Tree from Inorder and PostOrder Traversal
ANS : Construct A Binary Tree from Inorder and PostOrder Traversal.
Given Inorder and PostOrder Traversal of a binary tree, we need to construct the unique binary tree represented by them.
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :
// SC :
Node *constructTree2(vector<int> &postorder, int postStart, int postEnd,
                     vector<int> &inorder, int inStart, int inEnd, map<int, int> &mp)
{
    if (postStart > postEnd || inStart > inEnd)
        return NULL;

    Node *root = newNode(postorder[postEnd]);
    int elem = mp[root->data];
    int nElem = elem - inStart;

    root->left = constructTree2(postorder, postStart, postStart + nElem - 1,
                                inorder, inStart, elem - 1, mp);
    root->right = constructTree2(postorder, postStart + nElem, postEnd - 1, inorder,
                                 elem + 1, inEnd, mp);

    return root;
}

Node *buildTree2(vector<int> &postorder, vector<int> &inorder)
{
    int postStart = 0, postEnd = postorder.size() - 1;
    int inStart = 0, inEnd = inorder.size() - 1;

    map<int, int> mp;
    for (int i = inStart; i <= inEnd; i++)
    {
        mp[inorder[i]] = i;
    }

    return constructTree2(postorder, postStart, postEnd, inorder, inStart, inEnd, mp);
}

/*
29. Serialize And Deserialize a Binary Tree
ANS :  Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC : O(N)
// SC :O(N)
// Encodes a tree to a single string.
string serialize(Node *root)
{
    if (!root)
        return "";

    string s = "";
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *curNode = q.front();
        q.pop();
        if (curNode == NULL)
            s.append("#,");
        else
            s.append(to_string(curNode->data) + ',');
        if (curNode != NULL)
        {
            q.push(curNode->left);
            q.push(curNode->right);
        }
    }
    return s;
}

// Decodes your encoded data to tree.
Node *deserialize(string data)
{
    if (data.size() == 0)
        return NULL;
    stringstream s(data);
    string str;
    getline(s, str, ',');
    Node *root = new Node(stoi(str));
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {

        Node *node = q.front();
        q.pop();

        getline(s, str, ',');
        if (str == "#")
        {
            node->left = NULL;
        }
        else
        {
            Node *leftNode = new Node(stoi(str));
            node->left = leftNode;
            q.push(leftNode);
        }

        getline(s, str, ',');
        if (str == "#")
        {
            node->right = NULL;
        }
        else
        {
            Node *rightNode = new Node(stoi(str));
            node->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

/*
30. Morris Preorder Traversal of a Binary Tree
ANS :
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC : O(N)
// SC :O(1)
// Uses the concept of Threaded Binary tree
vector<int> morrisPreorderTraversal(Node *root)
{
    vector<int> preorder;

    Node *cur = root;
    while (cur != NULL)
    {
        if (cur->left == NULL)
        {
            preorder.push_back(cur->data);
            cur = cur->right;
        }
        else
        {
            Node *prev = cur->left;
            while (prev->right != NULL && prev->right != cur)
            {
                prev = prev->right;
            }

            if (prev->right == NULL)
            {
                prev->right = cur;
                preorder.push_back(cur->data);
                cur = cur->left;
            }
            else
            {
                prev->right = NULL;
                cur = cur->right;
            }
        }
    }
    return preorder;
}
/*
31. Morris Inorder Traversal of a Binary tree
ANS :
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC : O(N)
// SC :O(1)
vector<int> morrisInorderTraversal(Node *root)
{
    vector<int> inorder;

    Node *cur = root;
    while (cur != NULL)
    {
        if (cur->left == NULL)
        {
            inorder.push_back(cur->data);
            cur = cur->right;
        }
        else
        {
            Node *prev = cur->left;
            while (prev->right != NULL && prev->right != cur)
            {
                prev = prev->right;
            }

            if (prev->right == NULL)
            {
                prev->right = cur;
                cur = cur->left;
            }
            else
            {
                prev->right = NULL;
                inorder.push_back(cur->data);
                cur = cur->right;
            }
        }
    }
    return inorder;
}

/*
32. Flatten Binary Tree to Linked List
ANS : Flatten Binary Tree To Linked List. Write a program that flattens a given binary tree to a linked list.
Note:
The sequence of nodes in the linked list should be the same as that of the preorder traversal of the binary tree.
The linked list nodes are the same binary tree nodes. You are not allowed to create extra nodes.
The right child of a node points to the next node of the linked list whereas the left child points to NULL.
Input :   || Output :
*/
// Bruteforce ----------->
// TC :O(N)
// SC :O(N)
void flattenBruteforce(Node *root)
{
    Node *prev = NULL;
    if (root == NULL)
        return;

    flattenBruteforce(root->right);
    flattenBruteforce(root->left);

    root->right = prev;
    root->left = NULL;
    prev = root;
}
// Better ----------->
// TC :O(N)
// SC :O(N)
void flattenBetter(Node *root)
{
    if (root == NULL)
        return;
    stack<Node *> st;
    st.push(root);
    while (!st.empty())
    {
        Node *cur = st.top();
        st.pop();

        if (cur->right != NULL)
        {
            st.push(cur->right);
        }
        if (cur->left != NULL)
        {
            st.push(cur->left);
        }
        if (!st.empty())
        {
            cur->right = st.top();
        }
        cur->left = NULL;
    }
}
// Optimal ---------->
// TC :O(N)
// SC :O(1)
void flattenOptimal(Node *root)
{
    Node *cur = root;
    while (cur)
    {
        if (cur->left)
        {
            Node *pre = cur->left;
            while (pre->right)
            {
                pre = pre->right;
            }
            pre->right = cur->right;
            cur->right = cur->left;
            cur->left = NULL;
        }
        cur = cur->right;
    }
}
// =====================================BINARY SEARCH TREE===============================================>>
/*
-->>Binary Search Trees: popularly known as BST, are the category of Binary Trees used to optimize the operation of searching an element among the Tree Nodes in a Binary Tree.
        8
      /   \
     3     10
    / \      \
   1   6      14
      / \     /
     4   7   13
-->>As we can visualize from the above Tree, the right subtree has all the elements greater than the root element and the left subtree has all the elements lesser than the root element. A point to note here is that every subtree is itself a Binary Search Tree as it contains a subtree whose root node is lesser than the value of the current node and another subtree whose root node is greater than the value of the current node.
-->>Left Child < Node < Right Child
-->>Duplicate node values are not allowed. However, in some exceptional cases of Binary Search Tree implementation, we can represent a Binary Search Tree with duplicate node values
If we really need duplicates then you can slidely chnage the condition to
Left Child <= Node < Right Child
Why is there a need to use a Binary Search Tree instead of a simple Binary Tree?
-->>This particularly makes the time of searching for a given node in a Binary Search Tree a lot less than searching in a simple Binary Tree.
For example, if we have to search for an element, we can directly compare it to the root node value of the BST, if the value matches then we have found the element, if say the value is greater than the root node, we say that we now move on to searching that element in the right subtree because the right subtree has all the node values greater than the root value. The search process is terminated for the left subtree as it would only search for those nodes which have values lesser than the root.
In every binary search tree's height will be gives like logN
*/

/*
33. Search in a Binary Search Tree
ANS : Write a program to search a node with a given value in a binary search tree.
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC : O(logN)
// The time required will be proportional to the height of the tree, if the tree is balanced, then the height of the tree is logN.
// SC :
Node *searchBSTOptimal(Node *root, int target)
{
    while (root != NULL && root->data != target)
    {
        root = target < root->data ? root->left : root->right;
    }
    return root;
}
/*
34. Ceil in a BST
ANS : If target is given also binary search tree have same value then return it else return target>=root->data
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :O(logN)
// SC :
int findCeil(Node *root, int target)
{
    int ceil = -1;
    while (root != NULL)
    {
        if (root->data == target)
        {
            ceil = root->data;
            return ceil;
        }
        if (target > root->data)
            root = root->right;
        else
        {
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;
}

/*
35. Floor in BST
ANS : If target is given also binary search tree have same value then return it else return target<=root->data
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC : O(logN)
// SC :
// Find insert point and insert it
int findFloor(Node *root, int target)
{
    int floor = -1;
    while (root != NULL)
    {
        if (root->data == target)
        {
            floor = root->data;
            return floor;
        }
        if (target > root->data)
        {
            floor = root->data;
            root = root->right;
        }
        else

            root = root->left;
    }
    return floor;
}

/*
36. Insert a Given Node in Binary Search Tree
ANS :  Given a root node reference of a Binary Search Tree and a key, insert a new node with value as the given key in the Binary Search Tree following the rules of a BST. Return the modified Binary Search Tree after insertion.
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :O(logN)
// SC :
Node *insertIntoBST(Node *root, int val)
{
    // If the root node is NULL, create a new node
    // with the given value and return it as the new root.
    if (root == NULL)
    {
        return new Node(val);
    }

    // cur pointer to traverse the tree
    Node *cur = root;

    // While loop to traverse the tree to find
    // the appropriate position for insertion.
    while (true)
    {
        // If the current node's value is less
        // than or equal to the value to be inserted,
        // move to the right subtree.
        if (cur->data <= val)
        {
            // If the right child of the current node
            // is not NULL, update 'cur' to the right child.
            if (cur->right != NULL)
            {
                cur = cur->right;
            }
            // If the right child is NULL, create a new node
            // with the given value as the right child
            // and exit the while loop.
            else
            {
                cur->right = new Node(val);
                break;
            }
        }
        // If the current node's value is greater than
        // the value to be inserted,
        // move to the left subtree.
        else
        {
            // If the left child of the current node
            // is not NULL, update 'cur' to the left child.
            if (cur->left != NULL)
            {
                cur = cur->left;
            }
            // If the left child is NULL, create a new node
            // with the given value as the left child
            // and exit the while loop.
            else
            {
                cur->left = new Node(val);
                break;
            }
        }
    }
    // Return the root of the
    // modified tree after insertion.
    return root;
}

/*
37. Delete a Node in Binary Search Tree
ANS : Given a root node reference of a Binary Search Tree and a key, delete the node with the given key in the Binary Search Tree. Return the modified Binary Search Tree.
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :
// SC :
// Search node and delete

// Helper function to find the

// last right node in a subtree
Node *findLastRight(Node *root)
{
    // Traverse to the rightmost node in the subtree
    if (root->right == NULL)
    {
        // Return the rightmost node
        return root;
    }

    // Recursively find the last right node
    return findLastRight(root->right);
}
// Helper function to delete the node
Node *helper(Node *root)
{
    // If the left child of the root is null,
    // return the right child
    if (root->left == NULL)
    {
        return root->right;
    }
    else if (root->right == NULL)
    {

        // If the right child is null,
        // return the left child
        return root->left;
    }

    // If both left and right children exist
    // Store the right child

    Node *rightChild = root->right;

    // Find the last right child of the left subtree
    Node *lastRight = findLastRight(root->left);

    // Set the right child of the last
    // right node to the stored right child
    lastRight->right = rightChild;

    // Return the left child as the new subtree
    return root->left;
}

Node *deleteNode(Node *root, int key)
{
    // Check if the root is empty
    if (root == NULL)
    {
        // Return null if the root is empty
        return NULL;
    }

    // If the current root node has the key to be deleted
    if (root->data == key)
    {
        // Delete the node using the helper function
        return helper(root);
    }

    // Create a dummy node pointing to the root
    Node *dummy = root;
    // While loop to traverse the tree
    while (root != NULL)
    {
        // If the value to be deleted
        // is in the left subtree
        if (root->data > key)
        {
            // If the left child exists and
            // its value matches the key
            if (root->left != NULL && root->left->data == key)
            {

                // Delete the node using the helper function
                root->left = helper(root->left);
                break;
            }
            else
            {
                // If the value is not in the left
                // subtree, move to the right subtree
                if (root->right != NULL && root->right->data == key)
                {
                    // Delete the node using the helper function
                    root->right = helper(root->right);
                    break;
                }
                else
                {
                    // Move to the right subtree
                    root = root->right;
                }
            }
        }
    }

    // Return the modified tree
    return dummy;
}

/*
38. Kth largest/smallest element in Binary Search Tree
ANS :
Input : 1 2 3 4 5 6  || Output : smallest: 3 largest 4
*/
// Bruteforce ----------->
// TC :O(N)+O(logN)
// SC :O(N)
// Try any DFS Trevarsal then put elem into a DS then sort it then find smallest/largest from this DS
// Better ----------->
// TC :O(N)
// SC :O(N)
// You can remove logN using In-order Trevarsal bcz In-Order Trevarsal sort it self
// You can remove space if you use cnt++==target
// Still,Here space is also N for stack/iterative trevarsal for this you need N for space
// Optimal ---------->
// Time Complexity: O(min(K,N))
// Space Complexity: O(min(K,N))
// Only using morris Trevarsal you can remove space O(N) try Morris In-order Trevarsal
// K-th largest==(N-k-th)smallest
Node *kthlargest(Node *root, int &k)
{
    if (root == NULL)
        return NULL;

    Node *right = kthlargest(root->right, k);
    if (right != NULL)
        return right;
    k--;

    if (k == 0)
        return root;

    return kthlargest(root->left, k);
}

Node *kthsmallest(Node *root, int &k)
{
    if (root == NULL)
        return NULL;

    Node *left = kthsmallest(root->left, k);
    if (left != NULL)
        return left;
    k--;
    if (k == 0)
        return root;

    return kthsmallest(root->right, k);
}
/*
39. Check if a tree is a Binary Search Tree or Binary Tree
ANS :
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :O(N)
// SC :

// Helper function to recursively validate the BST property
bool isValidBST(Node *root, long minVal, long maxVal)
{
    if (root == nullptr)
    {
        // Base case: an empty
        // tree is a valid BST
        return true;
    }

    // Checks if the current node
    // violates the BST property
    if (root->data >= maxVal || root->data <= minVal)
    {
        return false;
    }

    // Recursively checks left and right
    // subtrees with updated constraints
    // that every value on its left subtree
    // should be smaller than the current node
    // and every value on its right subtree
    // should be greater than the current node
    return isValidBST(root->left, minVal, root->data) && isValidBST(root->right, root->data, maxVal);
}
// Function to check if a given binary
// tree is a valid binary search tree (BST)
bool isValid(Node *root)
{
    // Calls the helper function isValidBST
    // with initial min and max values
    return isValidBST(root, LONG_MIN, LONG_MAX);
}
/*
40. LCA(lowest common ancestor) in Binary Search Tree
ANS : Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :O(H)
// SC :O(1)
/*

        8
      /   \
     3     10
    / \      \
   1   6      14
      / \     /
     4   7   13

p=1,q=6 then ancestor = 3 cz its common
approach is where both pointer taking separation that will be my ancestor

*/
Node *lowestCommonAncestorBST(Node *root, Node *p, Node *q)
{
    // Check if the root is null
    if (root == nullptr)
    {
        // If null, return null as there's no LCA
        return nullptr;
    }

    // Store the value of the current root node
    int curr = root->data;

    // If both p and q values are greater
    // than the current root's value
    if (curr < p->data && curr < q->data)
    {
        // Recursively search in the
        // right subtree for the LCA
        return lowestCommonAncestorBST(root->right, p, q);
    }

    // If both p and q values are smaller
    // than the current root's value
    if (curr > p->data && curr > q->data)
    {
        // Recursively search in the
        // left subtree for the LCA
        return lowestCommonAncestorBST(root->left, p, q);
    }

    // If the values are on either side of the current root's value,
    // or one of the values matches the current root's value,
    // return the current root as the LCA
    return root;
}
/*
41. Construct a BST from a Pre-order Traversal
ANS :
Input :  preorder = [8,5,1,7,10,12] || Output:  return root or [8,5,10,1,7,null,12]
*/
// Bruteforce ----------->
// TC :O(N^2)
// SC :
Node *bstFromPreorderBruteforce(const vector<int> &preorder)
{
    if (preorder.empty())
        return nullptr;

    Node *root = new Node(preorder[0]);

    for (int i = 1; i < preorder.size(); ++i)
    {
        Node *node = root;
        while (true)
        {
            if (preorder[i] < node->data)
            {
                if (node->left == nullptr)
                {
                    node->left = new Node(preorder[i]);
                    break;
                }
                else
                {
                    node = node->left;
                }
            }
            else
            {
                if (node->right == nullptr)
                {
                    node->right = new Node(preorder[i]);
                    break;
                }
                else
                {
                    node = node->right;
                }
            }
        }
    }

    return root;
}

// Better ----------->
// TC :o(NlogN)+O(N)
// SC :O(N)
Node *bstFromPreorderBetter(vector<int> &preorder)
{
    if (preorder.empty())
        return nullptr;

    vector<int> inorder = preorder;
    sort(inorder.begin(), inorder.end());
    // This is BST using preorder and inorder
    Node *ret = buildTree(preorder, inorder);
    return ret;
}
// Optimal ---------->
// TC :O(3N)
// SC :
Node *buildT(vector<int> &A, int &i, int bound)
{
    if (i == A.size() || A[i] > bound)
        return NULL;
    Node *root = new Node(A[i++]);
    root->left = buildT(A, i, root->data);
    root->right = buildT(A, i, bound);
    return root;
}
Node *bstFromPreorderOptimal(vector<int> &preorder)
{
    int i = 0;
    return buildT(preorder, i, INT_MAX);
}

/*
42.Inorder Predecessor And Successor In BST
ANS :
1. The predecessor of a node in BST is that node that will be visited just before the given node in the inorder traversal of the tree. If the given node is visited first in the inorder traversal, then its predecessor is NULL.
2. The successor of a node in BST is that node that will be visited immediately after the given node in the inorder traversal of the tree. If the given node is visited last in the inorder traversal, then its successor is NULL.
Input :   || Output :
*/
// Bruteforce ----------->
// TC :O(N)+O(logN) or O(N) binary.linear
// SC :O(N)
// Try inorder traversal bcz its sort itself then store all this node in DS then try linear search or binary search rerurn for successor is >target and predecessor is <target
// Better ----------->
// TC :(N)
// SC :
// while doing inorder traversal if any number greater than target that will be our successor
// Optimal ---------->
// TC :O(H)
// SC :
// As we know BST have left<root<right , so if we stand at root and root->left<target then
// there is no change of finding successor then go for right and do the same
Node *inorderSuccessor(Node *root, Node *p)
{
    Node *successor = NULL;
    while (root != nullptr)
    {
        if (p->data >= root->data)
            root = root->right;
        else
        {
            successor = root;
            root = root->left;
        }
    }
    return successor;
}
Node *inorderPredecessor(Node *root, Node *p)
{
    Node *predecessor = NULL;
    while (root != nullptr)
    {
        if (p->data <= root->data)
            root = root->left;
        else
        {
            predecessor = root;
            root = root->right;
        }
    }
    return predecessor;
}

/*
43. Design BST Iterator
ANS :
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :O(H)
// SC :

// next=1st root
// hasNext=if elem have then return true else false
class BSTIterator
{
    stack<Node *> myStack;

public:
    BSTIterator(Node *root)
    {
        pushAll(root);
    }
    bool hasNext()
    {
        return !myStack.empty();
    }
    int next()
    {
        Node *tempNode = myStack.top();
        myStack.pop();
        pushAll(tempNode->right);
        return tempNode->data;
    }

private:
    void pushAll(Node *node)
    {
        for (; node != NULL; myStack.push(node), node = node->left)
            ;
    }
};

/*
44. Merge Two BSTs
ANS : You are given two binary search trees of integers having ‘N’ and ‘M’ nodes. Return an array that contains elements of both BST in sorted order.
Input :   || Output :
*/
// Bruteforce ----------->
// TC :O(M+N)
// SC :O(H1+H2)
// Iterative inorder traversal
class snode
{
public:
    Node *t;
    snode *next;
};

// Function to add an element k to stack
void push(snode **s, Node *k)
{
    snode *tmp = new snode();

    // perform memory check here
    tmp->t = k;
    tmp->next = *s;
    (*s) = tmp;
}

// Function to pop an element t from stack
Node *pop(snode **s)
{
    Node *t;
    snode *st;
    st = *s;
    (*s) = (*s)->next;
    t = st->t;
    free(st);
    return t;
}

// Function to check whether the stack is empty or not
int isEmpty(snode *s)
{
    if (s == NULL)
        return 1;

    return 0;
}
//.................... END OF STACK RELATED
// STUFF....................

/* Utility function to create a new Binary Tree node */

// The function to print data of two BSTs in sorted order
void mergeBruteforce(Node *root1, Node *root2)
{
    // s1 is stack to hold nodes of first BST
    snode *s1 = NULL;

    // Current node of first BST
    Node *current1 = root1;

    // s2 is stack to hold nodes of second BST
    snode *s2 = NULL;

    // Current node of second BST
    Node *current2 = root2;

    // If first BST is empty, then output is inorder
    // traversal of second BST
    if (root1 == NULL)
    {
        inorderTraversal(root2);
        return;
    }
    // If second BST is empty, then output is inorder
    // traversal of first BST
    if (root2 == NULL)
    {
        inorderTraversal(root1);
        return;
    }

    // Run the loop while there are nodes not yet printed.
    // The nodes may be in stack(explored, but not printed)
    // or may be not yet explored
    while (current1 != NULL || !isEmpty(s1) || current2 != NULL || !isEmpty(s2))
    {
        // Following steps follow iterative Inorder
        // Traversal
        if (current1 != NULL || current2 != NULL)
        {
            // Reach the leftmost node of both BSTs and push
            // ancestors of leftmost nodes to stack s1 and
            // s2 respectively
            if (current1 != NULL)
            {
                push(&s1, current1);
                current1 = current1->left;
            }
            if (current2 != NULL)
            {
                push(&s2, current2);
                current2 = current2->left;
            }
        }
        else
        {
            // If we reach a NULL node and either of the
            // stacks is empty, then one tree is exhausted,
            // print the other tree
            if (isEmpty(s1))
            {
                while (!isEmpty(s2))
                {
                    current2 = pop(&s2);
                    current2->left = NULL;
                    inorderTraversal(current2);
                }
                return;
            }
            if (isEmpty(s2))
            {
                while (!isEmpty(s1))
                {
                    current1 = pop(&s1);
                    current1->left = NULL;
                    inorderTraversal(current1);
                }
                return;
            }

            // Pop an element from both stacks and compare
            // the popped elements
            current1 = pop(&s1);
            current2 = pop(&s2);

            // If element of first tree is smaller, then
            // print it and push the right subtree. If the
            // element is larger, then we push it back to
            // the corresponding stack.
            if (current1->data < current2->data)
            {
                cout << current1->data << " ";
                current1 = current1->right;
                push(&s2, current2);
                current2 = NULL;
            }
            else
            {
                cout << current2->data << " ";
                current2 = current2->right;
                push(&s1, current1);
                current1 = NULL;
            }
        }
    }
};
// Better ----------->
// TC :O(M+N)
// SC :O(H1+H2)
vector<int> mergeBetter(Node *root1, Node *root2)
{
    vector<int> res;
    stack<Node *> s1, s2;
    while (root1 || root2 || !s1.empty() || !s2.empty())
    {
        while (root1)
        {
            s1.push(root1);
            root1 = root1->left;
        }
        while (root2)
        {
            s2.push(root2);
            root2 = root2->left;
        }
        // Step 3 Case 1:-
        if (s2.empty() || (!s1.empty() && s1.top()->data <= s2.top()->data))
        {
            root1 = s1.top();
            s1.pop();
            res.push_back(root1->data);
            root1 = root1->right;
        }
        // Step 3 case 2 :-
        else
        {
            root2 = s2.top();
            s2.pop();
            res.push_back(root2->data);
            root2 = root2->right;
        }
    }
    return res;
}
// Optimal ---------->
// TC :O(N+M)
// SC :O(1)
Node *bstToDoublyLinkedList(Node *root)
{
    if (!root)
        return nullptr;

    Node *head = nullptr;
    Node *tail = nullptr;
    Node *current = root;
    Node *pre = nullptr;

    while (current)
    {
        if (!current->left)
        {
            if (!head)
            {
                head = new Node(current->data);
                tail = head;
            }
            else
            {
                tail->next = new Node(current->data);
                tail->next->prev = tail;
                tail = tail->next;
            }
            current = current->right;
        }
        else
        {
            pre = current->left;
            while (pre->right && pre->right != current)
                pre = pre->right;

            if (!pre->right)
            {
                pre->right = current;
                current = current->left;
            }
            else
            {
                pre->right = nullptr;
                if (!head)
                {
                    head = new Node(current->data);
                    tail = head;
                }
                else
                {
                    tail->next = new Node(current->data);
                    tail->next->prev = tail;
                    tail = tail->next;
                }
                current = current->right;
            }
        }
    }
    return head;
}

// Function to merge two sorted doubly linked lists (in-place)
Node *mergeDoublyLinkedLists(Node *a, Node *b)
{
    if (!a)
        return b;
    if (!b)
        return a;

    Node dummy(0);
    Node *current = &dummy;

    while (a && b)
    {
        if (a->data < b->data)
        {
            current->next = a;
            a->prev = current;
            a = a->next;
        }
        else
        {
            current->next = b;
            b->prev = current;
            b = b->next;
        }
        current = current->next;
    }

    if (a)
    {
        current->next = a;
        a->prev = current;
    }
    else
    {
        current->next = b;
        b->prev = current;
    }

    return dummy.next;
}

// Function to print the doubly linked list
void printDoublyLinkedList(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to convert BSTs to sorted doubly linked lists, merge them, and print the result
void mergeBSTsOptimal(Node *root1, Node *root2)
{
    Node *list1 = bstToDoublyLinkedList(root1);
    Node *list2 = bstToDoublyLinkedList(root2);
    Node *mergedList = mergeDoublyLinkedLists(list1, list2);

    cout << "Merged and sorted doubly linked list: ";
    printDoublyLinkedList(mergedList);
}

/*
45. Two SUm in BST
ANS : You are given a Binary Search Tree (BST) and a target value ‘K’. Your task is to return true if there exist two nodes in the given BST such that the sum of their values is equal to the given target ‘K’, else return false.
1. All the elements of the Binary Search Tree are unique.
2. You can’t use the same node value/element of BST twice.
Input :   || Output :
*/
// Bruteforce ----------->
// TC :O(N)
// SC :O(N)
void inorderTE(Node *root, vector<int> &elems)
{
    if (!root)
        return;
    stack<Node *> s;
    Node *current = root;
    while (current != nullptr || !s.empty())
    {
        while (current != nullptr)
        {
            s.push(current);
            current = current->left;
        }
        current = s.top();
        s.pop();
        elems.push_back(current->data);
        current = current->right;
    }
}

// Function to check if there exists a pair summing up to k in the BST
bool pairSumBstBruteforce(Node *root, int k)
{
    if (!root)
        return false;

    // Store elements of BST in vector
    vector<int> elems;
    inorderTE(root, elems);
    printVector(elems);
    // Two pointer approach
    int left = 0, right = elems.size() - 1;
    while (left < right)
    {
        int sum = elems[left] + elems[right];
        if (sum == k)
        {
            cout << elems[left] << " " << elems[right] << endl;
            return true;
        }
        else if (sum < k)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return false;
}
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :O(N)
// SC :O(H)
class BSTIterator2
{
    stack<Node *> myStack;
    bool reverse = true;

public:
    BSTIterator2(Node *root, bool isReverse)
    {
        reverse = isReverse;
        pushAll(root);
    }
    bool hasNext()
    {
        return !myStack.empty();
    }
    int next()
    {
        Node *tempNode = myStack.top();
        myStack.pop();
        if (!reverse)
            pushAll(tempNode->right);
        else
            pushAll(tempNode->left);
        return tempNode->data;
    }

private:
    void pushAll(Node *node)
    {
        for (; node != NULL;)
        {
            myStack.push(node);
            if (reverse == true)
                node = node->right;
            else
                node = node->left;
        }
    }
};
class sol
{
public:
    bool findTarget(Node *root, int k)
    {
        if (!root)
            return false;
        BSTIterator2 l(root, false);
        BSTIterator2 r(root, true);
        int i = l.next();
        int j = r.next();
        while (i < j)
        {
            if (i + j == k)
                return true;
            else if (i + j < k)
                i = l.next();
            else
                j = r.next();
        }
        return false;
    }
};

/*
46.  Recover Binary Search Tree
ANS : You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.
Input :   || Output :
*/
// Bruteforce ----------->
// TC :O(N)
// SC :O(N)
void inorderTraversall(Node *root, vector<Node *> &elements)
{
    if (!root)
        return;
    inorderTraversall(root->left, elements);
    elements.push_back(root);
    inorderTraversall(root->right, elements);
}
void recoverTree(Node *root)
{
    if (!root)
        return;

    vector<Node *> elements;
    inorderTraversall(root, elements);

    Node *first = nullptr;
    Node *second = nullptr;

    for (int i = 0; i < elements.size() - 1; ++i)
    {
        if (elements[i]->data > elements[i + 1]->data)
        {
            if (!first)
            {
                first = elements[i];
                second = elements[i + 1];
            }
            else
            {
                second = elements[i + 1];
                break; // We found both misplaced elements, no need to continue
            }
        }
    }

    swap(first->data, second->data);
}
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :O(N)
// SC :O(1)
class S
{
private:
    Node *first;
    Node *prev;
    Node *middle;
    Node *last;

private:
    void inorderL(Node *root)
    {
        if (root == NULL)
            return;
        inorderL(root->left);
        if (prev != NULL && (root->data < prev->data))
        { // if this is a first violation then mark these two as first and middle
            if (first == NULL)
            {
                first = prev;
                middle = root;
            } // if this is a second violation then mark this node as a last
            else
                last = root;
        }
        // Mark this node as a previous
        prev = root;
        inorderL(root->right);
    }

public:
    void recoverTreeOptimal(Node *root)
    {
        first = middle = last = NULL;
        prev = new Node(INT_MIN);
        inorderL(root);
        if (first && last)
            swap(first->data, last->data);
        else if (first && middle)
            swap(first->data, middle->data);
    }
};

/*
47. Size of Largest BST in Binary Tree
ANS : You have been given a Binary Tree of 'N' nodes, where the nodes have integer values. Your task is to return the size of the largest subtree of the binary tree which is also a BST.
Input :   || Output :
*/
// Bruteforce ----------->
// TC :O(N^2)
// SC :O(H)
// Helper function to check if a binary tree is a BST
bool isBST(Node *root, int min_val, int max_val)
{
    if (!root)
        return true;
    if (root->data <= min_val || root->data >= max_val)
        return false;
    return isBST(root->left, min_val, root->data) && isBST(root->right, root->data, max_val);
}

// Helper function to calculate the size of a binary tree
int size(Node *root)
{
    if (!root)
        return 0;
    return 1 + size(root->left) + size(root->right);
}

// Function to find the largest BST in a binary tree
int largestBST(Node *root)
{
    if (!root)
        return 0;

    if (isBST(root, INT_MIN, INT_MAX)) // Check if the entire tree is a BST
        return size(root);

    // Recursively find the largest BST in the left and right subtrees
    int left = largestBST(root->left);
    int right = largestBST(root->right);

    // Return the maximum size found in the left, right, and current subtrees
    return max(left, right);
}
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :O(N)
// SC :O(1)
class NodeValue
{
public:
    int maxNode, minNode, maxSize;
    NodeValue(int minNode, int maxNode, int maxSize)
    {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};
class ss
{
private:
    NodeValue largestBstSubtreeHelper(Node *root)
    {
        if (!root)
            return NodeValue(INT_MAX, INT_MIN, 0);
        auto left = largestBstSubtreeHelper(root->left);
        auto right = largestBstSubtreeHelper(root->right);
        if (left.maxNode < root->data && root->data < right.minNode)
        {
            // Its a BST
            return NodeValue(min(root->data, left.minNode), max(root->data, right.maxNode), left.maxSize + right.maxSize + 1);
        }
        // Otherwise return [-inf,inf] so that parent can't be valid BST
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }

public:
    int largestBSTSubtree(Node *root)
    {
        return largestBstSubtreeHelper(root).maxSize;
    }
};
//============================EXTRA IMPORTANT============================>>
/*
48.  Create Binary Tree
ANS : Given an array 'arr' that contains 7 integers representing the values of nodes in a binary tree. This represents level order.
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal -----Level Order----->
// TC :O(N)
// SC :O(N)
Node *createTree(vector<int> &arr)
{
    queue<Node *> q;
    // Create the root node with the value from the first element of the array
    Node *root = new Node(arr[0]);
    q.push(root);

    int i = 0;

    // Construct the binary tree using the remaining elements of the array
    while (!q.empty() && i < 3)
    {
        Node *t = q.front();
        q.pop();

        // Create the left child node with the value from the corresponding index in the array
        Node *left = new Node(arr[2 * i + 1]);
        t->left = left;
        q.push(left);

        // Create the right child node with the value from the corresponding index in the array
        Node *right = new Node(arr[2 * i + 2]);
        t->right = right;
        q.push(right);
        i++;
    }
    return root;
}

/*
49.
ANS :
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :
// SC :

/*
50.
ANS :
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :
// SC :

// ================================MAIN START=================================>>

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("./i.txt", "r", stdin);
    //     freopen("./o.txt", "w", stdout);
    // #endif
    /*
        Some short function
           int maxi = *max_element(arr.begin(), arr.end());
            int sum = accumulate(arr.begin(), arr.end(), 0);
    */

    // Srart code here-------->>
    // struct Node *root = new Node(1);
    // root->left = newNode(2);
    // root->right = newNode(3);
    // root->left->left = newNode(4);
    // root->left->right = newNode(5);
    // root->left->right->left = newNode(8);
    // root->right->left = newNode(6);
    // root->right->right = newNode(7);
    // root->right->right->left = newNode(9);
    // root->right->right->right = newNode(10);
    // printTree(root);
    // Binary Tree created
    // inorderTraversal(root);
    // cout << endl;
    // preorderTraversal(root);
    // cout << endl;
    // postorderTraversal(root);
    // cout << endl;
    // vector<vector<int>> ans = levelorderTraversal(root);
    // vector<vector<int>> ans = zigzagLevelOrder(root);
    // printVectorVector(ans);
    // cout << "This is Binary tree" << endl;
    // cout << maxDepthLevelOrder(root);
    // cout << maxDepthLevelOrderOptimal(root);
    // cout << isBalancedBruteforce(root);
    // cout << isBalancedOptimal(root);
    // cout << diameterOfBinaryTreeBruteforce(root);
    // cout << diameterOfBinaryTreeOptimal(root);
    // cout << maxPathSum(root);
    // vector<int> boundaryTraversal;
    // boundaryTraversal = printBoundary(root);
    // vector<vector<int>>ans=findVertical(root);
    // vector<int> ans = topView(root);
    // vector<int> ans = rightSideView(root);
    // cout << isSymmetric(root);
    // cout << "The Output is : " << endl;
    // printVector(ans);
    // vector<int> arr;

    // bool res;
    // res = getPath(root, arr, 10);

    // cout << "The path is ";
    // for (auto it : arr)
    // {
    //     cout << it << " ";
    // }
    // cout << "Tree's width is : " << widthOfBinaryTree(root);
    // changeTree(root);
    // cout << "After chnage" << endl;
    // printTree(root);
    // Node *target = root->right;
    // cout << "Target= " << target->data << endl;
    // vector<int> ans = distanceK(root, target, 2);
    // cout << "The nodes are ";
    // printVector(ans);
    // cout << "Time Taken " << timeToBurTree(root, 3);
    // int count = 0;
    // inOrderTravCntNodes(root, count);
    // cout << "Total Node is " << count << endl;
    // cout << "Total Node is " << countNodes(root);
    // vector<int> preorder{10, 20, 40, 50, 30, 60};
    // vector<int> inorder{40, 20, 50, 10, 60, 30};
    // Node *rot = buildTree(preorder, inorder);
    // printTree(rot);
    // vector<int> postorder{40, 50, 20, 60, 30, 10};
    // vector<int> inorder{40, 20, 50, 10, 60, 30};
    // Node *rot = buildTree2(postorder, inorder);
    // printTree(rot);
    // cout << "Serialize binary tree is " << serialize(root) << endl;
    // cout << "Deserialize binary tree is ";
    // Node *ans = deserialize(serialize(root));
    // printTree(ans);
    // vector<int> ans = morrisPreorderTraversal(root);
    // printVector(ans);
    // vector<int> ans2 = morrisInorderTraversal(root);
    // printVector(ans2);
    // flattenBruteforce(root);
    // flattenBetter(root);
    // flattenOptimal(root);
    // while (root->right != NULL)
    // {
    //     cout << root->data << "->";
    //     root = root->right;
    // }
    // cout << root->data;
    struct Node *root = new Node(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);
    // printTree(root);
    // Node *found = searchBSTOptimal(root, 10);
    // printTree(found);
    // cout << "Ceil is " << findCeil(root, 5);
    // cout << endl;
    // cout << "Floor is " << findFloor(root, 5);
    // insertIntoBST(root, 2);
    // printTree(root);
    // inorderTraversal(root);
    // cout << endl;
    // int k = 3;
    // Node *ans = kthlargest(root, k);
    // cout << "Largest :" << ans->data << endl;
    // int p = 3;
    // Node *ans2 = kthsmallest(root, p);
    // cout << "Smallest :" << ans2->data << endl;
    // bool isValidBST = isValid(root);

    // if (isValidBST)
    // {
    //     cout << "The tree is a valid BST." << endl;
    // }
    // else
    // {
    //     cout << "The tree is not a valid BST." << endl;
    // }
    // Node *ans = lowestCommonAncestorBST(root, root->left->left, root->left->right);
    // cout << ans->data;
    // Set the seed based on current time

    // Function to generate a random number between min and max (inclusive)
    // Node * ans=bstFromPreorderBruteforce({8,5,1,7,10,12});
    // vector<int> preorder = {8, 5, 1, 7, 10, 12};
    // Node *ans = bstFromPreorderBetter(preorder);
    // Node *ans = bstFromPreorderOptimal(preorder);
    // printTree(root);
    // Node *ans = inorderSuccessor(root, root->left->right);
    // Node *ans2 = inorderPredecessor(root, root->left->right);
    // cout << "Successor " << ans->data << endl;
    // cout << "Predecessor " << ans2->data;
    Node *temp2 = NULL;
    temp2 = newNode(4);
    temp2->left = newNode(5);
    temp2->right = newNode(2);
    // mergeBruteforce(root, temp2);
    // vector<int> ans = mergeBetter(root, temp2);
    // printVector(ans);
    // mergeBSTsOptimal(root, temp2);

    // int k = 2;
    // sol obj;
    // cout << obj.findTarget(root, k);
    // recoverTree(temp2);
    // S obj;
    // obj.recoverTreeOptimal(temp2);
    // printTree(temp2);
    // ss obj;
    // cout << "ans " << obj.largestBSTSubtree(root);
    cout << "ans " << largestBST(root);

    // End code here-------->>
    return 0;
}
