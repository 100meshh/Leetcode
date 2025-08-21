class Solution {
public:
 int r,c;
 int row[4]={-1,1,0,0};
 int col[4]={0,0,-1,1};
 bool valid(int i,int j){
    return i>=0 && i<r && j>=0 && j<c;
 }


    void solve(vector<vector<char>>& board) {


        r=board.size();
        c=board[0].size();

        queue<pair<int,int>>q;

        //check first row
        for(int i=0;i<c;i++){
            if(board[0][i]=='O'){
                q.push(make_pair(0,i));
                board[0][i]='T';
            }
        }
        //check first col
        for(int i=0;i<r;i++){
            if(board[i][0]=='O'){
                q.push(make_pair(i,0));
                board[i][0]='T';
            }
        }
        //check last row
        for(int i=0;i<c;i++){
            if(board[r-1][i]=='O'){
                q.push(make_pair(r-1,i));
                board[r-1][i]='T';
            }
        }
        //check last col
        for(int i=0;i<r;i++){
            if(board[i][c-1]=='O'){
                q.push(make_pair(i,c-1));
                board[i][c-1]='T';
            }
        }
        while(!q.empty()){
            int new_i=q.front().first;
            int new_j=q.front().second;
            q.pop();
            //check valid and changable
            for(int k=0;k<4;k++){
                if(valid(new_i+row[k],new_j+col[k]) && board[new_i+row[k]][new_j+col[k]]=='O'){
                    board[new_i+row[k]][new_j+col[k]]='T';
                    q.push(make_pair(new_i+row[k],new_j+col[k]));
                }

            }
        }
        //replace all t with 0 and all 0 with x
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(board[i][j]=='O') board[i][j]='X';
                else if(board[i][j]=='T')board[i][j]='O';
            }
        }
    }
};