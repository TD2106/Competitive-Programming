#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <functional>
using namespace std;
#define MAX 100
int V;
bool visited[MAX];
int path[MAX];
list<int> graph[MAX];
map<string, int> citys;
int b[MAX];
int m;
void BFS(int s)
{
    for(int i = 0; i < V; i++)
    {
		visited[i] = false;
		path[i] = -1;
	}
    queue<int> q;
 
    visited[s] = true;
    q.push(s);
 
    list<int>::iterator i;
 
    while(!q.empty())
    {
        s = q.front();
        q.pop();
        for(i=graph[s].begin(); i!=graph[s].end(); i++)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                q.push(*i);
				path[*i] = s;
            }
        }
    }
}

bool CheckCity(string c)
{
	map<string, int>::iterator it;
	it = citys.find(c);
	if(it != citys.end())
		return true;
	return false;
}

void Print_Path(int s, int f)
{
	m = 0;
	while(1)
	{
		b[m++] = f;
		f = path[f];
		if(f==s)
		{
			b[m++] = s;
			break;
		}
	}

}

int main()
{
    //freopen("INPUT.INP", "rt", stdin);
	//freopen("OUTPUT.OUT", "wt", stdout);
	int E, Q, T, count = 0;
	string u, v;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &E);
		scanf("%d", &Q);
		map<int, char> temp;
		temp.clear();
		citys.clear();
		for(int i=0; i<E; i++)
		{
			cin>>u>>v;
			if(CheckCity(u)==false)
			{
				citys[u] = count;
				temp[count] = u[0];
				count++;
			}
			if(CheckCity(v)==false)
			{
				citys[v] = count;
				temp[count] = v[0];
				count++;
			}
			graph[citys[u]].push_back(citys[v]);
			graph[citys[v]].push_back(citys[u]);
		}
		V = count;
		for(int i=0; i<Q; i++)
		{
			memset (path, -1, sizeof(path));
			memset (b, 0, sizeof(b));
			cin>>u>>v;
			BFS(citys[u]);
			Print_Path(citys[u], citys[v]);
			for(int j=m-1; j>=0; j--)
			{
				cout<<temp[b[j]];
			}
			cout<<endl;
		}
		if(T!=0)
			cout<<endl;
	}
    return 0;
}
