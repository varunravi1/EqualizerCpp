#include <iostream>
#include "HighPass.h"
HighPass::HighPass(bool highPass)
{
	this->sign = highPass ? -1.0f : 1.0f;
}
//setting if this instrance of the class will be high pass or low pass
void HighPass::setPass(bool highPass)
{
	this->highpass = highpass;
}
//setting cutoff frequency
void HighPass::setCutoffFrequency(float cutoffFrequency)
{
	this->cutoffFrequency = cutoffFrequency;
}
//setting sampling rate
void HighPass::setSamplingRate(float samplingRate)
{
	this->samplingRate = samplingRate;
}
//audio processing block
void HighPass::processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer)
{
	constexpr auto PI = 3.14159265359f; //PI constant
	dnBuffer.resize(buffer.getNumChannels(), 0.f); //resizing the buffer vector to the number of channels from the JUCE audio buffer
	const auto tan = std::tan(PI * cutoffFrequency / samplingRate);
	const auto a1 = (tan - 1.f) / (tan + 1.f); //allpass filter coefficient
	
	for (auto channel = 0; channel < buffer.getNumChannels(); ++channel) //iterating through all channels in the JUCE buffer
	{
		auto channelSamples = buffer.getWritePointer(channel); //getting a write pointer to the channel
		for (auto i = 0; i < buffer.getNumSamples();++i) //iterating through all the samples in the channel
		{
			std::cout << channel << " " << i << std::endl;
			const auto inputSample = channelSamples[i]; //getting the current sample in the current channel
			const auto allPassSample = a1 * inputSample + dnBuffer[channel]; //getting the allpassfiltered output 
			dnBuffer[channel] = inputSample - a1 * allPassSample; //no clue that this dnBuffer is doing tbh
			const auto filterOutput = 0.5 * (inputSample + sign * allPassSample); //using the formula, we multiply by 0.5 to account for amplitude doubling, and then we add/subtract the allpass filtered sample based on which type of filter we want this to be
			channelSamples[i] = filterOutput; //store the updated filtered value back into the channelsamples array
		}

	}
}