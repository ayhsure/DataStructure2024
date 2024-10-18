#include<iostream>
#include<string>
#include<vector>

std::vector<int> match_table(std::string& str) {
	int len = str.length();
	std::vector<int> table(len, 0);
	int idx = 0;
	for (int k = 1;k < len;k++)
	{
		if (str[k] != str[idx])
		{
			table.at(k) = 0;
			idx = 0;
		}
		else
		{
			table.at(k) = idx + 1;
			idx++;
		}
	}
	return table;
}

bool kmp(std::string& main_str, std::string& sub_str) {
	int i = 0;
	int j = 0;
	int main_len = main_str.length();
	int sub_len = sub_str.length();
	std::vector<int> table = match_table(sub_str);
	do{
		if (main_str[i] == sub_str[j])
		{
			i++;
			j++;
		}
		else
		{
			if (j == 0)
				i++;
			else
				j = table.at(j - 1);
		}
	} while (i < main_len && j < sub_len);
	if (j >= sub_len - 1) 
		return true;
	else 
		return false;
}
	
int main() {
	std::string str1;
	std::string str2;
	std::cin >> str1 >> str2;
	bool flag = kmp(str1, str2);
	if (flag)
		std::cout << "match success";
	else
		std::cout << "match fail";
	return 0;
}