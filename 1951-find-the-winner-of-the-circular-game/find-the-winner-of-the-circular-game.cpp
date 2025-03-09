class Solution {
public:
int winner(vector<bool>&person,int n,int index,int person_left,int k)
    {
        //base case
        if(person_left==1)
        {
            for(int i=0;i<n;i++)
            {
                if(person[i]==0)
                return i;
            }
        }
        int kill=(k-1)%person_left;
        while(kill--)
        {
            index=(index+1)%n;
            //jab tk 1 hai tnb tk index ko aage bdao
            while(person[index]==1)
            {
                index=(index+1)%n;
            }
        }
            //0 wale ko 1 bnao
            person[index]=1;
            // next 0 ko find kro
            while(person[index]==1)
            {
                index=(index+1)%n;
            }
        return winner(person,n,index,person_left-1,k);
        

    }
    int findTheWinner(int n, int k) {
        vector<bool>person(n,0);
        return winner(person,n,0,n,k)+1;
    }
};