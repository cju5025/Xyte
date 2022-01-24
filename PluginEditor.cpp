#include "PluginProcessor.h"
#include "PluginEditor.h"

XyteAudioProcessorEditor::XyteAudioProcessorEditor (XyteAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    setSize (MAIN_PANEL_WIDTH, MAIN_PANEL_HEIGHT);
    
    mMainPanel = std::make_unique<MainPanel>(&audioProcessor);
    addAndMakeVisible(mMainPanel.get());
    
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
