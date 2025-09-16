/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* helper(vector<vector<int>>& grid, int row, int col, int size) {
        bool allSame = true;
        int firstVal = grid[row][col];
        for (int i = row; i < row + size; i++) {
            for (int j = col; j < col + size; j++) {
                if (grid[i][j] != firstVal) {
                    allSame = false;
                    break;
                }
            }
            if (!allSame) break;
        }

        if (allSame) {
            // Leaf node
            return new Node(firstVal == 1, true);
        }

        Node* node = new Node(true, false); // val doesn't matter for internal nodes
        int half = size / 2;
        node->topLeft = helper(grid, row, col, half);
        node->topRight = helper(grid, row, col + half, half);
        node->bottomLeft = helper(grid, row + half, col, half);
        node->bottomRight = helper(grid, row + half, col + half, half);
        return node;

        return node;
    }

    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();

        return helper(grid, 0, 0, n);
    }
};