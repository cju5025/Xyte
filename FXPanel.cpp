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
        int y = (getHeight() * 0.5) - (slider_size);
    
        mLowBandFreqSlider = std::make_unique<ParameterSlider>(mProcessor->parameters, "Low Peak Freq");
        mLowBandFreqSlider->setBounds(x, y, slider_size, slider_size);
        addAndMakeVisible(*mLowBandFreqSlider);
        y += slider_size * 2;
//        x += slider_size * 2;
    
        mLowBandGainSlider = std::make_unique<ParameterSlider>(mProcessor->parameters, "Low Peak Gain");
        mLowBandGainSlider->setBounds(x, y, slider_size, slider_size);
        addAndMakeVisible(*mLowBandGainSlider);
        y += slider_size * 2;
    //        x += slider_size * 2;
    
}

