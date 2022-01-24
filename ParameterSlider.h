#pragma once

#include "JuceHeader.h"
#include "XyteDial.h"

class ParameterSlider
:   public Slider
{
public:
    
    ParameterSlider(AudioProcessorValueTreeState& stateToControl, const String& parameterID);
    ~ParameterSlider();
    
private:
    
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> mAttachment;
    XyteDial mDialLookAndFeel;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ParameterSlider);
};

