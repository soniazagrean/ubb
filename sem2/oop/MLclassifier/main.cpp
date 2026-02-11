#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

#include "testDistances.h"
#include "GenerativeModel.h"

// play by the generative tiny-models
void testModels(const string& prompt) {
    Distance<string> *distance;
    // distance = new HammingDistance<string>();
    distance = new JaccardDistance<string>();

    vector<GenerativeModel*> models = {
        new EchoModel(),
        new ReverseModel(),
        new RandomWordModel(3),
        new NearestNeighbour<string>(distance,"data.in")
    };

    cout << "Query: " << prompt << endl;
    cout << "Answers:" << endl;
    for (int i = 0; i< models.size(); i++) {
        cout << "   " << models[i]->generate(prompt) << endl;
        delete models[i]; // Clean up memory
    }
}

int main(int argc, char *argv[]){

    // testAll();
    cout << "the 1st example ..." << endl;
    testModels("Hello, AI!");
    cout << "the 2nd example ..." << endl;
    testModels("ana;are;mere;");

    cout << "End ..." << endl;
    return 0;
}
