class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int total = numBottles;
        int empties = numBottles;
        while (empties >= numExchange) {
            empties -= numExchange;
            total += 1;
            empties += 1;
            numExchange++;
        }
        return total;
    }
};