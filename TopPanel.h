#pragma once

#include "PanelBase.h"

class TopPanel
:   public PanelBase
{
public:
    
    TopPanel(XyteAudioProcessor* inProcessor);
    ~TopPanel();
    
    void paint(Graphics& g) override;
    
private:
    
};
