#ifndef DISTANCE_H_
#define DISTANCE_H_

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

template <class T>
class Distance{
public:
	virtual double evaluate(vector<T> data1, vector<T> data2) = 0;
	virtual ~Distance(){}
};

template <class T>
class HammingDistance : public Distance<T>{
public:
	HammingDistance(){}
	double evaluate(vector<T> data1, vector<T> data2){
		int noDiff = 0;
		for(int i = 0; i < data1.size(); i++){
			if (data1[i] != data2[i]){
				noDiff++;
			}
		}
		return noDiff;
	}
	~HammingDistance(){}
};


template <class T>
class JaccardDistance : public Distance<T>{
public:
	JaccardDistance(){}
	double evaluate(vector<T> data1, vector<T> data2){
		int noCommon = 0;
		for(int i = 0; i < data1.size(); i++){
			if(std::find(data2.begin(), data2.end(), data1[i]) != data2.end()){
			      noCommon++;
			}
		}
		return 1.0 - noCommon / (double) (data1.size() + data2.size() - noCommon);
	}
	~JaccardDistance(){}
};

#endif /* DISTANCE_H_ */