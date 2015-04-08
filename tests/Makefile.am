GTEST_DIR=/home/anirudh/Downloads/gtest-1.7.0
AM_CXXFLAGS = -isystem ${GTEST_DIR}/include -I${GTEST_DIR} -I$(srcdir)/../modules/bm_sim/include -I$(srcdir)/../modules/bf_lpm_trie/include -pthread
LDADD = libgtest.a libgmain.a $(srcdir)/../modules/bm_sim/libbmsim.a $(srcdir)/../modules/bf_lpm_trie/libbflpmtrie.a -lnanomsg -lboost_system -lboost_thread -lm -lgmp -lJudy -ljsoncpp
AUTOMAKE_OPTIONS = foreign subdir-objects no-dependencies

# Static library for gtest
check_LIBRARIES = libgtest.a libgmain.a
libgtest_a_SOURCES = ${GTEST_DIR}/src/gtest-all.cc
libgmain_a_SOURCES = ${GTEST_DIR}/src/gtest_main.cc

# Define unit tests
common_source =
TESTS = test_actions \
test_checksums \
test_conditionals \
test_data \
test_handle_mgr \
test_p4objects \
test_parser \
test_phv \
test_queue \
test_tables
check_PROGRAMS = $(TESTS)

# Sources for tests
test_actions_SOURCES       = $(common_source) test_actions.cpp
test_checksums_SOURCES     = $(common_source) test_checksums.cpp
test_conditionals_SOURCES  = $(common_source) test_conditionals.cpp
test_data_SOURCES          = $(common_source) test_data.cpp
test_handle_mgr_SOURCES    = $(common_source) test_handle_mgr.cpp
test_p4objects_SOURCES     = $(common_source) test_p4objects.cpp
test_parser_SOURCES        = $(common_source) test_parser.cpp
test_phv_SOURCES           = $(common_source) test_phv.cpp
test_queue_SOURCES         = $(common_source) test_queue.cpp
test_tables_SOURCES        = $(common_source) test_tables.cpp