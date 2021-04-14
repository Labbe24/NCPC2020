#include <iostream>

int main()
{
    int stackNum;
    int coinStack[50];
    int firstHalfStackIndexes[25];
    int secondHalfStackIndexes[25];
    int stackSum = 0;
    int firstHalfStackSum = 0;
    int secondHalfStackSum = 0;


    std::cin >> stackNum;

    if (stackNum < 2 || stackNum > 50) {
        std::cout << "no";
        return 0;
    }

    for (int i = 0; i < stackNum; i++) {
        std::cin >> coinStack[i];
        stackSum += coinStack[i];
    }

    if (stackSum % 2 == 0) {
        for (int i = 0; i < stackNum; i++) {
            if (firstHalfStackSum + coinStack[i] <= stackSum / 2) {
                firstHalfStackSum += coinStack[i];
                firstHalfStackIndexes[i] = i;
            }
            else {
                secondHalfStackSum += coinStack[i];
                secondHalfStackIndexes[i] = i;
            }
        }

        // Make stack-halfs equal
        while (firstHalfStackSum != secondHalfStackSum) {
            if (firstHalfStackSum > secondHalfStackSum) {
                for (int i = 0; i < stackNum; i++) {
                    if (firstHalfStackIndexes[i] >= 0) {
                        if (coinStack[firstHalfStackIndexes[i]] > 0) {
                            coinStack[firstHalfStackIndexes[i]]--;
                            firstHalfStackSum--;
                        }
                    }
                }
            }
            else if (firstHalfStackSum < secondHalfStackSum) {
                for (int i = 0; i < stackNum; i++) {
                    if (secondHalfStackIndexes[i] >= 0) {
                        if (coinStack[secondHalfStackIndexes[i]] > 0) {
                            coinStack[secondHalfStackIndexes[i]]--;
                            secondHalfStackSum--;
                        }
                    }
                }
            }
        }

        // Take two coins. One from each stack half until no coins are left
        while (firstHalfStackSum > 0 && secondHalfStackSum > 0) {
            for (int i = 0; i < stackNum; i++) {
                if (firstHalfStackIndexes[i] >= 0) {
                    if (coinStack[firstHalfStackIndexes[i]] > 0) {
                        coinStack[firstHalfStackIndexes[i]]--;
                        firstHalfStackSum--;
                        std::cout << i << " ";
                        break;
                    }
                }
            }

            for (int i = 0; i < stackNum; i++) {
                if (secondHalfStackIndexes[i] >= 0) {
                    if (coinStack[secondHalfStackIndexes[i]] > 0) {
                        coinStack[secondHalfStackIndexes[i]]--;
                        secondHalfStackSum--;
                        std::cout << i << " \n";
                        break;
                    }
                }
            }
        }
    }
    else {
        std::cout << "no";
    }
}
