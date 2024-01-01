#!/usr/bin/python
#
# Wallet Balance Graph Generator
# - getbalance.py
# - statsb.js
# - kotobalance.service
#
# Assumption:
#   - Username/Group = koto/koto
#   - k-nomp was installed under ~/k-nomp
#
# Installation:
# (1) copy scripts, install service
# $ mkdir ~/bin
# $ cp getbalance.py ~/bin
# $ chmod 755 ~/bin/getbalane.py
# $ cp statsb.js ~/k-nomp/website/static
# $ sudo cp kotobalance.service /etc/systemd/system
# $ sudo systemctl daemon-reload
# $ sudo systemctl start kotobalance
# $ sudo systemctl enable kotobalance
#
# (2) modify your ~/k-nomp/website/pages/stats.html
#
# <script>
#     document.querySelector('main').appendChild(document.createElement('script')).src = '/static/stats.js';
#+    document.querySelector('main').appendChild(document.createElement('script')).src = '/static/statsb.js';
# </script>
#
# (3) add this html to your ~/k-nomp/website/pages/stats.html
#+<div id="topCharts">
#+    <div class="chartWrapper">
#+        <div class="chartLabel">Pool Wallet Balance</div>
#+        <div class="chartHolder"><svg id="poolBalance"/></div>
#+    </div>
#+</div>
import commands
import sys
import json
import os
import time
import datetime

datapath = "balance.json"
if len(sys.argv) > 1:
	datapath = sys.argv[1]

data = []
if os.path.exists(datapath):
	f = open(datapath)
	data = json.loads(f.read())
	f.close()

while True:
	t = int(time.time())
	try:
		b = json.loads(commands.getoutput('koto-cli z_gettotalbalance'))
	except:
		pass;
	b["time"] = t
	b["transparent"] = float(b["transparent"])
	b["private"] = float(b["private"])
	b["total"] = float(b["total"])
	data.append(b)

	if data[0]["time"] < t - 3600*4:
		data = data[1:]

	f = open(datapath, "w")
	f.write(json.dumps(data))
	f.close()

	dt = datetime.datetime.fromtimestamp(time.time())
	dtstr = dt.strftime('%Y-%m-%d %H:%M:%S')
	print "%s: t=%d, p=%d" % (dtstr, b["transparent"], b["private"])
	sys.stdout.flush()

	while int(time.time()) < t + 30:
		time.sleep(1)

