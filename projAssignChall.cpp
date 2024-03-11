#include <iostream> // input-output library 
#include <math.h>  // library for sin function 
#include <vector>  // if using vectors 
#include "wav.hpp" // make sure to include this helper library 

using namespace std;

vector<int> makeTone(vector<int>waveform,int oneTone,int sample_rate ,int duration,int reps);


int main(){
	int sample_rate = 44100;
	int duration = 1.0;
	int numSamples = sample_rate*duration;
	int reps = 1;
	int funFreq = 440;
	vector<int>waveform;
	waveform = makeTone(waveform,20,sample_rate,duration,reps);	
	

	return 0;		
}

vector<int> makeTone(vector<int>waveform,int oneTone,int sample_rate ,int duration,int reps){
	std::cout << "this is running" << std::endl;
	std::cout << sample_rate  << std::endl;
	int volume = 6000;
	int numSamples = sample_rate*duration;
	for(int i = 0;i<numSamples;i++){
		double t = i*1/sample_rate;
		int temp = volume*sin(2*M_PI*frequency*t);
		waveform.push_back(temp);
		std::cout << temp << std::endl;
	}

	
	return waveform;
}







