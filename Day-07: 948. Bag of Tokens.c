// 948. Bag of Tokens (MEDIUM)
// https://leetcode.com/problems/bag-of-tokens/?envType=daily-question&envId=2024-03-04

int bagOfTokensScore(int* tokens, int tokensSize, int power) {
    int i, j, score=0;
    if(tokensSize==0 || tokensSize<0)
        return 0;
    int a[tokensSize];
    for (int i = 0; i < tokensSize - 1; i++) {
        for (int j = 0; j < tokensSize - i - 1; j++) {
            if (tokens[j] < tokens[j + 1]) {
                int temp = tokens[j];
                tokens[j] = tokens[j + 1];
                tokens[j + 1] = temp;
            }
        }
    }
    j=tokensSize-1;
    i=0;
    while(i<j)
        {
            if(power>=tokens[j])
                {
                    power-=tokens[j];
                    score++;
                    j--;
                }
            else
                {
                    power+=tokens[i];
                    score--;
                    i++;
                }
            if(score<0)
                return 0;
        }
    if(power>=tokens[i])
        {
            power-=tokens[i];
            score++;
        }
    return score;
}
