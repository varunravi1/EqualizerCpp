#pragma once
#include <vector>
#include "JuceHeader.h"
class HighPass
{
public:
	HighPass(bool highpass);
	void setPass(bool highpass);
	void setCutoffFrequency(float cutoffFrequency);
	void setSamplingRate(float samplingRate);

	void processBlock(juce::AudioBuffer<float>&, juce::MidiBuffer);
private:
	bool highpass;
	float cutoffFrequency;
	float samplingRate;
	std::vector<float> dnBuffer;
	float sign;
};

