#pragma once
#ifndef __XY_NODE_SINGLE_LINK_
#define __XY_NODE_SINGLE_LINK_

namespace xy{
    namespace base{
        struct node1Link{
          node1Link* nx;
          node1Link():nx(nullptr){}
          node1Link(node1Link*next): nx(next){}
        };

        template<typename T>
        struct data1Link:
          public node1Link,
          public T{
          typedef T valueType;
          data1Link(void):node1Link(nullptr), T(){}
          data1Link(node1Link*next):node1Link(next),T(){}
          data1Link(const T& that):node1Link(nullptr), T(that){}
          data1Link(const T& that, node1Link*next):node1Link(next), T(that){}
        };
    }
}

#endif//__XY_NODE_SINGLE_LINK_