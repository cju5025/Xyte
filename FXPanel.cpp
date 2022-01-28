#include "FXPanel.h"
#include "GUIHelpers.h"

FXPanel::FXPanel(XyteAudioProcessor* processor)
:   PanelBase(processor)
{
    setSize(FX_PANEL_WIDTH, FX_PANEL_HEIGHT);
}

FXPanel::~FXPanel()
{
    
}

void FXPanel::paint(Graphics& g)
{
    PanelBase::paint(g);
    if (mLowBandFreqSlider)
    {
        paintComponentLabel(g, mLowBandFreqSlider.get());
    }
    
    if (mLowBandGainSlider)
    {
        paintComponentLabel(g, mLowBandFreqSlider.get());
    }
    
    if (mLowBandQualitySlider)
    {
        paintComponentLabel(g, mLowBandFreqSlider.get());
    }
}

void FXPanel::addSliders()
{
        const int slider_size = 60;
        int x = 125;
        int y = (getHeight() * 0.5) - (slider_size * 0.5);
    
        mLowBandFreqSlider = std::make_unique<ParameterSlider>(mProcessor->parameters, "Low Peak Freq");
        mLowBandFreqSlider->setBounds(x, y, slider_size, slider_size);
        addAndMakeVisible(*mLowBandFreqSlider);
        x += slider_size * 2;
    
//        mRangeSlider = std::make_unique<ParameterSlider>(mProcessor->parameters, ParameterID[parameter_Range]);
//        mRangeSlider->setBounds(x, y, slider_size, slider_size);
//        addAndMakeVisible(*mRangeSlider);
//        x += slider_size * 2;
//
//        mBlendSlider = std::make_unique<ParameterSlider>(mProcessor->parameters, ParameterID[parameter_Blend]);
//        mBlendSlider->setBounds(x, y, slider_size, slider_size);
//        addAndMakeVisible(*mBlendSlider);
//        x += slider_size * 2;
    
}

