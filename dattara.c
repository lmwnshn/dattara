#include <time.h>

// clang-format off
// Extension magic.
#include "postgres.h"
#include "fmgr.h"
// clang-format on

#include "nodes/pathnodes.h"
#include "optimizer/plancat.h"

PG_MODULE_MAGIC;
void _PG_init(void);
void _PG_fini(void);

static void FakeGetRelationInfoHook(PlannerInfo *root, Oid relationObjectId, bool inhparent, RelOptInfo *rel);

static get_relation_info_hook_type get_relation_info_hook_original = NULL;

void _PG_init(void) {
  elog(LOG, "Loading dattara.");
  get_relation_info_hook_original = get_relation_info_hook;
  get_relation_info_hook = FakeGetRelationInfoHook;
}

void _PG_fini(void) {
  get_relation_info_hook = get_relation_info_hook_original;
  elog(LOG, "Unloading dattara.");
}

static void FakeGetRelationInfoHook(PlannerInfo *root, Oid relationObjectId, bool inhparent, RelOptInfo *rel) {
  // This hook is fired at the end of plancat.c::get_relation_info.
  elog(LOG, "Tuples: %lf\n", rel->tuples);
  if (rel->tuples == 100000) {
    rel->tuples = 10;
  }
}
