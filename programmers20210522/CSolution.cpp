#include <string>
#include <vector>

using namespace std;

int getCollatz(int num)
{
	if (num < 1)
		return -1;

	// 입력받은 수 형변환.
	long long new_num = num;

	// 현재까지 진행한 횟수.
	int runCount = 0;
	while (new_num != 1)
	{
		// Collatz 추측으로 1이될 경우 종료 & 아니면 계속 반복.
		if (new_num % 2 == 0)
		{
			// 현재 숫자가 짝수일 경우.
			new_num /= 2;
		}
		else
		{
			// 현재 숫자가  홀수일 경우.
			new_num *= 3;
			new_num += 1;
		}

		// 실행횟수 증가.
		runCount++;

		// 500번 했을때도 1이안된다면, -1로 반환 문제 조건.
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