class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int total = 0;

        while (numBottles >= numExchange) {
        total += numExchange;
        numBottles -= numExchange;
        numBottles++;
        numExchange++;
        }
        total+=numBottles;
        return total;
    }
};