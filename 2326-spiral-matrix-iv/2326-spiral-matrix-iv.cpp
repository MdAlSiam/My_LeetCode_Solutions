/*
class Solution {
    int nRows;
    int nCols;

    vector<vector<int>> matrix;

    void init() {
        for (int i = 0; i < nRows; i++) {
            vector<int> temp;
            for (int j = 0; j < nCols; j++) {
                temp.push_back(-1);
            }
            matrix.push_back(temp);
        }
    }

    bool isValid(int r, int c) {
        return r >= 0 and r < nRows and c >= 0 and c < nCols and matrix[r][c] == -1;
    }

    void go(int ro, int col, ListNode* curr, string direction) {
        matrix[ro][col] = curr->val;

        if (curr->next == nullptr) return;

        if (direction == "right") {
            if (isValid(ro, col+1)) {
                go(ro, col+1, curr->next, direction);
            }
            else {
                direction = "down";
            }
        }
        
        if (direction == "down") {
            if (isValid(ro+1, col)) {
                go(ro+1, col, curr->next, direction);
            }
            else {
                direction = "left";
            }
        }
 
        if (direction == "left") {
            if (isValid(ro, col-1)) {
                go(ro, col-1, curr->next, direction);
            }
            else {
                direction = "up";
            }
        }

        if (direction == "up") {
            if (isValid(ro-1, col)) {
                go(ro-1, col, curr->next, direction);
            }
            else {
                direction = "right";
            }
        }

        if (direction == "right") {
            if (isValid(ro, col+1)) {
                go(ro, col+1, curr->next, direction);
            }
            else {
                direction = "down";
            }
        }
    }
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        nRows = m;
        nCols = n;
        init();

        go(0, 0, head, "right");
        
        return matrix;
    }
};
*/

// [[3,0,2,6,8],[5,0,-1,-1,1],[5,2,4,9,7]]


class Solution {
    int nRows;
    int nCols;

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    vector<vector<int>> matrix;

    void init() {
        for (int i = 0; i < nRows; i++) {
            vector<int> temp;
            for (int j = 0; j < nCols; j++) {
                temp.push_back(-1);
            }
            matrix.push_back(temp);
        }
    }

    bool isValid(int r, int c) {
        return r >= 0 and r < nRows and c >= 0 and c < nCols and matrix[r][c] == -1;
    }
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        nRows = m;
        nCols = n;

        init();

        ListNode* curr = head;

        int x = 0;
        int y = 0;
        int di = 0;
        
        for (int i = 0; i < m*n; i++) {
            if (curr == NULL) break;
            matrix[x][y] = curr->val;
            curr = curr->next;

            if (isValid(x+dx[di], y+dy[di])) {
                x = x+dx[di];
                y = y+dy[di];
            }
            else {
                di = (di+1)%4;
                x = x+dx[di];
                y = y+dy[di];
            }
        }

        return matrix;
    }
};