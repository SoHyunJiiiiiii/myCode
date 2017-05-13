#ifndef __AUS_VOTE_H__
#define __AUS_VOTE_H__

#include <string>
#include <vector>
#include <map>
using namespace std;
struct Candidate {
	string name;
	int votes;

	Candidate(){}
	Candidate(string name_, int votes_) : name(name_), votes(votes_) {}
};

struct Voter {
	int index;
	int *vote;
};

class AusVoteSystem {
public:
	AusVoteSystem(const vector<string>& candidate_names,int candidateSize,int voterSize);
	~AusVoteSystem();

	bool AddVote(vector<int>& vote);
    int HalfResult();
    void CompleteResult(int idx);
	typedef vector<Candidate> RoundResult;
	vector<RoundResult> ComputeResult() const;

private:
	vector<string> candidates;  //참가자저장
	vector<int> votes;  //전체투표저장
    map<int,string> round_result;
    int *result;        //최종결과 임시저장
    int *two_result;
    int candidateSize_;
};


#endif
