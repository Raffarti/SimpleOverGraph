#!/usr/local/bin/python
# -*- coding: utf-8 -*-

import subprocess
import re

cmd = ["aticonfig","--adapter=0","--od-getclocks"]

p = subprocess.Popen(cmd, stdout=subprocess.PIPE)
out, err = p.communicate()
reg = re.search('(\\d+)(?:%)',out)
data = reg.group(1)
print(data)
