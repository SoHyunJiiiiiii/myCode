#include "aus_vote.h"
#include <iostream>

using namespace std;

int main() {

	int candidateSize;
	cin >> candidateSize;

	vector<string> candidates;
	string name;

	for(int i=0; i<candidateSize; i++) {
		cin >> name;
		candidates.push_back(name);
	}


	int voterSize;
	cin >> voterSize;
    AusVoteSystem aus(candidates,candidateSize,voterSize);
    
	for(int i=0; i<voterSize; i++) {
		vector<int> votes;
		int vote;
		for(int j=0; j<candidateSize; j++) {
			cin >> vote;
			votes.push_back(vote);
		}
		aus.AddVote(votes);
	}
    aus.HalfResult();
    //aus.CompleteResult(idx);
	
//	vector<AusVoteSystem::RoundResult> result = aus.ComputeResult();
//	AusVoteSystem::RoundResult round;
//	for(int i=0; i<result.size()-1; i++) {
//		round = result[i];
//		cout << "Round " << (i+1) << ": ";
//
//		for(int j=0; j<round.size(); j++)
//			cout << round[j].name << " " << round[j].votes << " ";
//		cout << endl;
//	}
//
//	round = result[ result.size()-1 ];
//	cout << "Winner: " << (round.size()==1? round[0].name : "") << endl;

	return 0;
}
