#include "PanelBase.h"

PanelBase::PanelBase(XyteAudioProcessor* processor)
:   mProcessor(processor)
{
    
}

PanelBase::~PanelBase()
{
    
}

void PanelBase::paint(Graphics& g)
{
    g.setColour(Colour(17, 46, 44));
    g.fillAll();
    
    g.setColour(Colours::black);
    g.drawRect(0, 0, getWidth(), getHeight());
}
