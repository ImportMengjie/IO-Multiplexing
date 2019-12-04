
aux_source_directory(. POLL_DIR_ALL_SOURCE)

add_library(Poll ${POLL_DIR_ALL_SOURCE})
# add_library(Poll poll.h poll.cc)