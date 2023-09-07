#include "VolumeClass.h"
void Volume::SetDefaultVol(float vol)
{
	this->vol = vol;
}

void VolProcessBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer)
{
	constexpr auto PI = 3.14159265359f; //PI constant
	for (auto channel = 0; channel < buffer.getNumChannels(); ++channel) //iterating through all channels in the JUCE buffer
	{
		auto channelSamples = buffer.getWritePointer(channel); //getting a write pointer to the channel
		for (auto i = 0; i < buffer.getNumSamples();++i) //iterating through all the samples in the channel
		{
			const auto inputSample = channelSamples[i]; //getting the current sample in the current channel

		}
	}
}
