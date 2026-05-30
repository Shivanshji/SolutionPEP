#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
#include <algorithm>

using namespace std;

vector<vector<string>> minimizeCashFlow(vector<vector<string>>& transactions) {
    unordered_map<string, long long> balance;

    for (size_t i = 0; i < transactions.size(); i++) {
        string from = transactions[i][0];
        string to = transactions[i][1];
        long long amount = stoll(transactions[i][2]);

        balance[from] -= amount;
        balance[to] += amount;
    }

    vector<pair<string, long long>> debtors;
    vector<pair<string, long long>> creditors;

    for (auto it = balance.begin(); it != balance.end(); it++) {
        string name = it->first;
        long long amount = it->second;

        if (amount < 0) {
            debtors.push_back({name, -amount});
        } else if (amount > 0) {
            creditors.push_back({name, amount});
        }
    }

    vector<vector<string>> result;

    size_t i = 0;
    size_t j = 0;

    while (i < debtors.size() && j < creditors.size()) {
        string debtorName = debtors[i].first;
        string creditorName = creditors[j].first;

        long long debtorAmount = debtors[i].second;
        long long creditorAmount = creditors[j].second;

        long long settledAmount = min(debtorAmount, creditorAmount);

        result.push_back({
            debtorName,
            creditorName,
            to_string(settledAmount)
        });

        debtors[i].second -= settledAmount;
        creditors[j].second -= settledAmount;

        if (debtors[i].second == 0) {
            i++;
        }

        if (creditors[j].second == 0) {
            j++;
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<vector<string>> transactions;

    for (int i = 0; i < n; i++) {
        string from;
        string to;
        string amount;

        cin >> from >> to >> amount;

        vector<string> transaction;
        transaction.push_back(from);
        transaction.push_back(to);
        transaction.push_back(amount);

        transactions.push_back(transaction);
    }

    vector<vector<string>> result = minimizeCashFlow(transactions);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i][0] << " owes "
             << result[i][1] << ": "
             << result[i][2] << endl;
    }

    return 0;
}