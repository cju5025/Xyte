#include "PluginProcessor.h"
#include "PluginEditor.h"

XyteAudioProcessorEditor::XyteAudioProcessorEditor (XyteAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    setSize (400, 300);
}

XyteAudioProcessorEditor::~XyteAudioProcessorEditor()
{
    
}

void XyteAudioProcessorEditor::paint (juce::Graphics& g)
{

}

void XyteAudioProcessorEditor::resized()
{

}
