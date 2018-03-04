#include <maya/MPxNode.h>
#include <maya/MTypeId.h>
#include <maya/MString.h>
#include <maya/MStatus.h>
#include <maya/MPlug.h>
#include <maya/MDataBlock.h>
#include "fbm/fbm.h"


class ShakeNode : MPxNode
{
    public:
        ShakeNode();
        virtual ~ShakeNode();
        MStatus compute(const MPlug &plug, MDataBlock &block);

        static void* creator();
        static MStatus initialize();

    public:
        static MString m_typeName;
        static MTypeId m_typeId;
        static MObject m_input;
        static MObject m_output;
        static MObject m_amplitude;

    private:
        FBM::Fbm *m_fbm;
};