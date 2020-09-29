#!/bin/sh
CORES=$(nproc)
df -h | awk '$NF=="/"{printf "Uso del Disco: %d/%dGB (%s)\n", $3, $2, $5}'
free -m | awk 'NR==2{printf "Uso de la Memoria: %s/%sMB (%.2f%%)\n", $3, $2, $3*100/$2 }'
top -bn1 | grep Cpu | awk "{printf \"Uso del Procesador: %.2f%% total (%.2f%% user, %.2f%% system)\n\", \$2+\$4, \$2, \$4}"
top -bn1 | grep load | awk "{printf \"Promedio de carga del Procesador ($CORES núcleos): %d%% (%d%% total)\n\", \$(NF-2)/$CORES*100, \$(NF-2)*100}"
echo 'Procesos con mayor consumo de CPU:'
ps -eo %cpu,%mem,pid,ppid,comm --sort=-%cpu | head -n 4
