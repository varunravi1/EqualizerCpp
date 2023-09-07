#pragma once
#include <vector>
#include "JuceHeader.h"
#include "HighPass.h"
class Volume : HighPass
{
public:
	void SetDefaultVol(float vol);
	void VolProcessBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer);
private:
	float vol;
};


