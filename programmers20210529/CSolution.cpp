#include <string>
#include <vector>
#include <map>

using namespace std;

string getNotFinishParticipantName(vector<string> participant, vector<string> completion)
{
	map<string, int> participantMap;
	for (vector<string>::iterator participantIndex = participant.begin(); participantIndex != participant.end(); ++participantIndex)
	{
		// ���� �̸��� ��������.
		string participantName = *participantIndex;

		// ���� �̸� ���� ī��Ʈ�Ͽ� �־��ֱ�.

		participantMap[participantName] = participantMap[participantName] + 1;
	}

	if (participantMap.empty())
		return "";

	// �����ڸ�ܿ��� ������ ����� �����ϱ�.
	for (vector<string>::iterator completionIndex = completion.begin(); completionIndex != completion.end(); ++completionIndex)
	{
		// ���� �̸��� ��������.
		string completionName = *completionIndex;

		// ���� �̸� ���� ī��Ʈ�Ͽ� �����ϱ�

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