#!/usr/bin/env bash

# Runtime: 4 ms, faster than 60.72% of Bash online submissions for Word Frequency.
# Memory Usage: 3.2 MB, less than 93.10% of Bash online submissions for Word Frequency.

(tr ' ' '\n' | grep "\S" | sort | uniq -c | sort -r | awk '{print $2" "$1}') < words.txt