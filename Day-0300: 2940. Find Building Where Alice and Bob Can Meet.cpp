// 2940. Find Building Where Alice and Bob Can Meet (HARD)
// https://leetcode.com/problems/find-building-where-alice-and-bob-can-meet/description/?envType=daily-question&envId=2024-12-22

class Solution {
public:
    int numBuildings, maxTable[50010][20], logLookup[50010];

    int getMaxHeight(int start, int end) {
        int logSize = logLookup[end - start + 1];
        return max(maxTable[start][logSize], maxTable[end - (1 << logSize) + 1][logSize]);
    }

    vector<int> leftmostBuildingQueries(vector<int>& buildingHeights, vector<vector<int>>& queryList) {
        numBuildings = buildingHeights.size();
        maxTable[numBuildings][0] = INT_MAX;
        logLookup[0] = -1;

        for (int i = 1; i <= numBuildings; i++) {
            logLookup[i] = logLookup[i >> 1] + 1;
        }

        for (int i = 0; i < numBuildings; i++) {
            maxTable[i][0] = buildingHeights[i];
        }
        for (int j = 1; j < 20; j++) {
            for (int i = 0; i + (1 << j) - 1 < numBuildings; i++) {
                maxTable[i][j] = max(maxTable[i][j - 1], maxTable[i + (1 << (j - 1))][j - 1]);
            }
        }

        int totalQueries = queryList.size();
        vector<int> results(totalQueries);

        for (int queryIdx = 0; queryIdx < totalQueries; queryIdx++) {
            int aliceIdx = queryList[queryIdx][0], bobIdx = queryList[queryIdx][1];
            if (aliceIdx > bobIdx) swap(aliceIdx, bobIdx);

            if (aliceIdx == bobIdx) {
                results[queryIdx] = aliceIdx;
                continue;
            }

            if (buildingHeights[bobIdx] > buildingHeights[aliceIdx]) {
                results[queryIdx] = bobIdx;
                continue;
            }

            int requiredHeight = max(buildingHeights[aliceIdx], buildingHeights[bobIdx]);
            int left = bobIdx, right = numBuildings, mid;

            while (left < right) {
                mid = (left + right) >> 1;
                if (getMaxHeight(bobIdx, mid) > requiredHeight) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }

            results[queryIdx] = (left == numBuildings) ? -1 : left;
        }

        return results;
    }
};
