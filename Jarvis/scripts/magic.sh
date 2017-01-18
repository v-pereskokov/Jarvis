seq 1 100000 | while read $i; do echo -en "\rplaying...[•  ]"; sleep 1; echo -en "\rplaying...[∞• ]"; sleep 1; echo -en "\rplaying...[∞∞•]"; sleep 1; done
