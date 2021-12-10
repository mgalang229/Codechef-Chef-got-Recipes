#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<string> d(n);
		for (int i = 0; i < n; i++) {
			cin >> d[i];
		}
		// assign a power of 2 (bitmask) in every vowel
		vector<long long> freq((1 << 5), 0);
		string vowels = "aeiou";
		map<char, int> mp;
		for (int i = 0; i < 5; i++) {
			mp[vowels[i]] = i;
		}
		// count the frequency of every bitmask created (1 to 31)
		// for example: aiu = 10101 (e and o are not present)
		for (int i = 0; i < n; i++) {
			int mask = 0;
			for (int j = 0; j < (int) d[i].size(); j++) {
				mask = mask | (1 << (mp[d[i][j]]));
			}
			freq[mask]++;
		}
		// calculate the distinct pairs ((i, j) = (j, i)) in the frequency of
		// the strings where all the vowels are present since the loop below
		// will not be able to handle this edge case
		long long ans = (freq[31] * (freq[31] - 1)) / 2;
		// calculate the final answer by multiplying the frequency of a bit
		// into the frequency of another bit wherein their union (OR) 
		// set is equal to 31 (aeiou = 11111)
		// note: start the inner for-loop at (i + 1) in order to avoid getting
		// twice of the final value needed (unordered pairs: (i, j) = (j, i))
		for (int bit1 = 0; bit1 < 32; bit1++) {
			for (int bit2 = bit1 + 1; bit2 < 32; bit2++) {
				if ((bit1 | bit2) == 31) {
					ans += freq[bit1] * freq[bit2];
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
