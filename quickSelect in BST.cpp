struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    void recursion(TreeNode *root, vector< int > &elements){
        if(root != nullptr) {
            elements.push_back(root->val);
            recursion(root->left, elements);
            recursion(root->right, elements);
        }
    }

    int partition(vector<int> &arr, int l, int r) 
{ 
    int x = arr[r], i = l; 
    for (int j = l; j <= r - 1; j++) { 
        if (arr[j] <= x) { 
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++; 
        } 
    } 
    int tmp = arr[i];
    arr[i] = arr[r];
    arr[r] = tmp;
    return i; 
} 

    int kthSmallestInVector(vector<int> &arr, int l, int r, int k) { 
    
    if (k > 0 && k <= r - l + 1) {  
        int index = partition(arr, l, r); 
  
        if (index - l == k - 1) 
            return arr[index]; 
  
        if (index - l > k - 1)  
            return kthSmallestInVector(arr, l, index - 1, k); 
  
        return kthSmallestInVector(arr, index + 1, r,  k - index + l - 1); 
    } 
    return INT_MAX; 
} 
  
    
    int kthSmallest(TreeNode* root, int k) {
        vector< int > elements;
        recursion(root, elements);

        return kthSmallestInVector(elements, 0, elements.size() - 1, k);
    }
};
