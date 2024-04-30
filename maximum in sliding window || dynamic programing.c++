vector<int> maxSlidingWindow(int k, vector<int> &nums) {
    int n = nums.size();
    vector<int> ans(n - k + 1);
    if(n == 1) {
        ans[0] = nums[0];
        return ans;
    }
    if(n ==0)
        return ans;
    int i = 1, j = k, max = nums[0], secondToMax = nums[1], indexOfMax = 0, indexOfSecondToMax = 1;

    for (int p = 0; p < k; p++)
        if (nums[p] >= max) {
            max = nums[p];
            indexOfMax = p;
        }

    for(int p = 0; p < k; p++){
        if(nums[p] >= secondToMax) {
            if (p != indexOfMax || nums[p] < max) {
                secondToMax = nums[p];
                indexOfSecondToMax = p;
            }
        }
    }

    ans[0] = max;
    while(j < n){

        if(indexOfMax < j){
            max = secondToMax;
            indexOfMax = indexOfSecondToMax;
        }

        if(indexOfSecondToMax < j){
            secondToMax = nums[j];
            indexOfSecondToMax = j;
        }


        if(nums[j] >= max){
            max = nums[j];
            indexOfMax = j;
        }

        else if(nums[j] >= secondToMax){
            secondToMax = nums[j];
            indexOfSecondToMax = j;
        }

        ans[i] = max;
        j++;
        i++;
    }

    return ans;
}
