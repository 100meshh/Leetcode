class Solution {
public:

    void merge(vector<int>&arr,int start,int mid,int end)
    {
        vector<int>temp(end-start+1);
        int first=start;
        int second=mid+1;
        int index=0;
        while(first<=mid && second<=end)
        {
            if(arr[first]<=arr[second])
            {
                temp[index]=arr[first];
                index++;
                first++;
            }
            else{
                temp[index]=arr[second];
                index++;
                second++;
            }
        }
        // left array ka elemnt bache hai to push them in the temp
        while(first<=mid)
        {
            temp[index]=arr[first];
            index++;
            first++;
        }
        //  right array ka element bache hai to push them in the temp
        while(second<=end)
        {
            temp[index]=arr[second];
            index++;
            second++;
        }
        // temp wale ko array me copy kro
        index=0;
        while(start<=end)
        {
            arr[start]=temp[index];
            start++;
            index++;
        }
    }
    void mergesort(vector<int>&arr,int start, int end)
    {
        if(start==end)
        return;
        int mid=start+(end-start)/2;
        // left me todo
        mergesort(arr,start,mid);
        // right me todo
        mergesort(arr,mid+1,end);
        // ascending order me sort kro
        merge(arr,start,mid,end);
    }

    vector<int> sortArray(vector<int>& nums) {
        // merge sort
        mergesort(nums,0,nums.size()-1);
        return nums;
        
    }
};