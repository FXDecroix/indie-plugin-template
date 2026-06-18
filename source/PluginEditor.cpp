#include "PluginEditor.h"

PluginEditor::PluginEditor (PluginProcessor& p)
    : AudioProcessorEditor (&p), processorRef (p)
{
    gainSlider.setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    gainSlider.setTextBoxStyle (juce::Slider::TextBoxBelow, false, 70, 18);
    addAndMakeVisible (gainSlider);
    gainAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment> (
        processorRef.apvts, "gain", gainSlider);

    gainLabel.setJustificationType (juce::Justification::centred);
    addAndMakeVisible (gainLabel);

    addAndMakeVisible (inspectButton);
    inspectButton.onClick = [&] {
        if (!inspector)
        {
            inspector = std::make_unique<melatonin::Inspector> (*this);
            inspector->onClose = [this]() { inspector.reset(); };
        }

        inspector->setVisible (true);
    };

    setSize (300, 300);
}

PluginEditor::~PluginEditor()
{
}

void PluginEditor::paint (juce::Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    auto area = getLocalBounds().reduced (12);

    g.setColour (juce::Colours::white);
    g.setFont (18.0f);
    auto title = juce::String (PRODUCT_NAME_WITHOUT_VERSION) + " v" VERSION;
    g.drawText (title, area.removeFromTop (28), juce::Justification::centred, false);
}

void PluginEditor::resized()
{
    auto area = getLocalBounds().reduced (12);
    area.removeFromTop (28); // title (painted)

    auto knobArea = area.removeFromTop (180);
    gainSlider.setBounds (knobArea.withSizeKeepingCentre (120, 140));
    gainLabel.setBounds (knobArea.withSizeKeepingCentre (120, 20).withY (knobArea.getBottom() - 20));

    area.removeFromTop (10);
    inspectButton.setBounds (area.removeFromTop (30).withSizeKeepingCentre (140, 30));
}
