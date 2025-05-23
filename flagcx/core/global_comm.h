#ifndef FLAGCX_GLOBAL_COMM_H_
#define FLAGCX_GLOBAL_COMM_H_

#include "bootstrap.h"
#include "flagcx.h"

#include <vector>

/* Opaque handle to flagcxInnerComm */
typedef struct flagcxInnerComm *flagcxInnerComm_t;

/* Opaque handle to flagcxHeteroComm */
typedef struct flagcxHeteroComm *flagcxHeteroComm_t;

typedef enum {
  flagcxCommunicatorUnknown = 0,
  flagcxCommunicatorHomo = 1,  // Homogeneous Communicator
  flagcxCommunicatorHybrid = 2 // Hybrid Communicator
} flagcxCommunicatorType_t;

struct flagcxComm {
  // TODO: adjust code format
  int rank;
  int nranks;
  int nclusters;
  int homo_rank;
  int homo_root_rank;
  int homo_inter_rank;
  int homo_ranks;
  int has_single_rank_homo_comm;
  int support_multi_nic;
  flagcxCommunicatorType_t comm_type;
  uint64_t magic;
  volatile uint32_t *abortFlag;
  int *cluster_sizes;
  int *cluster_ids;
  int *globalrank2homorank;
  int *cluster_inter_ranks;
  bootstrapState *bootstrap;
  flagcxInnerComm_t host_comm;
  flagcxInnerComm_t homo_comm;
  flagcxHeteroComm_t hetero_comm;
  // experimental for multi-nic support
  int homoInterRootRank;
  int homoInterMyRank;
  int homoInterRanks;
  std::vector<std::vector<int>> clusterInterRankList;
  flagcxInnerComm_t homoInterComm;
  std::vector<flagcxVendorType> clusterVendorMap;
};

#endif // end include guard