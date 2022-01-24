#pragma once

#include "PanelBase.h"
#include "FXPanel.h"

class CenterPanel
:   public PanelBase
{
public:
    
    CenterPanel(XyteAudioProcessor* processor);
    ~CenterPanel();
private:

    std::unique_ptr<FXPanel> mFXPanel;
};
