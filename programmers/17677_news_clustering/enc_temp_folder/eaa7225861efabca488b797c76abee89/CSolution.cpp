#include <string>
#include <vector>
#include <algorithm>
#include <regex>
#include <math.h>

using namespace std;

vector<string> getSubVector(string str)
{
    vector<string> subVector;

    std::transform(str.begin(), str.end(), str.begin(), ::tolower);

    for (int index = 0; index < str.length(); index++)
    {
        string sub = str.substr(index, 2);
        if (sub.length() != 2)
            continue;

        char first = sub.at(0);
        char second = sub.at(1);

        bool is_first_alpha = isalpha(first);
        bool is_second_alpha = isalpha(second);

        if (!is_first_alpha || !is_second_alpha)
            continue;

        subVector.push_back(sub);
    }

    return subVector;
}

vector<string> getIntersection(vector<string> str1SubVector, vector<string> str2SubVector)
{
    vector<string> intersectionVector;
    set_intersection(str1SubVector.begin(), str1SubVector.end(), str2SubVector.begin(), str2SubVector.end(), back_inserter(intersectionVector));

    return intersectionVector;
}

vector<string> getUnion(vector<string> str1SubVector, vector<string> str2SubVector)
{
    vector<string> unionVector;
    set_union(str1SubVector.begin(), str1SubVector.end(), str2SubVector.begin(), str2SubVector.end(), back_inserter(unionVector));

    return unionVector;
}

int getJaccard(string str1, string str2)
{
    // 입력받은 글자 2글자로 자르기.
    vector<string> str1SubVector = getSubVector(str1);
    vector<string> str2SubVector = getSubVector(str2);

    sort(str1SubVector.begin(), str1SubVector.end());
    sort(str2SubVector.begin(), str2SubVector.end());

    // 2글자 벡터를 기반으로 교집합 만들기.
    vector<string> intersectionVector = getIntersection(str1SubVector, str2SubVector);

    // 2글자 벡터를 기반으로 합집합 만들기.
    vector<string> unionVector = getUnion(str1SubVector, str2SubVector);

    // 집합 갯수.
    int intersection_count = intersectionVector.size();
    int union_count = unionVector.size();

    double jaccard = 1;
    if (0 < intersection_count && 0 < union_count)
        jaccard = (double) intersection_count / union_count;

    jaccard = floor(jaccard * 65536);
    return jaccard;
}

int main()
{
    int result1 = getJaccard("4", "FRENCH");

    return 0;
}