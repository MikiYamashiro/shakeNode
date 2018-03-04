#include <maya/MFnPlugin.h>
#include <maya/MObject.h>
#include <maya/MPxNode.h>
#include "shakeNode.h"


PLUGIN_EXPORT MStatus initializePlugin(MObject obj)
{ 
    MStatus status;
    MFnPlugin plugin(obj, "MikiYamashiro", "1.0", "Any");

    status = plugin.registerNode(ShakeNode::m_typeName, ShakeNode::m_typeId, ShakeNode::creator, ShakeNode::initialize);
    if (!status)
    {
        status.perror("registerNode");
        return status;
    }

    return status;
}

PLUGIN_EXPORT MStatus uninitializePlugin(MObject obj)
{
    MStatus status;
    MFnPlugin plugin(obj);

    status = plugin.deregisterNode(ShakeNode::m_typeId);
    if (!status)
    {
        status.perror("deregisterNode");
        return status;
    }

    return status;
}
