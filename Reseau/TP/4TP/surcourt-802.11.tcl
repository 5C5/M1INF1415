# ======================================================================
# Define options
# ======================================================================
set val(chan)           Channel/WirelessChannel    ;# channel type
set val(prop)           Propagation/TwoRayGround   ;# radio-propagation model
set val(netif)          Phy/WirelessPhy            ;# network interface type
set val(mac)            Mac/802_11                 ;# MAC type
set val(ifq)            Queue/DropTail/PriQueue    ;# interface queue type
set val(ll)             LL                         ;# link layer type
set val(ant)            Antenna/OmniAntenna        ;# antenna model
set val(ifqlen)         20                         ;# max packet in ifq
set val(nn)             2                          ;# number of mobilenodes
set val(rp)             AODV                       ;# routing protocol


# ======================================================================
# Main Program
# ======================================================================


#======================================================================
# Phy and Propagation Model
#======================================================================

#These settings allow 250m of range
# On fixe la zone de detection de porteuse 
# (identique a celle pour la communication)
Phy/WirelessPhy set CSThresh_ 3.652e-10;

#======================================================================
# MAC model
#======================================================================

# pas de RTS/CTS pour les paquets inferieurs a 3000 bytes
Mac/802_11 set RTSThreshold_  3000               ;# bytes
# vitesse de transmission pour les trames
Mac/802_11 set dataRate_ 11Mb
# vitesse de transmission pour les en-tetes physiques et ACKs
Mac/802_11 set basicRate_ 1Mb



#======================================================================
# Initialize Global Variables
#======================================================================

set ns_		[new Simulator]

# instantiation du fichier de traces
set file1 [open out1.tr w]
$ns_ trace-all $file1

# instantiation du fichier de traces pour NAM
set file2 [open out1.nam w]
$ns_ namtrace-all-wireless $file2 500 500

proc finish {} {
    global ns_ file1 file2
    $ns_ flush-trace
    close $file1
    close $file2
    exec nam out.nam &
	exit 0;
}



# set up topography object
set topo       [new Topography]
$topo load_flatgrid 500 500

#
# Create God
# global information about the state of the environment, network or nodes that an omniscent observer would have
#
set god_ [create-god $val(nn)]


# configure node

        $ns_ node-config -adhocRouting $val(rp) \
			 -llType $val(ll) \
			 -macType $val(mac) \
			 -ifqType $val(ifq) \
			 -ifqLen $val(ifqlen) \
			 -antType $val(ant) \
			 -propType $val(prop) \
			 -phyType $val(netif) \
			 -channelType $val(chan) \
			 -topoInstance $topo \
			 -agentTrace OFF \
			 -routerTrace OFF \
			 -macTrace ON \
			 -movementTrace OFF			


			 
##################################################
#define initial positions and number of hops
for {set i 0} {$i < [expr $val(nn)] } {incr i} {
	set node_($i) [$ns_ node]	
	#$node_($i) random-motion 0		;# disable random motion
}

# position des noeuds
$node_(0) set X_ 0.0
$node_(0) set Y_ 150.0
$node_(0) set Z_ 0.0

$node_(1) set X_ 150.0
$node_(1) set Y_ 150.0
$node_(1) set Z_ 0.0



##################################################
#define agents
set udp0 [new Agent/UDP]
$ns_ attach-agent $node_(0) $udp0
# fixe la valeur max d’une trame (hors en-tete couche 2)
$udp0 set packetSize_ 1500	# set MSS to xxxx bytes;
set null0 [new Agent/Null]
$ns_ attach-agent $node_(1) $null0
$ns_ connect $udp0 $null0

set cbr0 [new Application/Traffic/CBR]
$cbr0 attach-agent $udp0
# fixe la valeur des paquets generes par l’application
$cbr0 set packetSize_ 1500	# set packet size
# fixe le debit d’emission de l’application
$cbr0 set rate_ 20Mb
$ns_ at 0.0 "$cbr0 start"


##################################################
#initial positions for NAM
for {set i 0} {$i < $val(nn) } {incr i} {
	# 30 defines the node size for nam
	$ns_ initial_node_pos $node_($i) 30
}

##################################################

set stop 5.0

#for {set i 0} {$i < $val(nn) } {incr i} {
#    $ns_ at $stop "$node_($i) reset";
#}

$ns_ at $stop "$cbr0 stop"
$ns_ at $stop "finish"

puts "Starting Simulation..."
$ns_ run

