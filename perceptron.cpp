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
   cout << "Training the data...\n" << endl;
   
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
      cout << "\nErrors in this iteration: " << errors << "\n" << endl;
      cout << "New Weights: " << endl;
      for (int i = 0; i < 4; ++i){
         cout << weights[i] << ", ";
      }
      cout << "\n" << endl;
      
      //cout << "New weights: " << weights[0] << ", " << weights[1] << ", " << weights[2] << ", " << weights[3] << endl;
   }
   
   cout << "\nTotal iterations: " << iterations << "\n" <<  endl;
}

int main (int argc, char *argv[]) {

   cout << "Perceptron learning algorithm" << endl;
   
   cout << "Learning XOR...\n\n" << endl;
   
   float theta = 0.5;
   float learningRate = 0.6;
   
   vector<int*> trainingData = vector<int*>();
   
   //AND DATA
   int data1[3] = {0, 0, 0};
   int data2[3] = {0, 1, 0};
   int data3[3] = {1, 0, 0};
   int data4[3] = {1, 1, 1};

   //OR DATA
   int data5[3] = {0, 0, 0};
   int data6[3] = {0, 1, 1};
   int data7[3] = {1, 0, 1};
   int data8[3] = {1, 1, 1};
   
   //XOR DATA
   
   int data9[3] = {0, 0, 0};
   int data10[3] = {1, 0, 1};
   int data11[3] = {0, 1, 1};
   int data12[3] = {1, 1, 0};
   
   

   trainingData.push_back(data1);
   trainingData.push_back(data2);
   trainingData.push_back(data3);
   trainingData.push_back(data4);
  /*
   trainingData.push_back(data5);
   trainingData.push_back(data6);
   trainingData.push_back(data7);
   trainingData.push_back(data8);
   */
   
   float weights[4] = {1,1,1,1};
   cout << "Input Data teaching AND:\n0,0,0\n0,1,0\n1,0,0\n1,1,1" << endl;
   trainData(trainingData, weights, theta, learningRate);
   
   trainingData.clear();
   trainingData.push_back(data5);
   trainingData.push_back(data6);
   trainingData.push_back(data7);
   trainingData.push_back(data8);
   
   cout << "Input Data teaching OR:\n0,0,0\n0,1,1\n1,0,1\n1,1,1\n" << endl;
   trainData(trainingData, weights, theta, learningRate);
   
   trainingData.clear();
   trainingData.push_back(data9);
   trainingData.push_back(data10);
   trainingData.push_back(data11);
   trainingData.push_back(data12);
   
   cout << "Input Data teaching XOR:\n0,0,0\n1,0,1\n0,1,1\n1,1,1\n" << endl;
   trainData(trainingData, weights, theta, learningRate);
   return 0;
   
}