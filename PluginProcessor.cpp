#include "PluginProcessor.h"
#include "PluginEditor.h"


XyteAudioProcessor::XyteAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
}

XyteAudioProcessor::~XyteAudioProcessor()
{
}

const juce::String XyteAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool XyteAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool XyteAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool XyteAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double XyteAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int XyteAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int XyteAudioProcessor::getCurrentProgram()
{
    return 0;
}

void XyteAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String XyteAudioProcessor::getProgramName (int index)
{
    return {};
}

void XyteAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void XyteAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void XyteAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool XyteAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void XyteAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);

        // ..do something to the data...
    }
}

//==============================================================================
bool XyteAudioProcessor::hasEditor() const
{
    return true;
}

juce::AudioProcessorEditor* XyteAudioProcessor::createEditor()
{
    return new XyteAudioProcessorEditor (*this);
}

//==============================================================================
void XyteAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{

}

void XyteAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{

}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new XyteAudioProcessor();
}
