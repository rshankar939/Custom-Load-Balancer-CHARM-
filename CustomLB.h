/**
 * \addtogroup CkLdb
*/
/*@{*/

#ifndef _CUSTOMLB_H_
#define _CUSTOMLB_H_

#include "CentralLB.h"
#include "CustomLB.decl.h"

void CreateGreedyLB();
BaseLB * AllocateGreedyLB();

class CustomLB : public CBase_CustomLB {

public:
  struct HeapData {
    double load;
    int    pe;
    int    id;
  };

  CustomLB(const CkLBOptions &);
  CustomLB(CkMigrateMessage *m):CBase_GreedyLB(m) { lbname = "CustomLB"; }
  void work(LDStats* stats);
private:
  enum           HeapCmp {GT = '>', LT = '<'};
      void           Heapify(HeapData*, int, int, HeapCmp);
  void           HeapSort(HeapData*, int, HeapCmp);
  void           BuildHeap(HeapData*, int, HeapCmp);
  bool        Compare(double, double, HeapCmp);
  HeapData*      BuildCpuArray(BaseLB::LDStats*, int, int *);  
  HeapData*      BuildObjectArray(BaseLB::LDStats*, int, int *);      
  bool        QueryBalanceNow(int step);
};

#endif /* _HEAPCENTLB_H_ */

/*@}*/
