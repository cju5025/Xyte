#pragma once

#include "PanelBase.h"
#include "ParameterSlider.h"

class FXPanel
:   public PanelBase
{
public:
    
    FXPanel(XyteAudioProcessor* inProcessor);
    ~FXPanel();
    
    void paint(Graphics& g) override;
    void addSliders();
    
private:
    
    std::unique_ptr<ParameterSlider> mLowBandFreqSlider;
    std::unique_ptr<ParameterSlider> mLowBandGainSlider;
    std::unique_ptr<ParameterSlider> mLowBandQualitySlider;
    
    std::unique_ptr<ParameterSlider> mMidBandFreqSlider;
    std::unique_ptr<ParameterSlider> mMidBandGainSlider;
    std::unique_ptr<ParameterSlider> mMidBandQualitySlider;
    
    std::unique_ptr<ParameterSlider> mHighBandFreqSlider;
    std::unique_ptr<ParameterSlider> mHighBandGainSlider;
    std::unique_ptr<ParameterSlider> mHighBandQualitySlider;
};

