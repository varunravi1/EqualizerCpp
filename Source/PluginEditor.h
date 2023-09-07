/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"


//==============================================================================
/**
*/
class SimplePluginAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    SimplePluginAudioProcessorEditor (SimplePluginAudioProcessor&, juce::AudioProcessorValueTreeState& vts);
    ~SimplePluginAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:

    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SimplePluginAudioProcessor& audioProcessor;
    juce::Slider highPassslider;
    juce::Slider lowpassslider;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> highpassCutoffFrequencyAttachment;
    juce::Label highPassLabel;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> lowpassCutoffFrequencyAttachment;
    juce::Label lowPassLabel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SimplePluginAudioProcessorEditor)
};
