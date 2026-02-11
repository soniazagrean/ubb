#ifndef DATA_H_
#define DATA_H_

#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <iostream>
#include "Distance.h"

using namespace std;

class Data{
	vector<string> features;
	string label;
public:
	Data(string line){
		std::stringstream sline(line);
		string token;
		while (getline(sline, token, ';')) {
		        features.push_back(token);
//		        cout << token << endl;
		}
		features.pop_back();
		label = token;
	}
	string getLabel(){
		return this->label;
	}
	vector<string> getFeatures(){
		return this->features;
	}
//	int compare(Data &d){
//		int noDiff = 0;
//		for (int i = 0; i < this->features.size(); i++){
//			if (d.features[i] != this->features[i])
//				noDiff++;
//		}
//		return noDiff;
//	}

	int compare(Data &d, Distance<string> *dist){
		return dist->evaluate(this->features, d.features);
	}
};



#endif /* DATA_H_ */
