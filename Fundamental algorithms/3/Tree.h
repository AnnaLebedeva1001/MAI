#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

const string Letters = "abcdefghijklmonpqrstuvwxyz";

const string errors[] =
{
    "Input file not found",
    "Wrong argument count",
    "You can't call function with another call for a parameter"
};

void error(int errorId)
{
    cout << "Error: " << errors[errorId - 1] << "!!1!1 Press any key to exit...";
    exit(errorId);
}

struct TreeNode
{
    pair<string, int> key;
    bool recursive;
    TreeNode* son;
    TreeNode* brother;
    TreeNode() : key(), recursive(), son{ nullptr }, brother{ nullptr } {};
    TreeNode(pair<string, int> k) : key{ k }, recursive{ 0 }, son{ nullptr }, brother{ nullptr } {};
};

class Tree
{
private:
    TreeNode* root;

    TreeNode* Insert(TreeNode* node, pair<string, int> son)
    {
        if (node == nullptr)
            return new TreeNode(son);

        TreeNode* temp;

        if (node->son == nullptr)
        {
            node->son = new TreeNode(son);
            return node;
        }

        temp = node->son;

        while (temp->brother != nullptr)
            temp = temp->brother;

        temp->brother = new TreeNode(son);

        return node;
    }

    void rec(TreeNode* node, vector<Tree>& decl, vector<TreeNode*>& all_call)
    {
        int f = 0, j;

        if (node != nullptr) {
            all_call.push_back(node);
            for (size_t i = 0; i < decl.size(); i++)
                if (decl[i].getter()->key.first == node->key.first)
                {
                    j = i;
                    f = 1;
                    if (decl[i].getter()->recursive)
                    {
                        f = 0;
                    }
                    break;
                }
            if (f)
            {
                rec(decl[j].getter()->recursive ? decl[j].getter() : decl[j].getter()->son, decl, all_call);
                rec(decl[j].getter()->recursive ? decl[j].getter() : decl[j].getter()->brother, decl, all_call);
            }
            else
            {
                rec(node->son, decl, all_call);
                rec(node->brother, decl, all_call);
            }
            if (node->brother)
                rec(node->brother, decl, all_call);
        }
    }

    void Is_recursive(TreeNode* root)
    {
        TreeNode* temp = root->son;

        while (temp != nullptr)
        {
            if (temp->key.first == root->key.first && temp->key.second == root->key.second)
            {
                root->recursive = 1;
                break;
            }
            temp = temp->brother;
        }
    }

    void PrintTree(TreeNode* node, vector<Tree>& decl)
    {
        static int cnt = 1;
        int f = 0, j;

        if (node != nullptr) {
            for (int i = 0; i < cnt; i++)
                std::cout << "\t";
            cout << node->key.first;
            for (size_t i = 0; i < decl.size(); i++)
                if (decl[i].getter()->key.first == node->key.first)
                {
                    j = i;
                    f = 1;
                    if (decl[i].getter()->recursive)
                    {
                        cout << " " << "recursive" << "\n";
                        f = 0;
                    }
                    break;
                }
            if (f)
            {
                cout << "\n";
                cnt++;
                PrintTree(decl[j].getter()->recursive ? decl[j].getter() : decl[j].getter()->son, decl);
                cnt--;
                PrintTree(decl[j].getter()->recursive ? decl[j].getter() : decl[j].getter()->brother, decl);
            }
            else
            {
                cnt++;
                PrintTree(node->son, decl);
                cnt--;
                PrintTree(node->brother, decl);
            }
            if (node->brother)
                PrintTree(node->brother, decl);
        }
    }

public:

    Tree() : root(nullptr) {};

    void Add(pair<string, int> son)
    {
        root = Insert(root, son);
    }

    void Is_rec()
    {
        Is_recursive(root);
    }

    void Rec_(vector<Tree>& decl, vector<TreeNode*>& all_call)
    {
        rec(root, decl, all_call);
    }

    void Print(vector<Tree>& decl)
    {
        PrintTree(root, decl);
    }

    TreeNode* getter()
    {
        return root;
    }

    void reset()
    {
        root = nullptr;
    }
};

unsigned int is_in_vec(vector<Tree>& func_vec, string str)
{
    for (unsigned int i = 0; i < func_vec.size(); i++)
    {
        if (func_vec[i].getter()->key.first == str)
            return i;
    }

    return func_vec.size();
}

void parser_fromfile(ifstream& inf, vector<Tree>& func_vec, vector<pair<string, int>>& not_found, vector<pair<string, int>>& main_vec)
{
    char c;
    string str, name;
    int cnt, from, to;
    Tree tree;
    unsigned int i, j = 0;
    bool decl = 0, main = 0;
    static int brack = 0, decl_brack = 0;

    if (!inf.is_open())
        error(1);

    while (!inf.eof())
    {
        getline(inf, str);

        if (str.find("{") != string::npos && str.find("}") != string::npos)
            continue;

        if (str.find("{") != string::npos && str.find("\"{") == string::npos && str.find("\'{") == string::npos)
            brack++;

        if (str.find("}") != string::npos && str.find("\"}") == string::npos && str.find("\'}") == string::npos)
        {
            brack--;
            if (decl && (brack - decl_brack + 1) == 0)
            {
                func_vec.push_back(tree);
                name.clear();
                decl = 0;
                tree.reset();
                continue;
            }
        }

        if (str.find("main(") != string::npos)
        {
            main = 1;
            for (auto tree : func_vec)
                tree.Is_rec();
            continue;
        }

        if (str.find("#include") != string::npos)//�������� �� ��������
        {
            from = str.find("\"");
            if (from++ != string::npos && str.find("\"#include") == string::npos)
            {
                to = str.find("\"", from);
                string include_file(str, from, to - from);
                ifstream fIn(include_file);
                parser_fromfile(fIn, func_vec, not_found, main_vec);
            }
            continue;
        }
        else if (str.find("(") == string::npos)
        {
            continue;
        }
        else if (str.find("if (") != string::npos || str.find("for (") != string::npos || str.find("while (") != string::npos || str.find("do (") != string::npos)
        {
            continue;
        }
        else if (str.find("(") != string::npos && str.find("(", str.find("(") + 1) != string::npos)
        {
            cout << str << "\n";
            error(3);
        }

        for (i = 0; i < str.size(); i++)
        {
            c = str.at(i);

            if (c == '\t')
            {
                continue;
            }
            else if (Letters.find(tolower(c)) != -1 || c == '_' || c == '~')
            {
                name += c;
            }
            else if (c == '(')
            {
                cnt = 0;
                j = i;

                do
                {
                    j = str.find(",", j + 1);
                    cnt++;
                } while (j++ != string::npos);

                if (str.find(";") != string::npos)
                {
                    if (main)
                    {
                        j = is_in_vec(func_vec, name);
                        if (j != func_vec.size() && func_vec[j].getter()->key.second != cnt)
                        {
                            cout << name << "\n";
                            error(2);
                        }
                        if (j != func_vec.size())
                        {
                            main_vec.push_back(make_pair(name, cnt));
                        }
                        else
                        {
                            not_found.push_back(make_pair(name, cnt));
                        }
                    }
                    else
                    {
                        j = is_in_vec(func_vec, name);
                        if (j != func_vec.size() && func_vec[j].getter()->key.second != cnt)
                        {
                            cout << name << "\n";
                            error(2);
                        }
                        if (j != func_vec.size() || (tree.getter()->key == make_pair(name, cnt)))
                        {
                            tree.Add(make_pair(name, cnt));
                        }
                        else
                        {
                            not_found.push_back(make_pair(name, cnt));
                        }
                    }
                    name.clear();
                    break;
                }

                if (!name.empty())
                {
                    tree.Add(make_pair(name, cnt));
                    decl = 1;
                    decl_brack = brack + 1;

                    if (str.find("{") != string::npos)
                    {
                        decl_brack = brack;
                    }
                }

                name.clear();
                break;
            }
            else
            {
                name.clear();
            }
        }
    }
}

void print_func_tree(vector<Tree>& decl, vector<pair<string, int>>& not_found, vector<pair<string, int>>& main)
{
    cout << "Function tree:" << "\n";
    cout << "main" << "\n";

    for (auto func : main)
    {
        for (size_t i = 0; i < decl.size(); i++)
            if (decl[i].getter()->key.first == func.first)
            {
                decl[i].Print(decl);
            }
    }
}

void findallrecursive(vector<Tree> decl, vector<pair<string, int>> main)
{
    vector<TreeNode*> all_call;
    for (auto func : main)
    {
        for (size_t i = 0; i < decl.size(); i++)
            if (decl[i].getter()->key.first == func.first)
            {
                decl[i].Rec_(decl, all_call);
            }
    }

    for (size_t i = 0; i < all_call.size(); i++)
    {
        for (size_t j = 0; j < all_call.size(); j++)
            if (j != i && all_call[i]->key.first == all_call[i]->key.first)
            {
                all_call[i]->recursive = 1;
                all_call[j]->recursive = 1;
            }
    }
}


void func_tree(string file_name)
{
    vector<Tree> func_vec;
    vector<pair<string, int>> not_found;
    vector<pair<string, int>> main;
    int f = 0;

    ifstream inf(file_name);
    parser_fromfile(inf, func_vec, not_found, main);
    findallrecursive(func_vec, main);
    print_func_tree(func_vec, not_found, main);

    for (size_t i = 0; i < not_found.size(); i++)
    {
        while ((i + 1 < not_found.size()) && find(not_found.begin() + i + 1, not_found.end(), not_found[i]) != not_found.end())
            not_found.erase(find(not_found.begin() + i + 1, not_found.end(), not_found[i]));
    }

    cout << "\nNot declared functions:\n";
    for (auto i : not_found)
        cout << i.first << "\n";
}                         