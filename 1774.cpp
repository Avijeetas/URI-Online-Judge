/*
Approach:
1. Every node is the leaf of its own when they are connected to itself . We will set the node as its leaf node. 

2. After taking input ,as we are looking for total minimum cost, so we will sort according to weight in ascending order.

3. It is an important step, as we need to calculate total minimum cost. here each time we will merge two subsets which are not connected to each other,and if they are not connected we will add them,and add the cost. 

4.Besides ,it can't form a cycle ,so we will check that step 3 will run only n-1 or number of edges-1 times.

#Before connecting:
            1

        2

        5

        7
#After connecting 2,5,6,7:

            1

         2
         |   
         5
        / \
       6   7

*/


#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
const long long MAX = 1e4 + 5;
#define pr pair <long long, pair<long long, long long> >

long long id[MAX], nodes, edges;
pair <long long, pair<long long, long long> > p[MAX];

void initialize()
{
    for(long long i = 0;i < MAX;++i)
        id[i] = i; //setting leaf
}

long long root(long long x)
{
    while(id[x] != x)       //while leaf [ x ] ! = x  
    {
        id[x] = id[id[x]];  //id[x] =leaf of x;   

        x = id[x];          //storing the value of leaf node of x to x
    }
    return x; //returning the leaf 
}

void union1(long long x, long long y)
{
    long long p = root(x);
    long long q = root(y);
     id[p] = id[q]; //storing the leaf node of q to 
 //   cout<<id[p]<<" "<<id[q]<<endl;
//    puts("");
 //   cout<<endl;
}

long long kruskal(pair<long long, pair<long long, long long> > p[])
{
    long long x, y;
    long long cost, co=0,minimumCost = 0;
    for(long long i = 0;i < edges;++i)
    {
        
        // Selecting edges one by one in increasing order from the beginning
        x = p[i].second.first; 
        y = p[i].second.second;
        cost = p[i].first;

        // Check if the selected edge is creating a cycle or not
        if(root(x) != root(y))  //find the parent of x & y 
        {

            co++; //controlling to not forming cycle
        
            minimumCost += cost;  //adding the cost 
        
            union1(x, y); //if root/parent is not same then add them
        
            if(co==nodes-1)
            break;
        }    
    }
    return minimumCost; //returning the minimum cost 
}

int main()
{
    long long x, y;
    long long weight, cost, minimumCost;
    
    
    while(cin >> nodes>>edges && nodes && edges) {
        initialize(); //step 1
        
        for(long long i = 0;i < edges;++i)
        {
            cin >> x >> y >> weight;
            p[i] = make_pair(weight, make_pair(x, y));
        }
    
        // Sort the edges in the ascending order
        sort(p,p+edges);
        minimumCost = kruskal(p);
        cout << minimumCost << endl;}
    return 0;
}