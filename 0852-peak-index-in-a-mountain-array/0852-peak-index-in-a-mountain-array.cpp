class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int st = 0;
        int end = n-1;
        //int arr[p] > arr[p-1] && arr[p+1]<arr[p];

        
        while(st< end){
            int mid = st + (end -st)/2;
            if(arr[mid]<arr[mid+1]){
                st = mid + 1;
            }
            else{
                end  = mid;
            }
        }
     return st;   
    }
};