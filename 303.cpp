// LeetCode 303: Range Sum Query Immutable

class NumArray {
public:
    int* tree;
    int size;

    NumArray(vector<int>& nums) {
        // build
        size = nums.size();
        init_tree(size);

        build_tree(nums, 1, 0, nums.size()-1);
    }

    void build_tree(vector<int>& nums, int node, int b, int e) {
        if (b == e) {
            tree[node] = nums[b];
            return;
        }

        int mid = (b+e)/2;
        int left = 2*node;
        int right = 2*node+1;

        build_tree(nums, left, b, mid);
        build_tree(nums, right, mid+1, e);

        tree[node] = tree[left]+tree[right];
    }

    void init_tree(int size) {
        tree = new int[4*size];
    }
    
    int sumRange(int left, int right) {
        // query
        int ans = query(1, 0, size-1, left, right);

        return ans;
    }

    int query(int node, int b, int e, int i, int j) {
        if (i > e or j < b) return 0;

        if (i <= b and e <= j) return tree[node];

        int mid = (b+e)/2;
        int left = 2*node;
        int right = 2*node+1;

        int ret1 = query(left, b, mid, i, j);
        int ret2 = query(right, mid+1, e, i, j);

        return ret1+ret2;
    }
};