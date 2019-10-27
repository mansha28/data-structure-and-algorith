 #include<iostream>
 #include<vector>
 using namespace std;
 int count;
 bool is_valid(int x,int y,int key,vector<vector<int>>&input,vector<vector<int>>&visited,int m,int n)
 {
     if(x<m&&y<n&&x>=0&&y>=0)
     {
         if(visited[x][y]==false && input[x][y]==key)
         return true;
         else
         {
             return false;
         }
         
     }
     else
     return false;
 }
 void BFS(int x,int y, int i,int j,vector<vector<int>>&input,vector<vector<int>>&visited,vector<vector<int>>&g_visited,int m,int n)
 {
     
     visited[i][j]=1;
     g_visited[i][j]=1;
     count++;
     if(x!=y)
     return;
     int x_move[]={0,0,1,-1};
     int y_move[]={1,-1,0,0};
     for(int u=0;u<4;u++)
     {
         if(is_valid(i+y_move[u],j+x_move[u],x,input,visited,m,n))
         BFS(x,y,i+y_move[u],j+x_move[u],input,visited,g_visited,m,n);
     }
     void reset_visited(vector<vector<int>>&visited,int m,int n)
     {
         for(int i=0;i<m;i++)
         {
             for(int j;j<n;j++)
             visited[i][j]=0;
         }
     }
 
 }
 void reset_result(int key,vector<vector<int>>&input,vector<vector<int>>&visited,vector<vector<int>>&result,int m,int n)
 {
     for(int i=0;i<m;i++)
     {
         for(intj+0;j<n;j++)
         {
             if(visited[i][j] && input[i][j]==key)
             result[i][j]=visited[i][j];
             else
             {
                 result[i][j]=0;
             }
             
         }
     }
 }
 void print_result(int res) 
{ 
    cout << "The largest connected "
         << "component of the grid is :" << res << "\n"; 
  
    // prints the largest component 
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < m; j++) { 
            if (result[i][j]) 
                cout << result[i][j] << " "; 
            else
                cout << ". "; 
        } 
        cout << "\n"; 
    } 
} 
  
// function to calculate the largest connected  
// component 
void computeLargestConnectedGrid(vector<vector<int>> &input,vector<vector<int>> &visited,vector<vector<int>> &g_visited,vector<vector<int>> &result,int m, int n) 
{ 
    int current_max = INT_MIN; 
  
    for (int i = 0; i < m; i++) 
    { 
        for (int j = 0; j < n; j++) 
        { 
            if(g_visited[i][j]==0){ 
            count = 0; 
  
            // checking cell to the right 
            if (j < m) 
                BFS(input[i][j], input[i][j + 1], i, j, input,visited,g_visited,m,n); 
  
            // updating result 
            if (count >= current_max) { 
                current_max = count; 
                reset_result(input[i][j], input,visited,result,m,n); 
            } 
            reset_visited(visited,m,n); 
            count = 0; 
  
            // checking cell downwards 
            if (i + 1 < n) 
                BFS(input[i][j], input[i + 1][j], i, j, input,visited,g_visited,m,n); 
  
            // updating result 
            if (count >= current_max) { 
                current_max = count; 
                reset_result(input[i][j], input,visited,result,m,n); 
            } 
        } 
    } 
    print_result(current_max); 
} 
// Drivers Code 
int main() 
{ 
    int m,n,k;
    cin>>m>>n;
    cin>>k;
    int x,y;

    vector<vector<int>> input(n);
    
    int temp;
    for(int i=0;i<m;i++)
    {    for(int j=0;j<n;j++)
        {
            input[i].push_back(0);
        }
    }

    for(int i=0;i<k;i++)
    {
        cin>>x>>y;
        char input[x][y]=1;
    }

    vector<vector<int>> vis(n);
    vector<vector<int>> g_vis(n);
    vector<vector<int>> res(n);
    
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            vis[i].push_back(0);
            g_vis[i].push_back(0);
            res[i].push_back(0);
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j;j<n;j++)
        {
            if(!input[i][j]){
                g_vis[i][j]=1;
            }
        }
    }
    // function to compute the largest 
    // connected component in the grid 
    computeLargestConnectedGrid(input,vis,g_vis,res,m,n); 
    return 0; 
} 
