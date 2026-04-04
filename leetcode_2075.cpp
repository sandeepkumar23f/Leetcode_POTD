class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if (rows == 0) return "";
        
        int n = encodedText.size();
        int cols = n / rows;
        
        vector<vector<char>> grid(rows, vector<char>(cols));
        
        // Fill the grid row-wise
        int idx = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                grid[i][j] = encodedText[idx++];
            }
        }
        
        string result = "";
        
        // Traverse diagonals
        for (int startCol = 0; startCol < cols; startCol++) {
            int i = 0, j = startCol;
            while (i < rows && j < cols) {
                result += grid[i][j];
                i++;
                j++;
            }
        }
        
        // Remove trailing spaces
        while (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }
        
        return result;
    }
};
