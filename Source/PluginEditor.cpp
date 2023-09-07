/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SimplePluginAudioProcessorEditor::SimplePluginAudioProcessorEditor (SimplePluginAudioProcessor& p, juce::AudioProcessorValueTreeState& vts)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    addAndMakeVisible(highPassslider);
    highPassslider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    highpassCutoffFrequencyAttachment.reset(new juce::AudioProcessorValueTreeState::SliderAttachment(vts, "highpasscutoff_frequency", highPassslider));
    addAndMakeVisible(highPassLabel);
    highPassLabel.setText("High Pass Cutoff Frequency", juce::dontSendNotification);



    addAndMakeVisible(lowpassslider);
    lowpassslider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    lowpassCutoffFrequencyAttachment.reset(new juce::AudioProcessorValueTreeState::SliderAttachment(vts, "lowpasscutoff_frequency", lowpassslider));
    addAndMakeVisible(lowPassLabel);
    lowPassLabel.setText("Low Pass Cutoff Frequency", juce::dontSendNotification);
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 400);
}

SimplePluginAudioProcessorEditor::~SimplePluginAudioProcessorEditor()
{
}

//==============================================================================
void SimplePluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
}

void SimplePluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    highPassslider.setBounds(15,35, 100, 300);
    highPassLabel.setBounds(highPassslider.getX(), highPassslider.getY() - 30, 200, 50);

    lowpassslider.setBounds(highPassslider.getX() + 200,highPassslider.getY(), 100, 300);
    lowPassLabel.setBounds(lowpassslider.getX(), lowpassslider.getY() - 30 , 200, 50);

}
