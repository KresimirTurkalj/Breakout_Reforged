#include "Object2D.h"

Object2D::Object2D() : objectInfo(ObjectInfo{ ObjectType::Unknown })
{

}

Object2D::Object2D(ObjectInfo info) : objectInfo(info)
{

}

ObjectInfo& Object2D::getObjectInfo()
{
    return objectInfo;
}

void Object2D::moveObject(std::chrono::steady_clock::duration, Object2D* collidingObject)
{
    
}
