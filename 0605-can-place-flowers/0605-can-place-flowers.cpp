class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        flowerbed.push_back(0);

        int places = 0;

        if (flowerbed[0] == 0 and flowerbed[1] == 0) {
            flowerbed[0] = 1;
            places++;
        }

        for (int i = 1; i < flowerbed.size()-1; i++) {
            if (flowerbed[i] == 0 and flowerbed[i-1] == 0 and flowerbed[i+1] == 0) {
                flowerbed[i] = 1;
                places++;
            }
        }

        return n <= places;
    }
};