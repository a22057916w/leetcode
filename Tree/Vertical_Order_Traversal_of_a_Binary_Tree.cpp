/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Coordinate {
public:
  int x, y;
  int val;

  Coordinate(int x, int y, int val): x(x), y(y), val(val) {}

  // sorted the coordinates according to the requirements of the problem
  bool operator <(const Coordinate &c) const {
    if(x == c.x) {
      if(y == c.y)
        return val < c.val;
      else
        return y > c.y;
    }
    else
      return x < c.x;
  }
};

class Solution {
public:
  vector<Coordinate> coord;   // array to store coordinates

  vector<vector<int>> verticalTraversal(TreeNode* root) {

    // produce the coordinates array by DFS
    mapping(root, 0, 0);

    // sorted the coordinates according to the requirements of the problem
    sort(coord.begin(), coord.end());

    vector<vector<int>> result;
    int last_x = -1E9;

    // group a 1d sorted array to an 2d array by x
		for (int i = 0; i < coord.size(); i++) {
			if (coord[i].x > last_x) {
				result.push_back({});
				last_x = coord[i].x;
			}
			result.back().push_back(coord[i].val);
		}

    // return the answer
    return result;
  }

  void mapping(TreeNode *curr, int x, int y) {
    if(curr) {

      // transform a node into a coordinate, then put it into array
      Coordinate c(x, y, curr->val);
      coord.push_back(c);

      // keep traversing
      mapping(curr->left, x - 1, y - 1);
      mapping(curr->right, x + 1, y - 1);
    }
  }

};
