#include <iostream> // input-output library 
#include <math.h>  // library for sin function 
#include <vector>  // if using vectors 
#include "wav.hpp" // make sure to include this helper library 
#include <string>
#include <fstream>

using namespace std;

vector<int> makeTone(vector<int>waveform,int oneTone,int sample_rate ,int duration,int reps);

vector<int>makeText(vector<int>waveform,string filename,int oneTone,int sample_rate ,int duration,int reps);


int main(){
	int sample_rate = 44100;
	int duration = 0.5;
	int numSamples = sample_rate*duration;
	int reps = 10;
	int funFreq = 440;
	vector<int>waveform;
	waveform = makeTone(waveform,funFreq,sample_rate,duration,reps);	
	
	waveform = makeText(waveform,"brickInWall.txt",funFreq,sample_rate,duration,reps);
	MakeWavFromVector("tone1.wav",sample_rate,waveform);
	return 0;		
}

vector<int> makeTone(vector<int>waveform,int oneTone,int sample_rate ,int duration,int reps){
	std::cout << "this is running" << std::endl;
	std::cout << sample_rate  << std::endl;
	int volume = 6000;
	int numSamples = sample_rate*duration;
	for(int i = 0;i<numSamples;i++){
		double t = i*1.0/sample_rate;
		int temp = volume*sin(2*M_PI*oneTone*t);
		waveform.push_back(temp);
		//std::cout << temp << std::endl;
		//std::cout << temp << std::endl;

	}
	std::cout<<"------------------------------------------------"<<std::endl;
		
	return waveform;
}

vector<int>makeText(vector<int>waveform,string filename,int oneTone,int sample_rate ,int duration,int reps){
	ifstream txtfile;
	string line;
	txtfile.open("brickInWall.txt");
	if(txtfile.is_open()){
		while(getline(txtfile,line)){
		//	std::cout<<line<<std::endl;
			int temp = stoi(line);
			waveform = makeTone(waveform,temp,sample_rate,duration,reps);
		}
		txtfile.close();
	}
	

	return waveform;
}






