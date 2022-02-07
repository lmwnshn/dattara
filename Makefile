EXTENSION = dattara
MODULE_big = dattara
DATA = dattara--0.0.1.sql
OBJS = dattara.o
PG_CONFIG ?= pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)