#include <string>
#include <vector>

using namespace std;

int getCollatz(int num)
{
	if (num < 1)
		return -1;

	// �Է¹��� �� ����ȯ.
	long long new_num = num;

	// ������� ������ Ƚ��.
	int runCount = 0;
	while (new_num != 1)
	{
		// Collatz �������� 1�̵� ��� ���� & �ƴϸ� ��� �ݺ�.
		if (new_num % 2 == 0)
		{
			// ���� ���ڰ� ¦���� ���.
			new_num /= 2;
		}
		else
		{
			// ���� ���ڰ�  Ȧ���� ���.
			new_num *= 3;
			new_num += 1;
		}

		// ����Ƚ�� ����.
		runCount++;

		// 500�� �������� 1�̾ȵȴٸ�, -1�� ��ȯ ���� ����.
		if (500 < runCount)
		{
			runCount = -1;
			break;
		}
	}

	return runCount;
}

int main()
{
	int result = getCollatz(6);
	return 0;
}