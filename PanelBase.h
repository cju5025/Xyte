#pragma once

#include "JuceHeader.h"
#include "PluginProcessor.h"
#include "InterfaceDefines.h"

class PanelBase
:   public Component
{
public:
  
    PanelBase( XyteAudioProcessor* processor );
    ~PanelBase();
    
    void paint ( Graphics& g ) override;
    
private:
    
    XyteAudioProcessor* mProcessor;
    
};