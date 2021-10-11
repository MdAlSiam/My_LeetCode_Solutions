class Solution {
public:
    int rangeBitwiseAnd(long long int left, long long int right) {
        left--;
        long long int zerosInBitTillLeft[32];
        long long int zerosInBitTillRight[32];

        long long int segmentSize = 2;
        for (long long int i = 0; i < 32; i++) {
            long long int howManySegments = (left+1)/segmentSize;
            long long int remaining = (left+1)%segmentSize;
            zerosInBitTillLeft[i] = howManySegments*(segmentSize/2); 
            zerosInBitTillLeft[i] += min(segmentSize/2, remaining);

            segmentSize *= 2;
        }

        segmentSize = 2;
        for (long long int i = 0; i < 32; i++) {
            long long int howManySegments = (right+1)/segmentSize;
            long long int remaining = (right+1)%segmentSize;
            zerosInBitTillRight[i] = howManySegments*(segmentSize/2); 
            zerosInBitTillRight[i] += min(segmentSize/2, remaining);

            segmentSize *= 2;
        }

        long long int ans = 0;
        segmentSize = 1;
        for (long long int i = 0; i < 32; i++) {
            if (zerosInBitTillRight[i]-zerosInBitTillLeft[i] == 0) {
                ans += segmentSize;
            }
            segmentSize *= 2;
        }

        return (int) ans;
    }
};