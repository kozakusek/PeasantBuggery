#!/bin/bash
for f in *; do [ -f "$f" ] && ! head -n1 "$f" | grep -q '^#' && printf '#include <bits/stdc++.h>\nusing namespace std;\n\n' | cat - "$f" > "$f.tmp" && mv "$f.tmp" "$f"; done
