#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int getMixCount(vector<int> scoville, int K)
{
    if (scoville.empty())
        return -1;

    // 자료구조 생성.
    std::make_heap(scoville.begin(), scoville.end(), std::greater<>{});
    
    int count = 0;
    while (1)
    {
        // 첫번째로 낮은 스코빌 점수.
        std::pop_heap(scoville.begin(), scoville.end(), std::greater<>{});
        int scoville_1 = scoville.back();
        if (K <= scoville_1)
            break;

        scoville.pop_back();
        if (scoville.empty())
            return -1;

        // 두번째로 낮은 스코빌 점수.
        std::pop_heap(scoville.begin(), scoville.end(), std::greater<>{});
        int scoville_2 = scoville.back();
        scoville.pop_back();

        // 첫번째와 두번째를 믹스한 스코빌 생성 및 추가.
        int mixScoville = scoville_1 + (scoville_2 * 2);

        count++;
    }
    
    return count;
}

void main()
{
    vector<int> scoville;
    scoville.push_back(1);
    scoville.push_back(2);
    scoville.push_back(3);
    scoville.push_back(9);
    scoville.push_back(10);
    scoville.push_back(12);

    int count = getMixCount(scoville, 7);
    return;
}