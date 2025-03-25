#include <bits/stdc++.h>
using namespace std;

class node 
{
    public :
    int data ; 
    node * left ;
    node * right ;

    node(int d){
        data = d ;
        left =NULL;
        right= NULL ;
    }
};

class cmp{

    public: 
    bool operator ()(node * a , node* b)
    {
     return a->data > b->data ;
    }
} ;
class Solution {
    public:
    void traversal(node* root ,vector<string>ans ,string s)
    {
        if(root->left==NULL && root->right==NULL)
        {
            ans.push_back(s) ;
            return;
        }
         traversal(root->left ,ans , s+'0');
         traversal(root->right ,ans,s+'1');
    }

    vector<string> huffmanCodes(string S ,vector<int> f ,int N){
        priority_queue<node*, vector<node*> , cmp>pq;

        for(int i = 0 ; i<f.size();i++)
        {
            node* temp = new node(f[i]);
            pq.push(temp);
            
        }
        while(pq.size()>1)
        {
            node* first = pq.top();
            pq.pop();
            node* second = pq.top();
            pq.pop();
            node* merge =new node(first->data + second->data) ;
            merge->left =first ;
            merge->right = second ;
            pq.push(merge);
          
        }
        string s ="" ;

        vector<string>ans ;

        node* root =pq.top();

        traversal(root , ans ,s);
        return ans ;      
    }
};



int main()
{
    
    

    return 0;
}
