#ifndef TOURNAMENTSORT_H
#define TOURNAMENTSORT_H

#include <vector>
#include <cmath>

template <typename T>
void TournamentSort(std::vector<T> &data)
{
    if (data.size() < 2)
        return;
    int size = data.size();
    int height = 0;
    while (pow(2, height) < size)
        height++;
    TreeNode tree();
    T first = data.front();
    T last = data.back();
    tree.createTournamentTree(height, data);
    while (data.size() != size)
    {
        data.push_back(tree.getNextNode());
    }
}

template <typename T>
class TreeNode
{
    T key;
    TreeNode *right;
    TreeNode *left;
    int height;

public:
    TreeNode(int height) : T(0), right(nullptr), left(nullptr), height(height) {};
    ~TreeNode() { deleteTournamentTree(); };
    void createTournamentTree(int height, std::vector<T> &data)
    {
        if (this->height == height)
            return;
        this->left = addNode(this->height + 1);
        this->left->createTournamentTree();
        this->left->key = data.front();
        data.erase(data.begin());
        if (data.empty())
            return;
        this->right = addNode(this->height + 1);
        this->right->createTournamentTree(height);
        this->right->key = data.front();
        data.erase(data.begin());
        if (data.empty())
            return;
        if (right && left)
            if (this->left->key < this->right->key)
                this->key = this->left->key;
            else
                this->key = this->right->key;
        else if (left && !right)
            this->key = this->left->key;
        else if (!left && right)
            this->key = this->right->key;
        return;
    };
    TreeNode *addNode(int height)
    {
        return new TreeNode(height);
    };
    void deleteTournamentTree(TreeNode *node)
    {
        if (node == nullptr)
            return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    };
    T getNextNode()
    {
        if (this->key == this->left->key)
            findlist(this->right->key);
        else
            find(this->left->key);
        return this->key;
    };
    void findlist(T key)
    {
        if (!this->left && !this->right)
            return;
        if (this->left->key == key)
            this->left->findlist(key);
        this->key = this->right->key;
        else this->right->findlist(key);
    };
};

#endif