#pragma once
#ifndef __XY_NODE_SINGLE_LINK_
#define __XY_NODE_SINGLE_LINK_

namespace XyQZ{
    namespace base{
        struct nodeSingLink{
          nodeSingLink* nx;
          nodeSingLink():nx(nullptr){}
          nodeSingLink(nodeSingLink*next): nx(next){}
        };

        template<typename T>
        struct dataNodeSingLink:
          public nodeSingLink,
          public T{
          typedef T valueType;
          dataNodeSingLink(void):nodeSingLink(nullptr), T(){}
          dataNodeSingLink(nodeSingLink*next):nodeSingLink(next),T(){}
          dataNodeSingLink(const T& that):nodeSingLink(nullptr), T(that){}
          dataNodeSingLink(const T& that, nodeSingLink*next):nodeSingLink(next), T(that){}
        };
    }
}

#endif//__XY_NODE_SINGLE_LINK_