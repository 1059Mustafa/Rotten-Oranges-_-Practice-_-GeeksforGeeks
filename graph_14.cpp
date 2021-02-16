class Solution {
public:

    void push_neighbour(pair<int,int>p,vector<vector<int>>&g, queue<pair<int,int>>&q,int r,int c)
    {
        int X=p.first;
        int Y=p.second;
        int x[]={-1,1,0,0};
        int y[]={0,0,-1,1};
        for(int i=0;i<4;i++)
        {
            if(X+x[i]<0||X+x[i]>=r||Y+y[i]<0||Y+y[i]>=c||g[X+x[i]][Y+y[i]]!=1)
            {
                continue;
            }
            q.push({X+x[i],Y+y[i]});
            g[X+x[i]][Y+y[i]]==2;
            
        }
    }

    int orangesRotting(vector<vector<int>>& grid) 
    {
       int r=grid.size();
       int c=grid[0].size();
       int time=0;
       queue<pair<int,int>>q;
       for(int i=0;i<r;i++)
       {
           for(int j=0;j<c;j++)
           {
               if(grid[i][j]==2)
               {
                   q.push({i,j});
                  //grid[i][j]=3;
               }
           }
       }
       int count=q.size();
       while(count>0)
       {
           for(int i=0;i<count;i++)
           {
               pair<int,int>p=q.front();
               q.pop();
               push_neighbour(p,grid,q,r,c);
           }
           count=q.size();
           if(count>0)
           {
               time++;
           }
       }
       for(int i=0;i<r;i++)
       {
           for(int j=0;j<c;j++)
           {
               if(grid[i][j]==1)
               {
                   return -1;
               }
           }
       }
       return time;
       
    }
};
