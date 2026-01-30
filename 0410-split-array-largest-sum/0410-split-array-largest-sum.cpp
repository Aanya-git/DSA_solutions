class Solution {
public:

    bool isValid(vector<int>& nums,int n,int m,int allowedPages){
        int stu = 1; 
        int pages =0;
        for(int i=0; i<n;i++){
            if(nums[i]> allowedPages){
                return false;
            }
            if(pages + nums[i]<= allowedPages){
                pages += nums[i];
            }
            else{
                stu++;
                pages= nums[i];
            }
        }
        if(stu > m){
            return false;
        }
        else{
            return true;
        }

    }
    int splitArray(vector<int>& nums, int k) {
        int st = 0;
        int end = 0;
        int n = nums.size();
        for(int count = 0; count <n; count++){
            end += nums[count];
        }
        int ans = -1;
        while(st<= end){
            int mid = st + (end-st)/2;
            if(isValid(nums, n, k,mid)){
                ans = mid ;
                end = mid - 1;
            }
            else{
                st = mid + 1;
            }
        }
        return ans;
    }
};