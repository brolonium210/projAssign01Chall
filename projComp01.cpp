#include <iostream> // input-output library 
#include <math.h>  // library for sin function 
#include <vector>  // if using vectors 
#include "wav.hpp" // make sure to include this helper library

using namespace std;

void makeTone(vector<int>& waveform,int vol,int numSamp,int sampRate,int Freq){
	double attackStart = 0;
	double attackEnd = numSamp*0.3;
	double attackModifier = 0.1;

	double decayStart = (numSamp*0.3)+1;
	double decayEnd = numSamp*0.6;
	double decayModifier = 0.2;

	double sustainStart = (numSamp*0.6)+1;
	double sustainEnd = numSamp*0.8;
	double sustainModifier = 0.5;
	double sustainLevel = 0.7;

	double releaseStart = (numSamp*0.8)+1;
	double releaseEnd = numSamp;
	double releaseModifier = 0.2;	
	

	//for(int i =0;i<numSamp;i++){
	//	double t = i*1.0/sampRate;
	//	int temp = vol*sin(2*M_PI*Freq*t);
	//	waveform.push_back(temp);
	//}
	//
	//
	//this was really hard to figure out and I needto do more reps 	
	for(int i=attackStart;i<attackEnd;i++){
		double t = i*1.0/sampRate;
		float progress = (float)((i-attackStart)/(attackEnd-attackStart));		
//		cout << progress << endl;
		double volmod = pow(progress,attackModifier);
		//cout << volmod << endl;
		//this wasnt cast right and was just producing a flat 0
		int temp = ((int)(vol*volmod))*sin(2*M_PI*Freq*t);
		//cout << temp << endl;
		waveform.push_back(temp);		
	}
	for(int i=decayStart;i<decayEnd;i++){
		double t = i*1.0/sampRate;
		float progress = (float)((i-decayStart)/(decayEnd-decayStart));		
		double volmod = (1-(1-sustainLevel) * pow(progress,decayModifier));	
		int temp = ((int)(vol*volmod))*sin(2*M_PI*Freq*t);
		waveform.push_back(temp);	
	}
	for(int i=sustainStart;i<sustainEnd;i++){
		double t = i*1.0/sampRate;
		double volmod = sustainLevel;	
		int temp = ((int)(vol*volmod))*sin(2*M_PI*Freq*t);
		waveform.push_back(temp);	
	}
	for(int i=releaseStart;i<releaseEnd;i++){
		double t = i*1.0/sampRate;
		float progress = (float)((i-releaseStart)/(releaseEnd-releaseStart));		
		double volmod = sustainLevel * pow(1 - progress, releaseModifier);	
		int temp = ((int)(vol*volmod))*sin(2*M_PI*Freq*t);
		waveform.push_back(temp);	
	}


}

//void makeReal(vector<int>& waveform,int vol,int numSamp,int sampRate,int Freq){
	
//}



int main(){
	int sampRate = 44100;
	int dur = 1;
	int numSamp = sampRate*dur;

	vector<int>waveform;
	int tone1Freq = 500;
	int tone2Freq = 1500;

	int vol = 6000;
	int reps = 6;

	while(reps>0){
		cout << reps%2 << endl;
		if((reps%2)==1){
			makeTone(waveform,vol,numSamp,sampRate,tone1Freq);
		}else{
			makeTone(waveform,vol,numSamp,sampRate,tone2Freq);	
		}
		reps--;
	}

	MakeWavFromVector("tone5.wav",sampRate, waveform);

	return 0;
}

