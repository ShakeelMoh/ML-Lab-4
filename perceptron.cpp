//Perceptron Lab 4
//Shakeel Mohamed

#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <cmath>
#include <algorithm>

using namespace std;

void trainData(vector<int*> trainingData, float * weights, float theta, float learningRate){
   cout << "Training the data" << endl;
   
   int output;
   int errors = 1;//set to one to start
   float xwSum; //(x1w1 + x2w2 + .... xnwn)
   int iterations = 0;
   while (errors > 0){
      errors = 0;
      iterations++;
      for (int i = 0; i < trainingData.size(); ++i){
         xwSum = trainingData[i][0] * weights[i] + trainingData[i][1] * weights[i];
         if (xwSum > theta){
            output = 1; //Positive output
         } else {
            output = 0; // Negative output
         }
         if (output == trainingData[i][2]){
            //Do nothing. Already learnt
            cout << "Set " << (i+1) << " is already learnt" << endl;
         } else {
            errors++;
            //Alter the weight for that training data set
            cout << "Learning set " << (i+1) << endl;
            weights[i] = weights[i] + (learningRate * (trainingData[i][2] - output) * xwSum);
            //cout << "New weight for set " << i << " is " << weights[i];
         
         }
         
      }
      cout << "Errors in this iteration: " << errors << endl;
      cout << "New weights: " << weights[0] << ", " << weights[1] << ", " << weights[2] << ", " << weights[3] << endl;
   }
   
   cout << "\nTotal iterations: " << iterations << "\n" <<  endl;
}

int main (int argc, char *argv[]) {

   cout << "Perceptron learning algorithm" << endl;
   
   cout << "AND GATE:\n" << endl;
   
   float theta = 0.5;
   float learningRate = 0.6;
   
   vector<int*> trainingData = vector<int*>();
   int data1[3] = {0, 0, 0};
   int data2[3] = {0, 1, 0};
   int data3[3] = {1, 0, 0};
   int data4[3] = {1, 1, 1};
   
   trainingData.push_back(data1);
   trainingData.push_back(data2);
   trainingData.push_back(data3);
   trainingData.push_back(data4);
   
   float weights[4] = {1,1,1,1};
   
   trainData(trainingData, weights, theta, learningRate);

   return 0;
   
}