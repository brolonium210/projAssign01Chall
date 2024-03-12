#ifndef PROJASSIGN01CHALL_H
#define  PROJASSIGN01CHALL_H
#include <iostream> // input-output library 
#include <math.h>  // library for sin function 
#include <vector>  // if using vectors 
#include "wav.hpp" // make sure to include this helper library 
#include <string>
#include <fstream>
using namespace std;

//make a single array with all required setup values
class setupVals{
	public:
		int volume=0;
		int sampRate = 44100;
		double dur = 1;
		int numSamp;
		//double t;
		vector<string> intVals;
		vector<int>funFreqVals;
		vector<int>funFreqCalc;
		vector<int>harmonics;
		int realNoteBase;
		vector<int>realNote;
		string fileName;
	
	int getVolume();
	int getSampRate();
	int getNumSamp();
	double getDur();	
	
	void calcNumSamp();

	void setIntVals(vector<string>& intVals,string fileName);

	void setFunFreqVals(vector<int>& funFreqVals,vector<string>intVals);

	void setHarmonics(vector<int>& harmonics ,int funFreq);

	void setFunFreqCalcVals(vector<int>& funFreqCalc ,vector<int>funFreqVals);
	
};
	int setupVals::getVolume(){
		return volume;
	}
	int setupVals::getSampRate(){
		return sampRate;
	}
	int setupVals::getNumSamp(){
		numSamp = sampRate*dur;
		return numSamp;
	}
	double setupVals::getDur(){
		return dur;
	}


	void setupVals::setIntVals(vector<string>& intVals,string fileName){
		ifstream txtFile;
		string line;
		txtFile.open(fileName);
		if(txtFile.is_open()){
			while(getline(txtFile,line)){
			//	std::cout<<line<<std::endl;
				intVals.push_back(line);
			}
		}else{
			std::cout<<"couldnt open file"<<std::endl;
		}	
	}

	void setupVals::setFunFreqVals(vector<int>& funFreqVals,vector<string>intVals){
	for(int i=0;i<intVals.size();i++){
			int funFreq = stoi(intVals[i]); 
			//std::cout<<getSampRate()<<std::endl;	
			funFreqVals.push_back(funFreq);
		}
	}

	void setupVals::setFunFreqCalcVals(vector<int>& funFreqCalc ,vector<int>funFreqVals){
		int volume = getVolume();
		int sampRate = getSampRate();	
		int numSamp = getNumSamp();

		for(int i =0;i<funFreqVals.size();i++){
			std::cout << "------------------------------------"<<std::endl;
			std::cout << funFreqVals[i] << std::endl;
			for(int j=0;j<numSamp;j++){
				double t = j*1.0/sampRate;
				int inc = 6000/numSamp;
				
			if (j < (3*(numSamp/10))) {
    				volume = volume+inc;
			} else if (j > (3*(numSamp/10)) && j < (5*(numSamp/10))) {
    				volume = volume-inc;
			} else if (j>(5*(numSamp/10)) && j<(8*(numSamp/10))) {
    				volume = volume;
			}else if (j>(8*(numSamp/10))) {
    				volume = volume-inc; 
				}else {
    				volume = 6000;
			}

				int temp = volume*sin(2*M_PI*funFreqVals[i]*t);
				std::cout<<temp<<std::endl;
				if(temp > 0){
					funFreqCalc.push_back(temp);	
				}
			}
			

		}
		}


//make a fundamental frequency out of an integer
//int makeFun(int inputVal){
//	int temp = 
//}


//make a real notes out of a fundamental frequency
//read in a text file and return a vector of integers
//read in a vector of integers and return a vector of fundamental freqs
//read in a vector of fundamental freqs and return expanded real notes






#endif



