#!/usr/bin/env bash

# Runtime: 0 ms, faster than 100.00% of Bash online submissions for Valid Phone Numbers.
# Memory Usage: 3.1 MB, less than 96.43% of Bash online submissions for Valid Phone Numbers.

grep -E '^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$' file.txt