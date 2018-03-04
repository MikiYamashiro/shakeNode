#include "shakeNode.h"
#include <maya/MFnNumericAttribute.h>

// TODO : change typeid
MTypeId ShakeNode::m_typeId(0x00128341);
MString ShakeNode::m_typeName("shakeNode");
MObject ShakeNode::m_input;
MObject ShakeNode::m_output;
MObject ShakeNode::m_amplitude;


ShakeNode::ShakeNode()
{
    m_fbm = new FBM::Fbm();
}

ShakeNode::~ShakeNode()
{
    delete m_fbm; 
}

MStatus ShakeNode::compute(const MPlug &plug, MDataBlock &block)
{
    if (plug.attribute() == m_output)
    {
        MDataHandle ampHandle = block.inputValue(m_amplitude);
        MDataHandle inpHandle = block.inputValue(m_input);
        MDataHandle outHandle = block.outputValue(m_output);

        float amp = ampHandle.asFloat();
        float input = inpHandle.asFloat();

        outHandle.setFloat(amp * input);
        block.setClean(plug);
    }
    else
    {
        return MS::kUnknownParameter;
    }

    return MS::kSuccess;
}

void* ShakeNode::creator()
{
    return new ShakeNode();
}

MStatus ShakeNode::initialize()
{
    
    // octaves; unsigned int; keyable False!
    // noiseType = enum  == perlin, wave, simple
    // amplitude; float
    // frequency; float
    // lacunarity; float
    // persistence float
    // offset; float

    // input, output
    MFnNumericAttribute nAttr;

    m_amplitude = nAttr.create( "amplitude", "amp", MFnNumericData::kFloat, 0.0 );
    nAttr.setWritable(true);
    nAttr.setStorable(true);
    nAttr.setKeyable(true);
    addAttribute(m_amplitude);

    m_output = nAttr.create( "output", "out", MFnNumericData::kFloat, 0.0 );
    nAttr.setWritable(false);
    nAttr.setStorable(false);
    nAttr.setKeyable(false);
    addAttribute(m_output);

    m_input = nAttr.create( "input", "inp", MFnNumericData::kFloat, 0.0 );
    nAttr.setWritable(true);
    nAttr.setStorable(true);
    nAttr.setKeyable(true);
    addAttribute(m_input);
    
    attributeAffects(m_input, m_output);
    attributeAffects(m_amplitude, m_output);    

    return MS::kSuccess;
}
