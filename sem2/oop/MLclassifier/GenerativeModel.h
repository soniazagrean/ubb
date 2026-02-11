#ifndef GENERATIVEMODEL_H_
#define GENERATIVEMODEL_H_
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>
#include "Data.h"
#include "Distance.h"

using namespace std;

class GenerativeModel {
    public:
        virtual string generate(const string& prompt) = 0;
        virtual ~GenerativeModel() {}
    };
    
// Echo generator
class EchoModel : public GenerativeModel {
    public:
        string generate(const string& prompt){
            return "Echo: " + prompt;
        }
};

// Reverse generator
class ReverseModel : public GenerativeModel {
    public:
        string generate(const string& prompt){
            string reversed = prompt;
            reverse(reversed.begin(), reversed.end());
            return "Reverse: " + reversed;
        }
};

//Random Word Generator
class RandomWordModel : public GenerativeModel {
    private:
        int noTokens;
    public:
        RandomWordModel(int lim = 5){
            this->noTokens = lim;
        }
        string generate(const string& prompt){
            vector<string> words = {"facultate", "cursuri", "student", "flori", "supa", "pian"};
            string result = "Random: ";
            for (int i = 0; i < this->noTokens; ++i) {
                result += words[rand() % words.size()] + " ";
            }
            return result;
        }
};

template <class T>
class NearestNeighbour : public GenerativeModel{
    private:
        Distance<T>* dist;
        std::vector<Data> knowledgeBase;
    public:
        NearestNeighbour(Distance<string> *d, char* fileName){
            this->dist = d;
            //loadTrainData from file
            std::ifstream fin(fileName);
            while (!fin.eof()){
                std::string line;
                fin >> line;
                Data d = Data(line);
                this->knowledgeBase.push_back(d);
            }
            fin.close();
        }
        string bestMatched(string s){
            Data d = Data(s + "noLabel");
            string answer = "no label";
            double minDist = s.length();
            for (int i = 0; i < this->knowledgeBase.size(); i++){
                double crtDist = d.compare(this->knowledgeBase[i], this->dist);
                if (crtDist < minDist){
                    minDist = crtDist;
                    answer = this->knowledgeBase[i].getLabel();
                }	//if
            }	//for i
            return answer;
        }
        string generate(const string& prompt) override {
            // return "Generated output based on KNN logic";
            string result = "kNN: " + bestMatched(prompt);
            return result;
        }
};

#endif /* GENERATIVEMODEL_H_ */