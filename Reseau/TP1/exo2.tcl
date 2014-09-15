#Script des exos 2 et trois

# instantiation du simulateur
set ns [new Simulator]

# associer les couleurs pour NAM
$ns color 1 green
$ns color 2 red
$ns color 3 blue

# instantiation du fichier de traces
set file1 [open out3.tr w]
$ns trace-all $file1

# instantiation du fichier de traces pour NAM
set file2 [open out3.nam w]
$ns namtrace-all $file2

# procédure pour lancer automatiquement le visualisateur NAM à la fin de la simulation
proc finish {} {
global ns file1 file2
$ns flush-trace
close $file1
close $file2
exec nam out3.nam &
exit 0
}

# instantiation de deux noeuds
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]

# instantiation d'une ligne de communication full duplex entre les divers noeuds
$ns duplex-link $n0 $n2 2Mb 10ms DropTail
$ns duplex-link $n1 $n2 2Mb 10ms DropTail
$ns duplex-link $n2 $n3 1.5Mb 20ms DropTail
$ns queue-limit $n2 $n3 15
$ns duplex-link-op $n2 $n3 queuePos 0.5

# instanciation d'une connexion UDP entre n1 et n3
set udp [new Agent/UDP]
$ns attach-agent $n1 $udp
set null [new Agent/Null]
$ns attach-agent $n3 $null
$ns connect $udp $null

# instantiation d'une connexion TCP entre n0 et n3
set tcp [new Agent/TCP]
$ns attach-agent $n0 $tcp
set sink [new Agent/TCPSink]
$ns attach-agent $n3 $sink
$ns connect $tcp $sink

# instantiation d'un trafic CBR composé de paquets de 1000 octets, générés toutes les 5 ms
set cbr0 [new Application/Traffic/CBR]
$cbr0 attach-agent $udp
$cbr0 set packetSize_ 1000
$cbr0 set interval_ 0.005

# instantiation d'un trafic FTP composé de paquets de 1000 octets, générés toutes les 5 ms
set tcp0 [new Application/FTP]
$tcp0 attach-agent $tcp
# $tcp0 set packetSize_ 1000
# $tcp0 set interval_ 0.005

$udp set fid_ 3
$tcp set fid_ 2

# scénario de début et de fin de génération des paquets
$ns at 1 "$cbr0 start"
$ns at 5 "$cbr0 stop"
$ns at 2 "$tcp0 start"
$ns at 4 "$tcp0 stop"

# la simulation va durer 5 secondes de temps simulé
$ns at 5.0 "finish"

# début de la simulation
$ns run
