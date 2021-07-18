#!/bin/bash

valgrind -s \
	--leak-check=full \
	--show-reachable=yes \
	--error-exitcode=42 \
	--track-origins=yes \
	./tests_bin