#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

class XyteAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    XyteAudioProcessorEditor (XyteAudioProcessor&);
    ~XyteAudioProcessorEditor() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:

    XyteAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (XyteAudioProcessorEditor)
};
