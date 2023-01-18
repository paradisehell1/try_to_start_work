#include<iostream>
#include <sstream>
using namespace std;

int main() {
	char a[100];
	char y[100];
	char c = ' ';
	char c1 = '\n';
	int q;
	cin >> q;
	for (int i1 = 0; i1 < q; i1++) {
		cin >> a;
		int i = 0;
		int num;
		int l = 0;
		int k = 0;
		while (true) {

			l = 0;
			c = a[i];
			if (c >= '0' && c <= '9') {
				num = i;
				break;
			}
			if (c == ',') {
				i++;
				continue;
			}
			int j = i + 1;
			if (a[i] == '\0')
				break;
			i++;
			while (a[j] != '\0') {
				if (a[j] >= '0' && a[j] <= '9') {
					break;
				}
				if (a[j] == c) {
					l = 1;
					break;
				}
				j++;
			}
			if (l == 0) {
				k++;
			}

		}

		int position = a[0] - 'a' + 1;
		position = position + 32;

		int r = a[num] - '0';
		if (a[num + 1] != ',') {
			r = r + a[num + 1] - '0';
			num++;
		}
		num++;
		num++;
		r = r + a[num] - '0';

		if (a[num + 1] != ',') {
			r = r + a[num + 1] - '0';
			num++;
		}

		int sum = (k + r * 64) + (position * 256);

		std::ostringstream ss;
		ss << std::hex << sum;
		std::string result = ss.str();
		result[0] = '\0';
		int y1 = result.length();
		for (int y2 = 0; y2 < y1; y2++) {
			if (result[y2] == 'a' || result[y2] == 'b' || result[y2] == 'c' || result[y2] == 'd' || result[y2] == 'e' || result[y2] == 'f') {
				result[y2] = toupper(result[y2]);
			}
		}

		std::cout << result << " ";


	}