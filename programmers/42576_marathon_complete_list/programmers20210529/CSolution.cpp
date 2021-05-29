#include <string>
#include <vector>
#include <map>

using namespace std;

string getNotFinishParticipantName(vector<string> participant, vector<string> completion)
{
	map<string, int> participantMap;
	for (vector<string>::iterator participantIndex = participant.begin(); participantIndex != participant.end(); ++participantIndex)
	{
		// 선수 이름을 가져오기.
		string participantName = *participantIndex;

		// 같은 이름 갯수 카운트하여 넣어주기.

		participantMap[participantName] = participantMap[participantName] + 1;
	}

	if (participantMap.empty())
		return "";

	// 참가자명단에서 완주자 명단을 제외하기.
	for (vector<string>::iterator completionIndex = completion.begin(); completionIndex != completion.end(); ++completionIndex)
	{
		// 선수 이름을 가져오기.
		string completionName = *completionIndex;

		// 같은 이름 갯수 카운트하여 제외하기

		participantMap[completionName] = participantMap[completionName] - 1;
		if (participantMap[completionName] == 0)
			participantMap.erase(completionName);
	}

	if (participantMap.empty())
		return "";

	map<string, int>::iterator last = --participantMap.end();
	return last->first;
}

int main()
{
	vector<string> participant;
	participant.push_back("mislav");
	participant.push_back("stanko");
	participant.push_back("mislav");
	participant.push_back("ana");

	vector<string> completion;
	completion.push_back("stanko");
	completion.push_back("ana");
	completion.push_back("mislav");

	string result = getNotFinishParticipantName(participant, completion);
	return 0;
}