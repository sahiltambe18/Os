#include <iostream>
#include <vector>

using namespace std;

void input(int arr[][3])
{
	for (int i = 0; i < 5; i++)
	{
		cout << "enter for p" << i << " ";
		for (int j = 0; j < 3; j++)
		{
			cin >> arr[i][j];
		}
	}
}

void restore_available(vector<int> &available, vector<int> total, int allocated[][3])
{
	available = total;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			available[j] -= allocated[i][j];
		}
	}
}

int main()
{
	int need[5][3], p;
	vector<int> total = {10, 5, 7};
	vector<int> available(3, 0), req(3, 0);
	vector<int> safe;
	vector<int> final(5, 0);
	bool safe_flag = false;

	int allocated[5][3];
	// int allocated[5][3] = {{0, 1, 0},
	// 					   {2, 0, 0},
	// 					   {3, 0, 2},
	// 					   {2, 1, 1},
	// 					   {0, 0, 2}};

	cout << "Enter allocated resources : \n";
	input(allocated);

	int max[5][3];
	cout << "Enter max resources needed for process : \n";
	input(max);
	/*
	= {{7, 5, 3},
					 {3, 2, 2},
					 {9, 0, 2},
					 {2, 2, 2},
					 {4, 3, 3}};
	*/

	// need matrix
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			need[i][j] = max[i][j] - allocated[i][j];
		}
	}

	// available matrix
	restore_available(available, total, allocated);
	
	cout << "process id\n";
	cin >> p;
	// 1 0 2
	for (int i = 0; i < 3; i++)
	{
		cout << "enter resorces\n";
		cin >> req[i];
	}

	if (req[0] <= need[p][0] && req[1] <= need[p][1] && req[2] <= need[p][2])
	{
		if (req[0] <= available[0] && req[1] <= available[1] && req[2] <= available[2])
		{
			safe_flag = true;
			for (int j = 0; j < 3; j++)
			{
				available[j] -= req[j];
				allocated[p][j] += req[j];
				need[p][j] -= req[j];
			}
			// sequencing
			for (int x = 0; x < 5; x++)
			{
				for (int i = 0; i < 5; i++)
				{
					if (need[i][0] <= available[0] && need[i][1] <= available[1] && need[i][2] <= available[2] && final[i] == 0)
					{
						available[0] += allocated[i][0];
						available[1] += allocated[i][1];
						available[2] += allocated[i][2];
						final[i] = 1;
						safe.push_back(i);
					}
				}
			}
			for (auto flag : final)
			{
				if (flag == 0)
				{
					safe_flag = false;
					for (int j = 0; j < 3; j++)
					{
						available[j] += req[j];
						allocated[p][j] -= req[j];
						need[p][j] += req[j];
					}
					restore_available(available, total, allocated);
					break;
				}
			}
		}
	}

	if (safe_flag)
	{
		cout << "safe sequence is : ";
		for (auto pr : safe)
		{
			cout << "p" << pr << " ";
		}
	}
	else
	{
		cout << "not in safe sequence" << endl;
	}

	return 0;
}



/*
Enter allocated resources : 
enter for p0 0
1
0
enter for p1 2
0
0
enter for p2 3
0
2
enter for p3 2
1
1
enter for p4 0
0
2
Enter max resources needed for process :
enter for p0 7
5
3
enter for p1 3
2
2
enter for p2 9
0
2
enter for p3 2
2
2
enter for p4 4
3
3
3 3 2 process id
1
enter resorces
1
enter resorces
0
enter resorces
2
safe sequence is : p1 p3 p4 p0 p2
PS C:\Users\Lenovo\Desktop\code\os> 
*/