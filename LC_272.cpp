void dfs(TreeNode* root, priority_queue<pair<double, int>>& pq, double target, int k) {
    if(!root) return;

    pq.push(make_pair(fabs(target - double(root->val)), root->val));

    if(pq.size() > k)
        pq.pop();

    dfs(root->left, pq, target, k);
    dfs(root->right, pq, target, k);
}

vector<int> closestKValues(TreeNode* root, double target, int k) {
    priority_queue<pair<double, int>> pq;
    vector<int> result;

    dfs(root, pq, target, k);
    while(!pq.empty()) {
        result.push_back(pq.top().second);
        pq.pop();
    }

    return result;
}


public class Solution {
    public List<Integer> closestKValues(TreeNode root, double target, int k) {
        LinkedList<Integer> res = new LinkedList<>();
        collect(root, target, k, res);
        return res;
    }

    public void collect(TreeNode root, double target, int k, LinkedList<Integer> res) {
        if (root == null) return;
        collect(root.left, target, k, res);

        if (res.size() == k) {
            //if size k, add curent and remove head if it's optimal, otherwise return
            if (Math.abs(target - root.val) < Math.abs(target - res.peekFirst()))
                res.removeFirst();
            else return;
        }
        res.add(root.val);
        collect(root.right, target, k, res);
    }
}
