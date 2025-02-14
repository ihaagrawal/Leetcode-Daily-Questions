// 1352. Product of the Last K Numbers (MEDIUM)
// https://leetcode.com/problems/product-of-the-last-k-numbers/description/?envType=daily-question&envId=2025-02-14


class ProductOfNumbers {
private:
    vector<int> prefixProducts;

public:
    ProductOfNumbers() {
        prefixProducts.push_back(1);
    }

    void add(int num) {
        if (num == 0) {
            prefixProducts.clear();
            prefixProducts.push_back(1);
        } else prefixProducts.push_back(prefixProducts.back() * num);
    }

    int getProduct(int k) {
        int n = prefixProducts.size();
        if (k >= n) return 0;
        return prefixProducts.back() / prefixProducts[n - k - 1];
    }
};
