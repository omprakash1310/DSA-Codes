class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        int cols = n / rows;
        string res;
        for (int i = 0; i < cols; i++) {
            for (int r = 0, c = i; r < rows && c < cols; r++, c++) {
                res += encodedText[r * cols + c];
            }
        }
        while (!res.empty() && res.back() == ' ') res.pop_back();
        return res;
    }
};