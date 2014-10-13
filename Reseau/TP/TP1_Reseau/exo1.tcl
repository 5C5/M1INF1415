# instantiation du simulateur
set ns [new Simulator]

# associer les couleurs pour NAM
$ns color 1 green
$ns color 2 red
$ns color 3 blue

# instantiation du fichier de traces
set file1 [open out.tr w]
$ns trace-all $file1

# instantiation du fichier de traces pour NAM
set file2 [open out.nam w]
$ns namtrace-all $file2

# procédure pour lancer automatiquement le visualisateur NAM à la fin de la simulation
proc finish {} {
global ns file1 file2
$ns flush-trace
close $file1
close $file2
exec nam out.nam &
exit 0
}

# instantiation de deux noeuds
set n0 [$ns node]
set n1 [$ns node]

# instantiation d'une ligne de communication full duplex entre les noeuds n0 et n1
$ns duplex-link $n0 $n1 1Mb 10ms DropTail

# instantiation d'une connexion UDP
set udp [new Agent/UDP]
$ns attach-agent $n0 $udp
set null [new Agent/Null]
$ns attach-agent $n1 $null
$ns connect $udp $null

$udp set fid_ 1

# instantiation d'un trafic CBR composé de paquets de 1000 octets, générés toutes les 5 ms
set cbr0 [new Application/Traffic/CBR]
$cbr0 attach-agent $udp
$cbr0 set packetSize_ 1000
$cbr0 set interval_ 0.005

# scénario de début et de fin de génération des paquets par cbr0
$ns at 0.5 "$cbr0 start"
$ns at 4.5 "$cbr0 stop"

# la simulation va durer 5 secondes de temps simulé
$ns at 5.0 "finish"

# début de la simulation
$ns run
