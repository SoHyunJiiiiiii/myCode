#include "aus_vote.h"
#include <iostream>

using namespace std;

AusVoteSystem::AusVoteSystem(const vector<string>& candidate_names,int candidateSize,int voterSize) {

    candidates = candidate_names;
    candidateSize_ = candidateSize;
    //선호도1을 저장하는 배열
    result = new int[candidateSize_+1] ;
    for(int i=0; i<candidateSize_; i++){
        result[i] = 0;
    }
    //선호도2를 저장하는 배열
    two_result = new int[candidateSize_+1] ;
    for(int i=0; i<candidateSize_; i++){
        result[i] = 0;
    }
    vector<string>::iterator it;
    for(it = candidates.begin(); it != candidates.end(); it++){
        cout << "name " << (*it) << endl;
    }
}

AusVoteSystem::~AusVoteSystem() {
	/* implement here*/

}
// 후보별 선호도를 1순위부터 입력.
// 잘못된 숫자가 있거나 선호도 수가 후보자 수와 다르면
// 해당 입력을 무시하고 false를 리턴.
bool AusVoteSystem::AddVote(vector<int>& vote) {
    vector<int>::iterator it;
    int count=0,i=0;
    if(candidateSize_!=vote.size()) {
        return false;
    }
    
    for(it=vote.begin(); it!=vote.end(); it++) {
        if( (*it)==1 ) {
            result[count]++;
        }
        else if( (*it)==2 ) {
            two_result[count]++;
        }
        if( (*it) < 1 || (*it) > 3) {
            return false;
        }
        count++;
    }
    

    return true;
}
int AusVoteSystem::HalfResult(){
    

    for(int i=0; i<candidateSize_; i++) {
        votes.push_back(result[i]);
    }
    
    vector<int>::iterator votes_it = votes.begin();
    vector<string>::iterator candidates_it = candidates.begin();
    int min = (*votes_it);
    
    cout << "Round 1: " ;
    for(; votes_it!=votes.end(); votes_it++) {
        if( min > (*votes_it) ) {
            min = (*votes_it);
        }
        cout << (*candidates_it) << " " << (*votes_it) << " ";
        candidates_it++;
    }cout << endl;
    
    int idx=0,i=0;
    for(votes_it=votes.begin(); votes_it!=votes.end(); votes_it++) {
        if( (*votes_it) == min ) {
            idx = i;
            cout << "idx : " << idx << endl;
            votes.erase(votes.begin()+idx);
            return idx;
        }
        i++;
    }
    return idx;
}
void AusVoteSystem::CompleteResult(int idx){
    vector<int>::iterator votes_it;
    int i=0,tmp;
    for(votes_it=votes.begin(); votes_it!=votes.end(); votes_it++) {
        if( (i+1) % (idx+1) == 0 && (*votes_it)== 1 ) {
            tmp = i/3 ;
        }
        i++;
    }
    int current=0;
    for(votes_it=votes.begin(); votes_it!=votes.end(); votes_it++) {
        if(  current / candidateSize_ == tmp && (*votes_it)== 2 ) {

            result[current % candidateSize_]++;
        }
    }
    
    i=0;
    vector<string>::iterator candidates_it = candidates.begin();
    cout << "Round 2: " ;
    for(votes_it =votes.begin(); votes_it!=votes.end(); votes_it++) {
        cout << (*candidates_it) << " " << result[i++] << " ";
        candidates_it++;
    }cout << endl;
    
    
}

//int ComputeResult(const Candidate *candidateList, map<int, bool> &erased, int candidateSize, int voterSize, int start) {
//    for ( int i=0; i<candidateSize; i++){
//        cout << "Round 1: " << &candidateList[i] << endl;
//    }
//}
//
//vector<AusVoteSystem::RoundResult> AusVoteSystem::ComputeResult() const {
//	/* implement here*/
//
//}
