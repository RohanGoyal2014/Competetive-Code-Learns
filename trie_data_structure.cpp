#include<iostream>
#define ALPHABET_SIZE 26
using namespace std;
typedef long long ll;

struct Node
{
	Node* children[ALPHABET_SIZE];
	bool isEndOfWord;
};

Node* newNode()
{
	Node* node = new Node;
	node->isEndOfWord = false;
	for(int i=0;i<ALPHABET_SIZE;i++)
	{
		node->children[i] = NULL;
	}
	return node;
}

class Trie
{
public:
	Node* root;
	Trie()
	{
		root = newNode();
	}
	void insert(string s);
	void insert_util(Node* root,string s,int pos);
	bool search(string s);
	bool search_util(Node* root,string s,int pos);
};

void Trie::insert(string s)
{
	insert_util(root,s,0);
}

void Trie::insert_util(Node* root,string s,int pos)
{
	if(root->children[s[pos]-'a'] == NULL)
	{
		root->children[s[pos]-'a'] = newNode();
	}
	if(pos == s.length()-1)
	{
		root->children[s[pos]-'a']->isEndOfWord = true;
	}
	else
	{
		insert_util(root->children[s[pos]-'a'],s,pos+1);
	}
}

bool Trie::search(string s)
{
	return search_util(root,s,0);
}

bool Trie::search_util(Node* root,string s,int pos)
{
	if(root->children[s[pos]-'a'] == NULL)
		return false;
	if(pos == s.length()-1)
	{
		if(root->children[s[pos]-'a']->isEndOfWord)
			return true;
		else
			return false;
	}
	return	search_util(root->children[s[pos]-'a'],s,pos+1);
}

int main()
{
	string s = "vivek";
	Trie trie;
	trie.insert(s);
	cout<<trie.search(s);
	return 0;
}
