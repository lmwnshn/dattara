-- TODO(WAN): Create some HypoPG esque functions for scaling table sizes.

\echo Load me with "CREATE EXTENSION dattara;" \quit

CREATE FUNCTION dattara_blah
    LANGUAGE C
    VOLATILE
    STRICT
AS '$libdir/dattara', 'dattara_blah'
;