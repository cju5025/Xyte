#include "TopPanel.h"

TopPanel::TopPanel(XyteAudioProcessor* processor)
:   PanelBase(processor)
{
    setSize(TOP_PANEL_WIDTH, TOP_PANEL_HEIGHT);
}

TopPanel::~TopPanel()
{
    
}

void TopPanel::paint(Graphics& g)
{
    PanelBase::paint(g);
    
    g.drawFittedText("Xyte", 0, 0, getWidth() - 10, getHeight(), Justification::centred, 1);
}
