#pragma once
#ifndef __XY_NODE_DOUBLE_LINK_
#define __XY_NODE_DOUBLE_LINK_

namespace xy{
    namespace base{
        struct node2Link{
          node2Link *pv, *nx;
          node2Link():nx(nullptr), pv(nullptr){}
          node2Link(node2Link *previous, node2Link *next = nullptr): pv(previous), nx(next){}
        };

        template<typename T>
        struct data2Link:
          public node2Link,
          public T{
          typedef T valueType;
          data2Link(void):node2Link(), T(){}
          data2Link(node2Link*previous):node2Link(previous),T(){}
          data2Link(const T& that):node2Link(), T(that){}
          data2Link(const T& that, node2Link*previous, node2Link *next=nullptr):node2Link(previous, next), T(that){}
        };
    }
}

#endif//__XY_NODE_DOUBLE_LINK_