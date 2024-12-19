#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TrieNode
{

    TrieNode *child[26];

    bool wordEnd;

    TrieNode()
    {
        wordEnd = false;
        for (int i = 0; i < 26; i++)
        {
            child[i] = nullptr;
        }
    }
};

void insertKey(TrieNode *root, const string &key)
{

    TrieNode *curr = root;

    for (char c : key)
    {

        if (curr->child[c - 'a'] == nullptr)
        {

            TrieNode *newNode = new TrieNode();

            curr->child[c - 'a'] = newNode;
        }

        curr = curr->child[c - 'a'];
    }

    curr->wordEnd = true;
}

bool searchKey(TrieNode *root, const string &key)
{

    TrieNode *curr = root;

    for (char c : key)
    {

        if (curr->child[c - 'a'] == nullptr)
            return false;

        curr = curr->child[c - 'a'];
    }

    return true;
}

int main()
{
    TrieNode *root = new TrieNode();
    vector<string> arr =
        {"deekshapagal", "zoropagal", "do", "geek", "dad", "ball"};
    for (const string &s : arr)
    {
        insertKey(root, s);
    }

    vector<string> searchKeys = {"deeksha", "gee", "bat"};
    for (string &s : searchKeys)
    {
        cout << "Key : " << s << "\n";
        if (searchKey(root, s))
            cout << "Present\n";
        else
            cout << "Not Present\n";
    }

    return 0;
}
