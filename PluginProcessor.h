#pragma once

#include <JuceHeader.h>

struct ChainSettings
{
    float lowPeakFreq { 0 }, lowPeakGainInDecibels { 0 }, lowPeakQuality { 0 },
    float midPeakFreq { 0 }, midPeakGainInDecibels { 0 }, midPeakQuality { 0 },
    float highPeakFreq { 0 }, highPeakGainInDecibels { 0 }, highPeakQuality { 0 },
};

ChainSettings getChainSettings(AudioProcessorValueTreeState& apvts);

class XyteAudioProcessor  : public juce::AudioProcessor
{
public:
    XyteAudioProcessor();
    ~XyteAudioProcessor() override;

    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    static AudioProcessorValueTreeState::ParameterLayout createParameterLayout();
    
    AudioProcessorValueTreeState apvts {*this, nullptr, "Parameters", createParameterLayout()};

private:
    
    using Filter = dsp::IIR::Filter<float>;
    using MonoChain = dsp::ProcessorChain<Filter, Filter, Filter>;
    
    MonoChain leftChain, rightChain;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (XyteAudioProcessor)
};
