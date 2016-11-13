seq 1 1000000 | while read i; do echo -en "\rloading...[•  ]"; sleep 1; echo -en "\rloading...[∞• ]"; sleep 1; echo -en "\rloading...[∞∞•]"; sleep 1; done


