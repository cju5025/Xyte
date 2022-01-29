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
        paintComponentLabel(g, mLowBandGainSlider.get());
    }
    
    if (mLowBandQualitySlider)
    {
        paintComponentLabel(g, mLowBandQualitySlider.get());
    }
    
    if (mMidBandFreqSlider)
    {
        paintComponentLabel(g, mMidBandFreqSlider.get());
    }
    
    if (mMidBandGainSlider)
    {
        paintComponentLabel(g, mMidBandGainSlider.get());
    }
    
    if (mMidBandQualitySlider)
    {
        paintComponentLabel(g, mMidBandQualitySlider.get());
    }
    
    if (mHighBandFreqSlider)
    {
        paintComponentLabel(g, mHighBandFreqSlider.get());
    }
    
    if (mHighBandGainSlider)
    {
        paintComponentLabel(g, mHighBandGainSlider.get());
    }
    
    if (mHighBandQualitySlider)
    {
        paintComponentLabel(g, mHighBandQualitySlider.get());
    }
}

void FXPanel::addSliders()
{
        const int slider_size = 45;
        int x = getWidth() / 3 - slider_size;
        int y = (getHeight() * 0.5) - (slider_size);
    
        mLowBandFreqSlider = std::make_unique<ParameterSlider>(mProcessor->parameters, "Low Peak Freq");
        mLowBandFreqSlider->setBounds(x, y, slider_size, slider_size);
        addAndMakeVisible(*mLowBandFreqSlider);
        y += slider_size * 1.5;
    
        mLowBandGainSlider = std::make_unique<ParameterSlider>(mProcessor->parameters, "Low Peak Gain");
        mLowBandGainSlider->setBounds(x, y, slider_size, slider_size);
        addAndMakeVisible(*mLowBandGainSlider);
        y += slider_size * 1.5;
    
        mLowBandQualitySlider = std::make_unique<ParameterSlider>(mProcessor->parameters, "Low Peak Quality");
        mLowBandQualitySlider->setBounds(x, y, slider_size, slider_size);
        addAndMakeVisible(*mLowBandQualitySlider);
        y = (getHeight() * 0.5) - (slider_size);
        x += slider_size * 2;
    
        mMidBandFreqSlider = std::make_unique<ParameterSlider>(mProcessor->parameters, "Mid Peak Freq");
        mMidBandFreqSlider->setBounds(x, y, slider_size, slider_size);
        addAndMakeVisible(*mMidBandFreqSlider);
        y += slider_size * 1.5;

        mMidBandGainSlider = std::make_unique<ParameterSlider>(mProcessor->parameters, "Mid Peak Gain");
        mMidBandGainSlider->setBounds(x, y, slider_size, slider_size);
        addAndMakeVisible(*mMidBandGainSlider);
        y += slider_size * 1.5;

        mMidBandQualitySlider = std::make_unique<ParameterSlider>(mProcessor->parameters, "Mid Peak Quality");
        mMidBandQualitySlider->setBounds(x, y, slider_size, slider_size);
        addAndMakeVisible(*mMidBandQualitySlider);
        y = (getHeight() * 0.5) - (slider_size);
        x += slider_size * 2;
    
        mHighBandFreqSlider = std::make_unique<ParameterSlider>(mProcessor->parameters, "High Peak Freq");
        mHighBandFreqSlider->setBounds(x, y, slider_size, slider_size);
        addAndMakeVisible(*mHighBandFreqSlider);
        y += slider_size * 1.5;

        mHighBandGainSlider = std::make_unique<ParameterSlider>(mProcessor->parameters, "High Peak Gain");
        mHighBandGainSlider->setBounds(x, y, slider_size, slider_size);
        addAndMakeVisible(*mHighBandGainSlider);
        y += slider_size * 1.5;

        mHighBandQualitySlider = std::make_unique<ParameterSlider>(mProcessor->parameters, "High Peak Quality");
        mHighBandQualitySlider->setBounds(x, y, slider_size, slider_size);
        addAndMakeVisible(*mHighBandQualitySlider);
        y = (getHeight() * 0.5) - (slider_size);
        x += slider_size * 2;
    
}

