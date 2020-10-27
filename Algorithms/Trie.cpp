#include<bits/stdc++.h>
using namespace std;
	#define author          "Sihare0riginals"
	#define ss       		string 
	#define lli      		long long int
	#define ld       		long double
	#define f        		first
	#define s        		second
	#define all(v)   		v.begin(),v.end()
	#define I(a,i)			memset(a,i,sizeof(a));
	#define pb       		push_back
	#define mp       		make_pair
	#define L(i,start,end)  for(lli i=start;i<=end;i++)
	#define R(i,start,end)  for(lli i=start;i>=end;i--)
	#define ip(n) 			cin>>n;lli ip[n+1];L(i,1,n)cin>>ip[i];
const lli LINF = 1e18,mod=1e9+7;
void Bl0ck_M0mb0();
struct node{
	char c;
	bool isTerm=false;
	map<char,node*> hash;
	node(char ch){
		c=ch;
	}
};
void addWord(struct node *root,ss word)
{
	lli sz=word.size();
	L(i,0,sz-1)
	{
		if(!root->hash.count(word[i]))
		{
			struct node* child=new node(word[i]);
			root->hash[word[i]]=child;
		}
		root=root->hash[word[i]];
	}
	root->isTerm=true;
}
struct node* constructTrie(vector<ss> dict){
	struct node *root=new node('\0');
	lli sz=dict.size();
	L(i,0,sz-1)
		addWord(root,dict[i]);
	return root;
}
bool search(ss word,struct node *root)
{
	lli sz=word.size();
	L(i,0,sz-1)
	{
		if(root->hash.count(word[i]))
			root=root->hash[word[i]];
		else
			return false;
	}
	if(root->isTerm)
		return true;
	return false;
}
struct node* remove(struct node* root,ss word,lli depth)
{
	if(!root)
		return NULL;
	if(depth==word.size())	//last character
	{
		root->isTerm=false;
		if(!root->hash.size())
		{
			delete(root);
			root=NULL;
		}
		return root;
	}
	root=remove(root,word,depth+1);
	if(root->hash.size()==0&&root->isTerm==false)
	{
		delete(root);
		root=NULL;
	}
	return root;
}
signed main()
{
	lli t=1;
	//cin>>t;
	while(t--){
		lli n;
		cin>>n;
		vector<ss> ip;
		L(i,1,n)
		{
			ss le;
			cin>>le;
			ip.pb(le);
		}
		struct node* root=constructTrie(ip);
		lli k;
		cin>>k;
		L(i,1,k)
		{
			ss le;
			cin>>le;
			if(search(le,root))
				cout<<le+" Found"<<endl;
			else
				cout<<le+" Not Found"<<endl;
		}
		remove(root->hash['s'],"s",1);
		cout<<search("s",root)<<endl;
	}
	return 0;
}
